import cv2
import math
import numpy as np
from matplotlib import pyplot as plt

def method3(img):
    aux = np.zeros(img.shape)
    new_image = np.zeros((img.shape[0], img.shape[1], 1))
    s_min, s_max, h_min, h_max = 100, 179, 40, 60
    for i in range(len(img)):
        for j in range(len(img[i])):
            # Saturacao
            if img[i][j][2] >= 0 and img[i][j][2] <= s_min:
                aux[i][j][2] = 0
            elif img[i][j][2] > s_min and img[i][j][2] < s_max:
                aux[i][j][2] = img[i][j][2]
            elif img[i][j][2] >= s_max and img[i][j][2] <= 255:
                aux[i][j][2] = 255

            # Matiz
            if img[i][j][0] >= h_min and img[i][j][0] <= h_max:
                aux[i][j][0] = 255

            if aux[i][j][0] == aux[i][j][2]:
                new_image[i][j][0] = 255
            print(new_image[i][j])
    return new_image
            
img = cv2.cvtColor(cv2.imread("traffic_signs/img1.jpg"), cv2.COLOR_BGR2HLS)
img_norm = cv2.normalize(img, None, 0, 255, cv2.NORM_MINMAX)

result = method3(img)

plt.figure(figsize=(16, 16))
plt.subplot(131)
plt.imshow(img)
plt.subplot(132)
plt.imshow(result, cmap="gray")
plt.show()