#include<iostream>
using namespace std;
struct node {

	int data;
	node *next;
};

class CQueue
{
	node *front,*rear;
	public:
	CQueue() {
		front = NULL;
		rear = NULL;
	}

	void enqueue(int val) {

		node* newnode = new node();
		newnode->data = val;
		if(front == NULL && rear == NULL) {

			front = newnode;
			rear = front;
			rear->next = front;
		}
		else {

			rear->next = newnode;
			newnode->next = front;
			rear = newnode;
		}
	}

	void dequeue() {

		if(front == NULL) {
			cout<<"Underflow\n";
		}
		else if(rear == front)
		{
			node *temp = rear;
			front = NULL;
			rear = NULL;
			delete temp;
		}
		else{
			node *temp = front;
			front = front->next;
			rear->next = front;
			free (temp);
		}
	}

	void display()
	{
		if(front == NULL && rear == NULL)
			cout<<"Queue is empty\n";
		else {
			node* temp = front;
			do{
				cout<<temp->data<<" ";
				temp = temp->next;
			}while(temp!=front);
			cout<<endl;
		}
	}
};

int main()
{
	CQueue q;
	int choice,num;
	while(true) {

		cout<<"Choose from the following options:-\n1)INSERT\n2)DELETE\n3)PRINT\n4)EXIT\n";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"Enter a number to insert in queue:\n";
				cin>>num;
				q.enqueue(num);
				cout<<"----------------------------------\n";
				break;

			case 2: q.dequeue();
				cout<<"An Element Deleted\n";
				cout<<"----------------------------------\n";
				break;

			case 3:	cout<<"Queue Displayed:-\n";
				q.display();
				cout<<"----------------------------------\n";
				break;

			case 4: cout<<"Program exited\n:-----------------------------------:\n";
				exit(0);
				break;

			default: cout<<"Wrong option entered\n";
				 break;
		}
	}
	return 0;
}
