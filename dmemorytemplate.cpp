#include "dmemory.h"

template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << "\t";
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
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = number_index;
	for (int i = index + 1; i < n + 1; i++) buffer[i] = arr[i - 1];
	delete[] arr;
	n++;
	arr = buffer;
}


template <typename T> void Erase(T*& arr, int& n, const int index)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index + 1; i < n; i++) buffer[i - 1] = arr[i];
	delete[] arr;
	arr = buffer;
	n--;
}

template <typename T> void PopBack(T*& arr, int& n)
{
	Erase(arr, n, n - 1);
}

template <typename T> void PopFront(T*& arr, int& n)
{
	Erase(arr, n, 0);
}

//������� ���������� ������������� ������� � �������� (������������ � main)

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
		for (int j = 0; j < COLS; j++)
		{
			cout << arr_dual[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T> T** Push_Row_Back(T** arr_dual, int& ROWS, const int COLS)
{
	return Insert_Row(arr_dual, ROWS, COLS, ROWS);
}

template <typename T> void Push_Col_Back(T** arr_dual, const int ROWS, int& COLS)
{
	Insert_Col(arr_dual, ROWS, COLS, COLS);
}

template <typename T> T** Push_Row_Front(T**& arr_dual, int& ROWS, const int COLS)
{
	return Insert_Row(arr_dual, ROWS, COLS, 0);
}

template <typename T> void Push_Col_Front(T** arr_dual, const int ROWS, int& COLS)
{
	Insert_Col(arr_dual, ROWS, COLS, 0);
}

template <typename T> T** Insert_Row(T** arr_dual, int& ROWS, const int COLS, const int index)
{
	T** buffer = new T * [++ROWS];
	for (int i = 0; i < index; i++)buffer[i] = arr_dual[i];
	buffer[index] = new T[COLS]{};
	for (int i = index + 1; i < ROWS; i++)buffer[i] = arr_dual[i - 1];
	delete[] arr_dual;
	arr_dual = buffer;
	return arr_dual;
}

template <typename T> void Insert_Col(T** arr_dual, const int ROWS, int& COLS, const int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS + 1]{};
		for (int j = 0; j < index; j++) buffer[j] = arr_dual[i][j];
		for (int j = index + 1; j < COLS + 1; j++) buffer[j] = arr_dual[i][j - 1];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
	COLS++;
}

template <typename T> T** Pop_Row_Back(T** arr_dual, int& ROWS, const int COLS)
{
	return Erase_Row(arr_dual, ROWS, COLS, ROWS - 1);
}

template <typename T> void Pop_Cols_Back(T** arr_dual, const int ROWS, int& COLS)
{
	Erase_Cols(arr_dual, ROWS, COLS, COLS - 1);
}

template <typename T> T** Pop_Row_Front(T** arr_dual, int& ROWS, const int COLS)
{
	return Erase_Row(arr_dual, ROWS, COLS, 0);
}

template <typename T> void Pop_Cols_Front(T** arr_dual, const int ROWS, int& COLS)
{
	Erase_Cols(arr_dual, ROWS, COLS, 0);
}

template <typename T> T** Erase_Row(T** arr_dual, int& ROWS, const int COLS, const int index)
{
	delete arr_dual[index];
	T** buffer = new T * [--ROWS];
	for (int i = 0; i < index; i++) buffer[i] = arr_dual[i];
	for (int i = index + 1; i < ROWS + 1; i++) buffer[i - 1] = arr_dual[i];
	delete[] arr_dual;
	return buffer;
}

template <typename T> void Erase_Cols(T** arr_dual, const int ROWS, int& COLS, const int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr_dual[i][j];
		for (int j = index; j < COLS - 1; j++) buffer[j] = arr_dual[i][j + 1];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
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