father(john, jim).
father(john, ann).
father(jim, peter).

grandfather(X, Y) :- father(X, Z), father(Z, Y).

ibu(emy, charles).
ibu(emy, david).
ibu(emy, randy).
ibu(maria, fara).
saudara_kandung(Anak1, Anak2) :- ibu(Ibu,
Anak1), ibu(Ibu, Anak2).

% Maksimum 2 angka

max(X, Y, X) :- X >= Y.
max(X, Y, Y) :- X < Y.

% Faktorial

factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, Result1),
    Result is N * Result1.

% Maksimum 3 angka

max2(X, Y, Z, X) :- X >= Y, X >= Z.
max2(X, Y, Z, Y) :- Y >= X, Y >= Z.
max2(X, Y, Z, Z) :- Z >= X, Z >= Y.

% Absolut sebuah bilangan
abs(X, X) :- X >= 0.
abs(X, Y) :- X < 0, Y is -X.

% Menentukan apakah suatu nilai merupakan bilangan positif, atau negatif
isPositive(X) :- X >= 0.