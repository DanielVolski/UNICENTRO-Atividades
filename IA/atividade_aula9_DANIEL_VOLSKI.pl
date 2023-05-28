/* Atividade Aula 9 
 * 
 * Disciplina: Inteligência artificial
 * Aluno: Daniel Flavio Volski Daum
 * Turma: A
 */

/* Árvore genealógica */
mulher(filisbina).
mulher(rodolfina).
mulher(deusarina).
mulher(astolfa).
homem(justino).
homem(rodolfo).
homem(walter).
homem(victor).

filho(walter, victor). /*Walter é filho de Victor*/
filho(walter, astolfa). /*Walter é filho de Astolfa*/
filho(deusarina, victor). /*Deusarina é filha de Victor, irmã de Walter, tia de filisbina e rodolfina*/
filho(deusarina, astolfa). /*Deusarina é filha de Astolfa, irmã de Walter*/
filho(filisbina, walter). /* Filisbina é filha de Walter neta de Victor e Astolfa*/
filho(rodolfina, walter). /* Rodolfina é filha de Walter irmã de Filisbina*/

pai(X, Y) :- homem(X), filho(Y, X).
mae(X, Y) :- mulher(X), filho(Y, X).
irmão(X, Y) :- homem(X), X \== Y, mae(Z, X), mae(Z, Y), pai(W, X), pai(W, Y).
irmã(X, Y) :- mulher(X), X \== Y, mae(Z, X), mae(Z, Y), pai(W, X), pai(W, Y).
tio(X, Y) :- homem(X), (pai(Z, Y), irmão(X, Z)); (mae(Z, Y), irmão(X, Z)).
tia(X, Y) :- mulher(X), (pai(Z, Y), irmã(X, Z)); (mae(Z, Y), irmã(X, Z)).
sobrinho(X, Y) :- homem(X), tio(Y, X); tia(Y, X).
sobrinha(X, Y) :- mulher(X), tio(Y, X); tia(Y, X).
avô(X, Z) :- homem(X), (pai(X, Y), pai(Y, Z)); (pai(X, Y), mae(Y, Z)).
avó(X, Z) :- mulher(X), (mae(X, Y), mae(Y, Z)); (pai(X, Y), mae(Y, Z)).

/* Cálculo da média aritmética */
somatoria([], 0).
somatoria([X | Y], S) :- somatoria(Y, SY), S is X + SY.
conta_elementos([], 0).
conta_elementos([_X | Y], N) :- conta_elementos(Y, NY), N is NY + 1.
media([X | Y], M) :- somatoria([X | Y], S), conta_elementos([X | Y], N), M is S/N.
