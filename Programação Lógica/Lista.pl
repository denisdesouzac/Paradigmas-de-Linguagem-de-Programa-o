menorDeDois(A, B, A) :-
	A=< B.
menorDeDois(A, B, B) :-
	B < A.

menorDeTres(A,B,C,D) :-
	menorDeDois(A, B, MAB),
	menorDeDois(MAB, C, D).

fatorial(0, 1) :- !.
fatorial(N, Fat) :-
	N1 is N-1,
	fatorial(N1, FatN1),
	Fat is N * FatN1.

fibonacci(1,1) :- !.
fibonacci(2,1) :- !.
fibonacci(N, F) :-
	N1 is N-1,
	fibonacci(N1, F1),
	N2 is N-2,
	fibonacci(N2, F2),
	F is F1 + F2.

elemento(1, [C|_], C).
elemento(N, [_|R], E) :-
	N1 is N-1,
	elemento(N1, R, E).

pertence(C, C|_).
pertence(E, [_|R]) :-
	pertence(E, R).

nroElementos([], 0).
nroElementos(_|R, N) :-
	nroElementos(R, N1),
	N is N1 + 1.

maior([E], E) :- !.
maior([C|R], M):-
	maior(R, MR),
	maiorDeDois(C, MR, M).

maiorDeDois(A, B, A) :-
	A >= B.
maiorDeDois(A, B, B) :-
	B >= A.

nroOcorrencias(C, [C|R], Qtd) :- !,
	nroOcorrencias(C, R, OCR),
	Qtd is 1 + OCR.
nroOcorrencias(I, [_|R], Qtd):-
	nroOcorrencias(I, R, Qtd).
	nroOcorrencias(_, [], 0).

unicaOcorrencia(C, [C|R]):- !,
	not(pertence(C, R)).
unicaOcorrencia(E, [_|R]):-
	unicaOcorrencia(E, R).

maioresQue(Ref, [C|R], [C|Maiores]) :-
	Ref < C, !,
	maioresQue(Ref, R, Maiores).
maioresQue(Ref, [_|R], Maiores) :-
	maioresQue(Ref, R, Maiores).
maioresQue(_, [], []).

%concatena([], [], []).
%concatena([X|XS], [Y|YS], [X|Resto]):-
%	L2 is [Y|YS],
%	Resto is concatena(XS, L2, R1).

remove(C, [C|R], R) :- !.
remove(E, [C|R], [C|SemE]) :-
	remove(E, R, SemE).
	
removeUlt([_], []) :- !.
removeUlt([C|R], [C|SemU]):-
	removeUlt(R, SemU).
	
% remove repetidos

maiores(_, [], []).
maiores(1, [_], [_]).
maiores(N, [C|R], Maiores) :-
	Maiores is 


