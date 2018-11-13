#include<iostream>
using namespace std;

int Pivot(int a[],int lb,int ub)
{
	int left =lb;
	int right = ub;
	int loc = lb;
	while((a[loc]<=a[right]) && (loc!=right))
	{
		right=right-1;
	}

	if(loc==right)
	{
		return loc;
	}

	int temp = a[loc];
	a[loc] = a[right];
	a[right] = temp;
	loc = right;

	while((a[left]<=a[loc]) && (loc!=left))
	{
		left=left+1;
	}

	if(loc==left)
	{
		return loc;
	}
	
	temp = a[loc];
	a[loc] = a[left];
	a[left] = temp;
	loc = left;
}

void quicksort(int a[], int lb, int ub)
{
	int p;
	if(lb<ub)
	{
		p=Pivot(a,lb,ub);
		quicksort(a,lb,p-1);
		quicksort(a,p+1,ub);
	}
}

int main()
{
	int n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter Array Elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
