#include <stdio.h>
#include <stdlib.h>

int sharuru(int x, int y) {
    /* x = 0xFF -> 1111 1111
     * y = 0x00 -> 0000 0000
     * Res = 0x0F -> 0000 1111
     * x -> ambil 4 bit kanan, buang 4 bit kiri
     * y -> ambil 4 bit kiri, buang 4 bit kanan
     * x : sebelah kiri AND 0
     * y : sebelah kanan AND 0
     * x + y : x | y
     */
    return ((x & 0x0F) | (y & 0xF0));
}

int vampire (int x, int y) {
    /* Jika bit pada posisi yang sama bernilai sama, maka akan bernilai 1
     * Jika bit pada posisi yang sama bernilai berbeda, return 0
     * ~XOR(x, y)
     * XOR : ( A U B) - (A ^ B)
     * (A U B) ^ ~(A ^ B)
    */
    return ~(x ^ y);
}

int kamippoina(int n) {
    /*
     *  (2^n * 2) - 1
     *
     */
    int a = ~0;
    int b = n + 1;
    return  ~(a << b);
}

int aidoru_shinetai(int a) {
    /* Menukar bit ke-1 dan bit ke-4
     * 0b1000 = 0b0001
     *
     */
    int bit1 = (a >> 0) & 1;  // 1st bit
    int bit4 = (a >> 3) & 1; // 4th bit
// Create a mask to clear the 1st and 4th bits
    int clear_mask = ~(1 << 0 | 1 << 3);

// Clear the 1st and 4th bits in the original integer
    a &= clear_mask;

// Set the 1st and 4th bits to their new values
    a |= (bit1 << 3) | (bit4 << 0);

    return a;
}

int bitterchoco(int x) {
    /*
     * x * 23
     * x * 16 + x * 4 + x * 2 + x * 1
     */
    return ( x<<4) + (x<<2) + (x << 1);
}

int ghost(int n) {
    // Check if n is not zero and has no other set bits
    return (((n | (~n + 1)) >> 31) & 1) & !(n & (n - 1));

}

int max(int a, int b, int c) {
    int max = a + ~((a + ~b + 1) & ((a + ~b + 1) >> 31)) + 1;
    max = max + ~((max + ~c + 1) & ((max + ~c + 1) >> 31)) + 1;
    return max;
}

int add(int a, int b) {
    int sum = a ^ b;  // Calculate the sum without carry

    // Calculate overflow based on the sign of a, b, and sum
    int overflow = ((a & b) & 0x80000000) | ((~sum & a & b) & 0x80000000);

    // Calculate the maximum and minimum overflow values
    int max_overflow = overflow >> 31;
    int min_overflow = (~overflow) >> 31;

    // Calculate the final result using XOR
    return sum ^ max_overflow ^ min_overflow;
}


int main() {
    printf("vampire(0, 0) = %d (%x)\n", vampire(0, 0), vampire(0, 0));
    printf("vampire(0, 1) = %d (%x)\n", vampire(0, 1), vampire(0, 1));
    printf("vampire(0x000000F, 0xFFFFFFFF8) = %d (%x)\n", vampire(0x0000000F, 0xFFFFFFF8), vampire(0x0000000F, 0xFFFFFFF8));
    printf("%d\n", kamippoina(3));
    printf("shitenai %x\n", aidoru_shinetai(0b1010));
    printf("%d\n", bitterchoco(10));
    printf(" GHOST 32 %d\n", ghost(32));
    printf("15 %d\n", ghost(15));
    printf("1 %d\n", ghost(1));
    printf("0 %d\n", ghost(0));
    printf("2048 %d\n", ghost(2048));
    printf("MAX 10 2 5: %d\n", max(12, 2, 5));
    printf("MAX 10 2 5: %d\n", max(1, 2, 3));
    printf("ADD: %08x\n", add(0x40000000, 0x40000000));
    return 0;
}