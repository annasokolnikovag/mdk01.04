#include <stdio.h>
 
int main() {
    char str[] = "Hello METANIT.COM"; // Создание строки, которая будет занесена в файл
    size_t N = sizeof(str); // Вычисление размера строки
    FILE *fp = fopen("data.txt", "w"); // Открытие файла для записи 
    size_t count = fwrite(str, sizeof str[0], N, fp); // Запись строки в файл
    printf("wrote %zu elements out of %zu\n", count,  N); // Вывод в консоль о кол-ве символов, записанных в файл
    fclose(fp); // Закрытие файла
}