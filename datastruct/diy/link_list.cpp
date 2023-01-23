#include <algorithm>
#include <iostream>

using namespace std;

const int MX = 1000005;

int dat[MX], pre[MX], nxt[MX];
int unused; //비어있는 인덱스 
 
void create_test_dummy(){
	fill(pre,pre + MX, -1);
	fill(nxt,nxt + MX, -1);
	
	// 0번지는 더미 (원소가 아예없는경우의 예외처리를 간단하게 만들기 위해서) 
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
	
	// 다음 노드가 있는 경우에만. 
	if(temp != -1) pre[temp] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr){
	// 이미 주소값으로 쓰이는 인덱스를 전달 받았으므로 앞에서 부터 찾을 필요 없음 
//	int cur = nxt[0];
//	while(cur != addr) {
//		cur = nxt[cur];	
//		if(cur == -1) return;
//	}
	int prev_node = pre[addr];
	int next_node = nxt[addr];
	nxt[prev_node] = next_node;
	if(next_node != -1) pre[next_node] = prev_node;
	
	// 어차피 addr은 재활용하지 않을거라 -1로 초기화할 필요가 없음.
	// 문제에서 요구하는 연결리스트의 최대값만큼 배열을 선언하면 됨 
//	dat[addr] = -1;
//	pre[addr] = -1;
//	nxt[addr] = -1;
}

int main(){
	// 야매 이중연결리스트 
	// 메모리 누수때문에 실무에서는 사용하지 말것
	// 포인터 대신, 배열의 인덱스로 관리 
	create_test_dummy();
	traverse();
	insert(1, 88);
	insert(1, 99);
	traverse();
	erase(1);
	traverse();
	return 0; 
}

