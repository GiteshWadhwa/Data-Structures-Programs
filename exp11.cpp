#include<iostream>
using namespace std;
struct node {

	node *left;
	int data;
	node *right;
} *root;

class bst {

	int *ptr;
	public:
	bst() {

		root = NULL;
		ptr = NULL;
	}

	void insertEle(node *ptr,int num) {

		if(ptr == NULL) {

			node *newnode = new node();
			newnode->data = num;
			newnode->left = NULL;
			newnode->right = NULL;
			root = newnode;
			cout<<"Root node inserted\n";
			ptr = root;
		}
		else {

			if(ptr->data < num) {

				if(ptr->right!=NULL) {

					insertEle(ptr->right,num);
				}
				else {
					node *newnode = new node();
					newnode->data = num;
					ptr->right = newnode;
					newnode->left = NULL;
					newnode->right = NULL;
					cout<<"Right node inserted\n";
				}
			}
			else if(ptr->data > num) {

				if(ptr->left!=NULL) {

					insertEle(ptr->left,num);
				}
				else {
					node *newnode = new node();
					newnode->data = num;
					ptr->left = newnode;
					newnode->left = NULL;
					newnode->right = NULL;
					cout<<"Left node inserted\n";
				}
			}
			else {

				cout<<"The node already exists\n";
			}
		}
	}

	node* inOrderSucc(node* r) {

		node* temp = r;
		while(r!=NULL && temp->left!=NULL) {

			temp = temp->left;
		}
		return temp;
	}

	node* deleteEle(node* root,int key) {

		if(root==NULL)
			cout<<"Element doesn't exist"<<endl;
		else if(root->data>key)
			root->left=deleteEle(root->left,key);
		else if(root->data<key)
			root->right=deleteEle(root->right,key);
		else
		{
			if(root->left==NULL)
			{
				node* temp=root->right;
				delete root;
				return temp;
			}
			if(root->right==NULL)
			{
				node* temp=root->left;
				delete root;
				return temp;
			}

			node* temp = inOrderSucc(root->right);
			root->data = temp->data;
			root->right = deleteEle(root->right, temp->data);
		}
		return root;
	}

	void preOrder(node* root) {

		node* ptr = root;
		if(root == NULL) {
			return;
		}
		else {
			cout<<ptr->data<<" ";
			preOrder(ptr->left);
			preOrder(ptr->right);
		}
	}

	void inOrder(node* root) {

		node* ptr = root;
		if(root == NULL) {
			return;
		}
		else {
			preOrder(ptr->left);
			cout<<ptr->data<<" ";
			preOrder(ptr->right);
		}
	}

	void postOrder(node* root) {

		node* ptr = root;
		if(root == NULL) {
			return;
		}
		else {
			preOrder(ptr->left);
			preOrder(ptr->right);
			cout<<ptr->data<<" ";
		}
	}
};

int main()
{
	bst b;
	cout<<"Enter a number for following operations:-\n(0)EXIT\n(1)INSERT\n(2)DELETE\n(3)PRE-ORDER TRAVERSAL\n(4)POST-ORDER TRAVERSAL\n(5)IN-ORDER TRAVERSAL\n";
	int choice,n;
	cin>>choice;
	while(choice!=0) {
		switch(choice)
		{
			case 1:	cout<<"Enter a number to insert\n";
					cin>>n;
					b.insertEle(root,n);
					break;

			case 2: cout<<"Enter element to delete\n";
					cin>>n;
					b.deleteEle(root,n);
					break;

			case 3: cout<<"Pre order Traversal: ";
					b.preOrder(root);
					cout<<endl;
					break;

			case 4: cout<<"Post order Traversal: ";
					b.postOrder(root);
					cout<<endl;
					break;

			case 5: cout<<"In order Traversal: ";
					b.inOrder(root);
					cout<<endl;

		}
		cin>>choice;
	}


}


