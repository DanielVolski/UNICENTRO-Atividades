import tensorflow as tf
from tensorflow import keras
from keras import datasets
import matplotlib.pyplot as plt
from keras.layers import LeakyReLU, Dropout

(train_images, train_coarse_labels), (test_images, test_coarse_labels) = datasets.cifar100.load_data(label_mode='coarse')
train_images = train_images / 255.0
test_images = test_images / 255.0

super_categories = [
    "aquatic mammals", "fish", "flowers", "food containers", "fruit and vegetables",
    "household electrical devices", "household furniture", "insects", "large carnivores", "large man-made outdoor things",
    "large natural outdoor scenes", "large omnivores and herbivores", "medium-sized mammals", "non-insect invertebrates", "people",
    "reptiles", "small mammals", "trees", "vehicles 1", "vehicles 2",
]

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Conv2D(512, (3, 3), activation='relu', input_shape=(32, 32, 3)))
model.add(LeakyReLU(alpha=0.2))
model.add(Dropout(0.4))
model.add(tf.keras.layers.MaxPooling2D((2, 2)))
model.add(tf.keras.layers.Conv2D(512, (3, 3), activation='relu'))
model.add(LeakyReLU(alpha=0.2))
model.add(Dropout(0.4))
model.add(tf.keras.layers.MaxPooling2D((2, 2)))
model.add(tf.keras.layers.Conv2D(512, (3, 3), activation='relu'))
model.add(LeakyReLU(alpha=0.2))
model.add(Dropout(0.4))
model.add(tf.keras.layers.MaxPooling2D((2, 2)))
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(512, activation='relu'))
model.add(Dropout(0.4))
model.add(tf.keras.layers.Dense(20, activation='softmax'))
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
history = model.fit(train_images, train_coarse_labels, epochs=10, validation_data=(test_images, test_coarse_labels))

plt.plot(history.history['accuracy'], label='Treinamento')
plt.plot(history.history['val_accuracy'], label='Validade')
plt.xlabel('Epoca')
plt.ylabel('Acuracia')
#plt.ylim([0.4, 1.0])
plt.legend(loc='lower right')
#print(history.history.keys())
plt.show()