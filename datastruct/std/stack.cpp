#include<stack>
#include<iostream>
using namespace std;

void stackTest(){
	cout << "\n=====" << __func__ << "=====\n";
	stack<string> stk; 
	
	stk.push("ㄱ");
	stk.push("ㄴ");
	stk.push("ㄷ");
	stk.push("ㄹ");	
	stk.push("ㅁ");
	cout << stk.size() << "\n";
	while(stk.size()){
		cout << stk.top() << "\n";
		stk.pop();
	}
	
	cout << stk.empty() << "\n";
}

void popEmptyStack(){
	// 예외 발생 할 줄알았는데 안함 . 
	cout << "\n=====" << __func__ << "=====\n";
	stack<int> stk;
	stk.push(10);
	stk.pop();
	stk.pop();
	stk.pop();
	cout << "pop empty stack"<< "\n";
	cout << stk.top(); // 예외발생 
}

int main(){
	stackTest();
	popEmptyStack();
	
	return 0;
}


