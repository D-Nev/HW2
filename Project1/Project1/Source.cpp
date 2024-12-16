#include <iostream>
using namespace std;

class MyInt
{
private:
	int value;
public:
	MyInt(int value)
	{
		this->value = value;
	}
	void SetData(int value)
	{
		this->value = value;
	}
	int GetData() const
	{
		return value;
	}
};

class Node
{
private:
	MyInt myInt;
	Node* next;
public:
	Node(MyInt myInt) : myInt(myInt), next(nullptr) {}
	MyInt GetMyInt() const
	{
		return myInt;
	}
	void SetMyInt(MyInt myInt)
	{
		this->myInt = myInt;
	}
	Node* GetNext() const
	{
		return next;
	}
	void SetNext(Node* next)
	{
		this->next = next;
	}
};

class LinkedList
{
private:
	Node* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {}

	size_t GetSize() const
	{
		return size;
	}

	void InsertAtEnd(MyInt value)
	{
		if (head == nullptr)
		{
			InsertAtBeginning(value);
			return;
		}
		Node* newNode = new Node(value);
		Node* temp = head;
		while (temp->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		temp->SetNext(newNode);
		size++;
	}

	void InsertAtBeginning(MyInt value)
	{
		Node* newNode = new Node(value);
		newNode->SetNext(head);
		head = newNode;
		size++;
	}

	void DeleteFromBeginning()
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}
		Node* temp = head;
		head = head->GetNext();
		delete temp;
		size--;
	}

	void DeleteFromEnd()
	{
		if (head == nullptr)
		{
			cout << "List is empty.\n";
			return;
		}
		if (head->GetNext() == nullptr)
		{
			delete head;
			head = nullptr;
			size--;
			return;
		}
		Node* temp = head;
		while (temp->GetNext()->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		delete temp->GetNext();
		temp->SetNext(nullptr);
		size--;
	}

	MyInt GetAt(size_t index) const
	{
		if (index >= size)
		{
			throw out_of_range("Index out of range");
		}
		Node* temp = head;
		for (size_t i = 0; i < index; ++i)
		{
			temp = temp->GetNext();
		}
		return temp->GetMyInt();
	}

	void Print() const
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->GetMyInt().GetData() << " -> ";
			temp = temp->GetNext();
		}
		cout << "null\n";
	}

	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->GetNext();
			delete temp;
		}
	}
};

int main()
{
	LinkedList* list = new LinkedList();
	list->InsertAtBeginning(MyInt(5));
	list->InsertAtEnd(MyInt(7));
	list->InsertAtEnd(MyInt(9));

	cout << "List after insrt: ";
	list->Print();

	list->DeleteFromEnd();
	cout << "List after deletin: ";
	list->Print();

	list->DeleteFromBeginning();
	cout << "List deleting beginning: ";
	list->Print();

	try
	{
		cout << "Element indx 0: " << list->GetAt(0).GetData() << endl;
	}
	catch (const out_of_range& e)
	{
		cout << e.what() << endl;
	}

	delete list;
	return 0;
}
