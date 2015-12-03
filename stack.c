/*
** Stack implementation
**
** William
** Tue 24 Feb 2015 19:13:11 AEDT
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "stack.h"


void printFn(void *p){
	printf("%p\n", p);
}

/*
** Create a new stack with values <type payload>
** and return a pointer to that stack.
*/
Stack *stack_new() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->A = (void**)malloc(sizeof(void *));

	s->A[0] = NULL;
    s->size = 1;
    s->top = -1;
    return s;
}

/*
** Function to push an element to the top of stack
** changing top and size values as necessary
*/
void stack_push(Stack *s, void *item){
	if (s->top == (s->size)-1){
		s->size *= 2;
		s->A = (void**)realloc(s->A, sizeof(item) * (s->size + 1));
	}

	s->top++;
	s->A[s->top] = item;
}

/*
** Function to pop an element from the top of stack
** Return the popped element
*/
void *stack_pop(Stack *s){
	void *popped_item = s->A[s->top];

	if (s->top < 0){
		return 0;
	}

	s->top --;
	return popped_item;
}

/*
** Function to look at top element of stack
** Return the element
*/
void *stack_peek(Stack *s){
	return s->A[s->top];
}


/*
** Checks whether stack is empty
** Return 1 if stack s is empty, else 0
*/
int stack_isEmpty(Stack *s){
	if (s->top == -1){
		return 1;
	}
	return 0;
} 

/*
** Prints entire stack
*/
void stack_print(Stack *s, void(printFn)(void *)){
	int count = 0;

	while (count <= s->top){
		printFn(s->A[count]);
		count++;
	}
}