#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) return 0;  
    if (n == 2) return 1; 
    if (n % 2 == 0) return 0;  

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int is_right_truncatable_prime(int n) {
    if (n <= 0) return 0;
    while (n > 0) {
        if (!is_prime(n)) return 0;
        n /= 10;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "error\n");
        return 1;
    }

    int count;
    fscanf(file, "%d", &count);

    int number;
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &number);
        if (is_right_truncatable_prime(number)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    fclose(file);
    return 0;
}