#include <iostream>

using namespace std;

const int MAX_X = 1000005;
int dat[MAX_X], pos = 0;

void push(int x){
	dat[pos++] = x;
}

void pop(){
	pos--;
}

int top(){
	return dat[pos-1];
}

int main(){
	
}

