#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class LinkedList
{
	node *head;
	public:
	LinkedList() {

		head = NULL;
	}

	void createnode(int val) {

		node *n;
		n = (struct node*)malloc(sizeof(node));
		n->data = val;
		n->next = NULL;
		head = n;
	}

	void insertatbeg(int val) {

		if(head == NULL)
			createnode(val);
		else
		{
			node * firstnode;
			firstnode = (struct node*)malloc(sizeof(node));
			firstnode->data = val;
			firstnode->next = head;
			head = firstnode;
		}
	}

	void traverse() {

		struct node *cur;
		for(cur = head ; cur != NULL;cur = cur->next)
			 cout<<cur->data<<"\t";
		cout<<endl;
	}
	int deletionfrombeg()
	{
		node *temp;
		int n;
		temp = head;
		n = temp->data;
		head = temp->next;
		free(temp);
		return n;
	}
	int Head() {

		return head->data;
	}
};

class StackUsingLL
{
	LinkedList LL;
	public:
	void push(int num)
	{
		LL.insertatbeg(num);
	}
	int pop()
	{
		return LL.deletionfrombeg();
	}
	void peep() {
		cout<<LL.Head()<<" is the top of stack\n";
	}
	void display()
	{
		LL.traverse();
	}
};

int main()
{
	StackUsingLL s;
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

