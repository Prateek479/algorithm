#include <iostream>	
#include <math.h>
#include<vector>
#include<algorithm>

using namespace std;

#define all(a)  a.begin(),a.end() 
#define L1 1000000000000LL

void value(vector<long long> &a,long long n){
	a.push_back(n);
	if(n<L1){
		value(a,n*10);
		value(a,n*10+9);
	}
}

int main() {
	int t,n;
	cin>>t;
	long long num=9;
	vector <long long> a;
	value(a,num);
	sort(all(a));
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int i=0;i<a.size();i++){
			
			if(a[i] % n == 0){
				cout<<a[i];
				break;
			}
		}
		
	}	
	return 0;
}
