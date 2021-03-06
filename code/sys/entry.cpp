enum INTR_TABLE {
    INTR_PUT_CHAR = 0,
    INTR_PUT_NUMBER = 1,
    INTR_SLEEP_RECORD = 100,
    INTR_SLEEP_REACH = 101,
};
int sleep(int ms) {
    ms;
    interrupt 100;
    interrupt 101;
}
int put_char(char c) {
    c;
    interrupt 0;
}
int put_string(char *text) {
    while (put_char(*text++));
}
int put_int(int number) {
    number;
    interrupt 1;
}
int fib(int i) {
    if (i > 2)
        return fib(i - 1) + fib(i - 2);
    else
        return 1;
}
int fib2(int i) {
    return i > 2 ? fib(i - 1) + fib(i - 2) : 1;
}
int fib3(int i) {
    int a[3], j;
    a[0] = a[1] = 1;
    for (j = 1; j < i; ++j)
        a[2] = a[0] + a[1], a[0] = a[1], a[1] = a[2];
    return a[0];
}
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += i--;
    }
    return s;
}
int sum2(int n) {
    int i, s;
    for (i = 1, s = 0; i <= n ; ++i) {
        s += i;
    }
    return s;
}
int sum3(int i) {
    int s = 0;
    do {
        s += i--;
    } while (i > 0);
    return s;
}
int welcome() {
    put_string(" ________  ________        ___  ________  ________  ________     \n");
    put_string("|\\   __  \\|\\   __  \\      |\\  \\|\\   ___ \\|\\   ____\\|\\   ____\\    \n");
    put_string("\\ \\  \\|\\ /\\ \\  \\|\\  \\     \\ \\  \\ \\  \\_|\\ \\ \\  \\___|\\ \\  \\___|    \n");
    put_string(" \\ \\   __  \\ \\   __  \\  ___\\ \\  \\ \\  \\ \\\\ \\ \\  \\    \\ \\  \\       \n");
    put_string("  \\ \\  \\|\\  \\ \\  \\ \\  \\|\\  \\\\_\\  \\ \\  \\_\\\\ \\ \\  \\____\\ \\  \\_____\n");
    put_string("   \\ \\_______\\ \\__\\ \\__\\ \\________\\ \\_______\\ \\_______\\ \\_______\\\n");
    put_string("    \\|_______|\\|__|\\|__|\\|________|\\|_______|\\|_______|\\|_______|\n");
    put_string("\n\n");
    put_string("Welcome to @clibos system by bajdcc!");
    put_string("\n\n");
}
enum TEST {
    TEST_IF,
    TEST_TRIOP,
    TEST_ARRAY,
    TEST_WHILE,
    TEST_FOR,
    TEST_DO,
};
int test(int i) {
    switch (i) {
        case TEST_IF:
            put_string("fib(10):   "); put_int(fib(10));
            break;
        case TEST_TRIOP:
            put_string("fib2(10):  "); put_int(fib2(10));
            break;
        case TEST_ARRAY:
            put_string("fib3(10):  "); put_int(fib3(10));
            break;
        case TEST_WHILE:
            put_string("sum(100):  "); put_int(sum(100));
            break;
        case TEST_FOR:
            put_string("sum2(100): "); put_int(sum2(100));
            break;
        case TEST_DO:
            put_string("sum3(100): "); put_int(sum3(100));
            break;
        default:
            put_string("undefined task");
            break;
    }
    put_string("\n"); sleep(100);
}
int main(int argc, char **argv) {
    welcome();
    int i;
    for (i = TEST_IF; i <= TEST_DO; ++i)
        test(i);
    return 0;
}