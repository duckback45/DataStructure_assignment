#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"
#include "queue.h"

/*
 * visual studio 2019 ver 16.6.3
 * author Baek Sanghun
 */


typedef struct Data
{
    int s_count;
    int* p_numArray;
};
//����ڰ� �Է��� ���ڵ��� ������ �迭�� ����� �����͸� ����� �ִ� �Լ��̴�.
Data *ScanInteger()
{
    int count = 0;
    Data* _data = (Data*)malloc(sizeof(struct Data));
    
    printf("��� �����͸� �Է��Ұǰ���?");
    scanf_s("%d", &count);

	if(count <= 0)
	{
        printf("0���� ũ�� �Է����ּ���");
        system("cls"); 
        ScanInteger();
	}

    _data->s_count = count;
    _data->p_numArray = (int*)malloc(sizeof(int) * count);
	
	for(int i=0; i<count; i++)
	{
        printf("%d��° ���� �Է� : ", i + 1);
        scanf_s("%d", _data->p_numArray + i);
	}

    return _data;
    	
}


int main()
{
	//����ڷ� ���� �Է¹��� �迭�� ũ�⸦ ������
    Data* d = ScanInteger();

    int data_size = d->s_count;
	//������ �ʱ�ȭ�մϴ�.
    stack* stack = InitStack(data_size);
	
    for (int s = 0; s < data_size; s++)
    {
        Push(stack, d->p_numArray[s]);
    }
    free(d);

    //������ ������ top���� �ϳ��� ����մϴ�.
    int stack_count = stack->top;

    printf("���� �ִ� ����: ");
	while(stack_count > -1)
	{
        printf("%d ", stack->p_stack[stack_count]);
        stack_count--;

	}

    queue* main_queue = NewQueue(data_size);
    queue* sub_queue = NewQueue(data_size);
    int main_count = 0;
    int sub_count = 0;


	//���ÿ� �ִ� ������� �ΰ��� ť�� �̿��Ͽ� 
	//������� �������� ����� �ݴϴ�. ���� ����� MainQueue�� ����˴ϴ�.
	//�˰��� ������ ����Ʈ�� ��üȭ �س����ϴ�.
    for (int i = 0; i < data_size; i++)
    {
        int data = Pop(stack);
    	
        if (i == 0)
        {
            Enqueue(sub_queue, data);
        }
        else
        {
            Enqueue(main_queue, data);

            sub_count = sub_queue->count;

            for (int j = 0; j < sub_count; j++)
            {
                int sub_value = Dequeue(sub_queue);
                Enqueue(main_queue, sub_value);

            }

            main_count = main_queue->count;
            for (int k = 0; k < main_count; k++)
            {
                int main_Value = Dequeue(main_queue);
                Enqueue(sub_queue, main_Value);

            }

            sub_count = sub_queue->count;

            if (data_size - 1 <= i)
            {

                for (int n = 0; n < sub_count; n++)
                {

                    int sub_value = Dequeue(sub_queue);
                    Enqueue(main_queue, sub_value);

                }

            }


        }

    }

    printf("\n");


    printf("Main Queue ����: ");

    if (IsEmpty(main_queue))
        printf("Main Queue�� ������ֽ��ϴ�.");
	
    while (!IsEmpty(main_queue))
        printf("%d ", Dequeue(main_queue));


    printf("\n ");


    printf("Sub Queue ����: ");

    if (IsEmpty(sub_queue))
        printf("Sub Queue�� ������ֽ��ϴ�.");

    while (!IsEmpty(sub_queue))
        printf("%d ", Dequeue(sub_queue));

    DisposeQueue(main_queue);
    DisposeQueue(sub_queue);
    DisposeStack(stack);

    _getch();
    return 0;
}
