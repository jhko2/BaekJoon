/*#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node //��� ����
{
	char data;
	struct Node *next;
}Node;


typedef struct Stack //Stack ����ü ����
{
	Node *top;    //�� �� ���(���� �ֱٿ� ������ ���)
	int size;
}Stack;

//----------------------------------------------------------�Լ�
void InitStack(Stack *stack) //���� �ʱ�ȭ
{
	stack->top = NULL; //���� �ʱ�ȭ������ top�� NULL�� ����
	stack->size = 0;
}
void printSize(Stack *stack)
{
	printf("%d\n", stack->size);
}
int IsEmpty(Stack *stack) //���� ����ִ���Ȯ��
{
	return stack->top == NULL;    //top�� NULL�̸� �� ����
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
	Node *now = (Node *)malloc(sizeof(Node)); //��� ����
	now->data = data;//������ ����
	now->next = stack->top;//now�� next��ũ�� ���� top���� ����
	stack->top = now;   //������ �� ���� now�� ����
	stack->size++;
}
int Pop(Stack *stack) //�� ������ ��� ����
{
	Node *now;
	int re;
	if (IsEmpty(stack))
	{
		return -1;
	}
	now = stack->top;//now�� top���� ����
	re = now->data;//���� ���� now�� data�� ����

	stack->top = now->next;//top�� now�� next�� ����
	stack->size--; //size ����
	free(now);//�ʿ������ �޸� ����
	return re;
}
int main()
{
	int i, j, length;
	int flag = 1;
	int temp=1;
	int gar;
	int result=0; //�����
	char arr[3000];

	Stack stack;
	InitStack(&stack);

	scanf("%s", arr); //��ȣ�Է¹�
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
	if (IsEmpty(&stack)&&(flag==1)) //������ ����ְų�
		printf("%d\n", result); //����� ���
	else
	{
		flag = 0; //������ ������� �ʴٸ�
		printf("0\n");
	}
}*/ // ������ �𸣰ڽɴ�;; 
