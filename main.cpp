#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT
//#define ERASE
#define POINTER_ARITHMETIC

void FillRand(int arr[], const int n);

void FillRand(int** arr, const int ROWS, const int COLS);

void Print(int arr[], const int n);

void Print(int** arr, const int ROWS, const int COLS);

void PushBack(int *&arr, int& n, const int number);
void PushFront(int*& arr, int& n, const int number_front);
void Insert(int*& arr, int& n, const int number_index, const int index);
void PopBack(int*& arr, int& n);
void PopFront(int*& arr, int& n);
void Erase(int*& arr, int& n, const int index);


void main()
{
	setlocale(LC_ALL, "");
	//int n;
	//cout << "Введите размер массива: "; cin >> n;
	//int* arr = new int[n];
	//FillRand(arr, n);
	//cout << "Исходный массив:" << endl;
	//Print(arr, n);
	//cout << "Конец исходного массива" << endl << endl;


#ifdef PUSH_BACK

	// -----------------------------------------------------------------------
	// Добавляем элемент в конец массива
	int value;
	cout << "Введите добавляемый элемент: "; cin >> value;
	PushBack(arr, n, value);
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
	cout << "Добавили в конец массива число " << value << ":" << endl;
	Print(arr, n); cout << endl;
#endif //PUSH_BACK

#ifdef PUSH_FRONT

	//-------------------------------------------------------------------------
	// Добавляем элемент в начало массива

	int number_front;
	cout << "Введите число, добавляемое в начало: "; cin >> number_front;
	PushFront(arr, n, number_front);
	cout << "Добавили в начало массива число " << number_front << ":" << endl;
	Print(arr, n); cout << endl;

#endif //PUSH_FRONT


#ifdef INSERT
	//-------------------------------------------------------------------------
	// Добавляем значение по указанному индексу

	int number_index, index;
	cout << "Введите число, которое вы хотите добавить: "; cin >> number_index;
	cout << "Введите номер положения числа в массиве ,куда вы хотите его добавить от 1 до " << n << " :"; cin >> index;
	Insert(arr, n, number_index, index);
	cout << "Добавили число " << number_index << " по индексу " << index << ":" << endl;
	Print(arr, n); cout << endl;

#endif //INSERT

#ifdef POP_BACK
	//-------------------------------------------------------------------------
	// Удаляем последний элемент массива
	PopBack(arr, n);
	cout << "Удалили последний элемент массива:" << endl;
	Print(arr, n); cout << endl;

#endif //POP_BACK

#ifdef POP_FRONT
	//--------------------------------------------------------------------------
	// Удаляем нулевой элемент массива
	PopFront(arr, n);
	cout << "Удалили нулевой элемент массива:" << endl;
	Print(arr, n);

#endif // POP_FRONT
	
#ifdef ERASE
	//--------------------------------------------------------------------------
	// Удаляем элемент из массива по указанному индексу
	int index_erase;
	cout << "Укажите индекс удаляемого числа (от 1 до 5): "; cin >> index_erase;
	Erase(arr, n, index_erase);
	cout << "Удалили число по индексу " << index_erase << ":" << endl;
	Print(arr, n); cout << endl;

	delete[] arr;
#endif //ERASE



	int rows = 3, cols = 4, k = 0, l = 0;
	//cout << "Введите кол-во строк: "; cin >> rows;
	//cout << "Введите кол-во столбцов: "; cin >> cols;
	
	int** arr_dual = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr_dual[i] = new int[cols];
	}
	FillRand(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

#ifdef POINTER_ARITHMETIC
	// -------------------------------------------------------------------------------------------------------------
	// Вывод при помощи арифметики указателей
	cout << "Вывод при помощи арифметики указателей" << endl;
	for (int i = 0; i < rows; i++)
	{
		if (i == 1)k = (&arr_dual[1][0] - &arr_dual[0][0]);  //так как между двумя строками значение не постоянное, вычисляем ег ов переменную
		if (i == 2)l = (&arr_dual[2][0] - &arr_dual[1][0]);  //так как между 2 и 3 строкой значение не равное разгницы между 1 и 2 строкой, вычисляем его так же отдельно
		for (int j = 0; j < cols; j++)
		{
			cout << *(*arr_dual + k + l + j) << " ";
		}
		cout << endl;
	}
#endif POINTER_ARITHMETIC

	delete[] arr_dual;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr_dual, const int ROWS, const int COLS)
{
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)arr_dual[i][j] = rand() % 12;
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

void Print(int** arr_dual, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr_dual[i][j] << " ";
		}
		cout << endl;
	}
		
	
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
	int* buffer = new int[n - 1];
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

void Erase(int*& arr, int& n, const int index)
{
	int* buffer = new int[n - 1];
	bool exam = true;
	for (int i = 0, j = 0; i < n; i++, j++)
	{
		if ((i == index - 1) && exam) 
		{
			exam = false;
			j--;
			continue;
		}
		buffer[j] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	//cout << arr[n] << endl; //Проверка что выбранный элемент действительно удален и в памяти больше нет чисел из массива!
}