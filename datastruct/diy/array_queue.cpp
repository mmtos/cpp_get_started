#include <iostream>
using namespace std;

typedef struct ArrayQueue {
	int front; //in 위치는 0으로 고정..  
	int rear; //out 위치 
	int capacity;
	int* array;
} Queue;

//malloc과 realloc의 차이 & free 
Queue* createQueue(int capacity){
	Queue* q = (Queue*) malloc(sizeof(Queue));
	q -> front = 0;
	q -> rear = -1;
	q -> capacity = capacity;
	q -> array = (int*) malloc(capacity * sizeof(int)); 
	return q;
}

bool isEmpty(Queue* q){
	return q -> rear == -1;
}

bool isFull(Queue* q){
	return q -> rear == (q -> capacity) -1;
}

void shift(Queue* q){
	int rear = q -> rear;
	int* array = q-> array;
	for(int i=rear; i>=0; i--){
		array[i+1] = array[i];
	}	
}

void enqueue(Queue* q, int data){
	if(isFull(q)){
		cout << "This Queue is Fulled\n";
		return;
	}
	shift(q);
	q -> array[q -> front] = data;
	++q->rear;
	cout <<  data << " Inserted\n";
}

int dequeue(Queue* q){
	if(isEmpty(q)){
		cout << "Empty Queue\n";
		return INT_MIN;
	}
	return q -> array[q->rear--];
}

int main(){
	Queue* q = createQueue(5);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	
	cout << q -> front << "\n";
	cout << q -> rear << "\n";
	cout << q -> capacity << "\n";
	int* array = q -> array;
	for(int i=0; i<= q -> rear; i++){
		cout << array[i]<< ",";
	}		
	cout << "\n";
	
	cout << dequeue(q) << "\n";
	cout << dequeue(q) << "\n";
	cout << dequeue(q) << "\n";
	
	
	cout << q -> front << "\n";
	cout << q -> rear << "\n";
	cout << q -> capacity << "\n";
	for(int i=0; i<= q -> rear; i++){
		cout << array[i]<< ",";
	}		
	cout << "\n";
	
	return 0;
}
