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
//사용자가 입력한 숫자들을 포인터 배열로 만들어 데이터를 만들어 주는 함수이다.
Data *ScanInteger()
{
    int count = 0;
    Data* _data = (Data*)malloc(sizeof(struct Data));
    
    printf("몇개의 데이터를 입력할건가요?");
    scanf_s("%d", &count);

	if(count <= 0)
	{
        printf("0보다 크게 입력해주세요");
        system("cls"); 
        ScanInteger();
	}

    _data->s_count = count;
    _data->p_numArray = (int*)malloc(sizeof(int) * count);
	
	for(int i=0; i<count; i++)
	{
        printf("%d번째 정수 입력 : ", i + 1);
        scanf_s("%d", _data->p_numArray + i);
	}

    return _data;
    	
}


int main()
{
	//사용자로 부터 입력받은 배열의 크기를 가져옵
    Data* d = ScanInteger();

    int data_size = d->s_count;
	//스택을 초기화합니다.
    stack* stack = InitStack(data_size);
	
    for (int s = 0; s < data_size; s++)
    {
        Push(stack, d->p_numArray[s]);
    }
    free(d);

    //스택의 내용을 top부터 하나씩 출력합니다.
    int stack_count = stack->top;

    printf("스택 있는 내용: ");
	while(stack_count > -1)
	{
        printf("%d ", stack->p_stack[stack_count]);
        stack_count--;

	}

    queue* main_queue = NewQueue(data_size);
    queue* sub_queue = NewQueue(data_size);
    int main_count = 0;
    int sub_count = 0;


	//스택에 있는 내용들을 두개의 큐를 이용하여 
	//내용들을 역순으로 만들어 줍니다. 최종 결과는 MainQueue에 저장됩니다.
	//알고리즘 순서는 레포트에 구체화 해놨습니다.
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


    printf("Main Queue 내용: ");

    if (IsEmpty(main_queue))
        printf("Main Queue는 비워져있습니다.");
	
    while (!IsEmpty(main_queue))
        printf("%d ", Dequeue(main_queue));


    printf("\n ");


    printf("Sub Queue 내용: ");

    if (IsEmpty(sub_queue))
        printf("Sub Queue는 비워져있습니다.");

    while (!IsEmpty(sub_queue))
        printf("%d ", Dequeue(sub_queue));

    DisposeQueue(main_queue);
    DisposeQueue(sub_queue);
    DisposeStack(stack);

    _getch();
    return 0;
}
