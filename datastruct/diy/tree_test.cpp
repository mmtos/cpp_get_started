#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> adj[10];
int size, parent[10],depth[10];

void build_graph(){
	size = 8;
	// https://blog.encrypted.gg/1019
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(6);
	adj[6].push_back(7);
	adj[6].push_back(8);
	
	// ������(����� ó��)
	adj[2].push_back(1);
	adj[3].push_back(1);
	adj[4].push_back(1);
	adj[5].push_back(2);
	adj[6].push_back(4);
	adj[7].push_back(6);
	adj[8].push_back(6);
}

void clear_tree(){
	fill(parent,parent +10, 0);
	fill(depth,depth +10, 0);
}

void print_tree(){
	cout << "parent array\n";
	for(int i=1; i<=size; i++) cout << parent[i] << " ";
	cout << "\n";
	cout << "depth array\n";
	for(int i=1; i<=size; i++) cout << depth[i] << " ";
	cout << "\n";
	
}

void bfs(int root){
	cout << "\n=====" << __func__ << "=====\n";
	queue<int> q;
	q.push(root);
	parent[root] = 0;
	while(!q.empty()){
		int curr = q.front(); q.pop();
		cout << curr << " ";
		for(int next: adj[curr]){
			// �θ� ���� �ϳ��� ������ �ڽ������鸸 ť�� �ִ´�. 
			if(parent[curr] == next) continue;
			//Ʈ���� ���� ������ �湮�ϰ� �ȴ�.
			q.push(next);
			parent[next] = curr;
			depth[next] = depth[curr] + 1; 
		}
	}
	cout << "\n";
	
	print_tree();
	clear_tree();
}

void dfs(int root){
	cout << "\n=====" << __func__ << "=====\n";
	stack<int> stk;
	stk.push(root);
	parent[root] = 0;
	while(!stk.empty()){
		int curr = stk.top(); stk.pop();
		cout << curr << " ";
		for(int next: adj[curr]){
			// �θ� ���� �ϳ��� ������ �ڽ������鸸 ť�� �ִ´�. 
			if(parent[curr] == next) continue;
			//Ʈ���� ���� ������ �湮�ϰ� �ȴ�.
			stk.push(next);
			parent[next] = curr;
			depth[next] = depth[curr] + 1; 
		}
	}
	cout << "\n";
	print_tree();
	clear_tree();
} 


void dfs_recur(int sub_tree_root){
	cout << sub_tree_root << " ";
	for(int next : adj[sub_tree_root]){
		if(parent[sub_tree_root] == next) continue;
		parent[next] = sub_tree_root;
		depth[next] = depth[sub_tree_root] + 1; 
		dfs_recur(next);
	}
}

void dfs_recur_test(){
	cout << "\n=====" << __func__ << "=====\n";
	dfs_recur(1);
	
	cout << "\n";
	print_tree();
	clear_tree();
}

int main(){
	// #�ڷᱸ�� #Ʈ��
	build_graph();
	
	// � ������ ��Ʈ�� ��Ƶ� ��� Ʈ���� �ȴ�.
	bfs(1);
	dfs(1);
	
	bfs(2);
	bfs(3);
	
	dfs_recur_test();
	
}
