from cv2 import imread, imwrite

img = imread('colored_img_landscape.jpg')

fst_quadrant_height, fst_quadrant_width = int(img.shape[0] / 2), int(img.shape[1] / 2)

for y in range(fst_quadrant_height):
    for x in range(fst_quadrant_width):
        img[y, x] = (0, 255, 255)

imwrite('output_p2.jpg', img)