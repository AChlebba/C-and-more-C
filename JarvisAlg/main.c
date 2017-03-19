#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DLUGOSC_TABLICY 30


int SprawdzKat (double aX, double aY, double bX, double bY, double cX, double cY) {

    if((cX-bX)*(aY-bY)-(aX-bX)*(cY-bY)>0)
        return 1;
    else
        return 0;

}


void Jarvis (double tabPunkty[2][DLUGOSC_TABLICY]) {

    //zapisuje pierwszy element do zmiennej
    double pktOtoczkiX = tabPunkty[0][0];
    double pktOtoczkiY = tabPunkty[1][0];

    //wyszukuje najbardziej wysuniety w prawo element i zapamietuje
    for (int i=0; i<DLUGOSC_TABLICY; i++) {
        if (tabPunkty[0][i] > pktOtoczkiX){
            pktOtoczkiX = tabPunkty[0][i];
            pktOtoczkiY = tabPunkty[1][i];
        }

    }

    int i = 0;
    double tabPowloka[2][DLUGOSC_TABLICY];
    for(int k=0; k<DLUGOSC_TABLICY; k++){
        tabPowloka[0][k]=-1;
        tabPowloka[1][k]=-1;
    }
    double pktNextX;
    double pktNextY;

    do {
        tabPowloka[0][i]=pktOtoczkiX;
        tabPowloka[1][i]=pktOtoczkiY;

        pktNextX=tabPunkty[0][0];
        pktNextY=tabPunkty[1][0];

        for (int j=0; j<DLUGOSC_TABLICY; j++){

            if ( ((pktNextX == pktOtoczkiX)&&(pktNextY == pktOtoczkiY))||(SprawdzKat(tabPunkty[0][j],tabPunkty[1][j],tabPowloka[0][i],tabPowloka[1][i],pktNextX,pktNextY)) ){

                pktNextX=tabPunkty[0][j];
                pktNextY=tabPunkty[1][j];


            }
        }


        i=i+1;
        pktOtoczkiX = pktNextX;
        pktOtoczkiY = pktNextY;
    }while ((pktNextX != tabPowloka[0][1])&&(pktNextY != tabPowloka[1][1]));


printf("Wynik:\n");
for (int i=0; i<DLUGOSC_TABLICY; i++){
    printf("X:%f, Y:%f\n",tabPowloka[0][i],tabPowloka[1][i]);
}

// Zapisywanie wykresu z wynikami do pliku
FILE *fp;
   if ((fp=fopen("Wykres.txt", "w"))==NULL) {
     printf ("Nie mogê otworzyæ pliku Wykres.txt do zapisu!\n");
     exit(1);
     }

    int trafienie=0;
    for(double i=10; i>0; i=i-0.1){
        for(double j=0; j<10; j=j+0.1){
            for(int k=0; k<DLUGOSC_TABLICY; k=k+1){
                //if (i == tabPunkty[0][k] && j == tabPunkty[1][k])
                if (j > tabPunkty[0][k]-0.01 && j < tabPunkty[0][k]+0.01 && i > tabPunkty[1][k]-0.01 && i < tabPunkty[1][k]+0.01){
                    trafienie = 1;
                    for(int l=0; l<DLUGOSC_TABLICY; l=l+1){
                        if (j > tabPowloka[0][l]-0.01 && j < tabPowloka[0][l]+0.01 && i > tabPowloka[1][l]-0.01 && i < tabPowloka[1][l]+0.01){
                            trafienie = 2;
                            }
                        }
                    }
                }

                if (trafienie > 0){
                    if (trafienie == 1)
                        fprintf(fp,"0 ");
                    else
                         fprintf(fp,"# ");
                    }
                else
                    fprintf(fp,". ");
                trafienie = 0;
            }
        fprintf(fp,"\n");
        }
   fclose (fp);

}



int main()
{
    /*
    double tabPunkty[2][DLUGOSC_TABLICY] = {
    { 1, 5.3, 3.2, 2.5, 6.9, 4.4, 2.8, 0.1, 1.7, 3.2, 3.5, 7.1, 9.9},
    { 1, 5.4, 3.7, 6.2, 1.3, 3.3, 3.6, 3.1, 5.4, 0.2, 3.5, 3.1, 8.6},
     };
*/
    double seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);
    double tabPunkty[2][DLUGOSC_TABLICY];
    for(int k=0; k<DLUGOSC_TABLICY; k++){
        tabPunkty[0][k]=rand() % 10 + (rand() % 10)/10.0;
        tabPunkty[1][k]=rand() % 10 + (rand() % 10)/10.0;
    }

    printf("Punkty:\n");
    for (int i=0; i<DLUGOSC_TABLICY; i++){
        printf("X:%f, Y:%f\n",tabPunkty[0][i],tabPunkty[1][i]);
    }

    Jarvis(tabPunkty);

    return 0;
}
