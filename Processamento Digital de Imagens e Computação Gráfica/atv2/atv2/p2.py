import cv2
import numpy as np
from matplotlib import pyplot as plt

#Abrindo a imagem
img1 = cv2.imread('landscape.jpg')

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
img_log = np.array((255 / np.log(1 + np.max(img1))) * (np.log(img1 + 1)), dtype=np.uint8)

plt.figure(figsize=(16, 16))

plt.subplot(121)
plt.imshow(cv2.cvtColor(img_norm, cv2.COLOR_RGB2BGR))

plt.subplot(122)
plt.imshow(cv2.cvtColor(img_log, cv2.COLOR_RGB2BGR))

plt.show()