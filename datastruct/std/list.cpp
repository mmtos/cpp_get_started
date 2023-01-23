#include <list>
#include <iostream>

using namespace std;

void print(list<int> & l){
	for(int i:l) cout << i << ' ';
	cout << "\n";
}
int main(){
	list<int> L = {2,3};
	list<int>::iterator t = L.begin();
	L.push_front(10);
	cout << *t << '\n'; // 2
	L.push_back(5);
	L.insert(t,6); // 앞쪽에 insert함 
	print(L); //10,6,2,3,5
	t++;
	cout << *t << "\n"; //3
	t = L.erase(t); //지우고 난 다음 노드의 위치 리턴 
	cout << *t << "\n"; //5
	 
	return 0; 
}
