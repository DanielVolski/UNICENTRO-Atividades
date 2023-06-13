from matplotlib import pyplot as plt
import numpy as np
import cv2

def uniform_noise(size, prob=0.1):
    levels = int((prob * 255) // 2)
    noise = np.random.randint(-levels, levels, size)
    return noise

def gaussian_noise(size, mean=0, std=0.01):
    noise = np.multiply(np.random.normal(mean, std, size), 255)
    return noise

def impulsive_noise(image, prob=0.1, mode='salt_and_pepper'):
    noise = np.array(image, copy=True)
    for x in np.arange(image.shape[0]):
        for y in np.arange(image.shape[1]):
            rnd = np.random.random()
            if rnd < prob:
                rnd = np.random.random()
                if rnd > 0.5:
                    noise[x, y] = 255
                else:
                    noise[x, y] = 0
    return noise

def rmse(f, g):
    size = f.shape
    return np.sqrt(np.sum(np.square(f-g)) / (size[0] * size[1]))

def fft_image_filter(g, w):
    pad1 = (g.shape[0] // 2) - w.shape[0] // 2
    wp = np.pad(w, (pad1, pad1 - 1), "constant", constant_values=0)

    W = cv2.fftn(wp)
    G = cv2.fftn(g)
    R = np.multiply(W, G)
    r = np.real(cv2.fftshift(cv2.iffrn(R)))
    return r

def median_filter(g, k):
    a = k // 2
    r = np.zeros(g.shape)
    for x in np.arange(a, g.shape[0] - a + 1):
        for y in np.arange(a, g.shape[1] - a + 1):
            med_region = np.median(g[x-a:x+a+1, y-a:y+a+1])
            r[x, y] = med_region
    return r

def notch_reject_filter(shape, d0=9, u_k=0, v_k=0):
    P, Q = shape
    H = np.zeros((P, Q))

    for u in range(0, P):
        for v in range(0, Q):
            D_uv = np.sqrt((u - P / 2 + u_k) ** 2 + (v - Q / 2 + v_k) ** 2)
            D_muv = np.sqrt((u - P / 2 - u_k) ** 2 + (v - Q / 2 - v_k) ** 2)

            if D_uv <= d0 or D_muv <= d0:
                H[u, v] = 0.0
            else:
                H[u, v] = 1.0
    return H

def gaussian_filter(k=5, sigma=1.0):
    arx = np.arange((-k // 2 ) + 1.0, (k // 2) + 1.0)
    x, y = np.meshgrid(arx, arx)
    filt = np.exp(-(1 / 2) * (np.square(x) + np.square(y)) / np.square(sigma))
    return filt / np.sum(filt)

img = cv2.imread("lena.png")
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

uni_noise = uniform_noise(img.shape, prob=0.5)
img_uni = np.clip(img.astype(int) + uni_noise, 0, 255)

hist_img, _ = np.histogram(img, bins=256, range=(0, 255))
hist_uni, _ = np.histogram(img_uni, bins=256, range=(0, 255))

plt.figure(figsize=(14, 9))
plt.subplot(221)
plt.imshow(img, cmap="gray", vmin=0, vmax=255)
plt.axis('off')
plt.subplot(222)
plt.bar(np.arange(256), hist_img)
plt.subplot(223)
plt.imshow(img_uni, cmap="gray", vmin=0, vmax=255)
plt.axis('off')
plt.subplot(224)
plt.bar(np.arange(256), hist_uni)
plt.show()

#Filtro de ruído Gaussiano
gau_noise = gaussian_noise(img.shape, mean=0, std=0.05)
img_gau = np.clip(img.astype(int) + gau_noise, 0, 255)

hist_gau, _ = np.histogram(img_gau, bins=256, range=(0, 255))

plt.figure(figsize=(14, 9))
plt.subplot(121)
plt.imshow(img, cmap="gray", vmin=0, vmax=255)
plt.axis('off')
plt.subplot(122)
plt.bar(np.arange(256), hist_gau)
plt.show()

#filtro de ruído impulsivo
#

f = img
h = gaussian_filter(k=7, sigma=2.5)
a = int(f.shape[0] // 2 - h.shape[0] // 2)
h_pad = np.pad(h, (a, a - 1), "constant", constant_values=0)
F = cv2.fftn(f)
H = cv2.fftn(h_pad)

H1 = notch_reject_filter(img)
H2 = notch_reject_filter(img)
H3 = notch_reject_filter(img)
H4 = notch_reject_filter(img)
H5 = notch_reject_filter(img)
H6 = notch_reject_filter(img)

NotchFilter = H1 * H2 * H3 * H4 * H5 * H6
NotchRejectCenter = fshift * NotchFilter
NotchReject = np.fft.ifftshift(NotchRejectCenter)
inverse_NotchReject = np.fft.ifft2(NotchReject)