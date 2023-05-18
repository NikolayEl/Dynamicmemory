#pragma once

using namespace std;

//#define ONE_DYNAMIC_ARRAY
//#define PREFORMANCE_TEST
#define TWO_DYNAMIC_ARRAY

int** Allocate(const int ROWS, const int COLS);
void Clear(int**& arr_dual, const int ROWS);

void FillRand(int arr[], const int n);

void FillRand(int** arr, int ROWS, const int COLS);

void Print(int arr[], const int n);

void Print(int** arr, const int ROWS, const int COLS);

void PushBack(int*& arr, int& n, const int number);

int** Push_Row_Back(int** arr_dual, int& ROWS, const int COLS);
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

int** Pop_Row_Front(int** arr_dual, int& ROWS, const int COLS);
void Pop_Cols_Front(int** arr_dual, const int ROWS, int& COLS);

void Erase(int*& arr, int& n, const int index);

int** Erase_Row(int** arr_dual, int& ROWS, const int COLS, const int index);
void Erase_Cols(int** arr_dual, const int ROWS, int& COLS, const int index);