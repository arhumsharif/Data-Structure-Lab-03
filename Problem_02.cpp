#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
};
class Link_list
{
public:
	node* head;
	Link_list()
	{
		head = NULL;
	}
	node* return_head()
	{
		return head;
	}
	void insert(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (head == NULL)
		{
			head = ptr;
		}
		else
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}
	void delete_node(int k)
	{
		if (head == NULL)
		{
			cout << " Queue is Empty! " << endl;
			return;
		}
		else
		{
			node* ptr = head;
			head = head->next;
			delete ptr;
		}
	}
	node* search()
	{
		node* temp = head;
		if (head == NULL)
		{
			cout << " Queue is Empty " << endl;
			return NULL;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			return temp;
		}

	}
};
class Queue
{
	node* rear;
	node* front;
	Link_list l1;
public:
	Queue()
	{
		rear = NULL;
		front = NULL;
	}
	bool IsFull()
	{
		try
		{
			node* ptr = NULL;
			delete ptr;
		}
		catch (bad_alloc)
		{
			return true;
		}
		return false;
	}
	bool IsEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void EnQueue(int val)
	{
		if (IsFull() == true)
		{
			cout << " Queue is Full " << endl;
			return;
		}
		else
		{
			l1.insert(val);
			cout << "---------- EnQueued ----------- " << endl;
			rear = l1.search();
			
		}
	}
	int DeQueue()
	{
		int a;
		front = l1.return_head();
		if (IsEmpty() == true)
		{
			cout << " Queue is Empty! " << endl;
			return 0;
		}
		else if (rear == front)
		{
			a = front->data;
			l1.delete_node(a);
			rear = NULL;
			front = NULL;
			cout << " ------------ DeQueued ------------- " << endl;
			return a;
		}
		else
		{
			a = front->data;
			l1.delete_node(a);
			cout << " ------------ DeQueued ------------- " << endl;
			return a;
		}
	}
};
int main()
{
	Queue q1;
	int a = 0, val, get;
	char choice;
	while (a != -1)
	{
		cout << "                            Welcome!  " << endl;
		cout << " 1.    EnQueue " << endl;
		cout << " 2.    DeQueue " << endl;
		cout << " 3.    IsFull " << endl;
		cout << " 4.    IsEmpty " << endl;
		cout << endl << " Enter: ";
		cin >> choice;
		if (choice == '1')
		{
			cout << " Enter the Value: ";
			cin >> val;
			q1.EnQueue(val);
		}
		else if (choice == '2')
		{
			get = q1.DeQueue();
			cout << endl;
			cout << get << " Has been DeQueued " << endl;
		}
		else if (choice == '3')
		{
			if (q1.IsFull() == true)
			{
				cout << " Queue is Full " << endl;
			}
			else
			{
				cout << " Queue is not Full " << endl;
			}
		}
		else if (choice == '4')
		{
			if (q1.IsEmpty() == true)
			{
				cout << " Queue is Empty " << endl;
			}
			else
			{
				cout << " Queue is not Empty " << endl;
			}
		}
		else
		{
			cout << " Invalid Choice! " << endl;
		}
		cout << endl;
		cout << " Enter -1 to Quit: ";
		cin >> a;
	}
	return 0;
}