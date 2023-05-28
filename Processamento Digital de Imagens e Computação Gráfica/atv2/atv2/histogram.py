import cv2
import numpy as np
from matplotlib import pyplot as plt

img1 = cv2.imread('lena.png')
img2 = cv2.imread('landscape.jpg')
pixels_count_img1 = []
pixels_count_img2 = []

img1_norm = cv2.normalize(img1, None, 0, 100, cv2.NORM_MINMAX)
img2_norm = cv2.normalize(img2, None, 0, 100, cv2.NORM_MINMAX)
pixels_count_img1_norm = []
pixels_count_img2_norm = []

for i in range(256):
    pixels_count_img1.append(np.sum(img1 == i))
    pixels_count_img2.append(np.sum(img2 == i))
    pixels_count_img1_norm.append(np.sum(img1_norm == i))
    pixels_count_img2_norm.append(np.sum(img2_norm == i))

plt.hist(pixels_count_img1)
plt.show()

plt.hist(pixels_count_img2)
plt.show()

plt.hist(pixels_count_img1_norm)
plt.show()

plt.hist(pixels_count_img2_norm)
plt.show()