#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void PushBack(int *&arr, const int n, const int number);
void PushFront(int*& arr, const int n, const int number_front);
void Insert(int*& arr, const int n, const int number_index, const int index);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

#ifdef PUSH_BACK

	// -----------------------------------------------------------------------
	// Добавляем элемент в конец массива
	int value;
	cout << "Введите добавляемый элемент: "; cin >> value;
	PushBack(arr, n, value);
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
	n++;
	Print(arr, n); 
#endif //PUSH_BACK

#ifdef PUSH_FRONT

	//-------------------------------------------------------------------------
	// Добавляем элемент в начало массива

	int number_front;
	cout << "Введите число, добавляемое в начало: "; cin >> number_front;
	PushFront(arr, n, number_front);
	n++;
	Print(arr, n);

#endif //PUSH_FRONT

	//-------------------------------------------------------------------------
	// Добавляем значение по указанному индексу

	int number_index, index;
	cout << "Введите число, которое вы хотите добавить"; cin >> number_index;
	cout << "Введите номер положения числа в массиве ,куда вы хотите его добавить от 1 до " << n << " :"; cin >> index;
	Insert(arr, n, number_index, index);
	n++;
	Print(arr, n);
	
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void PushBack(int*& arr, const int n, const int number)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = number;
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
}

void PushFront(int*& arr, const int n, const int number_index)
{
	int* buffer = new int[n + 1];
	buffer[0] = number_index;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}

void Insert(int*& arr, const int n, const int number_index, const int index)
{
	int* buffer = new int[n + 1];
	bool exam = true;
	for (int i = 0, j = 0; i < n; i++, j++)
	{
		if ((i == index - 1)&&exam)
		{
			buffer[j] = number_index;
			i--;
			exam = false;
			continue;
		}
		else buffer[j] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
}