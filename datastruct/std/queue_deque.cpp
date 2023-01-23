#include<bits/stdc++.h>
using namespace std;

void queueTest(){
	queue<int> q;
	for(int i = 1; i <= 10; i++) q.push(i);
	while(q.size()){
		cout << q.front() << ' ';
		q.pop();
	}
}

// 앞 뒤로 꺼낼수 있음 
void dequeTest(){
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	
	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n";
	
	dq.pop_back();
	dq.pop_front();
	
	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n"; 
}

int main(){
	cout << "\n===queueTest===\n";
	queueTest();
	cout << "\n===dequeTest===\n";
	dequeTest();
	return 0;
}


