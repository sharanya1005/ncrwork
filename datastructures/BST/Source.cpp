#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *Root;
class BST
{
	
public:
	BST()
	{
		Root = NULL;
	}
	Node* NewNode(int elem)
	{
		struct Node *tmp=NULL;
		tmp = new Node;
		if (tmp == NULL)
			cout << "Failed memory allocation\n";
		else
		{
			
			tmp->data = elem;
			tmp->left = NULL;
			tmp->right = NULL;
		}
		return tmp;
	}
	Node* InsertNode(struct Node *curr,int elem)
	{
		
		if (curr == NULL)
		{
			
			return NewNode(elem);
		}
		if (elem < curr->data)
		{
			cout << curr->data << endl;
			curr = curr->left;
			return InsertNode(curr,elem);
		}
		else
		{
			cout << curr->data << endl;
			curr = curr->right;
			return InsertNode(curr, elem);
		}
		return curr;
		
	}
	void PreOrder(struct Node *curr)
	{
		if (curr != NULL)
		{
			cout << curr->data << " ";
			PreOrder(curr->left);
			PreOrder(curr->right);
		}

	}
	/*void PreOrder()
	{
		if (Root != NULL)
			print(Root);

	}
	void print(struct Node *curr)
	{

		if (curr != NULL)
		{
			cout << curr->data << " ";
			print(curr->left);
			print(curr->right);
		}

	}*/
	~BST()
	{
		if (Root != NULL)
			DeleteNode(Root);
	}
	void DeleteNode(struct Node * curr)
	{
		if (curr != NULL)
		{
			DeleteNode(curr->left);
			DeleteNode(curr->right);
			delete curr;
		}
	}
};
int main()
{
	BST Tree1;
	int choice, element;
	while (1)
	{
		cout << "Enter your choice:\n";
		cout << "1.Insert Node  2.PreOrder display of tree  3.Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter data for the Node:";
			cin >> element;
				if(Root==NULL)
					Root=Tree1.InsertNode(Root, element);
				else
					Tree1.InsertNode(Root, element);
			break;
		case 2:cout << "PreOrder of Tree\n";
			Tree1.PreOrder(Root);
			cout << endl;
			break;
		case 3:
		default:
			return 0;
		}
	}
}