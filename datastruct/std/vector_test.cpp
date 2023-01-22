#include<bits/stdc++.h>
using namespace std;

void vectorSumTest(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v.begin(), v.end(),0);
	cout << sum << '\n';
}

void vectorMaxMinTest(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto max = max_element(v.begin(), v.end());
	cout << *max << '\n';
	
	auto min = min_element(v.begin(), v.end());
	cout << *min << '\n';
}

//[Error] declaration of 'a' as multidimensional array 
//must have bounds for all dimensions except the first
void change(int a[][5]){
	a[0][4] = 999;
}

void array2DmodifyTest(){
	int a[3][5] = {
	{ 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 },
	{ 11, 12, 13, 14, 15 }
	};
	change(a);
	cout << a[0][4] << "\n";
}


void print2DArray(vector<vector<int>> &vv){
	for(vector<int> v : vv){
		cout << "[";
		for(int i : v){
			cout << i << ", ";
		}
		cout << "]\n";
	}
	cout << "\n";
}

void rotateCounterClockwise(vector<vector<int>> &key){
	int m = key.size();
	if( m == 0 ) return;
	vector<int> v = key[0];
	int n = v.size();
	
	// n,m matrix
	vector<vector<int>> temp(n, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// n = m = 3인 경우, 
			/* 
			 // 1행 
			 0,0 -> 2,0
			 0,1 -> 1,0
			 0,2 -> 0,0
			 
			 // 1열 
			 0,0 -> 2,0
			 1,0 -> 2,1
			 2,0 -> 2,2 
			*/
			temp[n-j-1][i] = key[i][j];
		}
	}
	key = temp;
	return;
}

void rotateClockwise(vector<vector<int>> &key){
	int m = key.size();
	if( m == 0 ) return;
	vector<int> v = key[0];
	int n = v.size();
	
	// n,m matrix
	vector<vector<int>> temp(n, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// n = m = 3인 경우, 
			/* 
			 // 1행 
			 0,0 -> 0,2
			 0,1 -> 1,2
			 0,2 -> 2,2
			 
			 // 1열 
			 0,0 -> 0,2
			 1,0 -> 0,1
			 2,0 -> 0,0 
			*/ 
			temp[j][m-i-1] = key[i][j];
		}
	}
	key = temp;
	return;
}

void matrixRotateTest(){
	vector<vector<int>> vv = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
	};
	print2DArray(vv);
	rotateCounterClockwise(vv);
	print2DArray(vv);
	rotateClockwise(vv);
	print2DArray(vv);
}


void vectorFindTest(){
	cout << "\n=====" << __func__ << "=====\n";
	vector<int> a = {1,2,3};
	auto it = find(a.begin(),a.end(),3);
	if(it == a.end()){
		cout << "not found";
	}else{
		cout << find(a.begin(),a.end(),3) - a.begin() <<"\n";
	}
	
}

void vectorCopyTest(){
	// https://terrorjang.tistory.com/85
	cout << "\n=====" << __func__ << "=====\n";
	vector<int> a = {1,2,3};
	vector<int> b,c;
	// resize 필수  
	b.resize((int)(a.size()));
	copy(a.begin(),a.end(),b.begin());
	for(int i:b) cout << i <<", ";
	cout << "\n";
	
	
	c.assign(a.begin(),a.end());
	for(int i:c) cout << i <<", ";
	cout << "\n";
}

void vectorPeekTest(){
	cout << "\n=====" << __func__ << "=====\n";
	vector<int> a = {1,2,3};
	cout << a.front() << "\n";
	cout << a.back() << "\n";
}

int main(){
	cout << "\n===vectorSumTest===\n";
	vectorSumTest();
	cout << "\n===vectorMaxMinTest===\n";
	vectorMaxMinTest();
	cout << "\n===array2DmodifyTest===\n";
	array2DmodifyTest();
	cout << "\n===matrixRotateTest===\n";
	matrixRotateTest();
	
	vectorFindTest();
	vectorCopyTest();
	vectorPeekTest();
	return 0;
}

