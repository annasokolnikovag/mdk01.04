#include <stdio.h>
 
int main() {
    int N  = 20;
    char str[N];   // определяем буфер достаточной длины
 
    FILE *fp = fopen("data.txt", "r"); // Открытие файла для чтения
    size_t count = fread(str, sizeof str[0], N, fp); // Считывание данных из файла в массив
    printf("read %zu elements out of %d\n", count,  N); // Вывод в консоль о кол-ве символов, записанных в файл
    printf(str); // Вывод строки
    fclose(fp); // Закрытие файла
}