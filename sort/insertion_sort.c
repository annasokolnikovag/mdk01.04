#include <stdio.h>

int main() {
    FILE * fh = fopen("1.dat", "wb+");
    int x = 0;
    long i;
    long isize = sizeof(int);
    long fsize;

    /// Запишем числа в файл
    for (i = 1; i <= 10; i++)
        fwrite(&i, isize, 1, fh);

    /// Определим число записей в файле
    fseek(fh, 0, SEEK_END);
    fsize = ftell(fh) / sizeof(int);

    /// Отпечатаем содержимое файла
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&x, isize, 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    /// Заменим нечетные числа на противоположные
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fseek(fh, isize * i, SEEK_SET);
        fread(&x, isize, 1, fh);
        if (x % 2 != 0) {
            x = - x;
            fseek(fh, isize * i, SEEK_SET);
            fwrite(&x, isize, 1, fh);
        }
    }

    /// Отпечатаем содержимое файла после замены нечетных чисел
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&x, sizeof(int), 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    // Сортировка вставками
    for (i = 1; i < fsize; i++) {
        fseek(fh, isize * i, SEEK_SET);
        fread(&x, isize, 1, fh);
        long j = i - 1;
        while (j >= 0) {
            fseek(fh, isize * j, SEEK_SET);
            int current;
            fread(&current, isize, 1, fh);
            if (current > x) {
                fseek(fh, isize * (j + 1), SEEK_SET);
                fwrite(&current, isize, 1, fh);
                j--;
            } else {
                break;
            }
        }
        fseek(fh, isize * (j + 1), SEEK_SET);
        fwrite(&x, isize, 1, fh);
    }

    /// Отпечатаем содержимое файла после сортировки вставками
    printf("Содержимое файла после сортировки вставками:\n");
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&x, sizeof(int), 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    fclose(fh);
    return 0;
}
