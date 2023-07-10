import cv2
import numpy as np
from matplotlib import pyplot as plt

def medianfilter(g, k):
    a = k//2
    r = np.zeros(g.shape)
    for x in np.arange(a, g.shape[0]-a+1):
        for y in np.arange(a, g.shape[1]-a+1):
            med_region = np.median(g[x-a:x+a+1, y-a:y+a+1])
            r[x,y] = med_region
    
    return r

img = cv2.imread("PDI_Exercicios_4_Imagens/circuito.tif")

img_filtered_1 = medianfilter(img, 7)
cv2.imwrite("images/filtered_1.png", img_filtered_1)
img_filtered_2 = medianfilter(img_filtered_1, 7)
cv2.imwrite("images/filtered_2.png", img_filtered_2)
img_filtered_3 = medianfilter(img_filtered_2, 7)
cv2.imwrite("images/filtered_3.png", img_filtered_3)