#include <iostream>
using namespace std;

struct node {
	int data;
	node* pNext;
};
typedef struct node Node;

struct list {
	Node* pHead;
	Node* pTail;
};
typedef struct list List;


bool isEmpty(List l)
{
	if (l.pHead) return false;
	else return true;
}


Node* createNode()
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Cannot allocate";
		return NULL;
	}
	else 
	{
		cin >> p->data;
		p->pNext = NULL;
		return p;
	}
}

void initList(List& l) 
{
	l.pHead = l.pTail = NULL;
}

void insertAtBegin(List& l, Node* p) 
{
	if (p == NULL) 
	{
		cout << "Node NULL"; 
		return;
	}
	else 
	{
		if (isEmpty(l)) l.pHead = l.pTail = p;
		else {
			p->pNext = l.pHead;
			l.pHead = p;
			return;
		}
	}
}

void output(List l) 
{
	if (isEmpty(l)) cout << "Khong co phan tu" << endl;
	else 
	{
		for (Node* i = l.pHead; i != NULL; i = i->pNext) 
		{
			cout << i->data << " ";
		}
		cout << endl;
	}

}

void enterList(List& l, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		Node* p = createNode();
		insertAtBegin(l, p);
	}
}


Node* minPositive(List l) 
{
	if (isEmpty(l)) return NULL;
	Node* p = NULL;
	int count = 0;
	for (Node* i = l.pHead; i != NULL; i = i->pNext) 
	{
		if (i->data > 0 && count == 0) 
		{
			p = i;
			count = 1;
		}
		if (p && i->data < p->data && i->data > 0) p = i;
	}
	if (p) return p;
	else return NULL;
}

Node* maxMinus(List l) 
{
	if (isEmpty(l)) return NULL;
	Node* p = NULL;
	int count = 0;
	for (Node* i = l.pHead; i != NULL; i = i->pNext) 
	{
		if (i->data < 0 && count == 0) 
		{
			p = i;
			count = 1;
		}
		if (p && i->data > p->data && i->data < 0) p = i;
	}
	if (p) return p;
	else return NULL;
}

int countXinList(List l, int x) 
{
	if (isEmpty(l)) return 0;
	int count = 0;
	for (Node* i = l.pHead; i != NULL; i = i->pNext) 
	{
		if (x == i->data) count++;
	}
	return count;
}


void deleteAtBegin(List& l) 
{
	if (isEmpty(l)) return;
	else 
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

void deleteAtEnd(List& l) 
{
	if (isEmpty(l)) return;
	else {
		if (l.pHead == l.pTail) deleteAtBegin(l);
		Node* p = l.pTail;
		for (Node* i = l.pHead; i != NULL; i = i->pNext) 
		{
			if (i->pNext == l.pTail) 
			{
				l.pTail = i;
				l.pTail->pNext = NULL;
				delete p;
				return;
			}
		}
	}
}


void deleteXinList(List& l, int x) 
{
	if (isEmpty(l)) return;
	else 
	{
		while(l.pHead && l.pHead->data == x) deleteAtBegin(l);
		if (isEmpty(l)) return;
		if (x == l.pTail->data) deleteAtEnd(l);
		for (Node* i = l.pHead; i != NULL; i = i->pNext) 
		{
			if (i->pNext && i->pNext->data == x) 
			{
				while (i->pNext->data == x) 
				{
					Node* p = i->pNext;
					i->pNext = i->pNext->pNext;
					delete p;
				}
			}
		}
	}
	
}

int main() 
{
	List l;
	initList(l);
	int n;
	cin >> n;
	enterList(l, n);
	output(l);
	Node *p = minPositive(l);
	if (p) cout << "Phan tu duong nho nhat: " << p->data << endl;
	else cout << "Khong co phan tu duong" << endl;
	Node* p1 = maxMinus(l);
	if (p1) cout << "Phan tu am lon nhat: " << p1->data << endl;
	else cout << "Khong co phan tu am" << endl;
	cout << "Nhap x: ";
	int x;
	cin >> x;
	cout << "So phan tu x trong danh sach la : " << countXinList(l, x) << endl;
	cout << "Danh sach sau khi xoa la: ";
	deleteXinList(l,x);
	output(l);
	return 0;
}
