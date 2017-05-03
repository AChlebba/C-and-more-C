#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ILOSC_KROKOW 10




int PoliczIlosc(char ciag[], char liczba, int start){

int ilosc = 1;
int flag = 1;
int j = 1;

while(flag == 1){
    if (ciag[start+j] == liczba){
        ilosc++;
        j++;
    }
    else
        flag = 0;
}

return ilosc;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PoliczCyfry(char ciag[], int len, int n){

    char nowyCiag[100] = "";
    int ilosc;

    //for(int i=0; i<len; i++)
    int i = 0;
    while(i<len)
        {
        char  * liczba;
        liczba = ciag[i];

        ilosc = PoliczIlosc(ciag, liczba, i);

        char strIlosc[3];
        sprintf(strIlosc, "%d", ilosc);

        strcat(nowyCiag, strIlosc);
        strcat (nowyCiag, &liczba);


        i=i+ilosc;
    }


    printf(" Nowy ciag       %s \n",nowyCiag);
    n++;
    if (n < ILOSC_KROKOW)
        PoliczCyfry(nowyCiag, strlen(nowyCiag), n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //nasz poczatkowy ciag
    char * ciag = "1";

    printf("Poczatkowy ciag: %s\n",ciag);
    //printf("Ilosc: %d \n",PoliczIlosc(ciag, '2', 2));
    PoliczCyfry(ciag, strlen(ciag), 0);

    return 0;
}
