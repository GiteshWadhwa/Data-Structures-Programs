#include<iostream>
using namespace std;
class Stack {
	int *arr;
	int size;
	int top;
	public:
	Stack()
	{
		cout<<"Enter size of array stack\n";
		cin>>size;
		top=-1;
		arr=new int[size];
	}
	void push(int item)
	{
		if(top==size)
			cout<<"Overflow\n";
		else
		{
			top++;
			arr[top]=item;
			cout<<"Element pushed\n";
		}
	}
	int pop()
	{
		int temp;
		if(top==-1)
			cout<<"Underflow\n";
		else
		{
			temp=arr[top];
			top--;
		}
		return temp;
	}
	int peep()
	{
		cout<<arr[top]<<" is top of the stack"<<endl;
	}
	void show()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	Stack s;
	cout<<"Enter a number to perform following operations:-\n1)PUSH\t2)POP\t3)DISPLAY TOP\t4)EXIT\n";
	int choice,num;
	cin>>choice;
	while(choice!=4) {

		switch(choice) {

			case 1:cout<<"Enter a number to push in stack\n";
					cin>>num;
					s.push(num);
					break;
			case 2:s.pop();
					cout<<"Element poped\n";
					break;
			case 3:s.peep();
					break;
			case 4:break;
			case 5:cout<<"Invalid number entered\n";
		}
		cout<<"-----------------------------------------\n";
		cin>>choice;
	}
	return 0;
}

