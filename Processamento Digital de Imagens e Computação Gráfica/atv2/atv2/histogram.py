import cv2
import numpy as np
from matplotlib import pyplot as plt
import sys

def histogram(A, nbins):
    N, M, _ = A.shape
    hist_b = np.zeros(nbins).astype(int)
    hist_g = np.zeros(nbins).astype(int)
    hist_r = np.zeros(nbins).astype(int)

    for x in range(N):
        for y in range(M):
            hist_b[A[x, y, 0]] += 1
            hist_g[A[x, y, 1]] += 1
            hist_r[A[x, y, 2]] += 1

    return (hist_b, hist_g, hist_r)

img1 = cv2.imread('lena.png')
img2 = cv2.imread('landscape.jpg')
img1_norm = cv2.normalize(img1, None, 0, 100, cv2.NORM_MINMAX)
img2_norm = cv2.normalize(img2, None, 0, 100, cv2.NORM_MINMAX)

b_pixels_img1, g_pixels_img1, r_pixels_img1 = histogram(img1, 256)
b_pixels_img2, g_pixels_img2, r_pixels_img2 = histogram(img2, 256)

b_pixels_img1_norm, g_pixels_img1_norm, r_pixels_img1_norm = histogram(img1_norm, 256)
b_pixels_img2_norm, g_pixels_img2_norm, r_pixels_img2_norm = histogram(img2_norm, 256)

plt.bar(np.arange(256), b_pixels_img1)
plt.bar(np.arange(256), g_pixels_img1)
plt.bar(np.arange(256), r_pixels_img1)
plt.title("Image 1")
plt.show()

plt.bar(np.arange(256), b_pixels_img1_norm)
plt.bar(np.arange(256), g_pixels_img1_norm)
plt.bar(np.arange(256), r_pixels_img1_norm)
plt.title("Image 1 normalized")
plt.show()

plt.bar(np.arange(256), b_pixels_img2)
plt.bar(np.arange(256), g_pixels_img2)
plt.bar(np.arange(256), r_pixels_img2)
plt.title("Image 2")
plt.show()

plt.bar(np.arange(256), b_pixels_img2_norm)
plt.bar(np.arange(256), g_pixels_img2_norm)
plt.bar(np.arange(256), r_pixels_img2_norm)
plt.title("Image 2 normalized")
plt.show()