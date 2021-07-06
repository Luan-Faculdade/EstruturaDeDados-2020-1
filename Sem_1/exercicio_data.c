#include <stdlib.h>
#include <stdio.h>

typedef struct{
int dia, dia2;
int mes, mes2;
int ano, ano2;
}data;

data *getFirstDate();
data *getSecondDate();
void showFirstDate(data *d);
void showSecondDate(data *d);
void verifyFirstDate(data *dt);
void verifySecondDate(data *dt);
void intervaloData(data *d);
int valorMeses(int val);


int main(){

    showFirstDate(getFirstDate());
    showSecondDate(getSecondDate());

    return 0;
}

data *getFirstDate(){
    data *dt = (data *)malloc(sizeof(data));

    printf("\nInsira um data (Utilize o formato DD/MM/AAAA): ");
    scanf("%i/%i/%i", &dt -> dia, &dt -> mes, &dt -> ano);

    return dt;
}

data *getSecondDate(){
    data *dt = (data *)malloc(sizeof(data));

    printf("\nInsira um data (Utilize o formato DD/MM/AAAA): ");
    scanf("%i/%i/%i", &dt -> dia2, &dt -> mes2, &dt -> ano2);

    return dt;
}

void showFirstDate(data *d){

    int mm;
    mm = d -> mes;

    printf("\n%i/%i/%i\n", d -> dia, d -> mes, d -> ano);

    switch(mm){
        case 1:
            printf("%i de Janeiro de %i", d -> dia, d -> ano);
            break;
        case 2:
            printf("%i de Fevereiro de %i", d -> dia, d -> ano);
            break;
        case 3:
            printf("%i de Marco de %i", d -> dia, d -> ano);
            break;
        case 4:
            printf("%i de Abril de %i", d -> dia, d -> ano);
            break;
        case 5:
            printf("%i de Maio de %i", d -> dia, d -> ano);
            break;
        case 6:
            printf("%i de Junho de %i", d -> dia , d -> ano);
            break;
        case 7:
            printf("%i de Julho de %i", d -> dia, d -> ano);
            break;
        case 8:
            printf("%i de Agosto de %i", d -> dia, d -> ano);
            break;
        case 9:
            printf("%i de Setembro de %i", d -> dia, d -> ano);
            break;
        case 10:
            printf("%i de Outubro de %i", d -> dia, d -> ano);
            break;
        case 11:
            printf("%i de Novembro de %i", d -> dia, d -> ano);
            break;
        case 12:
            printf("%i de Dezembro de %i", d -> dia, d -> ano);
            break;
        default:
            break;
    }

    printf("\n%i-%i-%i\n", d -> ano, d -> mes, d -> dia);
}

void showSecondDate(data *d){

    int mm;
    mm = d -> mes2;

    printf("\n%i/%i/%i\n", d -> dia2, d -> mes2, d -> ano2);

    switch(mm){
        case 1:
            printf("%i de Janeiro de %i", d -> dia2, d -> ano2);
            break;
        case 2:
            printf("%i de Fevereiro de %i", d -> dia2, d -> ano2);
            break;
        case 3:
            printf("%i de Marco de %i", d -> dia2, d -> ano2);
            break;
        case 4:
            printf("%i de Abril de %i", d -> dia2, d -> ano2);
            break;
        case 5:
            printf("%i de Maio de %i", d -> dia2, d -> ano2);
            break;
        case 6:
            printf("%i de Junho de %i", d -> dia2, d -> ano2);
            break;
        case 7:
            printf("%i de Julho de %i", d -> dia2, d -> ano2);
            break;
        case 8:
            printf("%i de Agosto de %i", d -> dia2, d -> ano2);
            break;
        case 9:
            printf("%i de Setembro de %i", d -> dia2, d -> ano2);
            break;
        case 10:
            printf("%i de Outubro de %i", d -> dia2, d -> ano2);
            break;
        case 11:
            printf("%i de Novembro de %i", d -> dia2, d -> ano2);
            break;
        case 12:
            printf("%i de Dezembro de %i", d -> dia2, d -> ano2);
            break;
        default:
            break;
    }

    printf("\n%i-%i-%i\n", d -> ano2, d -> mes2, d -> dia2);

    intervaloData(d);
}

void verifyFirstDate(data *dt){
    int aa, dd, mm;

    dd = dt -> dia;
    mm = dt -> mes;
    aa = dt -> ano;

    if(aa>=0 && aa<=9999){
        if(mm >= 1 && mm <= 12){
            if((dd >= 1 && dd <=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                printf("ok");
                showFirstDate(dt);
            }else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
                printf("ok");
                showFirstDate(dt);
            }else if((dd >= 1 && dd <= 28) && (mm == 2)){
                printf("ok");
                showFirstDate(dt);
            }else if(dd == 29 && mm==2 && (aa % 400 == 0 || (aa % 4 == 0 && aa%100!=0))){
                printf("ok");
                showFirstDate(dt);
            }else{
                printf("error");
            }
        }else{
            printf("error");
        }
    }else{
        printf("error");
    }  
}

void verifySecondDate(data *dt){
    int aa, dd, mm;

    dd = dt -> dia2;
    mm = dt -> mes2;
    aa = dt -> ano2;

    if(aa>=0 && aa<=9999){
        if(mm >= 1 && mm <= 12){
            if((dd >= 1 && dd <=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                printf("ok");
                showSecondDate(dt);
            }else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
                printf("ok");
                showSecondDate(dt);
            }else if((dd >= 1 && dd <= 28) && (mm == 2)){
                printf("ok");
                showSecondDate(dt);
            }else if(dd == 29 && mm==2 && (aa % 400 == 0 || (aa % 4 == 0 && aa%100!=0))){
                printf("ok");
                showSecondDate(dt);
            }else{
                printf("error");
            }
        }else{
            printf("error");
        }
    }else{
        printf("error");
    }  
}

void intervaloData(data *d){

    int d1, d2, m1, m2, a1, a2;
    int ref, df1, df2, j;
    
    d1 = d -> dia;
    d2 = d -> dia2;
    m1 = d -> mes;
    m2 = d -> mes2;
    a1 = d -> ano;
    a2 = d -> ano2;

    ref = a1;

    if(a2 < a1){
        ref = a2;
    }

    //printf("%i", m1);
    df1=valorMeses(m1);

    for(j=ref;j<a1;j++){
        if(j%4 == 0){
            df1+=1;
        }
    }

    df1=df1+d1+(a1 - ref)*365;
    df2=0;

    for(j=ref; j < a2; j++){
        if(j%4==0){
            df2+=1;
        }
    }

    df2=valorMeses(m2) + df2 + d2 + ((a2 - ref) * 365);

    printf("\n A diferença entre as duas datas e de %i dias", abs(df2-df1));

}

int valorMeses(int val){
    int k;

    switch(val){
        case 1:
            k=0;
            break;
        case 2:
            k=31;
            break;
        case 3:
            k=59;
            break;
        case 4:
            k=90;
            break;
        case 5:
            k=120;
            break;
        case 6:
            k=151;
            break;
        case 7:
            k=181;
            break;
        case 8:
            k=212;
            break;
        case 9:
            k=243;
            break;
        case 10:
            k=273;
            break;
        case 11:
            k=304;
            break;
        case 12:
            k=334;
            break;
        default:
            printf("Error na entrada de dados");
            printf("\n%i", val);
            break;
    }

    return k;
}