/*#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node //노드 정의
{
	char data;
	struct Node *next;
}Node;


typedef struct Stack //Stack 구조체 정의
{
	Node *top;    //맨 앞 노드(가장 최근에 생성한 노드)
	int size;
}Stack;

//----------------------------------------------------------함수
void InitStack(Stack *stack) //스택 초기화
{
	stack->top = NULL; //스택 초기화에서는 top을 NULL로 설정
	stack->size = 0;
}
void printSize(Stack *stack)
{
	printf("%d\n", stack->size);
}
int IsEmpty(Stack *stack) //스택 비어있는지확인
{
	return stack->top == NULL;    //top이 NULL이면 빈 상태
}
int printTop(Stack *stack)
{
	if (stack->top == NULL)
		return -1;
	else
		return stack->top->data;
}
void Push(Stack *stack, int data)
{
	Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
	now->data = data;//데이터 설정
	now->next = stack->top;//now의 next링크를 현재 top으로 설정
	stack->top = now;   //스택의 맨 앞은 now로 설정
	stack->size++;
}
int Pop(Stack *stack) //맨 마지막 노드 제거
{
	Node *now;
	int re;
	if (IsEmpty(stack))
	{
		return -1;
	}
	now = stack->top;//now를 top으로 설정
	re = now->data;//꺼낼 값은 now의 data로 설정

	stack->top = now->next;//top을 now의 next로 설정
	stack->size--; //size 줄임
	free(now);//필요없으니 메모리 해제
	return re;
}
int main()
{
	int i, j, length;
	int flag = 1;
	int temp=1;
	int gar;
	int result=0; //결과값
	char arr[3000];

	Stack stack;
	InitStack(&stack);

	scanf("%s", arr); //괄호입력받
	length = strlen(arr);

	for (j = 0; j < length; j++)
	{
		if (arr[j] == '(')
		{
			temp = temp * 2;
			Push(&stack, '(');
		}
		else if (arr[j] == '[')
		{
			temp = temp * 3;
			Push(&stack, '[');
		}
		else if (arr[j] == ')')
		{
			if (arr[j - 1] == '(')
				result = result + temp;
			if (IsEmpty(&stack))
			{
				flag = 0;
				break;
			}
			if (printTop(&stack) == '(')
				gar=Pop(&stack);
			temp = temp / 2;
		}
		else if (arr[j] == ']')
		{
			if (arr[j - 1] == '[')
				result = result + temp;
			if (IsEmpty(&stack))
			{
				flag = 0;
				break;
			}
			if (printTop(&stack) == '[')
				gar = Pop(&stack);
			temp = temp / 3;
		}
	}
	if (IsEmpty(&stack)&&(flag==1)) //스택이 비어있거나
		printf("%d\n", result); //결과값 출력
	else
	{
		flag = 0; //스택이 비어있지 않다면
		printf("0\n");
	}
}*/ // 도저히 모르겠심다;; 
