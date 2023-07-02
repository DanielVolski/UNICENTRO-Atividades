import cv2
from matplotlib import pyplot as plt
import numpy as np

teste = cv2.cvtColor(cv2.imread("PDI_Exercicios_3_Imagens/teste.png"), cv2.COLOR_BGR2GRAY)
teste_dft = cv2.dft(np.float32(teste), flags=cv2.DFT_COMPLEX_OUTPUT)

n1 = teste.shape[0] // 2 
m1 = teste.shape[1] // 2

CONST = 100
teste_copy_hp = np.fft.fftshift(teste_dft)
teste_copy_hp[n1-CONST:n1+CONST, m1-CONST:m1+CONST] = 0
teste_copy_hp = np.fft.ifftshift(teste_copy_hp)
teste_copy_hp = cv2.idft(teste_copy_hp)
teste_copy_hp = cv2.magnitude(teste_copy_hp[:, :, 0], teste_copy_hp[:, :, 1])

teste_copy_lp = np.fft.fftshift(teste_dft)
teste_copy_lp[:n1-CONST, : ] = 0
teste_copy_lp[ : , :m1-CONST] = 0
teste_copy_lp[n1+CONST:, : ] = 0
teste_copy_lp[ : , m1+CONST: ] = 0
teste_copy_lp = np.fft.ifftshift(teste_copy_lp)
teste_copy_lp = cv2.idft(teste_copy_lp)
teste_copy_lp = cv2.magnitude(teste_copy_lp[:, :, 0], teste_copy_lp[:, :, 1])

teste_copy_bs = np.fft.fftshift(teste_dft)
teste_copy_bs[100:-100,100:-100] = 0
teste_copy_bs = np.fft.ifftshift(teste_copy_bs)
teste_copy_bs = cv2.idft(teste_copy_bs)
teste_copy_bs = cv2.magnitude(teste_copy_bs[:, :, 0], teste_copy_bs[:, :, 1])

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(teste_copy_hp, cmap="gray")
plt.show()

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(teste_copy_lp, cmap="gray")
plt.show()

plt.figure(figsize=(16, 16))
plt.subplot(111)
plt.imshow(teste_copy_bs, cmap="gray")
plt.show()

cv2.imwrite('images/teste_high_pass_filter.png', teste_copy_hp)
cv2.imwrite('images/teste_low_pass_filter.png', teste_copy_lp)
cv2.imwrite('images/teste_band_stop_filter.png', teste_copy_bs)