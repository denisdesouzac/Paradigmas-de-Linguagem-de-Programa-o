menorDeDois(A, B, A):-
	A =< B, !.
menorDeDois(_, B, B).

menorDeTres(A, B, C, D):-
	menorDeDois(A, B, MAB),
	menorDeDois(MAB, C, D).

fatorial(0, 1):-!.
fatorial(N, Fat):-
	N1 is N-1,
	fatorial(N1, FatN1),
	Fat is N*FatN1.

fibonacci(1,1):-!.
fibonacci(2,1):-!.
fibonacci(N, F):-
	N1 is N-1,
	fibonacci(N1, F1),
	N2 is N-2,
	fibonacci(N2, F2),
	F is F1+F2.

elemento(1, [C|_], C):-!.
elemento(N, [_|R], E):-
	N1 is N-1,
	elemento(N1, R, E).

pertence(C, [C|_]):-!.
pertence(E, [_|R]):-
	pertence(E, R).

nroElementos([], 0).
nroElementos([C|R], N):-
	nroElementos(R, N1),
	N is N1+1.

maiorDeDois(A, B, A):-
	A >= B, !.
maiorDeDois(_, B, B).

maior([E], E):-!.
maior([C|R], M):-
	maior(R, MR),
	maiorDeDois(C, MR, M).


nroOcorrencias(E, [C|R], QTD):-
	nroOcorrencias(C, R, OCR),
	QTD is 1 + OCR.
nroOcorrencias(I, [_|R], QTD):-
	nroOcorrencias(I, R, QTD).
nroOcorrencias(_, [], 0).

unicaOcorrencia (C, [C|R]):-
	not(pertence(C, R)).
unicaOcorrencia(E, [_|R]):-
	unicaOcorrencia(E, R).

maioresQue(Ref, [C|R], [C|Maiores]:-
	Ref < C, !,
	maioresQue(Ref, R, Maiores).
maioresQue(Ref, [_|R], Maiores):-
	maioresQue(Ref, R, Maiores).
maioresQue(_,[], []).

concatena([], L, L).
concatena([C|R], L, [C|Outros]):-
	concatena(R, L, Outros).

remove(C, [C|R], R):-!.
remove(E, [C|R], [C|RsemE]):-
	remove (E, R, RsemE).

removeUltimo([_], []):-!.
removeUltimo([C|R], [C|RsemU]):-
	removeUltimo(R, RsemU).

removeRepetidos([C1|R1], [C1|R2]):-
	removeTodos(C1, R1, R1semC1),
	removeRepetidos(R1semC1, R2).
removeRepetidos([], []).

removeTodos(C, [C|R], RsemC):-!,
	removeTodos(C, R, RsemC).
removeTodos(E, [C|R], [C|RsemE]:-
	removeTodos(E, R, RsemE.
removeTodos(_, [], []).


