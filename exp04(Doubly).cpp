#include<iostream>
using namespace std;
struct node {

	node *prev;
	int data;
	node *next;
};

class DLinkedList {

	node *head;
	public:
	DLinkedList() {

		head = NULL;

	}

	node* createnode(int val) {

		node *nn;
		nn = new node;
		nn->data = val;
		nn->prev = NULL;
		nn->next = NULL;
		return nn;
	}

	void insertatbeg(int val) {

		node *nn;
		nn = createnode(val);
		if(head == NULL) {

			head = nn;
		}
		else {
			nn->next = head;
			head->prev = nn;
			head = nn;
		}
	}

	void insertatend(int val) {

		node *nn;
		nn = createnode(val);
		if(head == NULL) {

			head = nn;
		}
		else {
			node *temp = head;
			while(temp->next!=NULL) {

				 temp = temp->next;
			}
			nn->prev = temp;
			temp->next = nn;
		}
	}

	void insertatloc(int val,int pos) {

		node *nn = createnode(val);
		if(head == NULL) {
			head = nn;
		}
		else if(head->next == NULL) {

			insertatend(val);
		}
		else {
			node *temp;
			temp = head;
			for(int i = 1;i < pos-1;i++) {

				temp = temp->next;
			}
			nn->next = temp->next;
			temp->next->prev = nn;
			temp->next = nn;
			nn->prev = temp;
		}
	}

	void traverse() {

		node *temp = head;
		while(temp != NULL) {

			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<endl;
	}

	void deleteatbeg() {

		if(head == NULL) {

			cout<<"Nothing to delete\n";

		}
		else if(head->next == NULL) {

			node *ptr;
			ptr = head;
			head = NULL;
			delete (ptr);
		}
		else {

			node *ptr = head;
			head = ptr->next;
			head->prev = NULL;
			delete (ptr);
		}
	}

	void deleteatend() {

		if(head == NULL) {

			cout<<"Nothing to delete\n";

		}
		else if(head->next == NULL) {

			deleteatbeg();
		}
		else {

			node *ptr = head;
			while(ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->prev->next = NULL;
			delete (ptr);
		}
	}

	void deleteatloc(int pos) {

		if(head == NULL) {

			cout<<"Nothing to delete\n";

		}
		else if(head->next == NULL) {

			node *ptr;
			ptr = head;
			head = NULL;
			delete (ptr);
		}
		else {

			node *ptr = head;
			for(int i=1;i<pos-1;i++) {

				ptr = ptr->next;
			}
			ptr->next->next->prev = ptr;
			ptr->next = ptr->next->next;
			delete (ptr->next);
		}
	}

	void deleteexisting(int val) {

		if(head == NULL) {

			cout<<"Nothing to delete\n";

		}
		else {

			node *ptr = head;
			int i = 1;
			while(ptr->next != NULL) {

						//cout<<ptr->data<<endl;
				if(ptr->data == val) {

					if(i == 1) {

						deleteatbeg();
						i = 1;
						ptr = head;
						traverse();
						continue;
					}
					else {

						deleteatloc(i);
						traverse();
						i--;
					}
				}
				i++;
				ptr = ptr->next;
			}
			if(ptr->data == val) {

				if(i == 1)
				{
					deleteatbeg();
					head = NULL;
				}
				else
					deleteatend();
			}
		}
	}

	void Search_dll(int ele) {

		node *temp = head;
		while(temp != NULL) {

			if(temp->data == ele)
				break;
			temp = temp->next;
		}

		if(temp == NULL)
			cout<<"Element not found\n";
		else
			cout<<"Element found\n";
	}
};

int main()
{
	DLinkedList dll;
	int choice,num;
	do {
		cout<<"Enter number to do following operation:-\n1)Inserting element at the beginning\t2)Inserting element at the end\t3)Inserting element at a particular location\n4)Deleting an existing element\t5)Searching the doubly linked list\t6)Displaying doubly linked list\t7)Exit\n";
		cin>>choice;
		switch(choice) {

			case 1: cout<<"Enter a number to insert at beginning:\n";
				cin>>num;
				dll.insertatbeg(num);
				break;

			case 2: cout<<"Enter a number to insert at the end:\n";
				cin>>num;
				dll.insertatend(num);
				break;

			case 3: int pos;
				cout<<"Enter a number to insert at a particular location:\n";
				cin>>num;
				cout<<"Enter a position where to insert the number:\n";
				cin>>pos;
				dll.insertatloc(num,pos);
				break;

			case 4:	cout<<"Enter number to delete:\n";
				cin>>num;
				dll.deleteexisting(num);
				break;

			case 5: cout<<"Enter number to search in the Doubly Linked List\n";
					cin>>num;
					dll.Search_dll(num);
					break;

			case 6: cout<<"Doubly linked list:-\n";
				dll.traverse();
				break;

			case 7: break;
			default: cout<<"Invalid Input\n";
		}
		cout<<"----------------------------------\n";
	}while(choice != 7);
	return 0;
}


