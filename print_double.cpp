#include <iostream>
#include <cstdio>

using namespace std;

void print_double_test(){
	double d = 3.123915151262;
	printf("%.3f\n",d);
	cout << fixed;
	//정수부 미포함 3자리 
	cout.precision(3);
	cout << d << "\n";
	
	cout.unsetf(ios::fixed);
	//정수부 포함 3자리  
	cout.precision(3);
	cout << d << "\n";
	
	cout.precision(4);
	cout << d << "\n";
}

void input_double_test(){
	double d;
	cin >> d;
	cout << d << "\n";
		
} 

int main(){
	print_double_test();
	input_double_test();
	return 0;
}
