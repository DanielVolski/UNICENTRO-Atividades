import cv2
import numpy as np
from matplotlib import pyplot as plt

def gaussian_filter(image, ksize=(9, 9), sigma=5.0):
    blurred = cv2.GaussianBlur(image, ksize, sigma)
    return blurred

teste_img = cv2.cvtColor(cv2.imread("PDI_Exercicios_3_Imagens/teste.png"), cv2.COLOR_BGR2GRAY)

teste_img_filtered = gaussian_filter(teste_img)

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(teste_img_filtered, cmap="gray")
plt.show()

cv2.imwrite("images/teste_gaussian_blur.png", teste_img_filtered)