#include <stdio.h>
#include <stdlib.h>

#include "queue.h"



queue* NewQueue(size_t size)
{
    //����ü Queue ũ�� 1���� �������� �޸� �Ҵ�
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    //Data * ũ�� size ���� �������� �޸� �Ҵ�
    queue->front = queue->rear = NULL;
    queue-> count = 0;//ť�� ������ ���� ������ 0���� ����    
    return queue;//�������� ������ queue ��ȯ
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
