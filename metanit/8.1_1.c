/* �������� ���������, � ������� ������������ ������ � �������
 �������� �����, � ��������� ������� ���� � ��������� ������ �
 ������� �� ������� ���������.
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
printf("���� ������");
fclose(fp);
return 0;
}
