.data
	msgPeso: .asciiz "Digite o seu peso: "
	msgAltura: .asciiz "Digite a sua altura: "
	msgResultado: .asciiz "O resultado do seu IMC é: "
	magreza: .asciiz "Magreza!"
	normal:.asciiz "Normal"
	sobrepeso: .asciiz "Sobrepeso"
	obesidade: .asciiz "Obesidade"
	obesidadeGrave: .asciiz "Obesidade grave!"
	float1: .float 18.5
	float2: .float 25.0
	float3: .float 30.0
	float4: .float 40.0	
.text
	li $v0, 4		#Imprime string
	la $a0, msgPeso		#Carrega a string que será impressa
	syscall
	li $v0, 6		#Faz leitura de um float e coloca em $f0
	syscall
	mov.s $f1, $f0		#Move o valor float de $f0 para $f1
	li $v0, 4		#Imprime string
	la $a0, msgAltura	#Carrega a string que será impressa
	syscall
	li $v0, 6		#Faz a leitura de um float para $f0
	syscall	
	mul.s $f0, $f0, $f0	#altura²
	div.s $f12, $f1, $f0	#peso / altura²
	li $v0, 4		#Imprime string
	la $a0, msgResultado	#Carrega string que será impressa
	syscall
	l.s $f13, float1	#Carrega a constante 18.5 para $f13
	c.lt.s $f12, $f13	#Se $f12 < $f13 fp é marcado como 1 true
	bc1t resultadoMagreza	#Checa se fp é 1 ou 0, se for 1 então redireciona para a label indicada
	c.le.s $f13, $f12	#Se $f13 < $f12 fp é marcado como 1
	bc1t resultadoNormal	#Se fp estiver marcado como 1 vai para label resultadoNormal
	jal encerraAlgoritmo
resultadoMagreza:
	li $v0, 4
	la $a0, magreza
	syscall
	jal encerraAlgoritmo
resultadoNormal:
	l.s $f13, float2	#carrega float2 em $f13
	c.lt.s $f13, $f12	#Se $f13 < $f12 fp é marcado como 1
	bc1t resultadoSobrepeso	#Se fp estiver marcado como 1 vai para label resultadoSobrepeso
	li $v0, 4
	la $a0, normal
	syscall
	jal encerraAlgoritmo
resultadoSobrepeso:
	l.s $f13, float3	#carrega float3 em $f13
	c.lt.s $f13, $f12	#Se $f13 < $f12 fp é marcado como 1
	bc1t resultadoObesidade	#Se fp estiver marcado como 1 vai para label resultadoObesidade
	li $v0, 4
	la $a0, sobrepeso
	syscall
	jal encerraAlgoritmo
resultadoObesidade:
	l.s $f13, float4	#carrega float4 em $f13
	c.lt.s $f13, $f12	#Se $f13 < $f12 fp é marcado como 1
	bc1t resultadoObesidadeGrave	#Se fp estiver marcado como 1 vai para label resultadoObesidadeGrave
	li $v0, 4
	la $a0, obesidade
	syscall
	jal encerraAlgoritmo
resultadoObesidadeGrave:
	li $v0, 4
	la $a0, obesidadeGrave
	syscall
	jal encerraAlgoritmo
encerraAlgoritmo:
	li $v0, 10
	syscall
	