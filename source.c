#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "cpgplot.h"

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define ARRAY_SIZE 5000000

void disp_histo(int num, double vals[], char * heading, char * x_label)
{
    int j = 0;
    static float fvals[ARRAY_SIZE+1];
    float v_min = 1.0e30;
    float v_max = -1.0e30;
    for(j = 0; j<num; j++)
    {
        fvals[j] = vals[j];
        if(fvals[j] < v_min)
        {
            v_min = fvals[j];
        }
        if(fvals[j] > v_max)
        {
            v_max = fvals[j];
        }
    }
    cpgbbuf();
    /*
     * Now plot a histogram
     */

    // for display
//    cpgsci(15);

    // for outputting to ps file
    cpgsci(1);

    cpghist(num, fvals, v_min, v_max, 200,0);
//    printf("v_min: %f, v_max: %f", v_min, v_max);
    cpglab(x_label, "Counts", heading);
    // cpgsave saves the current graphics
    cpgsave();

}


int main(void)
{
    int i = 0;
    i = (int) time(NULL);
    //
    // Set a unique random seed
    //
    srand48(i);

    int npoints = ARRAY_SIZE/10;
    static double rand_array[ARRAY_SIZE+1];

    /*
     * Call ppgbeg to initiate PGPLOT and open the output device; cpgbeg
     * will prompt the user to supply the device name and type.
     */
    if (1 != cpgbeg(0, "?", 1, 1))
    {
        exit(EXIT_FAILURE);
    }
    cpgask(1);

    int j = 0;
    for(j = 0; j<npoints; j++)
    {
        rand_array[j] = drand48();
    }
    disp_histo(npoints, rand_array, "Uniform Random (1)","Random1");

    cpgend();
}