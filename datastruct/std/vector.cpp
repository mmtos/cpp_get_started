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
	
	//�������� ����, �Ǿ�, �ǵ� ��� ���Ի��� O(1)
	//�߰� ��� ���Ի��� O(n) 
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
	
	// auto : �ڷ��� �߷�  https://dydtjr1128.github.io/cpp/2019/06/04/Cpp-auto.html
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

// �Ű����� �迭�� ũ�⸦ �����ϴ°� Ư����. ���� ���ص� ���ư� , ���� �޶� ��  
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
	
	// ũ�Ⱑ 5�̸� �ʱⰪ�� 100�� vector�� ����
	vector<int> vi = createVectorWithInitValues(5,100);
	printVector(vi);
	
	vector<int> v2[10];
	cout << "v2" << "\n";
	for(vector<int> v : v2){
		printVector(v);
	}
	
	//vector�� 2���� �迭 �����
	vector<vector<int>> v3;
	cout << "v3" << "\n";
	for(vector<int> v : v3){
		printVector(v);
	}
	
	// ũ�� 10 * 10, �ʱⰪ�� 0 2���� vector �����
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


