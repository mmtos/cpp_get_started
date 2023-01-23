#include<stack>
#include<iostream>
using namespace std;

void stackTest(){
	cout << "\n=====" << __func__ << "=====\n";
	stack<string> stk; 
	
	stk.push("��");
	stk.push("��");
	stk.push("��");
	stk.push("��");	
	stk.push("��");
	cout << stk.size() << "\n";
	while(stk.size()){
		cout << stk.top() << "\n";
		stk.pop();
	}
	
	cout << stk.empty() << "\n";
}

void popEmptyStack(){
	// ���� �߻� �� �پ˾Ҵµ� ���� . 
	cout << "\n=====" << __func__ << "=====\n";
	stack<int> stk;
	stk.push(10);
	stk.pop();
	stk.pop();
	stk.pop();
	cout << "pop empty stack"<< "\n";
	cout << stk.top(); // ���ܹ߻� 
}

int main(){
	stackTest();
	popEmptyStack();
	
	return 0;
}


