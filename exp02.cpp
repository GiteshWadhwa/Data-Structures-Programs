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


		void linearSearch()
		{
			int val,i;
			cout<<"Enter element to search in the array\n";
			cin>>val;
			for(i=0;i<size;i++)
			{
				if(val==*(arr+i))
				{
					cout<<"Element found\n";
					break;
				}
			}
			if(i==size)
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
};

int main()
{
	Array a;
	a.getArr();
	a.linearSearch();
	a.printArr();
	return 0;
}
