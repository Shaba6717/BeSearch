// bisearch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>


using namespace std;

int bi_search(int *array, int left, int right, int key);
int* create_array(const int len);
void print_array(int* array, const int len);
void sort_array(int* a, const int size);
void heap_create(int* array, int root, const int len);
void swap(int &a, int &b);

int main()
{
	const int size = 11;
	int* arr = create_array(size);

	print_array(arr, size);
	sort_array(arr, size);
	print_array(arr, size);

	/*int answer = bi_search(arr, 0, size, 141);
	cout << "\nFind 141\tAnswer = " << answer << endl;

	answer = bi_search(arr, 0, size, 34);
	cout << "\nFind 34 \tAnswer = " << answer << endl;

	answer = bi_search(arr, 0, size, 364);
	cout << "\nFind 364\tAnswer = " << answer << endl;

	answer = bi_search(arr, 0, size, 1564);
	cout << "\nFind 1564\tAnswer = " << answer << endl;

	answer = bi_search(arr, 0, size, 967);
	cout << "\nFind 967\tAnswer = " << answer << endl;

	answer = bi_search(arr, 0, size, 300);
	cout << "\nFind 300\tAnswer = " << answer << endl;*/

	system("pause");
	delete [] arr;
    return 0;
}

int* create_array(const int len)
{
	if (len <= 0)
	{
		cout << "\nError create" << endl;
		return nullptr;
	};

	int* newArray = new int[len];
	for (int i = 0; i < len; i++)
	{
		newArray[i] = 10 + rand() % 100;
	}

	return newArray;
}

void print_array(int* array, const int len)
{
	if (array == nullptr || len <= 0)  cout << "\nError print" << endl;
	else
	{
		for (int i = 0; i < len; i++)
		{
			cout << array[i] << "\t";
		};

		cout << "\n\n";
	}	
}

void sort_array(int* array, const int len)
{
	long i;
	
	// строим кучу
	for (i = len / 2 - 1; i >= 0; --i)
		heap_create(array, i, len - 1);	

	// просеиваем элемент
	for (i = len - 1; i > 0; --i)
	{
		
		swap(array[0], array[i]);		
		heap_create(array, 0, i - 1);
	}

	
}

void heap_create(int* array, int root, const int len)
{
	int maxElem;
	int child;
	maxElem = array[root];

	while (root <= len / 2) 
	{
		child = 2 * root;

		if (child < len && array[child] < array[child + 1]) 
			child++;
		if (maxElem >= array[child])
			break;
		
		array[root] = array[child];    
		root = child;
	}
	array[root] = maxElem;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int bi_search(int *array, int left, int right, int key)
{
	if (array == nullptr)  return -2;

	int mid = left + int((right-left) / 2);	
	
	if (key < array[left] || key > array[right-1]) 
		return -1;

	if (array[left] == key)
		return left + 1;

	if (array[right-1] == key)
		return right;
	 
	if (array[mid] == key) 
		return mid + 1;	
	else
	{
		if (key > array[mid]) 
			bi_search(array, mid, right-1, key);
		else 
			bi_search(array, left, mid + 1, key);
	}
		
}
