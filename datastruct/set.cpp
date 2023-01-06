#include<bits/stdc++.h>
using namespace std;

// 중복 불가, 자동정렬
void setTest(){ 
	set<int> s;
	s.insert(12);
	s.insert(10);
	s.insert(2);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(90);
	s.insert(85);
	s.insert(45);
	cout << "set elements after insert\n";
	for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
	cout << '\n';
	
	auto it1 = s.find(10);
	auto it2 = s.find(90);
	
	// [ , ) 
	s.erase(it1, it2);
	
	cout << "set elements after erase\n";
	for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
	cout << '\n';
}

// 중복 허용, 자동정렬
void multiSetTest(){
	multiset<int> s;
	s.insert(12);
	s.insert(10);
	s.insert(2);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(90);
	s.insert(85);
	s.insert(45);
	cout << "Multiset elements after insert\n";
	for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
	cout << '\n';
	
	auto it1 = s.find(10);
	auto it2 = s.find(90);
	
	// [ , ) 
	s.erase(it1, it2);
	
	cout << "Multiset elements after erase\n";
	for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
	cout << '\n';
	
}

int main(){
	cout << "\n===setTest===\n";
	setTest();
	cout << "\n===multiSetTest===\n";
	multiSetTest();
	return 0;
}
