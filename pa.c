#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "point_array.h"

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )      {

        assert(pa);

        pa->len = 0;
	pa->reserved = 0;
	pa->points = NULL;
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa )     {

        assert(pa);

        if (pa->len > 0)        {

                free(pa->points);
                pa->len = 0;

                }


}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ) {

        assert(pa);
        assert(p);

        pa->len = (pa->len) + 1;
	pa->reserved = (pa->reserved) + 1;

	if ( sizeof(pa->points) < (pa->len)*sizeof(point_t) )	{

        	pa->points = (point_t*)realloc(pa->points, ( (pa->len)+1 )*sizeof(point_t));

        	if (pa->points == NULL) { return 1; }

		pa->reserved = (pa->reserved)+1;

	}

       pa->points[(pa->len)-1] = *p;

        return 0;

}


// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
// Return 0 on success and 1 on failure.
// Move the last element of the array into the index we want to remove and then remove the last element

int point_array_remove( point_array_t* pa, unsigned int i )     {

        assert(pa);
        if (pa == NULL) { return 1; }

        if (i >= pa->len) { return 2; }

        pa->points[i] = pa->points[(pa->len)-1];

        pa->len = (pa->len)-1;

	pa->reserved = (pa->reserved) + 1;

        return 0;

}

