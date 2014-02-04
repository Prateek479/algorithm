#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main(){
	std::string s;
	std::string s1;
	int res;
	cin>>s;
	cin>>s1;
		res=s.compare(s1);
		cout<<res;
	return 0;
}
