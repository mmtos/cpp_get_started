#include <iostream>

using namespace std;

//typedef struct BinaryNode{
//	int data; 
//	BinaryNode* left;
//	BinaryNode* right;
//} BinaryNode;
//
//BinaryNode* createRoot(int data){
//	BinaryNode* rtn = (BinaryNode*) malloc(sizeof(BinaryNode));
//	rtn -> data = data;
//	rtn -> left = NULL;
//	rtn -> right = NULL;	
//	return rtn;
//}
//
//void BinaryNodeTest(){
//	// 구조체로 이진트리를 표현 
//	cout << "==="<< __func__ << "===\n";
//}

void oneArrayBinaryTreeTest(){
	// 배열 하나로 이진트리를 표현 
	cout << "==="<< __func__ << "===\n";
	const int ARRAY_SIZE = 10;
	int tree[ARRAY_SIZE];
	
	fill(tree, tree + ARRAY_SIZE,-1);
	
	int root_index = 1;
//	int* root_pointer = &tree[root_index];
//	*root_pointer = 2;

	tree[root_index] = 2;
	int left = 2 * root_index;
	tree[left] = 3;
	int right = 2 * root_index + 1;
	tree[right] = 4;
	
	for(int i=0; i< ARRAY_SIZE; i++) cout << tree[i] << ",";
}

int main(){
	// 진 이진트리 : 노드가 0개 혹은 2개의 자식노드를 가짐  (1개는 허용되지 않음) 
	// 완전 이진트리 : 리프노드가 왼쪽부터 쭉 차있음.
	// 포화: 모든 내부노드의 자식이 2개임  
	// 균형: 왼쪽 오른쪽 자식트리의 높이 차이를 최대 1만큼만 허용  
	// AVL 및 Red-Black 트리는 균형 이진 트리입니다.
	oneArrayBinaryTreeTest();
	return 0; 
}
