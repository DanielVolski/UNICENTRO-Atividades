from cv2 import imread, imwrite

#Abrindo a imagem
img = imread('grayscale_image.jpeg')

(height, width) = img.shape[0], img.shape[1]

#Convertendo pixels com valor 127 em preto
for y in range(height):
    for x in range(width):
        if (img[y, x] == (127, 127, 127)).all():
            img[y, x] = (0, 0, 0)

#Salvando arquivo
imwrite('output_p1.jpg', img)