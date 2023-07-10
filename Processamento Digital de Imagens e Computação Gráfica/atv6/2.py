import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.cvtColor(cv2.imread("PDI_Exercicios_4_Imagens/pontos.png"), cv2.COLOR_BGR2GRAY)

img_filter = np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]])

result = cv2.filter2D(img, -1, img_filter)

limiar, img_limiar= cv2.threshold(result, 127, 255, cv2.THRESH_BINARY)

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(img_limiar)
plt.show()

cv2.imwrite("images/pontos_limiar.png", img_limiar)