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
//	// ����ü�� ����Ʈ���� ǥ�� 
//	cout << "==="<< __func__ << "===\n";
//}

void oneArrayBinaryTreeTest(){
	// �迭 �ϳ��� ����Ʈ���� ǥ�� 
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
	// �� ����Ʈ�� : ��尡 0�� Ȥ�� 2���� �ڽĳ�带 ����  (1���� ������ ����) 
	// ���� ����Ʈ�� : ������尡 ���ʺ��� �� ������.
	// ��ȭ: ��� ���γ���� �ڽ��� 2����  
	// ����: ���� ������ �ڽ�Ʈ���� ���� ���̸� �ִ� 1��ŭ�� ���  
	// AVL �� Red-Black Ʈ���� ���� ���� Ʈ���Դϴ�.
	oneArrayBinaryTreeTest();
	return 0; 
}
