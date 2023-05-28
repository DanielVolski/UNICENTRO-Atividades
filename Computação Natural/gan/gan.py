# -*- coding: utf-8 -*-
"""GANs.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1DCcEKBDOkLVRRjjq9eBPYqvT88OJJxY0
"""

from keras.optimizers import Adam
from keras.models import Sequential
from keras.layers import Dense, Flatten, Conv2D, Dropout, LeakyReLU, Reshape, Conv2DTranspose, UpSampling2D
from keras.datasets.mnist import load_data
from numpy import ones, zeros, expand_dims, where
from numpy.random import randn, randint
import matplotlib.pyplot as plt
from tensorflow.keras import datasets

def descriminador(in_shape=(32, 32, 3)):
  model = Sequential()
  model.add(Conv2D(64, (3, 3), padding='same', input_shape=in_shape))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Dropout(0.4))
  model.add(Conv2D(128, (3,3), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Dropout(0.4))
  model.add(Conv2D(128, (3,3), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Conv2D(256, (3,3), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Flatten())
  model.add(Dropout(0.4))
  model.add(Dense(1, activation='sigmoid'))
  # compile model
  opt = Adam(learning_rate=0.0002, beta_1=0.5)
  model.compile(loss='binary_crossentropy', optimizer=opt, metrics=['accuracy'])
  return model

def geradora(latent_dim):
  model = Sequential()
  n_nodes = 256 * 4 * 4
  model.add(Dense(n_nodes, input_dim=latent_dim))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Reshape((4, 4, 256)))
  model.add(Conv2DTranspose(128, (4,4), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Conv2DTranspose(128, (4,4), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Conv2DTranspose(128, (4,4), strides=(2,2), padding='same'))
  model.add(LeakyReLU(alpha=0.2))
  model.add(Conv2D(3, (3, 3), activation='relu', padding='same'))
  return model

def gan(g_model, d_model):
  d_model.trainable = False
  model = Sequential()
  model.add(g_model)
  model.add(d_model)
  opt = Adam(learning_rate=0.0002, beta_1=0.5)
  model.compile(loss='binary_crossentropy', optimizer=opt)
  return model

def treino(modelo_g, modelo_d, modelo_gan, dados, dim_latente, num_epochs=500, tam_batch=128):
  contador = 0
  batches_por_epoca = int(dados.shape[0] / tam_batch)
  metade_batch = int(tam_batch / 2)
  for i in range(num_epochs):
    for j in range(batches_por_epoca):
      dados_reais, rotulos_reais = gera_reais(dados, metade_batch)
      d_loss1, _ = modelo_d.train_on_batch(dados_reais, rotulos_reais)
      dados_falsos, rotulos_falsos = gera_falsos(modelo_g, dim_latente, metade_batch)
      d_loss2, _ = modelo_d.train_on_batch(dados_falsos, rotulos_falsos)
      dados_gan = gera_pontos_latentes(dim_latente, tam_batch)
      rotulos_gan = ones((tam_batch, 1))
      gam_perda = modelo_gan.train_on_batch(dados_gan, rotulos_gan)
      contador = contador + 1
      print('>%d, %d/%d, d1=%.3f, d2=%.3f g=%.3f' % (i+1, j+1, batches_por_epoca, d_loss1, d_loss2, gam_perda))
      # evaluate the model performance, sometimes
      if (i+1) % 10 == 0:
        print('teste')
        sumarizar_performance(i, modelo_g, modelo_d, dados, dim_latente)

def sumarizar_performance(epoch, g_model, d_model, dataset, latent_dim, n_samples=150):
  # prepare real samples
  X_real, y_real = gera_reais(dataset, n_samples)
  # evaluate discriminator on real examples
  _, acc_real = d_model.evaluate(X_real, y_real, verbose=0)
  # prepare fake examples
  x_fake, y_fake = gera_falsos(g_model, latent_dim, n_samples)
  # evaluate discriminator on fake examples
  _, acc_fake = d_model.evaluate(x_fake, y_fake, verbose=0)
  # summarize discriminator performance
  print('>Accuracy real: %.0f%%, fake: %.0f%%' % (acc_real*100, acc_fake*100))
  # save plot
  save_plot(x_fake, epoch)
  # save the generator model tile file
  filename = 'generator_model_%03d.h5' % (epoch+1)
  g_model.save(filename)

def save_plot(examples, epoch, n=7):
  # scale from [-1,1] to [0,1]
  examples = (examples + 1) / 2.0
  # plot images
  for i in range(n * n):
    # define subplot
    plt.subplot(n, n, 1 + i)
    # turn off axis
    plt.axis('off')
    # plot raw pixel data
    plt.imshow(examples[i])
    # save plot to file
  filename = 'generated_plot_e%03d.png' % (epoch+1)
  plt.savefig(filename)
  plt.close()

def gera_pontos_latentes(dim_latente, num_amostras):
  dados = randn(dim_latente * num_amostras)
  dados = dados.reshape(num_amostras, dim_latente)
  return dados

def gera_reais(dados, num_amostras):
  indices = randint(0, dados.shape[0], num_amostras)
  dados_reais = dados[indices]
  rotulos_reais = ones((num_amostras, 1))
  return dados_reais, rotulos_reais

def gera_falsos(modelo_g, latent_dim, num_amostras):
  pontos_latentes = gera_pontos_latentes(latent_dim, num_amostras)
  dados_falsos_gerados = modelo_g.predict(pontos_latentes)
  rotulos_falsos = zeros((num_amostras, 1))
  return dados_falsos_gerados, rotulos_falsos
#def gera_falsos(num_amostras):
#  dados_falsos = randn(28 * 28 * num_amostras)
#  dados_falsos = dados_falsos.reshape(num_amostras, 28, 28, 1)
#  rotulos_falsos = zeros((num_amostras, 1))
#  return dados_falsos, rotulos_falsos

def gera_falsas_rede_geradora(modelo_g, latent_dim, num_amostras):
  pontos_latentes = gera_pontos_latentes(latent_dim, num_amostras)
  dados_falsos_gerados = modelo_g.predict(pontos_latentes)
  rotulos_falsos = zeros((num_amostras, 1))
  return dados_falsos_gerados, rotulos_falsos

def carrega_amostras():
  (trein_dados, trein_rotulos), (teste_dados, teste_rotulos) = datasets.cifar10.load_data()
  gato_indices = where(trein_rotulos == 3)[0]
  gato_imagens = trein_dados[gato_indices]
  #gato_imagens = expand_dims(gato_imagens, axis=-1)
  gato_imagens = gato_imagens / 255.0
  return gato_imagens

dados = carrega_amostras()
dim_latente = 128
modelo_g = geradora(dim_latente)
modelo_d = descriminador()
modelo_gan = gan(modelo_g, modelo_d)

# Plota as imagens
for i in range(25):
    plt.subplot(7, 7, 1 + i)
    plt.axis('off')
    plt.imshow(dados[i])
plt.show()

treino(modelo_g, modelo_d, modelo_gan, dados, dim_latente)