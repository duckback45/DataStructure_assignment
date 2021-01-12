#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack* InitStack(int size)
{
	Stack* ret_stack = (Stack*)malloc(sizeof(Stack));
	ret_stack->top = -1;
	ret_stack->len_size = size;
	ret_stack->p_stack = (int*)malloc(sizeof(int) * size);

	return ret_stack;
}

int Is_Empty(stack *stack)
{
	if (stack->top == -1)
		return true;
	else
		return false;
}

void Push(stack * stack, int item)
{
	stack->top += 1;
	stack->p_stack[stack->top] = item;	
}

int Pop(stack * stack)
{
	int index;
	
	if (stack->top == -1)
	{
		printf("Stack is empty");
		exit(-1);
	}

	return stack->p_stack[(stack->top)--];
	
}

void DisposeStack(stack *stack)
{
	free(stack);
}

int Peek(stack* stack)
{
	if (Is_Empty(stack))
	{
		printf("스택 데이터가 없습니다. 넣어주세요");
		exit(-1);
	}

	return stack->p_stack[stack->top];
	
}