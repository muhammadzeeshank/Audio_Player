#include<iostream>
using namespace std;
template <class T>
struct Node
{
	T val;
	Node<T>* next;

};
template <class T>
class LinkedList
{
	Node<T>* head;
public:
	LinkedList();
	void insertAtStart(T n);
	void insertAtEnd(T d);
	void deleteAtStart();
	void deleteAtEnd();
	void traverse();
	T* getData();
	bool isEmpty();
	int findLength();
	void insertAtAnyPos(T i, int pos);
	void deleteAtAnyPos(int pos);
	LinkedList(const LinkedList<T>& obj);
	~LinkedList();
};
template <class T>
LinkedList<T>::LinkedList() : head(NULL) {}
template <class T>
void LinkedList<T>::insertAtStart(T n)
{
	Node<T>* a = new Node<T>;
	a->val = n;
	a->next = NULL;
	if (head == NULL)
		head = a;
	else
	{
		a->next = head;
		head = a;
	}
}
template <class T>
void LinkedList<T>::insertAtEnd(T d)
{
	if (head == NULL)
		insertAtStart(d);
	else
	{
		Node<T>* a = new Node<T>;
		a->val = d;
		a->next = NULL;
		Node<T>* p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = a;
	}
}
template <class T>
void LinkedList<T>::deleteAtStart()
{
	if (head == NULL)
	{
		cout << "LinkedList is empty\n";
	}
	else
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
		cout << "Start node deleted succesfully\n";
	}
}
template <class T>
void LinkedList<T>::traverse()
{
	if (head == NULL)
	{
		cout << "LinkedList is empty\n";
	}
	else
	{
		cout << "LinkedList values:\n";
		Node<T>* p = head;
		while (p != NULL)
		{
			cout << p->val << endl;
			p = p->next;
		}
	}
}
template <class T>
void LinkedList<T>::deleteAtEnd()
{
	if (head == NULL)
	{
		cout << "LinkedList is empty\n";
	}
	else
	{
		Node<T>* p = head;
		if (p->next != NULL)
		{
			while (p->next->next != NULL)
			{
				p = p->next;
			}
			delete p->next;
			p->next = NULL;
		}
		else
		{
			delete head;
			head = NULL;
		}
	}
}
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
template <class T>
int LinkedList<T>::findLength()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		int l = 1;
		Node<T>* p = head;
		while (p->next != NULL)
		{
			p = p->next;
			l++;
		}
		return l;
	}
}
template <class T>
void LinkedList<T>::insertAtAnyPos(T i, int pos)
{

	int length = findLength();
	if (pos == 1 || isEmpty())
	{
		insertAtStart(i);
	}
	else if (pos == ++length)
	{
		insertAtEnd(i);
	}
	else if (pos <= length && pos > 1)
	{
		Node<T>* a = new Node<T>;
		a->val = i;
		Node<T>* temp = head;
		int n = 2;
		while (n < pos)
		{
			n++;
			temp = temp->next;
		}
		a->next = temp->next;
		temp->next = a;
		temp = NULL;
		
	}
	else
		cout << "Insert Position is not available!\n";
}
template <class T>
void LinkedList<T>::deleteAtAnyPos(int pos)
{
	int length = findLength();
	if (isEmpty())
	{
		cout << "LinkedList is empty!\n";
	}
	else if (pos == 1)
	{
		deleteAtStart();
	}
	else if (pos == length)
	{
		deleteAtEnd();
	}
	else if ( pos > 1 && pos < length)
	{
		Node<T>* temp = head;
		int i = 2;
		while (i < pos)
		{
			i++;
			temp = temp->next;
		}
		Node<T>* temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
		temp2 = NULL;
	}
	else 
		cout << "Delete Position is not available!\n";

}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& obj)
{
	if (obj.head == NULL)
	{
		cout << "Nothing to copy\n";
	}
	else
	{
		Node<T>* temp1 = head; // temp1 = temp2
		Node<T>* temp2 = obj.head; // head = obj.head
		while ( temp2 != NULL)
		if (head == NULL)
		{
			Node<T>* tn = new Node<T>;
			tn->val = temp2->val;
			temp1 = tn;
			head = temp1;
			temp1->next = NULL;
			temp2 = temp2->next;
		}
		else
		{
			Node<T>* tn = new Node<T>;
			tn->val = temp2->val;
			tn->next = NULL;
			temp1->next = tn;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
}
template <class T>
LinkedList<T>::~LinkedList()
{
	if (head == NULL)
	{
		cout << "Node does not exist\n";
    }
	else
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			Node<T>* temp2 = temp;
            temp = temp->next;
			delete temp2;
			temp2 = NULL;
		}
		head = NULL;
	}
}
template <class T>
T* LinkedList<T>::getData()
{
    int l = findLength();
	T* arr = new T[l];
	int i = 0;
	if (head == NULL)
	{
		cout << "LinkedList is empty\n";
	}
	else
	{
		Node<T>* p = head;
		while (p != NULL)
		{
			arr[i] = p->val;
			p = p->next;
			i++;
		}
	}
	return arr;
}



