#include <iostream>
using namespace std;

// 전역으로 구조체 선언 
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

// ** : 포인터를 가리키는 포인터   
void push(Stack **top, int data){
	Stack *newNode = NULL;
	
	newNode = (Stack*) malloc(sizeof(Stack));
	if(newNode == NULL) {
		// 메모리를 할당받지 못한 경우  
		cout << "Stack already Full\n";
		return;
	}
	newNode -> data = data;
	newNode -> next = *top;
	*top = newNode; // Top이 가리키는 포인터 자체를 바꾸기 위해서 이중포인터를 쓴다.	 
	cout << data << " pushed in Stack\n";
}

int pop(Stack **top){
	Stack* temp = NULL;
	int data = 0;
	if(isEmpty(*top)){
		return INT_MIN;
	} 
	
	// top 포인터를 한칸 뒤로 
	temp = *top;
	*top = temp -> next;
	data = temp -> data;
	free(temp);
	return data;
}

void LinkedListStackTest(){
	cout << "\n=====" << __func__ << "=====\n";
	Stack* stk = createEmptyStack();
	
	// stk : 포인터, &stk 포인터의 포인터 
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
