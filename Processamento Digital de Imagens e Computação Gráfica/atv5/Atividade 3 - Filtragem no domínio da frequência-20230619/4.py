import cv2
from matplotlib import pyplot as plt
import numpy as np

img1_s = cv2.imread('./PDI_Exercicios_3_imagens/arara.png', 0)
img2_s = cv2.imread('./PDI_Exercicios_3_imagens/arara_filtro.png', 0)

F1s = cv2.dft(np.float32(img1_s), flags=cv2.DFT_COMPLEX_OUTPUT)
F2s = cv2.dft(np.float32(img2_s), flags=cv2.DFT_COMPLEX_OUTPUT)

dft_shift1 = np.fft.fftshift(F1s)
dft_shift2 = np.fft.fftshift(F2s)

n2 = F1s.shape[0]//2
m2 = F1s.shape[1]//2

CONST = 5

F1p = np.fft.fftshift(F1s).copy()
F1p[:n2-CONST, :] = 0 
F1p[:, :m2-CONST] = 0
F1p[n2+CONST:, :] = 0
F1p[:, m2+CONST:] = 0
F1p = np.fft.ifftshift(F1p)

img_back = cv2.idft(F1p)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])

plt.subplot(121),plt.imshow(img1_s, cmap = 'gray')
plt.subplot(122),plt.imshow(img_back, cmap = 'gray')

plt.show()

cv2.imwrite("images/arara_filtered.png", img_back)