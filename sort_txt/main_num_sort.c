#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    FILE *f_num = fopen("numbers.txt", "r"); // Открытие файла для чтения

    int x;
    int i;
    int fsize = 0; // Количество чисел

    // Считаем количество чисел в файле
    while (fscanf(f_num, "%d", &x) == 1) {
        fsize++;
    }

    // Возвращение указателя на начало файла
    fseek(f_num, 0, SEEK_SET);

    // Mассив для хранения чисел
    int numbers[fsize];

    // Замена нечетных чисел на противоположные
    for (i = 0; i < fsize; i++) {
        fscanf(f_num, "%d", &x);
        if (x % 2 != 0) {
            x = -x;
        }
        numbers[i] = x;
    }
    
    fclose(f_num); // Закрытие файла
     
    // Проверочная печать
    for (i = 0; i < fsize; i++) {
        printf("%d ", numbers[i]); }
    printf("\n");

    bubbleSort(numbers, fsize); // вызов функции сортировки
    
    FILE *f_sort_num = fopen("sort_numbers.txt", "w"); // Открытие файла для записи

    // Запиcь отсортированных чисел
    for (i = 0; i < fsize; i++) {
        fprintf(f_sort_num, "%d ", numbers[i]);
    }

    fclose(f_sort_num);
    
    // Проверочная печать
    for (i = 0; i < fsize; i++) {
        printf("%d ", numbers[i]); }
    
    return 0;
}