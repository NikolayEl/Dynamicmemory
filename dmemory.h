#pragma once
#include <iostream>
#include<ctime>

using namespace std;

//Прототипы функций одномерных массивов
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void PushFront(int*& arr, int& n, const int number_front);
void PushBack(int*& arr, int& n, const int number);
void Insert(int*& arr, int& n, const int number_index, const int index);
void PopBack(int*& arr, int& n);
void PopFront(int*& arr, int& n);
void Erase(int*& arr, int& n, const int index);

//Прототипы функции двумерных массивов без шаблона
int** IntAllocate(const int ROWS, const int COLS);
double** DoubleAllocate(const int ROWS, const int COLS);
char** CharAllocate(const int ROWS, const int COLS);

void FillRand(double** arr_dual, int ROWS, const int COLS);
void FillRand(int** arr_dual, int ROWS, const int COLS);
void FillRand(char** arr_dual, int ROWS, const int COLS);

//Прототипы функции двумерных массивов с шаблоном
template <typename T> void Print(T** arr, const int ROWS, const int COLS);
template <typename T> T** Push_Row_Back(T** arr_dual, int& ROWS, const int COLS);
template <typename T> void Push_Col_Back(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Push_Row_Front(T**& arr_dual, int& ROWS, const int COLS);
template <typename T> void Push_Col_Front(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Insert_Row(T** arr_dual, int& ROWS, const int COLS, const int index);
template <typename T> void Insert_Col(T** arr_dual, const int ROWS, int& COLS, const int index);