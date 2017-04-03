#include <iostream>

using namespace std;

typedef struct Node
{
	public:
		Node(int _data = 0);
		~Node();

	public:
		Node
			*next;

		int
			data,
			index;
} Node;

Node::Node(int _data)
{
	next = NULL;

	data = _data;
	index = 1;
}

Node::~Node()
{
	cout << "Destruktor node:" << index << "\n";

	delete next;
}

class List
{
	public:
		List();
		~List();

	public:
		 int Next();
	 
		bool HasNext();
	
		void IncrementIndex(Node *_node);
		void DecrementIndex(Node *_node);

		void GoToHead();
		void GoToTail();

		Node *FindByData(int _data);
		Node *FindByIndex(int _index);

		Node *FindPrev(Node *_current);
		Node *FindNext(Node* _current);

		void Add(int _data);
		void AddToHead(int _data);
		void AddToTail(int _data);

		void Delete();
		void DeleteFromHead();
		void DeleteFromTail();

		void Reverse();

		void Show();

	private:
		Node
			*head,
			*current,
			*tail;

		int
			allNodes;
};

List::List()
{
	allNodes = 0;

	current = head = tail = NULL;
}

List::~List()
{
	cout << "\n\nDestruktor head\n";

	delete head;
}

int List::Next()
{
	if (HasNext())
	{
		current = current->next;
		return current->data;
	}
	else
		return 0;
}

bool List::HasNext()
{
	if (current->next != NULL) return true;
	else                       return false;
}

void List::IncrementIndex(Node *_node)
{
	while (_node->next != NULL)
	{
		_node = _node->next;
		_node->index++;
	}
}

void List::DecrementIndex(Node *_node)
{
	while (_node->next != NULL)
	{
		_node = _node->next;
		_node->index = _node->index - 1;
	}
}

void List::GoToHead()
{
	current = head;
}

void List::GoToTail()
{
	current = tail;
}

Node* List::FindByData(int _data)
{
	GoToHead();

	while (current->next != NULL && current->data != _data) Next();

	return current;
}

Node* List::FindByIndex(int _index)
{
	GoToHead();

	while (current->next != NULL && current->index != _index) Next();

	return current;
}

Node *List::FindPrev(Node *_current)
{
	if (current == head) return head;

	Node *prev = head;

	while (prev->next != NULL && prev->next != _current) prev = prev->next;

	return prev;
}

Node* List::FindNext(Node *_current)
{
	if (_current->next)
	{
		return _current->next;
	}
	else
		return NULL;
}

void List::Add(int _data)
{
	if (current == tail)
	{
		AddToTail(_data);

		return;
	}

	Node *node = new Node(_data);

	if (allNodes > 0)
	{
		node->index = current->index + 1;
		node->next  = current->next;

		current->next = node;

		current = node;

		IncrementIndex(node);
	}
	else
		head = current = tail = node;

	allNodes++;
}

void List::AddToHead(int _data)
{
	Node *node = new Node(_data);

	if (allNodes > 0)
	{
		node->next = head;

		head = current = node;

		IncrementIndex(node);
	}
	else
		head = current = tail = node;

	allNodes++;
}

void List::AddToTail(int _data)
{
	Node *node = new Node(_data);

	if (allNodes > 0)
	{
		node->index = allNodes + 1;

		tail->next = node;

		tail = current = node;
	}
	else
		head = current = tail = node;

	allNodes++;
}

void List::Delete()
{
	if (allNodes == 1) return;

	if (current == tail)
	{
		DeleteFromTail();

		return;
	}

	DecrementIndex(current);
	allNodes--;

	Node
		*prev = FindPrev(current),
		*node = current;

	prev->next = current = current->next;

	node->index = -1;
	node->next = NULL;
	delete node;
}

void List::DeleteFromHead()
{
	if (allNodes == 1) return;

	DecrementIndex(head);
	allNodes--;

	Node *node = head;

	head = head->next;
	
	node->index = -1;
	node->next = NULL;
	delete node;
}

void List::DeleteFromTail()
{
	if (allNodes == 1) return;

	Node 
		*prev = FindPrev(current),
		*node = tail;

	current = tail = prev;
	tail->next = NULL;

	node->index = -1;
	node->next = NULL;
	delete node;

	allNodes--;
}

void List::Reverse()
{
	Node *prev = NULL, *next = NULL;
	
	current = head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = current = prev;

	int i = 1;

	while (current)
	{
		tail = current;
		current->index = i;
		current = current->next;
		i++;
	}
}

void List::Show()
{
	cout << "\n";

	for (int i = 1; i <= allNodes; i++) cout << FindByIndex(i)->index << "	" << FindByIndex(i)->data << "	" << FindByIndex(i) << "\n";

	cout << "\nHead: 	   " << head->data << "\nCurrent:   " << current->data << "\nTail:	   " << tail->data << "\n";
}

int main()
{
	List *list = new List;

	list->Add(47);
	list->Add(23);
	list->Add(41);
	list->Add(69);
	list->Add(50);
	list->Add(71);
	list->GoToHead();
	list->Next();
	list->Next();
	list->Delete();
	list->Delete();
	list->Delete();
	list->DeleteFromHead();
	list->Add(50);
	list->DeleteFromTail();
	list->Add(50);
	list->Add(41);
	list->Add(69);
	list->Delete();
	list->Add(50);

	list->Show();
	list->Reverse();
	list->Show();

	delete list;

	getchar();

	return 0;
}
