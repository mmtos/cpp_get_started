#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
	for(int i : v){
		cout << i << " ";
	}
	cout << "\n";
}
void basicOperationTest(){
	cout << "\n=====" << __func__ << "=====\n";
	
	//랜덤접근 가능, 맨앞, 맨뒤 요소 삽입삭제 O(1)
	//중간 요소 삽입삭제 O(n) 
	vector<int> v;
	for(int i = 1; i <= 10; i++){
		v.push_back(i);
	}
	cout << &v << "\n";
	printVector(v);
	
	v.pop_back();
	printVector(v);
	
	v.erase(v.begin(), v.begin() + 1 );
	printVector(v);
	
	// auto : 자료형 추론  https://dydtjr1128.github.io/cpp/2019/06/04/Cpp-auto.html
	// find (ns : algorithm)
	auto a = find(v.begin(), v.end(), 100);
	if(a == v.end()) cout << "not found" << "\n";

	// fill (ns : algorithm)
	fill(v.begin(), v.end(), 10);
	printVector(v);
	
	// clear
	v.clear();
	printVector(v);
	cout << v.size() << "\n";
}

vector<int> createVectorWithInitValues(int size, int initValue){
	return vector<int>(size,initValue);
}

// 매개변수 배열에 크기를 지정하는게 특이함. 지정 안해도 돌아감 , 길이 달라도 들어감  
void changeVectorArray(vector<int> v[20]){
	v[0][0] = 1000;
}

void changeTwoDepthVector(vector<vector<int>> &vv){
	vector<int> v;
	v.push_back(10000);
	vv.push_back(v);
}

void vectorListTest(){
	
	cout << "\n=====" << __func__ << "=====\n";
	
	vector<int> va[10];
	va[0].push_back(100);
	changeVectorArray(va);
	printVector(va[0]);
	
	vector<vector<int>> vv;
	changeTwoDepthVector(vv);
	printVector(vv[0]);
}

void createVectorTest(){
	
	cout << "\n=====" << __func__ << "=====\n";
	
	// 크기가 5이며 초기값이 100인 vector를 선언
	vector<int> vi = createVectorWithInitValues(5,100);
	printVector(vi);
	
	vector<int> v2[10];
	cout << "v2" << "\n";
	for(vector<int> v : v2){
		printVector(v);
	}
	
	//vector로 2차원 배열 만들기
	vector<vector<int>> v3;
	cout << "v3" << "\n";
	for(vector<int> v : v3){
		printVector(v);
	}
	
	// 크기 10 * 10, 초기값은 0 2차원 vector 만들기
	vector<vector<int>> v4(10, vector<int>(10, 0));
	cout << "v4" << "\n";
	for(vector<int> v : v4){
		printVector(v);
	}
}

int main(){
	
	basicOperationTest();
	
	vectorListTest();
	
	createVectorTest();
	
	return 0; 
}



