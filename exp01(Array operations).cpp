#include<iostream>
using namespace std;
static int size;

class array1
{
	int *arr;
	int arr_size;

	public:

		array1()
		{
			cout<<"Enter size of array\n";
			cin>>size;
			arr_size = size;
			arr = new int[size+1];
			for(int i=0;i<arr_size;i++)
			{
				cin>>arr[i];
			}
		}


		void printArray()
		{
			for(int i=0;i<arr_size;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}


		void insertion()
		{
			int temp,val,pos;
			cout<<"Enter value to insert:\n";
			cin>>val;
			cout<<"Enter position to insert the element\n";
			cin>>pos;
			arr_size = size+1;
			for(int i=(pos-1);i<arr_size;i++)
			{
				temp=arr[i];
				arr[i]=val;
				val=temp;

			}
			printArray();
		}


		void deletion()
		{
			int pos;
			cout<<"Enter the position to delete an element\n";
			cin>>pos;
			for(int i=pos;i<arr_size;i++)
			{
				arr[i-1]=arr[i];
			}
			arr_size--;
			printArray();
		}


		void findElement()
		{
			int val;
			cout<<"Enter element to find\n";
			cin>>val;
			for(int i=0;i<5;i++)
			{
				if(val==arr[i])
				{
					cout<<"Position of "<<val<<" is "<<i+1<<"\n";
				}
			}
		}
};

int main()
{
	array1 a;
	int choice;
	cout<<"Enter the value to perform following operation:-\n1)INSERT\t2)DELETE\t3)FIND LOCATION\n4)DISPLAY\n";
	cin>>choice;
	switch(choice)
	{
		case 1: a.insertion();
				break;
		case 2: a.deletion();
				break;
		case 3: a.findElement();
				break;
		case 4: a.printArray();
	}
	return 0;
}
