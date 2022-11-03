#include <bits/stdc++.h>
using namespace std;


void printArray(int arr[], int size){
//	cout << arr << "k\n";  // 배열의 첫번째 원소의 주소값 
//	cout << &arr << "kk\n"; // 배열 자체를 가리킴 
//	cout << arr + 1 << "kkk\n";  // +4 
//	cout << &arr + 1 << "kkkk\n"; // +8
	
	cout << sizeof(arr) << '\n'; // 8 byte : 64bit
	
	printf("%p a\n",arr);
	printf("%p aa\n",&arr);
	printf("%d a\n",sizeof(arr));
	printf("%d aa\n",sizeof(&arr));
	
	for(int i =0 ; i < size ; i++){
		cout << arr[i] << " ";
	}	
	cout << '\n';
}

void printArray(int *arr){
	cout << '\n';
	cout << '\n';
	cout <<  sizeof(arr) << '\n';
	for(int i = 0 ; i < sizeof(arr); i++){
		cout << arr[i] << " ";
	} 
	cout << '\n';
}

//void printArray(){
//	int a[5];
//	fill(a, a+5, 3);
//	for(int i : a){
//		cout << i << " ";
//	} 
//	cout << '\n';
//}

void basicOperation(){
	// 배열의 크기는 보통 문제에서 요구하는 최대 크기로 정의 
	int arrSize = 15;
	int a[arrSize];
	for(int i=1; i<=arrSize; i++) {
		a[i-1] = i;
	}
	// 중현이한테 물어보기.  
	printArray(a,arrSize);
	
	int *lastAddr = a + arrSize -1;
	*lastAddr= 999;
	printf("%d\n",*lastAddr);
	printf("%p\n",lastAddr);
	
	int *endArr = a + arrSize;
	printf("%d\n",*endArr); // 왜 항상 4 * 10 ?  우연의 일치였음 정상적으로 쓰레기값 나옴. 
	printf("%p\n",endArr);
	
	auto fi = find(a, a+arrSize, 100);
	if(fi == lastAddr){
		cout << "not found" << "\n";
	}
	
	fill(a, endArr, 10);
	printArray(a,arrSize);
} 

void initArray(){
	// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=smilennv&logNo=220295865481
	int arr[10][10];
	int* firstArrayPointer = arr[0];
	// 중요한 점은 fill로 초기화를 걸 때는 선언한 배열의 크기 전체를 초기화해야 한다는 점입니다
	// 왜? 
	fill(firstArrayPointer,firstArrayPointer + 10*10 , 3);
	printArray(firstArrayPointer,10);
}

void initArrayByMemset(){
	vector<int> v[10];
	cout << sizeof(v) << '\n';
	// 벡터 배열 초기화 ( 0만 됨 )  
	memset(v, 0, sizeof(v)); 
}

void copyArray(){
	int a[5];
	int copy[5];
	int copy2[5];
	cout << a << '\n';
	cout << sizeof(a) << '\n'; //20
	
	fill(a, a+5, 3);
	fill(copy, copy+5, -1);
	fill(copy2, copy2+5, -2);
	
	printArray(a,5);
	printArray(copy,5);
	printArray(copy2,5);
	
	memcpy(copy,a,sizeof(a));
	printArray(copy,5);
}

void printArrayTest(){
	cout << "copyArray2" << '\n';
	int org[10];
	int copy[10];
	int copy2[10];
	
	// https://msh1307.tistory.com/46
	/*
	 arr: 0x70fd90   타입: int* 
	 &arr: 0x70fd70 타입: int*[size] 
	 4바이트 차이  
	*/
	
	cout << org << "\n"; // 배열의 첫번째 원소의 주소값 
	cout << &org << "\n"; // 배열 자체를 가리킴 
	cout << org + 1 << "\n";
	cout << &org + 1 << "\n";
	cout << copy << "\n";
	cout << &copy << "\n";
	cout << copy2 << "\n";
	cout << &copy2 << "\n";
	
	
	printf("%d a\n",sizeof(org));
	printf("%d aa\n",sizeof(&org));
}

// 데이터추가와 삭제를 많이 하는 것은 연결 리스트, 탐색을 많이 하는 것은 배열
int main(){
//	basicOperation();
//	initArray();
//	initArrayByMemset();
	copyArray();
	printArrayTest();
	
}
