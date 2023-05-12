#include <iostream>
#include<ctime>
using namespace std;


//#define ONE_DYNAMIC_ARRAY


//#define PREFORMANCE_TEST

#define TWO_DYNAMIC_ARRAY

int** Allocate(const int ROWS, const int COLS);
void Clear(int** &arr_dual, const int ROWS);

void FillRand(int arr[], const int n);

void FillRand(int** arr, int ROWS, const int COLS);

void Print(int arr[], const int n);

void Print(int** arr, const int ROWS, const int COLS);

void PushBack(int *&arr, int& n, const int number);

int** Push_Row_Back(int** arr_dual, int &ROWS, const int COLS);
void Push_Col_Back(int** arr_dual, const int ROWS, int& COLS);

void PushFront(int*& arr, int& n, const int number_front);

int** Push_Row_Front(int**& arr_dual, int& ROWS, const int COLS);
void Push_Col_Front(int** arr_dual, const int COLS, int& ROWS);


void Insert(int*& arr, int& n, const int number_index, const int index);

int** Insert_Row(int** arr_dual, int& ROWS, const int COLS, const int index);
void Insert_Col(int** arr_dual, const int ROWS, int& COLS, const int index);

void PopBack(int*& arr, int& n);

int** Pop_Row_Back(int** arr_dual, int& ROWS, const int COLS);
void Pop_Cols_Back(int** arr_dual, const int ROWS, int& COLS);

void PopFront(int*& arr, int& n);

int** Pop_Row_Front(int**& arr_dual, int& ROWS, const int COLS);
int** Pop_Cols_Front(int**& arr_dual, const int ROWS, int& COLS);

void Erase(int*& arr, int& n, const int index);

int** Erase_Row(int**& arr_dual, int& ROWS, const int COLS, const int index);
int** Erase_Cols(int**& arr_dual, const int ROWS, int& COLS, const int index);


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


#ifdef ONE_DYNAMIC_ARRAY

	// -----------------------------------------------------------------------
	// Добавляем элемент в конец массива
	int value;
	cout << "Введите добавляемый элемент: "; cin >> value;
	PushBack(arr, n, value);
	//cout << &arr << endl; //проверка адреса массива - УСПЕШНО, работаем именно с одним и тем же массивом
	cout << "Добавили в конец массива число " << value << ":" << endl;
	Print(arr, n); cout << endl;

	//-------------------------------------------------------------------------
	// Добавляем элемент в начало массива

	int number_front;
	cout << "Введите число, добавляемое в начало: "; cin >> number_front;
	PushFront(arr, n, number_front);
	cout << "Добавили в начало массива число " << number_front << ":" << endl;
	Print(arr, n); cout << endl;

	//-------------------------------------------------------------------------
	// Добавляем значение по указанному индексу

	int number_index, index;
	cout << "Введите число, которое вы хотите добавить: "; cin >> number_index;
	cout << "Введите номер положения числа в массиве ,куда вы хотите его добавить от 1 до " << n << " :"; cin >> index;
	Insert(arr, n, number_index, index);
	cout << "Добавили число " << number_index << " по индексу " << index << ":" << endl;
	Print(arr, n); cout << endl;

	//-------------------------------------------------------------------------
	// Удаляем последний элемент массива
	PopBack(arr, n);
	cout << "Удалили последний элемент массива:" << endl;
	Print(arr, n); cout << endl;

	//--------------------------------------------------------------------------
	// Удаляем нулевой элемент массива
	PopFront(arr, n);
	cout << "Удалили нулевой элемент массива:" << endl;
	Print(arr, n);

	//--------------------------------------------------------------------------
	// Удаляем элемент из массива по указанному индексу
	int index_erase;
	cout << "Укажите индекс удаляемого числа (от 1 до 5): "; cin >> index_erase;
	Erase(arr, n, index_erase);
	cout << "Удалили число по индексу " << index_erase << ":" << endl;
	Print(arr, n); cout << endl;

	delete[] arr;
#endif ONE_DYNAMIC_ARRAY

#ifdef TWO_DYNAMIC_ARRAY
	//---------------------------------------------------------------------------------------------------------------
	// Двумерные динамические массивы
	int rows, cols;
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во столбцов: "; cin >> cols;

	int** arr_dual = Allocate(rows, cols);
	FillRand(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

	// -------------------------------------------------------------------------------------------------------------
	// Вывод при помощи арифметики указателей
	cout << "Вывод при помощи арифметики указателей" << endl;
	int k = 0, l = 0;
	//for (int i = 0; i < rows; i++)
	//{
	//	if (i == 1)k = (&arr_dual[1][0] - &arr_dual[0][0]);  //так как между двумя строками разница не постоянная, вычисляем её и записываем в переменную
	//	if (i == 2)l = (&arr_dual[2][0] - &arr_dual[1][0]);  //так как между 2 и 3 строкой разница не равна разнице между 1 и 2 строкой, вычисляем её так же отдельно
	//	for (int j = 0; j < cols; j++)
	//	{
	//		cout << *(*arr_dual + k + l + j) << " ";
	//	}
	//	cout << endl;
	//}



	// ---------------------------------------------------------------------------------------------------------
	// Добавляем в конец пустую строку
	cout << endl << "Добавляем в конец динамического массива пустую строку" << endl;
	arr_dual = Push_Row_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");

	//------------------------------------------------------------------------------------------------
	// Добавляем столбец в конец динамического массива

	cout << endl << "Добавляем столбец в конец динамического массива" << endl;
	Push_Col_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");
	//------------------------------------------------------------------------------------------------------------
	// Добавляем пустую строку в начало динамического массива

	cout << endl << "Добавляем пустую строку в начало динамического массива" << endl;
	arr_dual = Push_Row_Front(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");

	//---------------------------------------------------------------------------------------------------------
	// добавляет пустой столбец в начало двумерного динамического массива

	cout << endl << "Добавляем пустой столбец в начало" << endl;
	Push_Col_Front(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");

	//----------------------------------------------------------------------------------------------------------
	// вставляет пустую строку в двумерный динамический массив по заданному индексу
	cout << endl << "Вставляем пустую строку в двумерный динамический массив по заданному индексу" << endl;

	int index_row;
	cout << "Задайте индекс строки от 0 до " << rows << ": "; cin >> index_row; //Так как мы можем вставить в самый конец массива, потому мы пишем rows целиком (без вычетания)
	arr_dual = Insert_Row(arr_dual, rows, cols, index_row);
	Print(arr_dual, rows, cols);
	system("PAUSE");
	//---------------------------------------------------------------------------------------------
	// вставляет пустой столбец в двумерный динамический массив по заданному индексу
	cout << endl << "Вставляем пустой столбец в двумерный динамический массив по заданному индексу" << endl;

	int index_col;
	cout << "Укажите индекс куда будем вставлять столбец от 0 до " << cols << ": "; cin >> index_col;
	Insert_Col(arr_dual, rows, cols, index_col);
	Print(arr_dual, rows, cols);
	system("PAUSE");

	//------------------------------------------------------------------------------------
	// удаляет последнюю строку двумерного динамического массива
	cout << endl << "Удаляет последнюю строку двумерного динамического массива" << endl;
	arr_dual = Pop_Row_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");

	//-----------------------------------------------------------------------------------------------------------
	// удаляет столбец с конца двумерного динамического массива
	cout << endl << "Удаляем столбец с конца двумерного динамического массива" << endl;
	Pop_Cols_Back(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);
	system("PAUSE");
	//-----------------------------------------------------------------------------------------------------------
	//удаляет нулевую  строку двумерного динамического массива
	cout << endl << "Удаляем нулевую  строку двумерного динамического массива" << endl;
	arr_dual = Pop_Row_Front(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);


	//---------------------------------------------------------------------------------------------------------------
	//удаляет столбец с начала двумерного динамического массива
	cout << endl << "Удаляем столбец с начала двумерного динамического массива" << endl;
	arr_dual = Pop_Cols_Front(arr_dual, rows, cols);
	Print(arr_dual, rows, cols);

	//------------------------------------------------------------------------------------------------------------------
	// удаляет строку из двумерного динамического массива по заданному индексу
	cout << endl << "Удаляем строку из двумерного динамического массива по заданному индексу" << endl;

	int index_rows;
	cout << "Укажите индекс строки, которую хотите удалить от 0 до " << rows - 1 << ": "; cin >> index_rows;
	arr_dual = Erase_Row(arr_dual, rows, cols, index_rows);
	Print(arr_dual, rows, cols);

	//--------------------------------------------------------------------------------------------------------
	//удаляет столбец из двумерного динамического массива по заданному индексу
	cout << endl << "Удаляем столбец из двумерного динамического массива по заданному индексу" << endl;

	int index_cols;
	cout << "Введите индекс удаляемого столбца из двумерного динамического массива от 0 до " << cols - 1 << " : "; cin >> index_cols;
	arr_dual = Erase_Cols(arr_dual, rows, cols, index_cols);
	Print(arr_dual, rows, cols);

#endif TWO_DYNAMIC_ARRAY

#ifdef PREFORMANCE_TEST

	cout << "Память выделена, для добавления строки нажмите на любую клавишу" << endl;
	system("PAUSE");
	clock_t c_start = clock();
	arr_dual = Push_Row_Back(arr_dual, rows, cols);
	clock_t c_end = clock();
	cout << "Строка добавлена за: " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	system("PAUSE");


#endif PREFORMANCE_TEST
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
	arr_dual = nullptr;
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
			cout << arr_dual[i][j] << "\t";
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

int** Push_Row_Back(int** arr_dual, int &ROWS, const int COLS)
{
	int** buffer = new int*[++ROWS];
	for (int i = 0; i < ROWS - 1; i++) buffer[i] = arr_dual[i];
	delete[] arr_dual;
	arr_dual = buffer;
	arr_dual[ROWS - 1] = new int[COLS] {};
	return arr_dual;
}

void Push_Col_Back(int** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		//1) Создаем буферную строку:
		int* buffer = new int[COLS + 1] {};
		//2) Копируем все содержимое из исходной строки в буферную
		for (int j = 0; j < COLS; j++)buffer[j] = arr_dual[i][j];
		//3) Удаляем исходную строку
		delete[] arr_dual[i];
		//4) Записываем адрес новой строки в массив указателей
		arr_dual[i] = buffer;
	}
	COLS++;
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
	int** buffer = new int* [++ROWS];
	for (int i = 0; i < ROWS - 1; i++) buffer[i + 1] = arr_dual[i];
	delete[] arr_dual;
	arr_dual = buffer;
	arr_dual[0] = new int[COLS] {};
	return arr_dual;
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

int** Insert_Row(int** arr_dual, int& ROWS, const int COLS, const int index)
{
	int** buffer = new int* [++ROWS];
	for (int i = 0; i < index; i++)buffer[i] = arr_dual[i];
	buffer[index] = new int[COLS] {};
	for (int i = index + 1; i < ROWS; i++)buffer[i] = arr_dual[i - 1];
	delete[] arr_dual;
	arr_dual = buffer;
	return arr_dual;
}

void Insert_Col(int** arr_dual, const int ROWS, int& COLS, const int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS + 1] {};
		for (int j = 0; j < index; j++) buffer[j] = arr_dual[i][j];
		for (int j = index + 1; j < COLS + 1; j++) buffer[j] = arr_dual[i][j - 1];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
	COLS++;
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

void Push_Col_Front(int** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS + 1] {};
		for (int j = 0; j < COLS; j++) buffer[j + 1] = arr_dual[i][j];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
}

void Pop_Cols_Back(int** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS - 1] {};

	}
}

int** Pop_Row_Back(int** arr_dual, int& ROWS, const int COLS)
{
	int** buffer = new int*[--ROWS];
	for (int i = 0; i < ROWS; i++) buffer[i] = arr_dual[i];
	delete[] arr_dual;
	arr_dual = buffer;
	return arr_dual;
}

int** Pop_Row_Front(int**& arr_dual, int& ROWS, const int COLS)
{
	int** buffer = Allocate(--ROWS, COLS);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr_dual[i + 1][j];
		}
	}
	Clear(arr_dual, ROWS + 1);
	return buffer;
}

int** Pop_Cols_Front(int**& arr_dual, const int ROWS, int& COLS)
{
	int** buffer = Allocate(ROWS, --COLS);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr_dual[i][j + 1];
		}
	}
	Clear(arr_dual, ROWS);
	return buffer;
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

int** Erase_Row(int**& arr_dual, int& ROWS, const int COLS, const int index)
{
	int** buffer = Allocate(--ROWS, COLS);
	int temp = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i >= index) temp = 1;
			buffer[i][j] = arr_dual[i + temp][j];
		}
	}
	Clear(arr_dual, ROWS + 1);
	return buffer;
}

int** Erase_Cols(int**& arr_dual, const int ROWS, int& COLS, const int index)
{
	int** buffer = Allocate(ROWS, --COLS);
	int temp = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j >= index) temp = 1;
			if (j == 0 && i != 0 && j < index) temp = 0;
			buffer[i][j] = arr_dual[i][j + temp];
		}
	}
	Clear(arr_dual, ROWS);
	return buffer;
}