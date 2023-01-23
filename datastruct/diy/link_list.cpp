#include <algorithm>
#include <iostream>

using namespace std;

const int MX = 1000005;

int dat[MX], pre[MX], nxt[MX];
int unused; //����ִ� �ε��� 
 
void create_test_dummy(){
	fill(pre,pre + MX, -1);
	fill(nxt,nxt + MX, -1);
	
	// 0������ ���� (���Ұ� �ƿ����°���� ����ó���� �����ϰ� ����� ���ؼ�) 
	dat[0] = -1;
	nxt[0] = 2;
	
	dat[2] = 13;
	pre[2] = 0;
	nxt[2] = 1;
	
	dat[1] = 65;
	pre[1] = 2;
	nxt[1] = 4;
	
	dat[4] = 21;
	pre[4] = 1;
	nxt[4] = 5;
	
	dat[5] = 17;
	pre[5] = 4;
	
	unused = 6;
}

void traverse(){
	cout << "\n=====" << __func__ << "=====\n";
	int cur = nxt[0];
	while(cur != -1){
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	} 
	cout << "\n";
}

void insert(int addr, int num){
//	int cur = nxt[0];
//	while(cur != addr) cur = nxt[cur];
	int temp = nxt[addr];
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = temp;
	
	// ���� ��尡 �ִ� ��쿡��. 
	if(temp != -1) pre[temp] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr){
	// �̹� �ּҰ����� ���̴� �ε����� ���� �޾����Ƿ� �տ��� ���� ã�� �ʿ� ���� 
//	int cur = nxt[0];
//	while(cur != addr) {
//		cur = nxt[cur];	
//		if(cur == -1) return;
//	}
	int prev_node = pre[addr];
	int next_node = nxt[addr];
	nxt[prev_node] = next_node;
	if(next_node != -1) pre[next_node] = prev_node;
	
	// ������ addr�� ��Ȱ������ �����Ŷ� -1�� �ʱ�ȭ�� �ʿ䰡 ����.
	// �������� �䱸�ϴ� ���Ḯ��Ʈ�� �ִ밪��ŭ �迭�� �����ϸ� �� 
//	dat[addr] = -1;
//	pre[addr] = -1;
//	nxt[addr] = -1;
}

int main(){
	// �߸� ���߿��Ḯ��Ʈ 
	// �޸� ���������� �ǹ������� ������� ����
	// ������ ���, �迭�� �ε����� ���� 
	create_test_dummy();
	traverse();
	insert(1, 88);
	insert(1, 99);
	traverse();
	erase(1);
	traverse();
	return 0; 
}

