#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Użycie: %s liczba1 liczba2\n", argv[0]);
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int suma = a + b;
    
    printf("Suma %d i %d wynosi: %d\n", a, b, suma);
    return 0;
}
