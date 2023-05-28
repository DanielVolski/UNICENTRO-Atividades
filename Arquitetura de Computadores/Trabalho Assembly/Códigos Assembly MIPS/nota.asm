.data
	msgNota: .asciiz "Digite sua nota: "
	msgAprovado: .asciiz "Aprovado!"
	msgExame: .asciiz "Em exame!"
	msgReprovado: .asciiz "Reprovado!"
	msgNotaExame: .asciiz "Digite sua nota no exame: "	
.text
	li $v0, 4		#Solicita a impressão de uma string
	la $a0, msgNota		#Passa msgNota como argumento para a impressão
	syscall
	li $v0, 5		#Solicita a leitura de um inteiro e armazena em $v0
	syscall
	bge $v0, 70, aprovado	#Se $v0 >= 70, vai para a label aprovado
	blt $v0, 70, exame	#Se $v0 < 70 vai para a label exame
aprovado:
	li $v0, 4		#Solicita a imressão de uma string
	la $a0, msgAprovado	#Carrega a string que será impressa
	syscall
	jal encAlg		#Encerra
exame:
	blt $v0, 60, reprovado	#Se $v0 < 60, vai para a label reprovado
	li $v0, 4		#Solicita a imressão de uma string 
	la $a0, msgNotaExame	#Carrega a string que será impressa
	syscall
	li $v0, 5		#Faz a leitura de um inteiro
	syscall
	bge $v0, 70, aprovado	#Se $v0 >= 70, vai para a label aprovado
	blt $v0, 60, reprovado	#Se $v0 < 60 vai para a label exame
reprovado:
	li $v0, 4		#Solicita a imressão de uma string 
	la $a0, msgReprovado	#Carrega a string que será impressa
	syscall
	jal encAlg
encAlg:
	li $v0, 10
	syscall	