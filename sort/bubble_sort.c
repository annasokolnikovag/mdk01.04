/// Записываем в файл целые числа
/// Заменяем нечетные на противоположные
/// Гусятинер Л.Б., МГОТУ ККМТ, 26.11.2017 / КМПО РАНХиГС 30.03.2024
/** Задания.
1. Отсортировать файл "пузырьком"
2. Отсортировать файл "вставками"
3. Отсортировать файл "выбором"
4. Найти число в файле линейным поиском
5. Найти число в файле двоичным поиском
6. Выполнить сортировку и поиск для вещественных чисел, для строк, для структур
**/

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

    /// Отпечатаем содержимое файла
    fseek(fh, 0, SEEK_SET);
    for (i=0; i<fsize; i++) {
        fread(&x, sizeof(int), 1, fh);
        printf("%d ", x);
    }
    putchar('\n');
    fclose(fh);

    // Сортировка "пузырьком" и вывод отсортированных чисел
    fh = fopen("1.dat", "rb+"); // Открываем файл для чтения и записи
    if (fh == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int numbers[10]; // Массив для хранения чисел из файла

    // Считываем числа из файла в массив
    for (i = 0; i < 10; i++) {
        fread(&x, sizeof(int), 1, fh);
        numbers[i] = x;
    }

    // Применяем сортировку пузырьком к массиву
    bubbleSort(numbers, 10);

    printf("Отсортированные числа из файла:\n");
    // Выводим отсортированные числа в консоль
    for (i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    fclose(fh); // Закрываем файл
    return 0;
}
