
typedef struct Node //Queue 구조체 정의
{
    int data;
    struct Node* next;

}node;

typedef struct Queue //Queue 구조체 정의
{
    node* front; //꺼낼 인덱스(가장 오래전에 보관한 데이터가 있는 인덱스)
    node* rear;//보관할 인덱스
    int count;

}queue;

queue* NewQueue(size_t size);
int IsEmpty(queue* queue);
void Enqueue(queue* queue, int data);
int Dequeue(queue* queue);
void DisposeQueue(queue* queue);

