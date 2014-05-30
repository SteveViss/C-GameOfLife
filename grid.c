#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Set global variables */

main ()
{
    int i,y;
    int numRows, numCols;
    numRows = numCols = 50;
    int LastGrid [numRows][numCols];
    int NewGrid [numRows][numCols];
    srand(time(NULL));
    int Nsimu;

    Nsimu = 100;

    /* Initi grid */
    for (i = 0; i<numCols;i++) {
        for (y = 0; y<numRows;y++) {
            long double val = rand()/((long double) RAND_MAX);
            if (val < 0.5)
                    LastGrid[i][y] = 0;
            else
                    LastGrid[i][y] = 1;
            printf("LastGrid [%d][%d] = %d \n",i,y,LastGrid[i][y]);
            NewGrid[i][y] = 0;
        }
    }

    /* Run simu */
    int n;

    for (n = 0; n<Nsimu;n++) {
        printf("Time step = %d",n);
        /* Time step */
        for (i = 0; i<numCols;i++) {
            int ip = i + 1;
            int im = i-1;

            /* Torus on i*/

            switch(i){
                case 0:
                    im = numCols-1;
                    break;
                case 49:
                    ip = 0;
                    break;
            }

            for (y = 0; y<numRows;y++) {
                int yp = y + 1;
                int ym = y-1;

                /* Torus on y*/

                switch(y){
                    case 0:
                        ym = numCols-1;
                        break;
                    case 49:
                        yp = 0;
                        break;
                }

                int aliveCells;

                aliveCells = LastGrid[im][ym] + LastGrid[im][y]+ LastGrid[im][yp] + LastGrid[i][ym] + LastGrid[i][yp]+ LastGrid[ip][ym] + LastGrid[ip][y]+ LastGrid[ip][yp];

                /* Rules 1*/
                if (LastGrid[i][y] ==1 && aliveCells <= 2)
                    NewGrid[i][y] = 0;
                else
                    NewGrid[i][y] = 1;

                /* Rules 2*/
                if (LastGrid[i][y] ==1 && aliveCells == 2 ||  LastGrid[i][y] ==1 && aliveCells == 3)
                    NewGrid[i][y] = 1;
                else
                    NewGrid[i][y] = 1;

                /* Rules 3*/
                if (LastGrid[i][y] ==1 && aliveCells > 3)
                    NewGrid[i][y] = 0;
                else
                    NewGrid[i][y] = 1;

                /* Rules 4*/
                if (LastGrid[i][y] == 0 && aliveCells == 3 )
                    NewGrid[i][y] = 1;
                else
                    NewGrid[i][y] = 0;

                }
            }


            for (i = 0; i<numCols;i++) {
                for (y = 0; y<numRows;y++) {
                    LastGrid[i][y] = NewGrid[i][y] ;
                }
            }

          /* END SIMU*/

        }

    return 0;
}