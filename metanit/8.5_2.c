#include <stdio.h>
  
int main(void)
{
    // Создания файла для чтения
    char * filename = "data.txt";
    // буфер для считывания данных из файла
    char buffer[256];
    // чтение из файла
    FILE *fp = fopen(filename, "r"); // Открытие файла для чтения
    if(fp) 
    {
        // Считывание по 256 байт, пока не дойдем до конца файла
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer); 
        }
        fclose(fp);
    } 
}