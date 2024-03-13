#include <stdio.h>
  
int main(void)
{
    // строка для записи
    char * message = "Hello METANIT.COM!\nAn apple a day keeps the doctor away";
    // файл для записи
    char * filename = "data.txt";
    FILE *fp = fopen(filename, "w"); // Открытие файла для записи
    if(fp)
    {
        // записываем строку
        fputs(message, fp); //Запись строки в файл
        fclose(fp); // Закрытие файла
        printf("File has been written\n"); //Вывод о том что в файл была записана строка
    }
}