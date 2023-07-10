import cv2
import numpy as np
from matplotlib import pyplot as plt

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

img = cv2.cvtColor(cv2.imread("PDI_Exercicios_4_Imagens/linhas.png"), cv2.COLOR_BGR2GRAY)

filter_h = np.array([[-1, -1, -1], [2, 2, 2], [2, -1, -1]])
filter_plus_45 = np.array([[-1, -1, 2], [-1, 2, -1], [2, -1, -1]])
filter_v = np.array([[-1, 2, -1], [-1, 2, -1], [-1, 2, -1]])
filter_minus_45 = np.array([[2, -1, -1], [-1, 2, -1], [-1, -1, 2]])

img_filter_h = img_convolution(img, filter_h)
img_filter_plus_45 = img_convolution(img, filter_plus_45)
img_filter_v = img_convolution(img, filter_v)
img_filter_minus_45 = img_convolution(img, filter_minus_45)

limiar_h, img_h_limiar = cv2.threshold(img_filter_h, 127, 255, cv2.THRESH_BINARY)
limiar_plus_45, img_plus_45_limiar = cv2.threshold(img_filter_plus_45, 127, 255, cv2.THRESH_BINARY)
limiar_v, img_v_limiar = cv2.threshold(img_filter_v, 127, 255, cv2.THRESH_BINARY)
limiar_minus_45, img_minus_45_limiar = cv2.threshold(img_filter_minus_45, 127, 255, cv2.THRESH_BINARY)

cv2.imwrite("images/linhas_h.png", img_h_limiar)
cv2.imwrite("images/linhas_plus_45.png", img_plus_45_limiar)
cv2.imwrite("images/linhas_v.png", img_v_limiar)
cv2.imwrite("images/linhas_minus_45.png", img_minus_45_limiar)