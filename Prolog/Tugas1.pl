% 1. Faktorial
factorial(0, 1) :- !.
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, Result1),
    Result is N * Result1.

% 2. Positif/negatif
/*fakta, sebagai basis*/
p(0, positif).
/*aturan*/
/*2*/p(N, negatif):- \+(p(N, positif)). /*not p(N,positif)*/
/*1*/p(N, positif):- N1 is N - 1, p(N1, positif).

/* Karena tidak ada handling untuk negatif. Fungsinya hanya rekursif untuk positif n >= 0 yang akan dipanggil dengan N - 1 hingga mencapai 0
Namun jika nilai N adalah negatif, tidak ada handling yang dilakukan*/
% Pemberian cut tidak akan berpengaruh, begitupun dengan perubahan urutan

% 3. 



