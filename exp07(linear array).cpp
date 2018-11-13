#include<iostream>
using namespace std;
class CircularQueue {

	int *arr,size,front,rear;
	public:
	CircularQueue() {

		cout<<"Enter size of queue\n";
		cin>>size;
		arr = new int[size];
		front = -1;
		rear = -1;
	}
	void enqueue(int val) {

		if(front == (rear+1)%size||front == 0 && rear == size-1)

			cout<<"overflow\n";

		else if(front == -1 && rear == -1) {

			front = 0;
			rear = 0;
			arr[rear] = val;
		}
		else {
			/*if(rear == size - 1 && front > 0)
				rear = 0;*/
				rear = (rear+1)%size;cout<<front<<"\t"<<rear;
			arr[rear] = val;
		}
	}

	void dequeue() {

		if(front == -1) {

			cout<<"Underflow\n";
		}
		else if(front == rear){

			front = -1;
			rear = -1;
		}
		else if(front == size - 1) {

			front = 0;
		}
		else
			front++;
	}

	void traverse() {

		if(front == -1 && rear == -1) {

			cout<<"Queue is empty\n";
			return;
		}
		cout<<"Queue : ";
		if(rear >= front) {

			for(int i = front;i <= rear; i++) {

				cout<<arr[i]<<"\t";
			}
			cout<<endl;
		}
		else {

			for(int i = front;i < size;i++) {

				cout<<arr[i]<<"\t";
			}
			for(int i = 0;i <= rear;i++) {

				cout<<arr[i]<<"\t";
			}
			cout<<endl;
		}
	}
};
int main()
{
	CircularQueue c;
	cout<<"Enter a number to perform following operation:-\n0)EXIT\t1)ENQUEUE\t2)DEQUEUE\t3)DISPLAY\n";
	int choice,num;
	cin>>choice;
	while(choice!=0) {
		switch(choice) {

			case 1:cout<<"Add an element in the queue\n";
					cin>>num;
					c.enqueue(num);
					break;
			case 2:c.dequeue();
					cout<<"Element deleted\n";
					break;
			case 3:c.traverse();
			case 0:break;
		}
		cout<<"-------------------------------\n";
		cin>>choice;
	}
}

