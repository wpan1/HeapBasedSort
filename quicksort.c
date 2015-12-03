/*
** COMP20007 Design of Algorithms
** Semester 1 2015
** Assignment 1 Mergesort
**
** William Pan (694945)
** Thu 26 Feb 2015 11:04:32 AEDT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "partition.h"
#include "stack.h"

void quickSortstack(void **A, int s, int e, int(cmp)(void *, void*));

void myQuicksort(void **A, int n, int(cmp)(void *, void*)) {
    //Changing inputs
    quickSortstack(A,0,n-1,cmp);
}

void quickSortstack(void **A, int s, int e, int(cmp)(void *, void*)){
    // Create an stack
    Stack *stack = stack_new();
    long p, s_l = s, e_l = e;
 
    // Push initial values of s (starting position)
    // and e (ending position) to stack
    // Converting values to void*
    stack_push(stack, (void*)s_l);
    stack_push(stack, (void*)e_l);
 
    // Keep popping stack until empty
    while (stack_isEmpty(stack) == 0){
        // Pop e (ending position) and s (starting position)
        e_l = (long)stack_pop(stack);
        s_l = (long)stack_pop(stack);
 
        // Set pivot element at its correct position in sorted array
        // p = partition pivot position
        p = partition(&A[s_l],e_l-s_l+1,A[s_l],cmp)+s_l;

        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > s_l ){
            stack_push(stack, (void*)(s_l));
            stack_push(stack, (void*)(p - 1));
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < e_l ){
            stack_push(stack, (void*)(p + 1));
            stack_push(stack, (void*)(e_l));
        }
    }
}