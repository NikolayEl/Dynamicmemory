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
	T* buffer = new T[n + 1];
	buffer[0] = number_front;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n++;
}

template <typename T> void PushBack(T*& arr, int& n, const T number)
{
	T* buffer = new T[n + 1];
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

template <typename T> void Insert(T*& arr, int& n, T number_index, const int index)
{
	T* buffer = new T[n + 1];
	bool exam = true;
	for (int i = 0, j = 0; i < n; i++, j++)
	{
		if ((i == index - 1) && exam)
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

template <typename T> void Erase(T*& arr, int& n, const int index)
{
	T* buffer = new T[n - 1];
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

template <typename T> void PopBack(T*& arr, int& n)
{
	T* buffer = new T[n - 1];
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

template <typename T> void PopFront(T*& arr, int& n)
{
	T* buffer = new T[n - 1];
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
		for (int j = 0; j < COLS; j++)
		{
			cout << arr_dual[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T> T** Push_Row_Back(T** arr_dual, int& ROWS, const int COLS)
{
	T** buffer = new T * [++ROWS];
	for (int i = 0; i < ROWS - 1; i++) buffer[i] = arr_dual[i];
	delete[] arr_dual;
	arr_dual = buffer;
	arr_dual[ROWS - 1] = new T[COLS]{};
	return arr_dual;
}

template <typename T> void Push_Col_Back(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		//1) Создаем буферную строку:
		T* buffer = new T[COLS + 1]{};
		//2) Копируем все содержимое из исходной строки в буферную
		for (int j = 0; j < COLS; j++)buffer[j] = arr_dual[i][j];
		//3) Удаляем исходную строку
		delete[] arr_dual[i];
		//4) Записываем адрес новой строки в массив указателей
		arr_dual[i] = buffer;
	}
	COLS++;
}

template <typename T> T** Push_Row_Front(T**& arr_dual, int& ROWS, const int COLS)
{
	T** buffer = new T * [++ROWS];
	for (int i = 0; i < ROWS - 1; i++) buffer[i + 1] = arr_dual[i];
	delete[] arr_dual;
	arr_dual = buffer;
	arr_dual[0] = new T[COLS]{};
	return arr_dual;
}

template <typename T> void Push_Col_Front(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS + 1]{};
		for (int j = 0; j < COLS; j++) buffer[j + 1] = arr_dual[i][j];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
	COLS++;
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
	delete[] arr_dual[ROWS - 1];
	T** buffer = new T * [--ROWS];
	for (int i = 0; i < ROWS; i++) buffer[i] = arr_dual[i];
	delete[] arr_dual;
	return buffer;
}

template <typename T> void Pop_Cols_Back(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < COLS - 1; j++) buffer[j] = arr_dual[i][j];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
	COLS--;
}

template <typename T> T** Pop_Row_Front(T** arr_dual, int& ROWS, const int COLS)
{
	T** buffer = new T * [--ROWS];
	for (int i = 0; i < ROWS; i++)buffer[i] = arr_dual[i + 1];
	delete[] arr_dual;
	return buffer;
}

template <typename T> void Pop_Cols_Front(T** arr_dual, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < COLS - 1; j++)buffer[j] = arr_dual[i][j + 1];
		delete[] arr_dual[i];
		arr_dual[i] = buffer;
	}
	COLS--;
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