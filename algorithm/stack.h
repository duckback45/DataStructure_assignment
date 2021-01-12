typedef struct Stack
{
	int* p_stack;
	int len_size;
	int top;
}stack;

stack *InitStack(int size);
int Is_Empty(stack* stack);
void Push(stack* stack, int item);
int Pop(stack* stack);
void DisposeStack(stack* stack);
int Peek(stack* stack);

