/* Задание 22: Учет грузов на складе с использованием двух входных файлов**

В базе данных склада содержатся сведения о грузах и их размещении на стеллажах. 
Необходимо обработать информацию из двух входных файлов и сформировать список 
Названий грузов с указанием числа использованных стеллажей, упорядоченный по наименованию груза
и вывести в консоль, без выходного файла .

Структура входных файлов:
in1.txt содержит
Код стеллажа Название груза:
1 Принтер_HP
2 Монитор_Samsung
3 Клавиатура_L

in2.txt содержит
Номер стеллажа Дата укладки Код груза:
1 26.10.2022 1
2 27.10.2022 2
3 24.10.2022 3
4 24.10.2022 1
5 27.10.2022 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARGO 100
#define MAX_SHELVES 100

typedef struct {
    char id_cargo[20];
    char name[50];
} CargoInfo;

typedef struct {
    int id_shelves;
    char date[20];
    char id_cargo[20];
    char cargo_name[50];
} ShelfInfo;

int main() {
    // открытие файла на чтение
    FILE *f_cargo= fopen("in1.txt", "r");
    
    int cargo_count = 0; 
    CargoInfo cargo[MAX_CARGO];
    // Считывание данных из файла и запись в структуру cargo_info
    while (fscanf(f_cargo, "%s %s", cargo[cargo_count].id_cargo, cargo[cargo_count].name) == 2) {
        cargo_count++;
    }
    fclose(f_cargo); // Закрытие файла
    
    FILE *f_shelf = fopen("in2.txt", "r");
    
    int shelves_count = 0;
    ShelfInfo shelves[MAX_SHELVES];
    while (fscanf(f_shelf, "%d %s %s", &shelves[shelves_count].id_shelves, shelves[shelves_count].date, shelves[shelves_count].id_cargo) == 3) {
        shelves_count++;
    }
    fclose(f_shelf); 

    printf("Название груза Количество стеллажей\n");

    // Перебирание элементов грузов
    for (int i = 0; i < cargo_count; i++) { 
        int shelf_count = 0;
        for (int j = 0; j < shelves_count; j++) { // перебирание элементов массива стеллажей
            if (strcmp(cargo[i].id_cargo, shelves[j].id_cargo) == 0) { // если айди совпадают
                strcpy(shelves[j].cargo_name, cargo[i].name); //то копирует название груза
                shelf_count++;
            }
        }

        printf("%s %d\n", cargo[i].name, shelf_count);
    }
    return 0;
}
