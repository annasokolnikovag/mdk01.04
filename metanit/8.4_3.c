#include <stdio.h>
 
int main() {
    int N  = 20; 
    char str[N];  // Определение буфера достаточной длины
 
    FILE *fp = fopen("data.txt", "r");  // Открытие файла для чтения
    int count = fread(str, sizeof str[0], N, fp);  // Считывание данных из файла в буфер
    if(count == N)  // Если прочитаны все элементы
    {
        printf("%s \n", str);  // Вывод строки
    }
    else
    {
        if (feof(fp))   // Если достигнут конец файла
        {
            printf("Unexpected end of file\n");  // Вывод при неожиданном конце файла
            printf("Available: %s",str);  // Вывод данных, которые доступны 
        }
        else if (ferror(fp))    // Если произошла ошибка при чтении 
            perror("Error while reading file\n");  // Вывод сообщения об ошибке
    }
    fclose(fp);  // Закрытие файла
}
