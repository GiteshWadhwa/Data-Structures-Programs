#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class CircularLinkedList
{
	node *head;
	public:
	CircularLinkedList() {

		head = NULL;
	}

	void createnode(int val) {

		node *n;
		n = (struct node*)malloc(sizeof(node));
		n->data = val;
		n->next = n;
		head = n;
	}

	void insertatbeg(int val) {

		if(head == NULL)
			createnode(val);
		else
		{
			node * firstnode,* lastnode;
			firstnode = (struct node*)malloc(sizeof(node));
			lastnode = head;
			while(lastnode->next!=head)
				lastnode = lastnode->next;
			firstnode->data = val;
			firstnode->next = head;
			lastnode->next = firstnode;
			head = firstnode;
		}
	}

	void insertatend(int val)
	{
		node *ptr,*nn;
		nn = (struct node*)malloc(sizeof(node));
		nn->data = val;
		ptr = head;
		while(ptr->next!=head)
			ptr = ptr->next;
		ptr->next = nn;
		nn->next = head;
	}
	void traverse() {

		struct node *cur;
		cur = head ;
		if(head == NULL)
			cout<<"No circular Linked List exists"<<endl;
		else
		{
			do {
				cout<<cur->data<<"\t";
				cur = cur->next;
			}while(cur!=head);
			cout<<endl;
		}
	}

	void insertatloc(int val,int loc)
	{
		node *ptr,*nn;
		nn = (struct node*)malloc(sizeof(node));
		ptr = head;
		for(int i = 1;i < loc-1 && ptr!=NULL;i++)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
			cout<<"Location doesn't exist\n";
		else {
			nn->data = val;
			nn->next = ptr->next;
			ptr->next = nn;
		}
	}
	void deletefrombeg()
	{
		node *temp,*ptr;
		temp = head;
		ptr = head;
		if(head->next == head)
			head = NULL;
		else {
			while(ptr->next!=head)
				ptr = ptr->next;
			ptr->next = head->next;
			head = ptr->next;
		}
		delete (temp);
	}
	void deletefromend()
	{
		node *ptr,*prev;
		ptr = head;
		while(ptr->next!=head)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = head;
		delete (ptr);
	}
	void deleteatloc(int loc)
	{
		node *ptr,*prev;
		ptr = head;
		for(int i = 1;i < loc;i++)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = ptr->next;
		delete (ptr);
	}
	void delete_element(int item)
	{
		node *ptr;
		ptr = head;
		int i = 1;
		if(ptr->data == item) {

			deletefrombeg();
		}
		else {
			ptr = ptr->next;
			while(ptr!=head)
			{
				if(ptr->data == item)
				{
					if(ptr->next == head) {
						deletefromend();
						break;
					}
					else
					{
						deleteatloc(i);
						break;
					}
				}
				i++;
				ptr = ptr->next;
			}
		}
	}
	void Search_Cll(int ele) {

		struct node *cur = head;
		int flag = 0;
		if(head == NULL)
			cout<<"No circular Linked List exists"<<endl;
		else
		{
			do {
				if(cur->data == ele) {

					flag = 1;
					break;
				}
				cur = cur->next;
			}while(cur!=head);
			if(flag == 1)
				cout<<"Element found\n";
			else
				cout<<"Element not found\n";
		}
	}
};

int main()
{
	CircularLinkedList cll;
	int choice,num;
	do {
		cout<<"Enter number to do following operation:-\n1)Inserting element at the beginning\t2)Inserting element at the end\t3)Inserting element at a particular location\n4)Deleting an existing element\t5)Searching the doubly linked list\t6)Displaying doubly linked list\t7)Exit\n";
		cin>>choice;
		switch(choice) {

			case 1: cout<<"Enter a number to insert at beginning:\n";
				cin>>num;
				cll.insertatbeg(num);
				break;

			case 2: cout<<"Enter a number to insert at the end:\n";
				cin>>num;
				cll.insertatend(num);
				break;

			case 3: int pos;
				cout<<"Enter a number to insert at a particular location:\n";
				cin>>num;
				cout<<"Enter a position where to insert the number:\n";
				cin>>pos;
				cll.insertatloc(num,pos);
				break;

			case 4:	cout<<"Enter number to delete:\n";
				cin>>num;
				cll.delete_element(num);
				break;

			case 5: cout<<"Enter number to search in the Doubly Linked List\n";
					cin>>num;
					cll.Search_Cll(num);
					break;

			case 6: cout<<"Doubly linked list:-\n";
				cll.traverse();
				break;

			case 7: break;
			default: cout<<"Invalid Input\n";
		}
		cout<<"----------------------------------\n";
	}while(choice != 7);
	return 0;
}

