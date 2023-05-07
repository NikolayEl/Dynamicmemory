#include <iostream>
using namespace std;


//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT
//#define ERASE
//#define POINTER_ARITHMETIC
//#define ALLOCATE
//#define CLEAR
//#define PUSH_ROW_BACK
//#define POP_ROW_BACK
//#define PUSH_ROW_FRONT
#define PUSH_COL_FRONT

int** Allocate(const int ROWS, const int COLS);
void Clear(int** &arr_dual, const int ROWS);

void FillRand(int arr[], const int n);

void FillRand(int** arr, int ROWS, const int COLS);

void Print(int arr[], const int n);

void Print(int** arr, const int ROWS, const int COLS);

void PushBack(int *&arr, int& n, const int number);

int** Push_Row_Back(int** &arr_dual, int &ROWS, const int COLS);

void PushFront(int*& arr, int& n, const int number_front);

int** Push_Row_Front(int**& arr_dual, int& ROWS, const int COLS);

void Insert(int*& arr, int& n, const int number_index, const int index);
void PopBack(int*& arr, int& n);

int** Pop_Row_Back(int**& arr_dual, const int ROWS, int& COLS);

void PopFront(int*& arr, int& n);

int** Pop_Col_Front(int**& arr_dual, const int COLS, int& ROWS);

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

	//---------------------------------------------------------------------------------------------------------------
	// Двумерные динамические массивы

	int rows = 3, cols = 4;
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
	int k = 0, l = 0;
	for (int i = 0; i < rows; i++)
	{
		if (i == 1)k = (&arr_dual[1][0] - &arr_dual[0][0]);  //так как между двумя строками разница не постоянная, вычисляем её и записываем в переменную
		if (i == 2)l = (&arr_dual[2][0] - &arr_dual[1][0]);  //так как между 2 и 3 строкой разница не равна разнице между 1 и 2 строкой, вычисляем её так же отдельно
		for (int j = 0; j < cols; j++)
		{
			cout << *(*arr_dual + k + l + j) << " ";
		}
		cout << endl;
	}
#endif POINTER_ARITHMETIC

#ifdef ALLOCATE
	// -------------------------------------------------------------------------------------------------------------
	// Проверка функции Allocate
	int** arr_dual2 = Allocate(rows, cols);
	FillRand(arr_dual2, rows, cols);
	Print(arr_dual2, rows, cols);
	Clear (arr_dual2, rows);

#endif ALLOCATE

#ifdef CLEAR

	Clear(arr_dual, rows);
	Print(arr_dual, rows, cols);

#endif CLEAR

#ifdef PUSH_ROW_BACK
	// ---------------------------------------------------------------------------------------------------------
	// Добавляем в конец пустую строку
	cout << endl << "Добавляем в конец динамического массива пустую строку" << endl;
	arr_dual = Push_Row_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

#endif PUSH_ROW_BACK
	
#ifdef POP_ROW_BACK
	//------------------------------------------------------------------------------------------------
	// Добавляем столбец в конец динамического массива
	arr_dual = Pop_Row_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

#endif POP_ROW_BACK

#ifdef PUSH_ROW_FRONT
	//------------------------------------------------------------------------------------------------------------
	// Добавляем пустую строку в начало динамического массива

	cout << endl << "Добавляем пустую строку в начало динамического массива" << endl;
	arr_dual = Push_Row_Front(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

#endif PUSH_ROW_FRONT

#ifdef PUSH_COL_FRONT
	//---------------------------------------------------------------------------------------------------------
	// добавляет пустой столбец в начало двумерного динамического массива

#endif PUSH_COL_FRONT

	Clear(arr_dual, rows);
}
int** Allocate(const int ROWS, const int COLS)
{
	int** arr_dual = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr_dual[i] = new int[COLS];
	}
	return arr_dual;
}

void Clear(int** &arr_dual, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr_dual[i];
	}delete[] arr_dual;
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

int** Push_Row_Back(int** &arr_dual, int &ROWS, const int COLS)
{
	int** buffer = Allocate(++ROWS, COLS);
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr_dual[i][j];
		}
	}
	for (int i = 0; i < COLS; i++)buffer[ROWS -1][i] = 0;
	Clear(arr_dual, ROWS - 1);
	return buffer;
}

int** Pop_Row_Back(int**& arr_dual,const int ROWS, int &COLS)
{
	int** buffer = Allocate(ROWS, ++COLS);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j == COLS - 1)
			{
				buffer[i][j] = 0;
				continue;
			}
			buffer[i][j] = arr_dual[i][j];
		}
	}
	Clear(arr_dual, ROWS);
	return buffer;
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

int** Push_Row_Front(int**& arr_dual, int& ROWS, const int COLS)
{
	int** buffer = Allocate(++ROWS, COLS);
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i + 1][j] = arr_dual[i][j];
		}
	}
	for (int i = 0; i < COLS; i++)buffer[0][i] = 0;
	Clear(arr_dual, ROWS - 1);
	return buffer;
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

int** Pop_Col_Front(int**& arr_dual, const int COLS, int& ROWS)
{

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