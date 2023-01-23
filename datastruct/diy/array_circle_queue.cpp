#include <iostream>

using namespace std;

const int Q_SIZE = 7;
int head = 0, tail = 0, size = 0,a[Q_SIZE];

// 비어있을 때, 가득 찼을때 모두 head == tail임 
// 비어있는 경우와 꽉 찬 경우를 구분할 수 있는 방법?
// --> size 변수를 두자 

void push(int num){
	if( size == Q_SIZE ) {
		cout << "Q is fulled" << "\n";
		return;
	}
	a[tail++] = num; size++; 
	if(tail == Q_SIZE) tail = 0;
}

bool empty(){
	return size == 0;
}

void pop(){
	if(empty()){
		cout << "Q is empty" << "\n";
		return;
	}
	head++; size--;
	if(head % Q_SIZE == 0) head = 0;
}

int front(){
	return a[head];
}

int back(){
	if(tail == 0) return a[Q_SIZE-1];
	return a[tail-1];
}

void print_q_state(){
	cout << "\n====" << __func__ << "====\n";
	cout << "size : " << size << "\n";
	cout << "head : " << head << "\n";
	cout << "tail : " << tail << "\n";
	int temp_head = head;
	if(head < tail){
		while(temp_head != tail){
			cout << a[temp_head % Q_SIZE] << " ";
			temp_head++;
		}
	}else{
		while(temp_head != (tail + Q_SIZE)){
			cout << a[temp_head % Q_SIZE] << " ";
			temp_head++;
		}
	}
	cout << "\n";
}
void diy_q_test(){
	for(int i=1; i<=5; i++) push(i);
	print_q_state();
	push(-5);
	push(-4);
	pop();
	pop();
	push(-3);
	push(-2);
	push(-1);
	print_q_state();
	while(!empty()) pop();
	pop();
	pop();
	print_q_state();
	pop();
	for(int i=1; i<=Q_SIZE; i++) push(i);
	print_q_state();
}

int main(){
	//https://blog.encrypted.gg/934
	diy_q_test();
	for(int i=0; i< Q_SIZE;i++) cout << a[i] << " ";
	return 0;
} 
