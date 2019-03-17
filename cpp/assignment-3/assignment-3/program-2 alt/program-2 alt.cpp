#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack
{
private:
	vector<T> elements;    // elements 

public:
	void push(T const&);  // push element 
	void pop();               // pop element 
	T top() const;            // return top element 

	bool empty() const 
	{      // return true if empty.
		return elements.empty();
	}
};

template <class T>
void Stack<T>::push(T const& element) 
{
	// append copy of passed element 
	cout << "An element " << element << " is pushed onto the stack" << endl;
	elements.push_back(element);
}

template <class T>
void Stack<T>::pop()
{
	if (elements.empty())
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}

	// remove last element 
	elements.pop_back();
	cout << "An element is popped from the respective data type of stack" << endl;
}

template <class T>
T Stack<T>::top() const
{
	if (elements.empty()) 
	{
		throw out_of_range("Stack<>::top(): empty stack");
	}

	// return copy of last element 
	cout << "The top element in the respective data type of the stack is: " << endl;
	return elements.back();
}

int main() 
{
	try 
	{
		Stack<int>intStack;  // stack of ints 
		Stack<float>floatStack;
		Stack<string> stringStack;    // stack of strings 

		// manipulate int stack 
		intStack.push(10);
		intStack.push(20);
		floatStack.push(30.5);
		floatStack.push(70.5);
		cout << floatStack.top() << endl;
		cout << intStack.top() << endl;

		// manipulate string stack 
		stringStack.push("hello");
		stringStack.push("World");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		floatStack.pop();
		intStack.pop();
		cout << floatStack.top() << endl;
		cout << intStack.top() << endl;
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		floatStack.pop();
		intStack.pop();
		floatStack.pop();
		intStack.pop();
		
	}
	catch (exception const& ex) 
	{
		//cout << "Stack is empty" << endl;
		cerr << "Exception: " << ex.what() << endl;
		return -1;
	}
}