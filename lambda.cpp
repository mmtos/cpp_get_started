#include<bits/stdc++.h>

using namespace std;
int main(){
	string a = "bde";
	string b = "cae";
	cout << (a[2] == b[2]) << "\n";
	cout << (a[1]<b[1]) << "\n";
	cout << (a[0]<b[0]) << "\n";
	
	vector<string> strings = {"bde", "cae"};
	int n = 1;
	auto cmpLambda = [=](string a, string b){
        if(a[n] == b[n]) return a < b;
        return a[n] < b[n];
    };
    sort(strings.begin(),strings.end(),cmpLambda);
    for(string c : strings) cout << c << ",";
	return 0;
}

