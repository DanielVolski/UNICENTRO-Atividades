import cv2
import math
import numpy as np
from matplotlib import pyplot as plt

# def rgb_to_ihsl(img_rgb):
#     img_ihsl = np.zeros(img_rgb.shape)
#     for i in range(len(img_rgb)):
#         for j in range(len(img_rgb[i])):
#             b, g, r = img_rgb[i][j] / 255
#             if (b == g == r):
#                 tetha = math.acos(0)            
#             else:
#                 x = r - g/2 - b/2
#                 y = math.sqrt((r*r) + (g*g) + (b*b) - (r*g) - (r*b) - (g*b))
#                 tetha = math.acos(min(1, max(-1, x / y)))
#             if b <= g:
#                 img_ihsl[i][j][0] = tetha
#             else:
#                 img_ihsl[i][j][0] = 360 - tetha
#             img_ihsl[i][j][1] = max(r, g, b) - min(r, g, b)
#             img_ihsl[i][j][2] = 0.212*r + 0.715*g + 0.072*b
#     return img_ihsl

def method1(img, ref_pixel):
    luminance_sum = 0
    result = np.zeros(img.shape)
    

    for i in img:
        for j in i:
            luminance_sum = luminance_sum + j[1]
    
    nmean = (luminance_sum / (img.shape[0] * img.shape[1])) / 255
    thresh = pow(math.e, -nmean)

    for i in range(len(img)):
        for j in range(len(img[i])):
            dist = math.sqrt(math.pow((ref_pixel[2] / 255)*math.cos((ref_pixel[0] / 179)) - (img[i][j][2] / 255)*math.cos((img[i][j][0] / 179)), 2)
                             + math.pow((ref_pixel[2] / 255)*math.sin(ref_pixel[0] / 179) - (img[i][j][2] / 255)*math.sin((img[i][j][0] / 179)), 2))
            if dist < thresh:
                result[i][j] = 255
            else:
                result[i][j] = 0
    return result

img = cv2.cvtColor(cv2.imread("traffic_signs/img1.jpg"), cv2.COLOR_BGR2HLS)
ref_pixel = np.array([60, 127, 255])
img_segmented = method1(img, ref_pixel)

plt.figure(figsize=(16, 16))
plt.subplot(131)
plt.imshow(img)
plt.subplot(132)
plt.imshow([[ref_pixel]])
plt.subplot(133)
plt.imshow(img_segmented)
plt.show()