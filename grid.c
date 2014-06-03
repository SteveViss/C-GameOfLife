#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gol_output.h"

#define numRows 100
#define numCols 150

/* Set global variables */

int main ()
{
    int i,y;

    int ** LastGrid = malloc(sizeof (int *) * numCols);
    int ** NewGrid = malloc(sizeof (int *) * numCols);
    //int LastGrid [numRows][numCols];
    //int NewGrid [numRows][numCols];
    srand(time(NULL));
    int Nsimu;

    Nsimu = 1;

    /* Initi grid */
    for (i = 0; i<numCols;i++) {

        LastGrid[i] = malloc(sizeof (int) * numRows);
        NewGrid[i] = malloc(sizeof (int) * numRows);

        for (y = 0; y<numRows;y++) {

            long double val = rand()/((long double) RAND_MAX);


            if (val < 0.5)
                    LastGrid[i][y] = NewGrid[i][y]  =0;
            else
                    LastGrid[i][y] = NewGrid[i][y]  = 1;
  //          printf("LastGrid [%d][%d] = %d \n",i,y,LastGrid[i][y]);

        }
    }

    gol_disp_output (LastGrid, numRows, numCols);

    /* Run simu */
    int n;

    for (n = 0; n<Nsimu;n++) {
 //       printf("Time step = %d \n",n);
        /* Time step */
        for (i = 0; i<numCols;i++) {
            int ip = i + 1;
            int im = i-1;

            /* Torus on i*/

            switch(i){
                case 0:
                    im = numCols-1;
                    break;
                case numCols-1:
                    ip = 0;
                    break;
            }

            for (y = 0; y<numRows;y++) {
                int yp = y + 1;
                int ym = y-1;

                /* Torus on y*/

                switch(y){
                    case 0:
                        ym = numRows-1;
                        break;
                    case numRows-1:
                        yp = 0;
                        break;
                }

                int aliveCells;

                aliveCells = LastGrid[im][ym] + LastGrid[im][y]+ LastGrid[im][yp] + LastGrid[i][ym] + LastGrid[i][yp]+ LastGrid[ip][ym] + LastGrid[ip][y]+ LastGrid[ip][yp];


                if (LastGrid[i][y] == 1) {

                    if (aliveCells < 2 || aliveCells >3){

                        NewGrid[i][y] = 0;

                    } else {NewGrid[i][y] = 1;}

                } else if (aliveCells==3){

                        NewGrid[i][y] = 1;

                } else {NewGrid[i][y] = 0;}

                }
            }

            int ** swGrid = LastGrid;
            LastGrid = NewGrid;
            NewGrid = swGrid;
           gol_disp_output (LastGrid, numRows, numCols);

          /* END SIMU*/

        }

    gol_disp_terminate();
    return 0;
}