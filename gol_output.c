#include <stdio.h>
#include "gol_output.h"

int gol_disp_output (int ** grid, const size_t rowDim, const size_t colDim) {

	int returnValue = 0;
	char * outputRow = malloc( sizeof(char)	* (colDim) + 1);
	
	if(!grid || !outputRow) {
		returnValue = 1;
	} else {
		outputRow[colDim - 1] = '\0';
		for(size_t row = 0; row < rowDim; row++) {
			if(!grid[row]) {
				returnValue = 2;
				break;
			} else {
				for(size_t column = 0; column < colDim; column++) {
					if(grid[row][column])
						outputRow[column] = '1';
					else
						outputRow[column] = '0';
				}
			}
			printf("%s\n", outputRow);
		}
	}
	printf("\n");
	fflush(stdout);
	return returnValue;
}

void gol_disp_terminate() {
	printf("NA\n");
}