#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "partition.h"
#include "stack.h"
 
typedef struct {
    bool sorted;   // if this record is sorted
    int start;          // the index of the start
    int end;            // the index of the end
} mergeRecord;
 
mergeRecord *new_mergeRecord(bool sorted, int s, int e);
void myMergePass(void **A, int first, int last, int (cmp)(void *, void *));
 
mergeRecord *new_mergeRecord(bool sorted, int s, int e){
        mergeRecord *r = (mergeRecord *)malloc(sizeof(mergeRecord));
        r->sorted = sorted;
        r->start = s;
        r->end = e;
        return r;
}
 
void myMergesort(void **A, int n, int(cmp)(void *, void*)) {
        Stack *s = stack_new();
        mergeRecord *r = new_mergeRecord(false, 0, n-1);
        stack_push(s, r);
        while(stack_isEmpty(s) == 0){
                r = (mergeRecord*)stack_pop(s);
                if(r->sorted){
                        myMergePass(A, r->start, r->end, cmp);
                }
                else {
                        if(r->start < r->end){
                                int mid = (r->start + r->end) / 2;
                                stack_push(s, new_mergeRecord(true, r->start, r->end));
                                if(mid != r->start){
                                        stack_push(s, new_mergeRecord(false, r->start, mid));
                                }
                                if(mid != r->end - 1){
                                        stack_push(s, new_mergeRecord(false, mid+1, r->end));
                                }
                        }
                }
        }
       
}
 
void myMergePass(void **A, int first, int last, int (cmp)(void *, void *)){
        long *temp = (void**)malloc(sizeof(void *) * (last-first+1));
        if(first < last){
                int i1 = first;
                int mid = (first + last)/2;
                int i2 = mid + 1;
                int i;
               
                for(i = 0; i < last - first + 1; i++){
                        if(i1 > mid){
                                temp[i] = (long)A[i2];
                                i2++;
                        }
                        else if(i2 > last){
                                temp[i] = (long)A[i1];
                                i1++;
                        }
                        else if(cmp(A[i1],A[i2]) < 0){
                                temp[i]=(long)A[i1];
                                i1++;
                        }
                        else {
                                temp[i] = (long)A[i2];
                                i2++;
                        }
                }
               
                for(i = 0; i < last - first + 1; i++){
                        A[first+i]=(void*)temp[i];    
                }
        }
}