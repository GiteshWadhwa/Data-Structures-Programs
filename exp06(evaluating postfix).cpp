#include<iostream>
using namespace std;
struct node {

	int data;
	node *next;
};
class Stack {

	node* top = NULL;
	node* head = NULL;
public:
	void push(int val) {

		node* newnode = new node();
		newnode->data = val;
		newnode->next = NULL;
		if(top == NULL || head == NULL) {
			top = newnode;
			head = newnode;
		}
		else {

			top->next = newnode;
			top = newnode;
		}
	}

	int pop() {

		if(top == NULL)
			cout<<"Stack overflow\n";
		else {

			node* temp = head;
			node* prev = head;
			while(temp!=top) {

				prev = temp;
				temp = temp->next;
			}
			prev->next = NULL;
			top = prev;
			int ret = temp->data;
			delete temp;
			return ret;
		}
	}

	int Power(int n1,int n2) {

		int sum = 1;
		for(int i=0;i<n2;i++) {

			sum *= n1;
		}
		return sum;
	}
	int evaluate(int n1,int n2,char op) {

		switch(op) {

			case '+':return n2+n1;
					break;
			case '-':return n2-n1;
					break;
			case '*':return n2*n1;
					break;
			case '/':return n2/n1;
					break;
			case '^':return Power(n2,n1);
		}
	}
	int evalPostFix(char exp[],int s) {

		for(int i=0;i<s;i++) {

			if(isdigit((int)exp[i])) {

				push((int)exp[i] - 48);
			}
			else {

				int n1 = pop();
				int n2 = pop();
				push(evaluate(n1,n2,exp[i]));
			}
		}

		return top->data;
	}
};

int main() {

	Stack s;
	char postfix[] = {'9','8','6','+','*','2','/'};
	int size = sizeof(postfix);
	cout<<"Postfix expression: "<<postfix<<"\nEvaluating this expression:-\n";
	int ans = s.evalPostFix(postfix,size);
	cout<<ans;
}
