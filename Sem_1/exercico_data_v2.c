#include <stdio.h>
#include <stdlib.h>

//Codigo por Luan Emanuel, RA 2143860.

typedef struct{
    int day[2];
    int month[2];
    int year[2];
}date;

date *getDate(); //Funcao que recebe as duas datas do usuario.
void showDate(date *d); //Funcao que printa a data no formato requirido.
int verifyDate(date *d, int i); //Funcao que verifica se a data e valida.
void dateInterval(date *d); //Sistema que calcula o intervalo entre datas.
int monthValue(int val); //Complemento do sistema de intervalo que calcula os dias entre meses.

int main(){

    showDate(getDate());

    return 0;
}

date *getDate(){
    date *d = (date *)malloc(sizeof(date));
    int i;

    for(i=0;i<2;i++){
        printf("\nInsira um data (Utilize o formato DD/MM/AAAA): ");
        scanf("%i/%i/%i", &d -> day[i], &d -> month[i], &d -> year[i]);
        if(verifyDate(d, i) != 1){
            i--;
        }
    }

    return d;
}

void showDate(date *d){
    int mm;
    int i;

    printf("\n");

    for(i=0;i<2;i++){
        mm = d -> month[i];
        printf("\n%i/%i/%i\n", d -> day[i], d -> month[i], d -> year[i]);

        switch(mm){
            case 1:
                printf("%i de Janeiro de %i", d -> day[i], d -> year[i]);
                break;
            case 2:
                printf("%i de Fevereiro de %i", d -> day[i], d -> year[i]);
                break;
            case 3:
                printf("%i de Marco de %i", d -> day[i], d -> year[i]);
                break;
            case 4:
                printf("%i de Abril de %i", d -> day[i], d -> year[i]);
                break;
            case 5:
                printf("%i de Maio de %i", d -> day[i], d -> year[i]);
                break;
            case 6:
                printf("%i de Junho de %i", d -> day[i] , d -> year[i]);
                break;
            case 7:
                printf("%i de Julho de %i", d -> day[i], d -> year[i]);
                break;
            case 8:
                printf("%i de Agosto de %i", d -> day[i], d -> year[i]);
                break;
            case 9:
                printf("%i de Setembro de %i", d -> day[i], d -> year[i]);
                break;
            case 10:
                printf("%i de Outubro de %i", d -> day[i], d -> year[i]);
                break;
            case 11:
                printf("%i de Novembro de %i", d -> day[i], d -> year[i]);
                break;
            case 12:
                printf("%i de Dezembro de %i", d -> day[i], d -> year[i]);
                break;
            default:
                break;
        }

        printf("\n%i-%i-%i\n", d -> year[i], d -> month[i], d -> day[i]);
    }

    dateInterval(d);
}

int verifyDate(date *d, int i){
    int aa, dd, mm;

    dd = d -> day[i];
    mm = d -> month[i];
    aa = d -> year[i];

    if(aa>=0 && aa<=9999){
        if(mm >= 1 && mm <= 12){
            if((dd >= 1 && dd <=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                printf("Ok");
                return 1;
            }else if((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
                printf("Ok");
                return 1;
            }else if((dd >= 1 && dd <= 28) && (mm == 2)){
                printf("Ok");
                return 1;
            }else if(dd == 29 && mm==2 && (aa % 400 == 0 || (aa % 4 == 0 && aa%100!=0))){
                printf("Ok");
                return 1;
            }else{
                printf("Dia invalido!\n");
            }
        }else{
            printf("Mes invalido!\n");
        }
    }else{
        printf("Ano invalido!\n");
    }  
}

void dateInterval(date *d){

    int d1, d2, m1, m2, a1, a2;
    int ref, df1, df2, j;
    
    d1 = d -> day[0];
    d2 = d -> day[1];
    m1 = d -> month[0];
    m2 = d -> month[1];
    a1 = d -> year[0];
    a2 = d -> year[1];

    ref = a1;

    if(a2 < a1){
        ref = a2;
    }

    df1=monthValue(m1);

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

    df2=monthValue(m2) + df2 + d2 + ((a2 - ref) * 365);

    printf("\nA diferença entre as duas datas e de %i dias\n", abs(df2-df1));

}

int monthValue(int val){
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
            break;
    }

    return k;
}