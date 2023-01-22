#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void printArray(int* arr, int size){
	printf("[");
	for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
	printf("]\n");
}

void arrayInitTest(){
	cout << "\n=====" << __func__ << "=====\n";
	int a[] = {1,2,3};
	int aa[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
	printArray(a,sizeof(a)/ sizeof(int));
}

void arrayInitWithMemsetTest(){
	cout << "\n=====" << __func__ << "=====\n";
    int N = 15;
    int arr[15][15];
    memset(arr, -1, sizeof(arr[0][0]) * 15 * 15);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

void unsignedCharArrayTest(){
	printf("\n=====%s=====\n", __func__);
	// https://github.com/t0e8r1r4y/C-CPLUS/blob/main/C_LANG/C.md
	// https://linux.die.net/man/  C�� �Լ��� 
	// ���ڿ� ?  

    unsigned char src[62];
    unsigned char dest[62];
    memset(src, 0, sizeof(src));
    unsigned char *pp = src;

    *pp++ = 0x02; // �������� ó�� �ʿ��� ������ ä������ �� �ִ�. -> �Ƹ��� �������� append �޼������ �̷������� ������ �� ����.
    *pp++ = 0x0A;
    *pp++ = 0x0B;
    *pp++ = 0x0C;
    *pp++ = 0x0D;
    *pp++ = 0x03;
    *pp++ = 0x00;
    
    memcpy(dest, src, strlen( (char *) src));

    for(int i = 0; i < strlen((char *)dest); i++){
    	// X: 16���� 02 : �ڸ��� ( 0�� �־�� ���ڸ� ä����) 
    	// �ڸ��� ���� ��°� �߿��� 
        printf("%02X ", dest[i]);
    }
}

void findMinValueArrayTest(){
	cout << "\n=====" << __func__ << "=====\n";
	int a[] = {21,11,3,4};
	int min_value_index = min_element(a, a+4) - a;
	int min_value = *min_element(a, a+4);
	cout << min_value_index << " : " << min_value;
} 

int main(){
	arrayInitTest();
	arrayInitWithMemsetTest();
	unsignedCharArrayTest();
	findMinValueArrayTest();
	return 0;
}
