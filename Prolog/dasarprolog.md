## Struktur File
Struktur file adalah: bagian atas berisi fakta, bawahnya adalah fungsi-fungsinya

## Menjalankan File
Pertama pergi ke direktori file berada melalui terminal, lalu jalankan 'gprolog'
Untuk menjalankan file, gunakan perintah `consult('namafile').` atau `['namafile'].`
Setelahnya, kita bisa langsung memberikan query menggunakan fungsi-fungsi yang sudah ada.

## Struktur Fungsi
Ada dua tipe fungsi, yaitu boolean yang return true/false (contoh fungsi saudara_kandung() di latihan1.pl), atau fungsi 
yang akan return suatu angka (misalnya max(), max2()).

Untuk fungsi boolean, misal saudara_kandung(X, Y) :- orangtua(Z, X), orangtua(Z, Y), X \== Y.
Artinya, X dan Y adalah saudara kandung jika ada orang tua Z yang sama, dan X tidak sama dengan Y.
Fungsi saudara_kandung akan return true jika orangtua(Z, X) dan orangtua(Z, Y) benar.

Untuk fungsi yang return angka, misal max(X, Y, X) :- X >= Y.
Artinya saat X >= Y, maka yang di-return adalah nilai X tersebut. Jika X < Y, maka yang di-return adalah nilai Y tersebut, dapat dilihat di baris berikutnya di mana case
X < Y, maka max(X, Y, Y) :- X < Y. Di fungsi max tersebut, variabel yang paling akhir akan di-return (misal jika max(A, B, A), maka dari input A dan B, akan di-return nilai A).
Dalam implementasinya saat dijalankan di query, saat kita memasukkan fungsi max(1, 2, X), maka X akan bernilai 2. Isi nilai terakhir tersebut akan di-return.
Misal max(1, 2, X) dimasukkan saat query, maka hasilnya adalah X = 2.