#ifndef GOL_OUTPUT_H
#define GOL_OUTPUT_H

#include <stdlib.h>

/*	produce an output stream for updating the display; call this function once at the end of each time step
	grid is a 2-dimensional int array with states of one or zero
	rowDim and colDim are the row and column dimensions of the grid 
	Return value is 0 if output succeeds, non-zero otherwise */
int gol_disp_output (int ** grid, const size_t rowDim, const size_t colDim);

/* indicate that you are done sending output; closes the output window and terminates the calling program
on exit from the C program */
void gol_disp_terminate ();


#endif //GOL_OUTPUT_H