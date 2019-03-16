#include <iostream>
using namespace std;
template <class T>
int linear_search(T array[], int size_arr, T element)
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (array[count] == element)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int linear_search(char *array[], int size_arr, char *element)
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (strcpy(array[count], element) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	int *arr_int, size_IntArr, size_str, result;
	//char *arr_char;
	char **arr_string;
	cout << "enter the size of integer array\n";
	cin >> size_IntArr;
	arr_int = new int[size_IntArr];
	cout << "enter the integer array elements\n";
	for (int count = 0;count < size_IntArr;count++)

}