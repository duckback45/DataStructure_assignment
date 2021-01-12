
typedef struct Node //Queue ����ü ����
{
    int data;
    struct Node* next;

}node;

typedef struct Queue //Queue ����ü ����
{
    node* front; //���� �ε���(���� �������� ������ �����Ͱ� �ִ� �ε���)
    node* rear;//������ �ε���
    int count;

}queue;

queue* NewQueue(size_t size);
int IsEmpty(queue* queue);
void Enqueue(queue* queue, int data);
int Dequeue(queue* queue);
void DisposeQueue(queue* queue);

