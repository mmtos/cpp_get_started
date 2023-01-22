#include <iostream>

#include <queue>
using namespace std;

// ������ �迭�� ����Ʈ���� ǥ�� (left child, right child, parent, depth ��)
// 1�� ��尡 root, 0�� �ε����� �����
int lc[] = {0,2,4,6,0,0,0,0,0};
int rc[] = {0,3,5,7,0,8,0,0,0};
int p[9];

void bfs(){
	cout << "\n==="<< __func__ << "===\n";
	// level order traversal
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		cout << cur << " ";
		// ���� �ڽ��� �ִٸ� 
		if(lc[cur]) q.push(lc[cur]);
		// ������ �ڽ��� �ִٸ� 
		if(rc[cur]) q.push(rc[cur]);
	}
}

void pre_order_traversal(int subtree_root){
	// dfs�� ��� 
	cout << subtree_root << " ";
	if(lc[subtree_root]) pre_order_traversal(lc[subtree_root]);
	if(rc[subtree_root]) pre_order_traversal(rc[subtree_root]);
}
void in_order_traversal(int subtree_root){
	if(lc[subtree_root]) in_order_traversal(lc[subtree_root]);
	cout << subtree_root << " ";
	if(rc[subtree_root]) in_order_traversal(rc[subtree_root]);
}
void post_order_traversal(int subtree_root){
	if(lc[subtree_root]) post_order_traversal(lc[subtree_root]);
	if(rc[subtree_root]) post_order_traversal(rc[subtree_root]);
	cout << subtree_root << " ";
}
void multiArrayBinaryTreeTest(){
	bfs();
	cout << "\n==="<< "pre_order_traversal" << "===\n";
	pre_order_traversal(1);
	cout << "\n==="<< "in_order_traversal" << "===\n";
	in_order_traversal(1);
	cout << "\n==="<< "post_order_traversal" << "===\n";
	post_order_traversal(1);
}

int main(){
	// https://blog.encrypted.gg/1019
	// 11725
	multiArrayBinaryTreeTest();
	return 0; 
}
