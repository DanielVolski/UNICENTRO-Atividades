.data
	msgNomeProduto: .asciiz "Digite o nome do produto: "
	msgQtProduto: .asciiz "Digite a quantidade que será comprada: "
	msgValorProduto: .asciiz "Digite o valor do produto: "
	msgValorTotalCompra: .asciiz "O valor total da compra é: R$"
	nomeProduto: .space 20
	qtProduto: .word
	valorProduto: .float
.text	
	li $t1, 3				#$t1 armazena 3, que servirá como contador do loop
	loop:
		la $a0, msgNomeProduto		#Carrega msgNomeProduto em $a0
		jal printString			#Chama a função printString
		li $v0, 8			#Solicita a leitura de string
		la $a0, nomeProduto		#Carrega a variável nomeProduto em $a0
		la $a1, 20			#Realiza uma leitura de string de 20 caracteres
		syscall
		
		la $a0, msgQtProduto		#Carrega a variável msgQtProdtuo em $a0
		jal printString			#Chama a função printString
		li $v0, 5			#Realiza a leitura de um inteiro
		syscall
		mtc1 $v0, $f1			#Move o inteiro lido do registrador $v0 Coproc 1 $f1
		cvt.s.w $f1, $f1		#Converte o valor de $f1 (inteiro) para float 
		
		la $a0, msgValorProduto		#carrega a variável msgValorProduto em $a0
		jal printString			#Chama a função printString
		li $v0, 6			#Realiza a leitura de um float, e envia para $f0 em Coproc 1
		syscall
				
		mul.s $f2, $f0, $f1		#Multiplica o valor de $f0 por $f1 e armzena em $f2
		add.s $f12, $f12, $f2		#Soma o valor presente em $f3 com o valor de $f2
		subi $t1, $t1, 1		#Realiza a subtração do valor do registrador $t1
		bgtz $t1, loop
	
	la $a0, msgValorTotalCompra		#Carrega a mensagem msgValorTotalCompra em $a0
	jal printString				#Chama a função printString	
	li $v0, 2
	syscall

	jal endAlg
	
	#Função para fazer a impressão de strings
	printString:
		li $v0, 4
		syscall
		jr $ra
	
	#Função para finalizar o algoritmo
	endAlg:
		li $v0, 10
		syscall
