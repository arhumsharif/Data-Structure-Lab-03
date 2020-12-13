#include<iostream>
using namespace std;
class queue
{
private:
	int rear;
	int front;
	const int size = 5;
	int* arr;
public:
	queue()
	{
		rear = -1;
		front = -1;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	bool IsEmpty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull()
	{
		if (rear == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Enqueue(int val)
	{
		if (IsFull() == true)
		{
			cout << " Queue is Full " << endl;
			return;
		}
		else if (IsEmpty() == true)
		{
			rear = 0;
			front = 0;
			arr[rear] = val;
			cout <<endl<< "--------- Enqueued --------- " << endl;
		}
		else
		{
			rear++;
			arr[rear] = val;
			cout << endl << "--------- Enqueued --------- " << endl;
		}
	}
	int Dequeue()
	{
		int a;
		if (IsEmpty() == true)
		{
			cout << " Queue is Empty " << endl;
			return 0;
		}
		else if (rear==front)
		{
			a = arr[front];
			cout << " ----------- Dequeued ------------ " << endl;
			rear = -1;
			front = -1;
			return a;
		}
		else
		{
			a = arr[front];
			front++;
			cout << " ----------- Dequeued ------------ " << endl;
			return a;
		}
	}
};
int main()
{
	queue q1;
	int val, a = 0,getter=0;
	char choice;
	cout << "        ----- Welcome! ----- " << endl;
	while (a != -1)
	{
		cout << " 1.    EnQueue() " << endl;
		cout << " 2.    DeQueue() " << endl;
		cout << " 3.    IsEmpty() " << endl;
		cout << " 4.    IsFull() " << endl;
		cout << endl;
		cout << " -> Enter: ";
		cin >> choice;
		if (choice == '1')
		{
			cout << " Enter the Value to EnQueue: ";
			cin >> val;
			q1.Enqueue(val);
		}
		else if(choice=='2')
		{
			getter = q1.Dequeue();
			cout << endl;
			cout << getter << " Has been Dequeued " << endl;
		}
		else if (choice == '3')
		{
			if (q1.IsEmpty() == true)
			{
				cout << " Queue is Empty " << endl;
			}
			else
			{
				cout << " Queue is  not Empty " << endl;
			}
		}
		else if (choice == '4')
		{
			if (q1.IsFull() == true)
			{
				cout << " Queue is Full " << endl;
			}
			else
			{
				cout << " Queue is  not Full " << endl;
			}
		}
		else
		{
			cout << " InValid Key " << endl;
		}
		cout << endl << " Enter -1 to Exit: ";
		cin >> a;
		cout << endl;
	}
	return 0;
}