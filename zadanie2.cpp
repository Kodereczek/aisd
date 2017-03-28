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
	index = 0;
}

Node::~Node()
{
	//cout << "Destruktor node:" << index << "\n";
	
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

		void GotoHead();
		void GotoTail();

		Node *FindByData(int _data);
		Node *FindByIndex(int _index);

		void Add(Node *_node);
		void AddToHead(Node *_node);
		void AddToTail(Node *_node);

	public:
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

	current = tail = head;
}

List::~List()
{
	//cout << "Destruktor head\n";

	delete head;
}

int List::Next()
{
	if(HasNext())
	{
		current = current->next;
		return current->data;
	}
	else
		return 0;
}

bool List::HasNext()
{
	if(current->next != NULL) return true;
	else                      return false;
}

void List::GotoHead()
{
	current = head;
}

void List::GotoTail()
{
	current = tail;
}

Node* List::FindByData(int _data)
{
	GotoHead();

	while(current->next != NULL && current->data != _data) Next();

	return current;
}

Node* List::FindByIndex(int _index)
{
	GotoHead();

	while(current->next != NULL && current->index != _index) Next();

	return current;
}

void List::Add(Node *_node)
{
	_node->index = current->index + 1;
	_node->next  = current->next;
	current->next = _node;
	
	current = _node;

	allNodes++;

	while(_node->next != NULL)
	{
		_node = _node->next;
		_node->index++;
	}

}

void List::AddToHead(Node *_node)
{
	_node->index = 1;
	_node->next = head;
	head = current = _node;
	
	allNodes++;

	while(_node->next != NULL)
	{
		_node = _node->next;
		_node->index++;
	}
}

void List::AddToTail(Node *_node)
{
	allNodes++;

	_node->index = allNodes;
	_node->next = NULL;
	tail->next = _node;

	tail = current = _node;
}

int main()
{
	List *list = new List;

	Node
		*node1 = new Node(13),
		*node2 = new Node(15),
		*node3 = new Node(29),
		*node4 = new Node(51),
		*node5 = new Node(87);

	list->AddToHead(node1);
	list->Add(node3);
	list->Add(node4);
	list->Add(node2);
	list->Add(node5);

	for(int i = 1; i <= list->allNodes; i++) cout << list->FindByIndex(i)->data << "\n";
	
	delete list;

	getchar();

	return 0;
}
