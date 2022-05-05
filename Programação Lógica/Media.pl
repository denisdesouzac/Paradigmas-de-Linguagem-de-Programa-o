 /*nroElementos([], 0).
nroElementos(_|R, N) :-
	nroElementos(R, N1),
	N is N1 + 1.

soma([], 0).
soma([C|R], S) :-
    soma(R, S1),
    S is C + S1.

media([], 0).
media(L, M) :-
    M is soma(L)  nroElementos(L).
*/

 intercala([], L, L).
 intercala(L, [], L).
 intercala([C1], [C2], [C1, C2]):- !.
 intercala([C1|R1], [C2|R2], [C1, C2|Resto]):-
    intercala(R1, R2, Resto).
	
insereOrdenada(A, [], [A]).
insereOrdenada(A, [C|R], [A,C|R]) :-
	A < C, !.
insereOrdenada(A, [C|R1], [C|R]) :-
	insereOrdenada(A, R1, R).

concatena([], L, L).
concatena([C|R], L, [C|Outros]):-
	concatena(R, L, Outros).
