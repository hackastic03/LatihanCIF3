/* Bagian Fakta, Rule, dan Query */

/* Fakta */
/* Kiri */
% Tk. 1
pria(Athif).
usia(Athif, 60).
wanita(Joli).
usia(Joli, 58).
menikah(Athif, Joli).
menikah(Joli, Athif).

pria(Dillon).
usia(Dillon, 63).
wanita(Elysia).
usia(Elysia, 500).
menikah(Dillon, Elysia).
menikah(Elysia, Dillon).


% Tk. 2
anak(Michael, Athif).
anak(Michael, Joli).
anak(Margot, Athif).
anak(Margot, Joli).
pria(Michael).
usia(Michael, 28).
wanita(Margot).
usia(Margot, 43).
pria(Henri).
usia(Henri, 48).
menikah(Henri, Margot).
menikah(Margot, Henri).

anak(Hanif, Dillon).
anak(Hanif, Elysia).
pria(Hanif).
usia(Hanif, 47).

% Tk. 3
anak(Robert, Henri).
anak(Robert, Margot).
pria(Robert).
usia(Robert, 32).
anak(Bagas, Henri).
anak(Bagas, Margot).
pria(Bagas).
usia(Bagas, 29).
anak(Jena, Henri).
anak(Jena, Margot).
wanita(Jena).
usia(Jena, 27).

anak(Jeni, Hanif).
wanita(Jeni).
usia(Jeni, 28).
anak(Ana, Hanif).
wanita(Ana).
usia(Ana, 23).
menikah(Jena, Fio).
usia(Fio, 30).
pria(Fio).

% Tk. 4
anak(Rupert, Fio).
anak(Rupert, Jena).
pria(Rupert).
usia(Rupert, 6).
anak(Daniel, Jena).
anak(Daniel, Fio).
pria(Daniel).
usia(Daniel, 7).
anak(Emma, Fio).
anak(Emma, Jeni).
wanita(Emma).
usia(Emma, 6).


/* Rule */
saudara(X, Y) :- anak(X, Z), anak(Y, Z), X \== Y.
%saudaratiri(X, Y).
kakak(X, Y) :- saudara(X, Y).
keponakan(X, Y) :- anak(X, Z), saudara(Z, Y).
mertua(X, Y) :- menikah(Y, Z), anak(Z, X).
nenek(X, Y) :- wanita(X), anak(Y, Z), anak(Z, X).
keturunan(X, Y) :- anak(X, Y).
lajang(X) :- \+menikah(X, _).
anakbungsu(X) :- anak(X, _), \+anak(_, X).
yatimpiatu(X) :- anak(X, _), \+anak(_, X), \+anak(_, _).