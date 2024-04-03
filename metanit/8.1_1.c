/* Напишите программу, в которой пользователь вводит в консоли
 название файла, а программа создает файл с введенным именем и
 выводит на консоль результат.
*/
#include <stdio.h>

int main(void) {

char f[20];
scanf("%s", &f);

FILE *fp;
fp = fopen(f, "w");
if (!fp)
{
    perror("error");
    return 1;
}
printf("файл создан");
fclose(fp);
return 0;
}
