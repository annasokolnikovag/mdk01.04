#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_D 100
typedef struct {
    char type[20];
    char name[20];
    char znach[20];
    int position;
} detail;


typedef struct {
    char name[20];
    int count_type;
} typequantity;


int main(){

    FILE* f_detail = fopen("detail.txt", "r");

    if (f_detail != NULL){
        printf("error detail.txt");
        return 1;
    }

    detail det[MAX_D];
    int detail_count = 0;
    while(fscanf(f_detail, "%s %s %s %d", det[detail_count].name, det[detail_count].position, det[detail_count].type, &det[detail_count].znach) == 4){
        detail_count++;
    }
    fclose(f_detail);

    // пробная печать
    printf("Раздел спецификации Количество");
    typequantity t_q[detail_count];

    for (int i = 0; i < detail_count; i++ ){

    }

    FILE* f_out = fopen("out.txt", "w");

    fclose(f_out);
    return 0;
}
