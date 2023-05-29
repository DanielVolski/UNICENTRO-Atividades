import cv2
import numpy as np
import math
from matplotlib import pyplot as plt

#Abrindo a imagem
img1 = cv2.imread('lena.png')

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(cv2.cvtColor(img1, cv2.COLOR_BGR2RGB))
plt.show()

#Redimensionando a imagem em uma escala de 50 por cento
scale_percent = 50
dim_img1 = (int(img1.shape[1] * scale_percent / 100), int(img1.shape[0] * scale_percent / 100))
resized_img1 = cv2.resize(img1, dim_img1, interpolation=cv2.INTER_AREA)

#Convertendo a imagem colorida e redimensionada para a escala de cinza
img1_gray = cv2.cvtColor(resized_img1, cv2.COLOR_BGR2GRAY)

#Invertendo as cores da imagem colorida
img1_inverted = 255 - img1
print(img1_inverted)

#Invertendo as cores da imagem em escala de cinza
img1_gray_inverted = 255 - img1_gray

plt.figure(figsize=(16, 16))

#Faz o plot da imagem redimensionada
plt.subplot(221)
plt.imshow(cv2.cvtColor(resized_img1, cv2.COLOR_RGB2BGR))

#Faz o plot da imagem redimensionada em escala de cinza
plt.subplot(222)
plt.imshow(cv2.cvtColor(img1_gray, cv2.COLOR_RGB2BGR))

#Faz o plot da imagem redimensionada com as cores invertidas
plt.subplot(223)
plt.imshow(cv2.cvtColor(img1_inverted, cv2.COLOR_RGB2BGR), cmap='gray')

#Faz o plot da imagem redimensionada com as cores invertidas em escala de cinza
plt.subplot(224)
plt.imshow(cv2.cvtColor(img1_gray_inverted, cv2.COLOR_RGB2BGR), cmap='gray')

plt.show()

#Fazendo a normalização da imagem
img_norm = cv2.normalize(img1, np.array([]), 0, 100, cv2.NORM_MINMAX)

#Operador logaritmico
img_log = np.array((255 / np.log2(1 + np.max(img1.astype(np.int32)))) * np.log2(img1.astype(np.int32) + 1), dtype=np.uint8)
img_sig = np.array((255 / (1 + np.exp(-0.010 * (img1.astype(np.int32) - 127)))), dtype=np.uint8)

#Para aplicar a limiarização a imagem precisa estar em escala de cinza
T = 100
img_lim = np.zeros(img1_gray.shape)
img_lim[np.where(img1_gray > T)] = 1

plt.figure(figsize=(16, 16))

plt.subplot(241)
plt.imshow(cv2.cvtColor(img_norm, cv2.COLOR_RGB2BGR))

plt.subplot(242)
plt.imshow(cv2.cvtColor(img_log, cv2.COLOR_RGB2BGR))

plt.subplot(243)
plt.imshow(cv2.cvtColor(img_sig, cv2.COLOR_RGB2BGR))

plt.subplot(244)
plt.imshow(img_lim, cmap="gray")

plt.show()
