#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ILOSC_KROKOW 2


/*void PoliczCyfry(char ciag[20], int x){

    //inicjalizuje i zeruje tablice zliczaj¹ca iloœc cyfr w ci¹gu
    int liczby[10];
    for(int i=0; i<10; i++){
        liczby[i]=0;
    }

    //zlicza ilosc cyfr
    for(int i=0; i<strlen(ciag); i++){
        liczby[(ciag[i] - '0')]++;
    }

    char nowyCiag[20] = "";

    //tworzy nowy ciag na podstawie danych z tablicy
    for(int i=0; i<10; i++){
        if(liczby[i]!=0){
            int aInt = i;
            int lInt = liczby[i];
            char strFroma[15];
            char strFroml[15];
            sprintf(strFroma, "%d", aInt);
            sprintf(strFroml, "%d", lInt);
            strcat (nowyCiag, strFroma);
            strcat (nowyCiag, strFroml);
        }
    }

    printf("Nowy ciag %s \n",nowyCiag);
    x++;
    if (x < ILOSC_KROKOW)
        PoliczCyfry(nowyCiag, x);
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int PoliczIlosc(char ciag[], char liczba, int start){

int ilosc = 1;
int flag = 1;
int i = 1;

while(flag == 1){
    if (ciag[start+i] == liczba){
        ilosc++;
        i++;
    }
    else
        flag = 0;
}

return ilosc;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PoliczCyfry(char ciag[], int len, int n){

    char nowyCiag = "";
    int ilosc;

    for(int i=0; i<len; i++){

        char  liczba = ciag[i];
        printf("Liczba: %s  \n",ciag);

        ilosc = PoliczIlosc(ciag, liczba, i);
    printf("Ilosc: %d  \n",ilosc);
        char strIlosc[15];
        sprintf(strIlosc, "%d", ilosc);
    printf("Jeszcze dziala\n");
        strcat(nowyCiag, strIlosc);

        strcat (nowyCiag, liczba);


        i = i + ilosc;
    }


    printf("Nowy ciag %s \n",nowyCiag);
    n++;
    if (n < ILOSC_KROKOW)
        PoliczCyfry(nowyCiag, strlen(nowyCiag), n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //nasz poczatkowy ciag
    char * ciag = "111211";

    printf("Poczatkowy ciag: %s\n",ciag);
    //printf("Ilosc: %d \n",PoliczIlosc(ciag, '2', 2));
    PoliczCyfry(ciag, strlen(ciag), 0);

    return 0;
}
