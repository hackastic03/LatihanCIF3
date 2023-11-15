void Beginning (char *c) {
    if (strings_not_equal(*c, "Melt, I want to hold your hand in mine")) {
        illegal_move();
    }
    else {
        return;
    }
}