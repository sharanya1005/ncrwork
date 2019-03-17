/* generic function template to carry out linear search with the following
a. Demonstrate it for int, double and float data types
b. Use default arguments in the template function
c. Write an explicit specialization of the generic template for char* data type */

#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
template <class T>
T linear_search(T array[], int size_arr, T element)//function for int,double and float data types
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (array[count] == element)
		{
			flag = 1;
			cout << "Element "<<element<<" is found at location " << count << " in the input array" << endl;
			break;
		}
	}
	if(flag == 0)
	cout << "The element  "<<element<<" you want to search for is not present in the input array" << endl;
	return flag;
}
int linear_search(char *array[], int size_arr, char *element)//explicit specialisation for char data type
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (strcpy_s(array[count], sizeof(size_arr) ,element) == 0)
		{
			flag = 1;
			cout << "Element " << element << " is found at location " << count << " in the input array" << endl;
			break;
		}
	}
	if (flag == 0)
		cout << "The element " << element << " you want to search for is not present in the input array" << endl;
	return flag;
}
int main()
{
	/*int array[30];
	int *arr_int, size_IntArr, size_str, result,element;
	cout << "enter the size of integer array\n";
	cin >> size_IntArr;
	arr_int = new int[size_IntArr];
	cout << "enter the integer array elements\n";
	for (int count = 0;count < size_IntArr;count++)
	{
		cin >> array[count];
	}
	cout << "Enter the element you want to search for: " << endl;
	cin >> element;
	linear_search(array, size_IntArr, element);
	//int linearsearch<int>(array, size_IntArr, element);
	*/
	int a[5] = { 10, 20, 30, 40, 50 };
	linear_search<int>(a, 5, 30);
	linear_search<int>(a, 5, 100);
	float b[7] = { 1.5, 2.5, 3.5, 4.5, 5.5,6.5,7.5};
	linear_search<float>(b, 7, 4.5);
	linear_search<float>(b, 7, 10.5);
	char c[10] = { 'a', 'b','c', 'd','e','f','g','h','i','j' };
	linear_search<char>(c, 10, 'g');
	linear_search<char>(c, 10, 's');

}