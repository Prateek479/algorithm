#include<iostream>
#include<conio.h>

using namespace std;

void merge(int a[],int temp[],int left,int mid,int right);

void mergesort(int a[],int temp[],int low,int high)
{
	int mid;
	if(low < high ){
		
		mid=(int)(high+low)/2;
		mergesort(a,temp,low,mid);
		mergesort(a,temp,mid+1,high);
		merge(a,temp,low,mid+1,high);
	}
}

void merge(int a[],int temp[],int left,int mid,int right)
{
	int i,left_end,size,temp_pos;
	left_end=mid-1;
	size=right-left+1;
	temp_pos=left;
	while((left <= left_end) && (mid<=right)){
		if(a[left]<=a[mid]){
			temp[temp_pos]=a[left];
			temp_pos=temp_pos+1;
			left=left+1;
		}
		else{
			temp[temp_pos]=a[mid];
			mid=mid+1;
			temp_pos=temp_pos+1;
		}
	}
	
	while(left<=left_end)
	{
		temp[temp_pos]=a[left];
		left=left+1;
		temp_pos=temp_pos+1;
	}
	
	while(mid<=right)
	{
		temp[temp_pos]=a[mid];
		mid=mid+1;
		temp_pos=temp_pos+1;
	}
	
	for(int i=0;i<=size;i++){
		a[right]=temp[right];
		right=right-1;
	}
}

int main(){
	int a[]={5,4,9,8,7,1,2,0,3,6};
	int temp[10];
	mergesort(a,temp,0,9);
	for(int i=0;i<=9;i++)
		cout<<a[i];
	return 0;
}
