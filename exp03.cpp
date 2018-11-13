#include<iostream>
using namespace std;

class Array
{
	int *arr,size;
	public:
		void getArr()
		{
			cout<<"Enter size of Array\n";
			cin>>size;
			arr=new int[size];
			cout<<"Enter elements for Array\n";
			for(int i=0;i<size;i++)
			{
				cin>>*(arr+i);
			}
		}


		void binarySearch()
		{
			int val,flag=0,mid;
			int ub=size;
			int lb=0;
			bubbleSort();
			cout<<"Enter element to search in the array\n";
			cin>>val;
			while(lb<=ub)
			{
				mid=int((ub+lb)/2);
				if(arr[mid]==val)
				{
					cout<<"Element found at "<<mid<<" index\n";
					flag=1;
					break;
				}
				else
				{
					if(val<arr[mid])
					{
						ub=mid-1;
					}
					else
					{
						lb=mid+1;
					}
				}
			}
			if(flag==0)
			{
				cout<<"Element not found\n";
			}
		}


		void printArr()
		{
			for(int i=0;i<size;i++)
			{
				cout<<*(arr+i)<<" ";
			}
			cout<<endl;
		}


		void bubbleSort() {

			for(int i=0;i<size;i++) {

				for(int j=1;j<(size-i);j++) {

					if(arr[j-1] > arr[j]) {

						int temp = arr[j-1];
						arr[j-1] = arr[j];
						arr[j] = temp;
					}
				}
			}
			printArr();
		}
};


int main()
{
	Array a;
	a.getArr();
	a.binarySearch();
	a.printArr();
	return 0;
}
