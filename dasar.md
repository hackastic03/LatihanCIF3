### MATERI

#### Run C/C++
gcc "path and name of file to src code file.c/cpp" -o "name of file and the path of .exe"

#### 1. Mengenai Pre-processor and Compiler
Pre-processor adalah saat sebelum di-compile, data akan diolah duluan. 
Compiler adalah saat file di-compile, dan dapat menggunakan hasil pre-processing sebelumnya saat compile
https://www.sanfoundry.com/c-tutorials-general-difference-between-preprocessor-compiler/
#### 2. Mengenai file header
   https://www.tutorialspoint.com/cprogramming/c_header_files.htm#
#### 3. Mengenai define dan const untuk variabel
https://www.geeksforgeeks.org/diffference-define-const-c/
Saat menggunakan define, nilainya lebih global dan akan mengganti nilai setiap variabel yg memiliki nama sama dengan const yang sudah didefinisikan
Misal ada const pi = 3.14, jika ada variabel dengan nilai int pi = 2, maka pas di output tetap akan keluar 3.14 (bahkan error karena redefinition dari const)
#### 4. Mengenai typedef
https://www.geeksforgeeks.org/typedef-in-c/
#### 5. Mengenai format datatype specifier
https://www.freecodecamp.org/news/format-specifiers-in-c/
#### 6. Mengenai include
Include menggunakan <> untuk library yang sudah ada bawaaan dari C-nya, dan "" untuk library yang dibuat sendiri
Include bisa memakai path, tapi tidak disarankan karena akan mempersulit saat compile
#### 7. Mengenai pointer
https://youtu.be/zuegQmMdy8M?si=2vKup4Q8nyQV9qog
Untuk format specifier, bisa menggunakan %p atau langsung %(tipe data) (misal %d untuk int)
#### 8. Mengenai unsigned
https://www.educba.com/unsigned-int-in-c/
#### 9. Kehilangannya boolean di C
Bisa memakai: https://www.w3schools.com/c/c_booleans.php
Atau definisi nilai menggunakan #define di header
#### 10. Mengenai string
https://www.programiz.com/c-programming/c-strings
Jika misalkan 
#### 11. Mengenai malloc
Malloc adalah alokasi memori terlebih dahulu untuk data dinamis, karena besaran memori yang dibutuhkan belum diketahui
https://stackoverflow.com/questions/8800482/when-and-why-to-use-malloc
#### 12. Mengenai enum
Enumerasi sebagai tipe data enum adalah tipe data yang berisi kumpulan konstanta yang telah diberi nama. Bisa dibilang indeks yang awalnya 0, 1, 2 diubah menjadi nama2 yang bisa kita ubah
#### 13. Mengenai scanf
Scanf digunakan untuk mengambil input pengguna ke alamat dari variabel yang memuat nilai yang diinginkan. Sintaksnya adalah scanf("%</format specifier>", &<nama variabel>)
#### 14. Mengenai struct
Struct adalah tipe data yang berisi kumpulan variabel yang bisa berbeda tipe datanya. Struct bisa dianggap sebagai tipe data baru yang dibuat sendiri. Lebih lengkapnya lihat catatan Alstrukdat PPT
#### 15. String dalam input
https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/
#### 16. Struktur header
https://youtu.be/5UMHbzZGQuE?si=tm_1fxFu8jpIyJus
#### 17. Mengenai struct
https://youtu.be/CI9dRTvzgqE?si=2i8qJFWv2ZAaRceY
#### 18. Struct vs Class
https://youtu.be/fLgTtaqqJp0?si=mVRiusuZHtWYiugI
#### 19. Mengenai format untuk desimal
Agar nilai desimal tidak terlalu banyak digit di belakang koma, bisa menggunakan %.2f untuk 2 digit di belakang koma, atau format dasarnya adalah %.nf di mana f adalah banyak digit di belakang koma
#### 20. Mengenai malloc vs calloc
https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
Setelah memori dialokasikan menggunakan malloc atau calloc, kita bisa menggunakan fungsi free untuk menghapus alokasi memori dari variabel tersebut
#### 21. Array statis
https://www.youtube.com/playlist?list=PLBlnK6fEyqRjoG6aJ4FvFU1tlXbjLBiOP
#### 22. Data dinamis
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
#### 23. Mengenai constant dan global variable
https://www.quora.com/What-is-the-difference-between-a-constant-and-a-global-variable-in-C-language
