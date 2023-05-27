#include "dmemory.h"

template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T> void PushFront(T*& arr, int& n, const T number_front)
{
	Insert(arr, n, number_front, 0);
}

template <typename T> void PushBack(T*& arr, int& n, const T number)
{
	Insert(arr, n, number, n);
}

template <typename T> void Insert(T*& arr, int& n, T number_index, const int index)
{
	T* buffer = new T[++n];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = number_index;
	for (int i = index; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
}

template <typename T> void Erase(T*& arr, int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}

template <typename T> void PopBack(T*& arr, int& n)
{
	Erase(arr, n, n - 1);
}

template <typename T> void PopFront(T*& arr, int& n)
{
	Erase(arr, n, 0);
}

//Функции двумерного динамического массива с шаблоном (подключаемые в main)

template <typename T> T** Allocate(const int ROWS, const int COLS)
{
	T** arr_dual = new T* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr_dual[i] = new T[COLS];
	}
	return arr_dual;
}

template <typename T> void Print(T** arr_dual, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		Print(arr_dual[i], COLS);
	}
}

template <typename T> T** Push_Row_Back(T** arr_dual, int& ROWS, const int COLS)
{
	PushBack(arr_dual, ROWS, new T[COLS]{}); //функция pushback переопределяет массив указателей
	return arr_dual;
}

template <typename T> void Push_Col_Back(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		PushBack(arr_dual[i], COLS, T());
		COLS--; //компенсируем увеличение на один столбец
	}
	COLS++;
}

template <typename T> T** Push_Row_Front(T**& arr_dual, int& ROWS, const int COLS)
{
	PushFront(arr_dual, ROWS, new int[COLS] {});
	return arr_dual;
}

template <typename T> void Push_Col_Front(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		PushFront(arr_dual[i], COLS, T());
		COLS--;
	}
	COLS++;
}

template <typename T> T** Insert_Row(T** arr_dual, int& ROWS, const int COLS, const int index)
{
	Insert(arr_dual, ROWS, new T[COLS]{}, index);
	return arr_dual;
}

template <typename T> void Insert_Col(T** arr_dual, const int ROWS, int& COLS, const int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		Insert(arr_dual[i], COLS, T(), index);
		COLS--;
	}
	COLS++;
}

template <typename T> T** Pop_Row_Back(T** arr_dual, int& ROWS, const int COLS)
{
	delete[] arr_dual[ROWS - 1];
	PopBack(arr_dual, ROWS);
	return arr_dual;
}

template <typename T> void Pop_Cols_Back(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		PopBack(arr_dual[i], COLS);
		COLS++;
	}
	COLS--;
}

template <typename T> T** Pop_Row_Front(T** arr_dual, int& ROWS, const int COLS)
{
	delete[] arr_dual[0];
	PopFront(arr_dual, ROWS);
	return arr_dual;
}

template <typename T> void Pop_Cols_Front(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		PopFront(arr_dual[i], COLS);
		COLS++;
	}
	COLS--;
}

template <typename T> T** Erase_Row(T** arr_dual, int& ROWS, const int COLS, const int index)
{
	delete[] arr_dual[index];
	Erase(arr_dual, ROWS, index);
	return arr_dual;
}

template <typename T> void Erase_Cols(T** arr_dual, const int ROWS, int& COLS, const int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		Erase(arr_dual[i], COLS, index);
		COLS++;
	}
	COLS--;
}

template <typename T> void Clear(T**& arr_dual, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr_dual[i];
	}delete[] arr_dual;
	arr_dual = nullptr;
}