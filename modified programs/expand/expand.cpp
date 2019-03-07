#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int checking_range(char ch1, char ch2);
int expand_string(char input_str[], char output_str[]);

int checking_range(char ch1, char ch2)
{
	if ((ch1 >= 'a'  && ch1 <= 'z') && (ch1 <= ch2 && ch2 <= 'z'))//condition to check if ch1 and ch2 are lower case letters
		return 1;
	else if ((ch1 >= 'A'  && ch1 <= 'Z') && (ch1 <= ch2 && ch2 <= 'Z'))//condition to check if ch1 and ch2 are upper case letters
		return 1;
	else if ((ch1 >= '0'  && ch1 <= '9') && (ch1 <= ch2 && ch2 <= '9'))//condition to check if ch1 and ch2 are numbers
		return 1;
	else
		return 0; //if the entered is not a lower case or upper case or digit
}


int expand_string(char input_str[], char output_str[])
{
	int i, j, ch;
	i = j = 0;

	while ((ch = input_str[i++]) != '\0')//to check till the end of character in a string from first character
	{
		if (!(ch >= 'a'&& ch <= 'z') && !(ch >= 'A'&& ch <= 'Z') && !(ch == '-') && !(ch >= '0'&&ch <= '9'))//condition to check what type of data is entered

		{
			cout << "The input entered is not valid. Please enter valid data either alphabets or digits butnot special characters\n";
			system("pause");
			return 0;
		}

		if (input_str[i] == '-' && input_str[i + 1] >= ch)//if a hyphen exists and to check its left and right whether they are valid
		{
			i++;
			while (ch < input_str[i])//if left side is less than right side of the hyphen
				output_str[j++] = ch++;//expand
		}
		else
			output_str[j++] = ch;//print the character given unless it reaches EOS

		output_str[j] = '\0';

	}
	cout << "\nThe expanded notation of the given input string is : " << output_str << endl;
	getchar();
	return 0;
}

int main()
{
	char input_str[50], output_str[50], i = 0;
	printf("Enter the input string which to be expanded: ");
	cin >> input_str;
	int len = strlen(input_str);
	while (i != len)
	{
		if (input_str[i] == '-')
		{
			if (!checking_range(input_str[i - 1], input_str[i + 1]))//if it is not in valid range
			{
				cout << "The input entered is invalid.\n";
				system("pause");
				return 0;
			}
			else
			{
				i++;
			}

		}
		else
			i++;
	}

	expand_string(input_str, output_str);
	system("pause");
	return 0;
}