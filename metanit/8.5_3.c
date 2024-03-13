#include <stdio.h>
 
int main(void)
{
    char * filename1 = "data1.txt"; //Создание 2 файлов
    char * filename2 = "data2.txt";
    char buffer[256];
    FILE *f1 = fopen(filename1, "r");   // Открытие файла на чтение
    FILE *f2 = fopen(filename2, "w");   // Открытие файла на запись
    if(!f1 || !f2) // Если файлы не открыты
    {
        printf("Error occured while opening file\n"); // Вывод сообщения об ошибке
    }
    else
    {
        // Считывание по 256 байт из файла f1, пока не дойдем до конца
        while((fgets(buffer, 256, f1))!=NULL)
        {
            // запись строки в файл f2
            fputs(buffer, f2);
            printf("%s", buffer);
        }
    }
     
    fclose(f1); // Закрытие файлов
    fclose(f2);
     
    return 0;
}