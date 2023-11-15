void Black_Rose() {
    int numbers[6];
    int init = 240;
    int *a;
    read_six_numbers(a);

    if (numbers[0] != init) {
        illegal_move();
    }
    a = numbers;
    for (int i = 1; i <= 6; i++) {
        if (i % 2 == 0) {
            if (numbers[i] != numbers[0] * 2) {
                illegal_move();
            }
        }
        else {
            if (numbers[i] != numbers[0]) {
                illegal_move();
            }
        }
    }
    return;
}