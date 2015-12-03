/*
** Partition A[0..n-1] so that 
**  all elements less than ** *pivot are in A[0..k-1] and 
**  all elements not less than *pivot ** are in A[k..n-1]. 
** cmp should be used for comparisons.
**
** @return k
**
** Andrew Turpin
** Thu 26 Feb 2015 08:42:06 AEDT
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "partition.h"

// Function to swap pointers
void pointer_swap(void **pa, void **pb){
	void *temp = *pa; 
    *pa = *pb;
    *pb = temp;
}

// Function to partition array
// Returns position of pivot element
int partition(void **A, int n, void *pivot, int (cmp)(void *, void *)){
	int start_count = 0, end_count = n-1;

	while(1){
        //Finds last value smaller than pivot
		while (cmp(A[end_count],pivot) > 0){
            end_count--;
        }

        //Finds first value larger than pivot
        while (cmp(A[start_count],pivot) < 0){
            start_count++;
        }

        //If the two values found are identical
        //Ignore firstmost value
        if (cmp(A[start_count],A[end_count]) == 0){
            start_count ++;
        }

        //Swap the two values if they are in correct order
        if  (start_count < end_count){
            pointer_swap(&A[start_count],&A[end_count]);
        }
        //Returns pivot element number if two
        //values are not in correct order
        else{
            return end_count;
    	}
	}
}