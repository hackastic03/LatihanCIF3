/* Bagian Fakta, Rule, dan Query */

/* Fakta */
pria(athif).
pria(dillon).
pria(michael).
pria(henri).
pria(hanif).
pria(robert).
pria(bagas).
pria(fio).
pria(rupert).
pria(daniel).

usia(athif, 60).
usia(joli, 58).
usia(dillon, 63).
usia(elysia, 500).
usia(michael, 28).
usia(margot, 43).
usia(henri, 48).
usia(hanif, 47).
usia(robert, 32).
usia(bagas, 29).
usia(jena, 27).
usia(jeni, 28).
usia(ana, 23).
usia(fio, 30).
usia(rupert, 6).
usia(emma, 6).
usia(daniel, 7).

wanita(margot).
wanita(elysia).
wanita(joli).
wanita(jena).
wanita(jeni).
wanita(ana).
wanita(emma).

menikah(athif, joli).
menikah(joli, athif).
menikah(dillon, elysia).
menikah(elysia, dillon).
menikah(henri, margot).
menikah(margot, henri).
menikah(jena, fio).
menikah(fio, jena).
menikah(fio, jeni).
menikah(jeni, fio).

anak(michael, athif).
anak(michael, joli).
anak(margot, athif).
anak(margot, joli).
anak(hanif, dillon).
anak(hanif, elysia).
anak(robert, henri).
anak(robert, margot).
anak(bagas, henri).
anak(bagas, margot).
anak(jena, henri).
anak(jena, margot).
anak(jeni, hanif).
anak(ana, hanif).
anak(rupert, fio).
anak(rupert, jena).
anak(daniel, jena).
anak(daniel, fio).
anak(emma, fio).
anak(emma, jeni).


/* Rule */
saudara(X, Y) :- anak(X, Z),
                anak(Y, Z),
                X \= Y.
kakak(X, Y) :- saudara(X, Y),
               usia(X, A),
               usia(Y, B),
               A > B.
keponakan(X, Y) :- anak(X, Z),
                saudara(Z, Y).
mertua(X, Y) :- menikah(Y, Z), anak(Z, X).

nenek(X, Y) :- wanita(X), anak(Y, Z), anak(Z, X).

keturunan(X, Y) :- anak(X, Y).
keturunan(X, Y) :- anak(X, Parent), keturunan(Parent, Y).

lajang(X) :-
    pria(X), \+menikah(X, Y), \+menikah(Y, X).
lajang(X) :-
    wanita(X), \+menikah(X, Y), \+menikah(Y, X).

saudaratiri(X, Y) :-
    anak(X, Z), anak(Y, Z), anak(X, W), \+anak(Y, W).

anakbungsu(X) :-
    anak(X, Y), pria(Y), \+kakak(X, _).

yatimpiatu(X) :-
    pria(X), \+anak(X, _).
yatimpiatu(X) :-
    wanita(X), \+anak(X, _).


% Bagian Rekursivitas

/* Eksponen */
exponent(_, 0, 1).
exponent(X, Y, Z) :- Y > 0,
                Y1 is Y - 1,
                exponent(X, Y1, Z1),
                Z is Z1 * X.

/* Population */
population(P, R, T, C, X) :- C1 is T,
                            populationRec(P, R, T, C, C1, X).

populationRec(P, _, 0, _, _, P).
populationRec(P, R, T, C, C1, X) :- T > 0,
                                T1 is (T - 1),
                                C2 is (C - 1),
                                populationRec(P, R, T1, C2, C1, Temp),
                                (0 is (T mod 2) -> X is ((Temp * R) - (C1 + C)); X is ((Temp * R) + (C1 + C))).


/* Perrin */
perrin(0, 3).
perrin(1, 0).
perrin(2, 2).
perrin(X, Y) :- X > 2,
                X1 is X - 2,
                X2 is X - 3,
                perrin(X1, Y1),
                perrin(X2, Y2),
                Y is Y1 + Y2.


/* HCF */
hcf(X, 0, X) :- X > 0.
hcf(X, Y, Z) :- Y > 0,
                X1 is X mod Y,
                hcf(Y, X1, Z).


/* Make Pattern */
/* iterasi sampai N - 1 */
pattern(Row, Col, N) :- Col < N,
                        Row < N,
                        Last is N - 1,
                        Col \= Last, % Kolom belum sampai di akhir baris
                        R is (Last - Col), % Jarak ke kanan
                        D is (Last - Row),
                        lessthan(Col, R, Horizontal),
                        lessthan(Row, D, Vertikal),
                        lessthan(Vertikal, Horizontal, Res),
                        write(Res),
                        Move is (Col + 1), % Geser ke kanan 1 kolom
                        pattern(Row, Move, N).

/* last col */
pattern(Row, Col, N) :- Row =< N,
                        Col =< N,
                        Last is N - 1,
                        Col == Last,
                        R is (Last - Col),
                        D is (Last - Row),
                        lessthan(Col, R, Horizontal),
                        lessthan(Row, D, Vertikal),
                        lessthan(Vertikal, Horizontal, Res),
                        write(Res), nl,
                        Move is Row + 1, % Pindah baris karena udah di paling akhir baris
                        pattern(Move, 0, N).

makePattern(N) :- pattern(0, 0, N).

/* Bagian List */

/* List Statistik */
/* min */
lessthan(A, B, A) :- A =< B.
lessthan(A, B, B) :- A > B.

min([X], X).
min([Head | Tail], X) :- min(Tail, Temp),
                        lessthan(Head, Temp, X).

/* max */
morethan(A, B, A) :- A >= B.
morethan(A, B, B) :- A < B.

max([X], X).
max([Head | Tail], X) :- max(Tail, Temp),
                        morethan(Head, Temp, X).

/* range */
range([X], X).
range([Head | Tail], X) :- min([Head | Tail], Min),
                        max([Head | Tail], Max),
                        X is Max - Min.

/* count */
count([], 0).
count([_ | Tail], X) :- count(Tail, Temp),
                        X is Temp + 1.

/* sum */
sum([], 0).
sum([Head | Tail], X) :- sum(Tail, Temp),
                        X is Temp + Head.

/* List Manipulation */
/* get index */
getIndex([Head | _], Head, 1).
getIndex([_ | T], Elmt, Result) :- getIndex(T, Elmt, Temp),
                                    Result is Temp + 1.

/* get element */
getElmt([Head | _], 1, Head).
getElmt([_ | Tail], Index, Result) :- Index > 1,
                                    Index1 is Index - 1,
                                    getElmt(Tail, Index1, Result).

/* swap */
setElmt([_ | Tail], 1, Elmt, [Elmt | Tail]).
setElmt([Head | Tail], Index, Elmt, [Head | Result]) :- Index > 1,
                                                        Index1 is Index - 1,
                                                        setElmt(Tail, Index1, Elmt, Result).

swap(List, Index1, Index2, Res) :- getElmt(List, Index1, Temp1),
                                   getElmt(List, Index2, Temp2),
                                   setElmt(List, Index1, Temp2, Temp),
                                   setElmt(Temp, Index2, Temp1, Res).


/* slice */
slice(_, StartIndex, EndIndex, []) :- StartIndex >= EndIndex.
slice([H | T], 1, EndIndex, [H | Result]) :- EndIndex > 0,
                                            NextIndex is EndIndex - 1,
                                            slice(T, 1, NextIndex, Result).
slice([], _, _, []).
slice([_|T], StartIndex, EndIndex, Result) :- StartIndex > 1,
                                              End1 is EndIndex - 1,
                                              Start1 is StartIndex - 1,
                                              slice(T, Start1, End1, Result).


/* sort */
sortList([X], [X]).
sortList([Head | Tail], Result) :- min(Tail, Min),
                                   Head < Min,
                                   sortList(Tail, Temp),
                                   Result = [Head | Temp].

sortList([Head | Tail], Result) :- min(Tail, Min),
                                   Head == Min,
                                   sortList(Tail, Temp),
                                   Result = [Head | Temp].

sortList([Head | Tail], Result) :- min(Tail, Min),
                                   Head > Min,
                                   getIndex(Tail, Min, Index),
                                   setElmt(Tail, Index, Head, Temp),
                                   sortList(Temp, Result1),
                                   Result = [Min | Result1].

/* Bonus */
start :-
    retractall(secret_number(_)),
    retractall(score(_)),
    asserta(score(0)),
    random(1, 101, Secret),
    asserta(secret_number(Secret)),
    write('Welcome to Number Guesser Prolog!'), nl,
    write('Guess a Number between 1 to 100.'), nl,
    displayScore.


displayScore :-
    score(CurrentScore),
    write('Score: '), write(CurrentScore), nl.


minus :-
    score(CurrentScore),
    NewScore is (CurrentScore - 1),
    retractall(score(_)),
    asserta(score(NewScore)).

guess(X) :-
    clause(secret_number(_), _),
    secret_number(Secret),
    X = Secret,
    write('Correct.'), nl,
    score(CurrentScore),
    NewScore is (CurrentScore + 10),
    retractall(score(_)),
    asserta(score(NewScore)),
    displayScore.

guess(X) :-
    X >= 1, X =< 100,
    clause(secret_number(_), _),
    secret_number(Secret),
    X > Secret,
    write('Too Large.'), nl,
    minus,
    displayScore.

guess(X) :-
    X > 0, X < 101,
    clause(secret_number(_), _),
    secret_number(Secret),
    X < Secret,
    write('Too Small.'), nl,
    minus,
    displayScore.

guess(X) :-
    X < 1,
    clause(secret_number(_), _),
    write('Guess a Number between 1 to 100!').

guess(X) :-
    X > 100,
    clause(secret_number(_), _),
    write('Guess a Number between 1 to 100!').

reset :-
    clause(secret_number(_), _),
    secret_number(Secret),
    score(CurrentScore),
    write('Secret Number is '), write(Secret), nl,
    write('Score: '), write(CurrentScore), nl,
    write('resetting the game..'), nl, nl,
    start.

exit :-
    clause(secret_number(_), _),
    write('Thank you for Playing!'), nl,
    retractall(secret_number(_)),
    retractall(score(_)).