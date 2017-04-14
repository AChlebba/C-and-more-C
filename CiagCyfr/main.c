#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ILOSC_KROKOW 15


void PoliczCyfry(char ciag[20], int x){

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
}

int main()
{
    //nasz poczatkowy ciag
    char *ciag = "1";
    printf("Poczatkowy ciag: %s\n",ciag);

    int x = 0;
    PoliczCyfry(ciag, x);

    return 0;
}
