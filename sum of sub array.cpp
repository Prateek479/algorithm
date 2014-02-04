 #include <iostream>
using namespace std;
int max(int a,int b)
{
	return (a<=b?b:a);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	int op=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(sum+arr[i]>0)
		{
			sum+=arr[i];
		}
		op=max(sum,op);
	}
	
	cout<<op;	
	
    return 0;
}

