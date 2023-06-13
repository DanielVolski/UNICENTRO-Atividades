import cv2
import math
import numpy as np
from matplotlib import pyplot as plt

def plot_img(img):
    plt.figure(figsize=(16, 16))
    plt.subplot(111)
    plt.imshow(img, cmap='gray')
    plt.show()

def mean(img, k_size):
    size = int(k_size)

    if size % 2 == 0:
        size += 1

    kernel = np.ones((size, size), dtype=np.float32) / (size * size)
    result = img_convolution(img, kernel)

    return result.astype(np.uint8)

def get_neighbors(img, k):
    unidimensional_img = img.flatten()
    sorted_array = np.sort(unidimensional_img )
    k_neighbors = sorted_array[:k]
    img_neighbors = np.tile(k_neighbors, img.size // k)[:img.size]
    img_neighbors = img_neighbors.reshape(img.shape)
    return img_neighbors

def roberts(img):
    kernel_x = np.array([[1, 0, 0], [0, -1, 0]])
    kernel_y = np.array([[0, 1, 0], [-1, 0, 0]])

    grad_x = img_convolution(img, kernel_x)
    grad_y = img_convolution(img, kernel_y)

    grad = np.sqrt(grad_x**2 + grad_y**2)
    grad = (grad / np.max(grad)) * 255

    return grad.astype(np.uint8)

def prewitt(img):
    kernel_x = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]])
    kernel_y = np.array([[-1, -1, -1], [0, 0, 0], [1, 1, 1]])

    grad_x = img_convolution(img, kernel_x)
    grad_y = img_convolution(img, kernel_y)

    grad = np.sqrt(grad_x**2 + grad_y**2)
    grad = (grad / np.max(grad)) * 255

    return grad.astype(np.uint8)

def sobel(img):
    kernel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    kernel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    grad_x = img_convolution(img, kernel_x)
    grad_y = img_convolution(img, kernel_y)

    grad = np.sqrt(grad_x**2 + grad_y**2)
    grad = (grad / np.max(grad)) * 255

    return grad.astype(np.uint8)

def img_convolution(f, w):
    N, M = f.shape
    n, m = w.shape
    g = np.zeros(f.shape)
    w_flip = np.flip(np.flip(w, 0), 1)

    a = int((n - 1) / 2)
    b = int((m - 1) / 2)

    for x in range(a, N - a):
        for y in range(b, M - b):
            sub_f = f[x - a : x + a + 1, y - b:y + b + 1]
            g[x, y] = np.sum(np.multiply(sub_f, w_flip))
    
    return g

img1_gray = cv2.cvtColor(cv2.imread('lena.png'), cv2.COLOR_BGR2GRAY)
img2_gray = cv2.cvtColor(cv2.imread('landscape.jpg'), cv2.COLOR_BGR2GRAY)

mean_img1 = mean(img1_gray, 25)
roberts_img1 = roberts(img1_gray)
prewitt_img1 = prewitt(img1_gray)
sobel_img1 = sobel(img1_gray)

plt.figure(figsize=(16, 16))

plt.subplot(231)
plt.title("Filtro de suavização por média da vizinhança")
plt.imshow(mean_img1, cmap='gray')

plt.subplot(233)
plt.title("Filtro de Roberts")
plt.imshow(roberts_img1, cmap='gray')

plt.subplot(234)
plt.title("Filtro de Prewitt")
plt.imshow(prewitt_img1, cmap='gray')

plt.subplot(235)
plt.title("Filtro de Sobel")
plt.imshow(sobel_img1, cmap='gray')

plt.show()
