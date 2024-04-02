#include <stdio.h>
#include <stdlib.h>
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Проход по всем элементам массива
    for (i = 0; i < n - 1; i++) {
        // индекс минимального элемента в оставшейся части массива
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // изменение текущего элемента с минимальным
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

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

    // Сортировка выбором
    int *arr = (int*)malloc(fsize * sizeof(int));
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&arr[i], sizeof(int), 1, fh);
    }
    selection_sort(arr, fsize);
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fwrite(&arr[i], sizeof(int), 1, fh);
    }
    free(arr);

    /// Отпечатаем содержимое файла после сортировки выбором
    printf("Содержимое файла после сортировки выбором:\n");
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&x, sizeof(int), 1, fh);
        printf("%d ", x);
    }
    putchar('\n');

    fclose(fh);
    return 0;
}
