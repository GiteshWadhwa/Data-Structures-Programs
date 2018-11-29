#include<iostream>
using namespace std;

int* insertionSort(int a[],int size)
{
	int num,i,j;
	for(int i=1;i<size;i++) {

		num = a[i];
		j = i-1;

		while(j>=0 && a[j]>num) {

			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = num;
	}
	return a;
};

int main()
{
	int n,ent;
	cout<<"Enter size of array\n";
	cin>>n;
	int *arr = new int[n+1];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	arr = insertionSort(arr,n);

	cout<<"Insertion sort:-\n";

	for(int i=0;i<n;i++)
	{

		cout<<arr[i]<<"\t";
	}

	cout<<"\nEnter a number to enter in array\n";
	cin>>ent;
	arr[n] = ent;
	arr = insertionSort(arr,n+1);

	cout<<"Insertion sort:-\n";
	for(int i=0;i<n+1;i++)
	{
		cout<<arr[i]<<"\t";
	}
}
