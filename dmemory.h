#pragma once
#include <iostream>
#include<ctime>

using namespace std;

//Прототипы функций одномерных массивов
void FillRand(int arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(double arr[], const int n);
template <typename T> void Print(T arr[], const int n);
template <typename T> void PushFront(T*& arr, int& n, const T number_front);
template <typename T> void PushBack(T*& arr, int& n, const T number);
template <typename T> void Insert(T*& arr, int& n, T number_index, const int index);
template <typename T> void PopBack(T*& arr, int& n);
template <typename T> void PopFront(T*& arr, int& n);
template <typename T> void Erase(T*& arr, int& n, const int index);

//Прототипы функции двумерных массивов без шаблона
void FillRand(double** arr_dual, int ROWS, const int COLS);
void FillRand(int** arr_dual, int ROWS, const int COLS);
void FillRand(char** arr_dual, int ROWS, const int COLS);

//Прототипы функции двумерных массивов с шаблоном
template <typename T> T** Allocate(const int ROWS, const int COLS);
template <typename T> void Print(T** arr, const int ROWS, const int COLS);
template <typename T> T** Push_Row_Back(T** arr_dual, int& ROWS, const int COLS);
template <typename T> void Push_Col_Back(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Push_Row_Front(T**& arr_dual, int& ROWS, const int COLS);
template <typename T> void Push_Col_Front(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Insert_Row(T** arr_dual, int& ROWS, const int COLS, const int index);
template <typename T> void Insert_Col(T** arr_dual, const int ROWS, int& COLS, const int index);
template <typename T> T** Pop_Row_Back(T** arr_dual, int& ROWS, const int COLS);
template <typename T> void Pop_Cols_Back(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Pop_Row_Front(T** arr_dual, int& ROWS, const int COLS);
template <typename T> void Pop_Cols_Front(T** arr_dual, const int ROWS, int& COLS);
template <typename T> T** Erase_Row(T** arr_dual, int& ROWS, const int COLS, const int index);
template <typename T> void Erase_Cols(T** arr_dual, const int ROWS, int& COLS, const int index);
template <typename T> void Clear(T**& arr_dual, const int ROWS);