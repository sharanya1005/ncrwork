#include<string>
#include<stack>
#include<iostream>
using namespace std;

int addition(int, int);
int subtraction(int, int);
long int multiplication(long int, long int);
float division(int, int);

bool balancing_paranthesis(string input)//to check in the input string entered whether paranthesis are balanced or not
{
	stack<char> sta;

	char ch;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(' || input[i] == '[' || input[i] == '{')//if any opening bracket encounters
		{
			sta.push(input[i]);//push them on to the stack
			continue;//continue
		}

		if (sta.empty())///if the stack is empty return 1
			return true;

		switch (input[i])// to check for the closing brackets
		{
		case ')':       //if this is encountered then store the top element on stack in ch and pop that element if the 
			ch = sta.top();  //element stored is the opening bracket of other type then return 0 
			sta.pop();       //otherwise break from this case
			if (ch == '{' || ch == '[')
				return false;
			break;

		case '}':
			ch = sta.top();
			sta.pop();
			if (ch == '(' || ch == '[')
				return false;
			break;

		case ']':
			ch = sta.top();
			sta.pop();
			if (ch == '(' || ch == '{')
				return false;
			break;
		}
	}
	return (sta.empty());
}

int postfixevaluation(string str)
{
	stack<double> st;
	double left_operand, right_operand;
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]))
		{
			double a = (double)str[i];

			st.push(a - '0');
		}
		else
		{
			if (str[i] == '*')
			{
				left_operand = st.top();
				st.pop();
				right_operand = st.top();
				st.pop();
				long int result = multiplication(right_operand, left_operand);
				st.push(result);
			}
			if (str[i] == '/')
			{
				left_operand = st.top();
				st.pop();
				right_operand = st.top();
				st.pop();
				float result = division(right_operand, left_operand);
				st.push(result);
			}
			if (str[i] == '+')
			{
				left_operand = st.top();
				st.pop();
				right_operand = st.top();
				st.pop();
				int result = addition(right_operand, left_operand);
				st.push(result);
			}
			if (str[i] == '-')
			{
				left_operand = st.top();
				st.pop();
				right_operand = st.top();
				st.pop();
				int str = subtraction(right_operand, left_operand);
				st.push(str);
			}
		}

	}
	cout << endl << "Result is: " << st.top();
	return 0;
}


int precedence(char ch)
{
	if (ch == ')')
		return 5;
	else if (ch == ']')
		return 4;
	else if (ch == '}')
		return 3;
	else
		if (ch == '*' || ch == '/')
			return 2;

		else if (ch == '+' || ch == '-')
			return 1;

		else
			return -2;
}


int main()
{
	stack<char> inp;
	string input, postfix_string, postfix_value;
	cout << "Enter the expression to evaluate: " << endl;
	cin >> input;

	if (!balancing_paranthesis(input))
	{
		cout << "The data entered is invalid" << endl;
		getchar();
		return 0;
	}
	else
	{
		cout << "The paranthesis are balanced" << endl;

		int len = input.length();
		char ch;

		for (int i = 0; i < len; i++)
		{
			ch = input[i];
			if (ch >= '0' && ch <= '9')
			{
				postfix_string += input[i];
			}
			else
				if (inp.empty())
				{
					inp.push(ch);
					ch = inp.top();
				}
				else
				{
					if (precedence(ch) > precedence(inp.top()))
					{
						if (precedence(ch) == 5)
						{
							while (inp.top() != '(')
							{
								postfix_string += inp.top();
								inp.pop();
							}
							inp.pop();
						}
						else
							if (precedence(ch) == 4)
							{
								while (inp.top() != '[')
								{
									postfix_string += inp.top();
									inp.pop();
								}
								inp.pop();
							}
							else
								if (precedence(ch) == 3)
								{
									while (inp.top() != '{')
									{
										postfix_string += inp.top();
										inp.pop();
									}
									inp.pop();
								}
								else
									inp.push(ch);

					}
					else
						if (precedence(ch) == 1)
						{
							inp.push(ch);
						}
						else
						{
							while (!inp.empty())
							{
								if (inp.top() != '(' && inp.top() != '[' && inp.top() != '{')
								{
									postfix_string += inp.top();
									inp.pop();
								}
								else
									break;
							}
							inp.push(ch);
						}
				}
		}


		while (!inp.empty())
		{
			postfix_string += inp.top();
			inp.pop();
		}


		postfixevaluation(postfix_string);
	}
	getchar();
	return 0;
}