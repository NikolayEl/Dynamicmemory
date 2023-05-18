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

//Прототипы функции двумерных массивов
int** IntAllocate(const int ROWS, const int COLS);
double** DoubleAllocate(const int ROWS, const int COLS);
char** CharAllocate(const int ROWS, const int COLS);