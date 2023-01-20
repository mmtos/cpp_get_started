#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
  int top;
  int capacity;
  int* array;
} Stack;

/* �־��� capacity ũ��� stack�� �����ϴ� �Լ� */
Stack* createStack(int capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  if (!stack)
    return NULL;
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

/* ������ ����ִ��� Ȯ���ϴ� �Լ�. */
int isEmpty (Stack* stack) {
  return (stack->top == -1);
}

/* ������ ����á���� Ȯ���ϴ� �Լ�. */
int isFull (Stack* stack) {
  return (stack->top == stack->capacity - 1);
}

/* top ��ġ�� �ִ� ���� �������� �Լ� */
int peek (Stack* stack) {
  if(isEmpty(stack))
    return INT_MIN;  
  return stack->array[stack->top];
}

/* ���ÿ� ���� �߰��ϴ� �Լ� */
void push(Stack *stack, int data) {
  if (isFull(stack))
    printf("Stack is full\n");
  else {
     /* top�� 1������Ű�� ���� top�� ������ */
    stack->array[++stack->top] = data;
    printf("%d pushed to stack\n", data);
  }
}

/* ���ÿ� ���� �����ϴ� �Լ� */
int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return INT_MIN;
  }
  else /* top�� ���� 1 ���ҽ�Ŵ */
    return (stack->array[stack->top--]);
}

int main() 
{
  Stack* stack = createStack(3);
  
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  
  printf("%d poped from stack\n", pop(stack));
}
