#include <iostream>	
#include <math.h>

using namespace std;

bool issquare(int x){
	int s=sqrt(x);
	cout<<x<<endl;
	cout<<s*s<<endl;
	return (s*s == x );
	
}

bool isfibo(int n)
{
	return issquare(5*n*n + 4) || issquare(5*n*n - 4);
}
int main() {
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		if(isfibo(n))
			cout<<"IsFibo";
		else
			cout<<"IsNotFibo";
	}	
	return 0;
}
