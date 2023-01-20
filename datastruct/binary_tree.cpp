#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

void arrayTreeTest(){
	cout << "==="<< __func__ << "===\n";
	int tree[ARRAY_SIZE];
	fill(tree, tree + ARRAY_SIZE,INT_MIN);
	
	int root_index = 1;
	int* root_pointer = &tree[root_index];
	*root_pointer = 2;
	
	int left = 2 * root_index;
	tree[left] = 3;
	int right = 2 * root_index + 1;
	tree[right] = 4;
	
	for(int i=0; i< ARRAY_SIZE; i++){
		cout << tree[i] << ",";
	} 
}

typedef struct BinaryNode{
	int data; 
	BinaryNode* left;
	BinaryNode* right;
} BinaryNode;

BinaryNode* createRoot(int data){
	BinaryNode* rtn = (BinaryNode*) malloc(sizeof(BinaryNode));
	rtn -> data = data;
	rtn -> left = NULL;
	rtn -> right = NULL;	
	return rtn;
}

void BinaryNodeTest(){
	cout << "==="<< __func__ << "===\n";
}


int main(){
	// �� ����Ʈ�� : ��尡 0�� Ȥ�� 2���� �ڽĳ�带 ����  (1���� ������ ����) 
	// ���� ����Ʈ�� : ������尡 ���ʺ��� �� ������.
	// ��ȭ: ��� ���γ���� �ڽ��� 2����  
	// ����: ���� ������ �ڽ�Ʈ���� ���� ���̸� �ִ� 1��ŭ�� ���  
	// AVL �� Red-Black Ʈ���� ���� ���� Ʈ���Դϴ�.
	
	arrayTreeTest();
	
	return 0; 
}
