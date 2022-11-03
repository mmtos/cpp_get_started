#include <bits/stdc++.h>
using namespace std;


void printArray(int arr[], int size){
//	cout << arr << "k\n";  // �迭�� ù��° ������ �ּҰ� 
//	cout << &arr << "kk\n"; // �迭 ��ü�� ����Ŵ 
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
	// �迭�� ũ��� ���� �������� �䱸�ϴ� �ִ� ũ��� ���� 
	int arrSize = 15;
	int a[arrSize];
	for(int i=1; i<=arrSize; i++) {
		a[i-1] = i;
	}
	// ���������� �����.  
	printArray(a,arrSize);
	
	int *lastAddr = a + arrSize -1;
	*lastAddr= 999;
	printf("%d\n",*lastAddr);
	printf("%p\n",lastAddr);
	
	int *endArr = a + arrSize;
	printf("%d\n",*endArr); // �� �׻� 4 * 10 ?  �쿬�� ��ġ���� ���������� �����Ⱚ ����. 
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
	// �߿��� ���� fill�� �ʱ�ȭ�� �� ���� ������ �迭�� ũ�� ��ü�� �ʱ�ȭ�ؾ� �Ѵٴ� ���Դϴ�
	// ��? 
	fill(firstArrayPointer,firstArrayPointer + 10*10 , 3);
	printArray(firstArrayPointer,10);
}

void initArrayByMemset(){
	vector<int> v[10];
	cout << sizeof(v) << '\n';
	// ���� �迭 �ʱ�ȭ ( 0�� �� )  
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
	 arr: 0x70fd90   Ÿ��: int* 
	 &arr: 0x70fd70 Ÿ��: int*[size] 
	 4����Ʈ ����  
	*/
	
	cout << org << "\n"; // �迭�� ù��° ������ �ּҰ� 
	cout << &org << "\n"; // �迭 ��ü�� ����Ŵ 
	cout << org + 1 << "\n";
	cout << &org + 1 << "\n";
	cout << copy << "\n";
	cout << &copy << "\n";
	cout << copy2 << "\n";
	cout << &copy2 << "\n";
	
	
	printf("%d a\n",sizeof(org));
	printf("%d aa\n",sizeof(&org));
}

// �������߰��� ������ ���� �ϴ� ���� ���� ����Ʈ, Ž���� ���� �ϴ� ���� �迭
int main(){
//	basicOperation();
//	initArray();
//	initArrayByMemset();
	copyArray();
	printArrayTest();
	
}
