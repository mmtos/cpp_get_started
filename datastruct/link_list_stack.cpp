#include <iostream>
using namespace std;

// �������� ����ü ���� 
struct Node{
	int data;
	struct Node *next;
};

typedef Node Stack;

Stack* createEmptyStack(){
	return NULL; 
}

bool isEmpty(Stack *top){
	return top == NULL;
}

// ** : �����͸� ����Ű�� ������   
void push(Stack **top, int data){
	Stack *newNode = NULL;
	
	newNode = (Stack*) malloc(sizeof(Stack));
	if(newNode == NULL) {
		// �޸𸮸� �Ҵ���� ���� ���  
		cout << "Stack already Full\n";
		return;
	}
	newNode -> data = data;
	newNode -> next = *top;
	*top = newNode; // Top�� ����Ű�� ������ ��ü�� �ٲٱ� ���ؼ� ���������͸� ����.	 
	cout << data << " pushed in Stack\n";
}

int pop(Stack **top){
	Stack* temp = NULL;
	int data = 0;
	if(isEmpty(*top)){
		return INT_MIN;
	} 
	
	// top �����͸� ��ĭ �ڷ� 
	temp = *top;
	*top = temp -> next;
	data = temp -> data;
	free(temp);
	return data;
}

void LinkedListStackTest(){
	cout << "\n=====" << __func__ << "=====\n";
	Stack* stk = createEmptyStack();
	
	// stk : ������, &stk �������� ������ 
	push(&stk,3);
	push(&stk,4);
	push(&stk,5);
	cout << pop(&stk) << "\n";
	cout << pop(&stk) << "\n";
	cout << pop(&stk) << "\n";
}

int main(){
	LinkedListStackTest();
	return 0; 
}
