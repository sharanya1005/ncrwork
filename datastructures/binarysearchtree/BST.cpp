#include<iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class binarysearchtree
{
	struct node *start;
public:
	binarysearchtree();
	void insert(int);
	void delete_element(int, node *);
	void delete_node(node *);
	void inorder();
	void preorder();
	void postorder();
	~binarysearchtree();
	int find_max(node *);
	int find_min(node *);
	int height(node *);
	int noofleafnodes(node *);
	int noofnonleafnodes(node *);
	void print_inorder(node *);
	void print_preorder(node *);
	void print_postorder(node *);
};

binarysearchtree::binarysearchtree()
{
	start = NULL;
	left = NULL;
	right = NULL;
}
int binarysearchtree::noofleafnodes(struct node *current)
{
	if (current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	return (noofleafnodes(current->left) + noofleafnodes(current->right));
}

int binarysearchtree::noofnonleafnodes(struct node *current)
{
	if (current == NULL)
		return 0;
	if (current->left == NULL && current->right == NULL)
		return 1;
	return (noofnonleafnodes(current->left) + noofnonleafnodes(current->right));
}

int binarysearchtree::find_min(struct node *current)
{
	if (current != NULL)
	{
		while (current->left != NULL)
			current = current->left;
		return (current->data);
	}
	return -1;
}

int binarysearchtree::find_max(struct node *current)
{
	if (current != NULL)
	{
		while (current->right != NULL)
			current = current->right;
		return (current->data);
	}
	return -1;
}

int binarysearchtree::height(struct node *current)
{
	if (current == NULL)
		return -1;
	else
		return ( max (height(current->left), height(current->right)) + 1);
}

void binarysearchtree::print_inorder(struct node *current)
{
	if (current != NULL)
	{
		print_inorder(current->left);
		cout << current->data << " ";
		print_inorder(current->right);
	}
}

void binarysearchtree::print_preorder(struct node *current)
{
	if (current != NULL)
	{
		cout << current->data << " ";
		print_preorder(current->left);
		print_preorder(current->right);
	}
}

void binarysearchtree::print_postorder(struct node *current)
{
	if (current != NULL)
	{
		print_postorder(current->left);
		print_postorder(current->right);
		cout << current->data << " ";
	}
}
void binarysearchtree::inorder()
{
	if (start != NULL)
		print_inorder(start);
}

void binarysearchtree::preorder()
{
	if (start != NULL)
		print_preorder(start);
}

void binarysearchtree::postorder()
{
	if (start != NULL)
		print_postorder(start);
}

binarysearchtree::~binarysearchtree()
{
	if (start != NULL)
		delete_node(start);
}

void binarysearchtree::delete_node(node *current)
{
	if (current != NULL)
	{
		delete_node(current->left);
		delete_node(current->right);
		delete current;
	}
}

void binarysearchtree::insert(int element)
{
	struct node *current;
	if (current == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = element;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (element < current->data)
			current->left = insert(element);
		else
			current->right = insert(element);
		return current;
	}
}

void binarysearchtree::delete_element(int element, node *current)
{
	if (current != NULL)
	{
		if (element > current->data)
			current->right = delete_element(element, current->right);
		else
			if (element < current->data)
				current->left = delete_element(element, current->left);
			else
			{
				if (current->left != NULL && current->right != NULL)
				{
					current->data = find_max(current->left);
					current->left = delete_element(current->data, current->left);
				}
				else
				{
					struct node *temp;
					temp = current;
					if (current->left == NULL)
						current = current->right;
					else
						current = current->left;
					delete temp;
				}
				return current;
			}
	}
}


	int main()
	{
		binarysearchtree b;
		int noofelements, operation, insert, dele;
		cout << "Enter the no. of elements in a tree: ";
		cin >> noofelements;
		cout << "The elements are: ";
		for (i = 0; i < noofelements; i++)
		{
			cin >> a[i];
		}
		cout << "choose the operation you want to perform.\n";
		cout << "1. Insert  2. Delete_element 3. Inorder  4. Preorder\n";
		cout << "5. Postorder 6. findmax  7. find min 8. height  9. no.of leafnodes 10. no. of non leaf nodes";
		cin >> operation;

		while (operation <= 10 && operation != 0)
		{
			switch (operation)
			{
			case 1:
				cout << "Enter the element you want to insert: ";
				cin >> insert;
				b.insert(insert);
				cout << endl;
				break;
			case 2:
				cout << "Enter the element you want to delete: ";
				cin >> dele;
				b.delete_element(dele);
				cout << endl;
				break;
			case 3:
				b.inorder();
				break;
			case 4:
				b.preorder();
				break;
			case5:
				b.postorder();
				break;
			case 6:
				cout << "Enter the element ";
				break;
			case 7:
				cout << " ";
				break;

			case 8:
				cout << "Enter the element for which you want to find height: ";
				//cin >> 
				//b.height();
				cout << endl;
				break;

			case 9:
				cout << "Number of leaf nodes in a given tree are: " << b.noofleafnodes() << endl;
				break;
			case 10:
				cout << "Number of non leaf nodes in a given tree are: " << b.noofnonleafnodes() << endl;
				break;

			}
			cin >> operation;
		}
	}
