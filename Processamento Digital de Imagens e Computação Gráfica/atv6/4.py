import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.cvtColor(cv2.imread("PDI_Exercicios_4_Imagens/igreja.png"), cv2.COLOR_BGR2GRAY)

img_canny = cv2.Canny(img, 50, 50)

cv2.imwrite("images/igreja_canny.png", img_canny)