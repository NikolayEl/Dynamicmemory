#include <iostream>
using namespace std;

//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void PushBack(int *&arr, int& n, const int number);
void PushFront(int*& arr, int& n, const int number_front);
void Insert(int*& arr, int& n, const int number_index, const int index);
void PopBack(int*& arr, int& n);
void PopFront(int*& arr, int& n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	cout << "Исходный массив:" << endl;
	Print(arr, n);
	cout << "Конец исходного массива" << endl << endl;

#ifdef PUSH_BACK

	// -----------------------------------------------------------------------
	// Добавляем элемент в конец массива
	int value;
	cout << "Введите добавляемый элемент: "; cin >> value;
	PushBack(arr, n, value);
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
	Print(arr, n); 
#endif //PUSH_BACK

#ifdef PUSH_FRONT

	//-------------------------------------------------------------------------
	// Добавляем элемент в начало массива

	int number_front;
	cout << "Введите число, добавляемое в начало: "; cin >> number_front;
	PushFront(arr, n, number_front);
	Print(arr, n);

#endif //PUSH_FRONT


#ifdef INSERT
	//-------------------------------------------------------------------------
	// Добавляем значение по указанному индексу

	int number_index, index;
	cout << "Введите число, которое вы хотите добавить: "; cin >> number_index;
	cout << "Введите номер положения числа в массиве ,куда вы хотите его добавить от 1 до " << n << " :"; cin >> index;
	Insert(arr, n, number_index, index);
	Print(arr, n);

#endif //INSERT

#ifdef POP_BACK
	//-------------------------------------------------------------------------
	// Удаляем последний элемент массива
	PopBack(arr, n);
	Print(arr, n);

#endif //POP_BACK

#ifdef POP_FRONT
	//--------------------------------------------------------------------------
	// Удаляем нулевой элемент массива
	PopFront(arr, n);
	Print(arr, n);

#endif // POP_FRONT
	
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

void PushBack(int*& arr, int& n, const int number)
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
	n++;
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
}

void PushFront(int*& arr, int& n, const int number_index)
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
	n++;
}

void Insert(int*& arr, int& n, const int number_index, const int index)
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
	n++;
}

void PopBack(int*& arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	//cout << arr[n] << endl; //Проверка что последний элемент действительно удален!
}

void PopFront(int*& arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	//cout << arr[n] << endl; //Проверка что первый элемент действительно удален и в памяти больше нет чисел из массива!
}