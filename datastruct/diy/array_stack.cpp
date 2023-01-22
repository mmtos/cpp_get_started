#include <iostream>
using namespace std;

struct ArrayStack{
	int top;
	int capacity;
	int* array;
};

typedef ArrayStack Stack;

// Stack의 내부 값이 ( ex) top )이 변경이 안되는 문제가 있음
//Stack createStack(int capacity){
//	Stack stk;
//	stk.top = -1;
//	stk.capacity = capacity;
//	int a[capacity];
//	stk.array = a;
//	return stk;
//}
//
//bool isEmpty(Stack stk){
//	return stk.top == -1;
//}
//
//bool isFull(Stack stk){
//	return stk.top == (stk.capacity -1);
//}
//
//void push(Stack stk, int data){
//	if(isFull(stk))	{
//		cout << "Stack already Full\n";
//		return;
//	}
//	
//	stk.array[++(stk.top)] = data;
//	cout << data << " pushed in Stack\n";
//}
//
//int peek(Stack stk){
//	if(isEmpty(stk)){
//		return INT_MIN;
//	}
//	return stk.array[stk.top];
//}
//
//void printStack(Stack stk){
//	cout << "top: " << stk.top << "\n";
//	cout << "cap: " << stk.capacity << "\n";
//	cout << "peek: " << peek(stk) << "\n";
//	for(int i=0; i< stk.capacity; i++){
//		cout << stk.array[i] << ",";
//	}
//	cout << "\n"; 
//}


Stack* createStack(int capacity){
	Stack* stk = (Stack*) malloc(sizeof(Stack));
	stk->top = -1;
	stk->capacity = capacity;
	
	stk->array = (int*) malloc(stk-> capacity * sizeof(int));
	
	// 오류 발생함.. 뭐가 문제인지 찾기.  
//	int a[capacity];
//	stk->array = a;
	return stk;
}

bool isEmpty(Stack *stk){
	return stk -> top == -1;
}

bool isFull(Stack *stk){
	return stk->top == (stk-> capacity -1);
}

void push(Stack *stk, int data){
	if(isFull(stk))	{
//		cout << "Stack already Full\n";
//		return;
		// 동적배열로 capa 늘리기  
		stk->capacity *=2;
		cout << "Increase capacity to " << stk->capacity <<  " Now\n";
		stk -> array = (int*) realloc(stk->array,stk->capacity);
	}
	stk->array[++stk->top] = data;
	cout << data << " pushed in Stack\n";
}

int peek(Stack *stk){
	if(isEmpty(stk)){
		return INT_MIN;
	}
	return stk->array[stk->top];
}

void printStack(Stack *stk){
	cout << "top: " << stk -> top << "\n";
	cout << "cap: " << stk -> capacity << "\n";
	cout << "peek: " << peek(stk) << "\n";
//	for(int i=0; i< stk->capacity; i++){
//		cout << stk->array[i] << ",";
//	}
	cout << "\n"; 
}

void arrayStackTest(){
	cout << "\n=====" << __func__ << "=====\n";
//	int a[5];
//	Stack stk = {-1, 4, a};
	Stack* stk = createStack(2);	
	printStack(stk);
	push(stk,3);
	push(stk,4);
	push(stk,5);
	printStack(stk);
}

int main(){
	arrayStackTest();
	return 0; 
}
