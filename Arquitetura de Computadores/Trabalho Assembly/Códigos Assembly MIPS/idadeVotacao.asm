.data
	string: .asciiz "Digite sua idade: "
	naoVota: .asciiz "Não pode votar!"
	obrigatorio: .asciiz "Voto obrigatório!"
	opcional: .asciiz "Voto facultativo!"
	
.text
	la $a0, string		#Carrega string em $a0
	jal print		#Chama a função print
	jal scan		#Chama a função scan
	
	blt $v0, 16, printNaoVota	#Se $v0 < 16 chama a label printNaoVota
	bge $v0, 18, printObrigatorio	#se $v0 >= 18 chama a label printObrigatorio
	bge $v0, 16, menorDezoito
	jal endAlg
	
	menorDezoito:
		blt $v0, 18, printOpcional
	
	printNaoVota:
		la $a0, naoVota
		li $v0, 4
		syscall
		jal endAlg
		
	printObrigatorio:
		la $a0, obrigatorio
		li $v0, 4
		syscall
		jal endAlg
		
	printOpcional:
		la $a0, opcional
		li $v0, 4
		syscall
		jal endAlg
		
	print:
		li $v0, 4
		syscall
		jr $ra
		
	scan:
		li $v0, 5
		syscall
		jr $ra
	endAlg:
		li $v0, 10
		syscall
	
	
