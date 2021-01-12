#include <stdio.h>
#include <stdlib.h>

#include "queue.h"



queue* NewQueue(size_t size)
{
    //구조체 Queue 크기 1개를 동적으로 메모리 할당
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    //Data * 크기 size 개를 동적으로 메모리 할당
    queue->front = queue->rear = NULL;
    queue-> count = 0;//큐에 보관한 원소 개수를 0으로 설정    
    return queue;//동적으로 생성한 queue 반환
}

int IsEmpty(queue* queue)
{
    if (queue->front == NULL)
        return true;
    else
        return false;
}

void Enqueue(queue* queue, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = data;

	if(IsEmpty(queue))
	{
        queue->front = new_node;
        queue->rear = new_node;
	}
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->count += 1;

}

int Dequeue(queue* queue)
{
    node* pop_node;
    int value;

	if(IsEmpty(queue))
	{
        printf("It's emptt");
        exit(-1);
		
	}

    pop_node = queue->front;
    value = pop_node->data;
    queue->front = queue->front->next;
    queue->count -= 1;

    free(pop_node);
    return value;
}

void DisposeQueue(queue* queue)
{
    free(queue);

}
