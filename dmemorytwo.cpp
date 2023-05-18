#include "dmemory.h"

int** IntAllocate(const int ROWS, const int COLS)
{
	int** arr_dual = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr_dual[i] = new int[COLS];
	}
	return arr_dual;
}

double** DoubleAllocate(const int ROWS, const int COLS)
{
	double** arr_dual = new double* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr_dual[i] = new double[COLS];
	}
	return arr_dual;
}
char** CharAllocate(const int ROWS, const int COLS)
{
	char** arr_dual = new char* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr_dual[i] = new char[COLS];
	}
	return arr_dual;
}

void FillRand(double** arr_dual, int ROWS, const int COLS)
{

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr_dual[i][j] = rand() % (ROWS * COLS);
			arr_dual[i][j] /= 10;
		}
	}
}
void FillRand(int** arr_dual, int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr_dual[i][j] = rand() % (ROWS * COLS);
		}
	}
}

void FillRand(char** arr_dual, int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr_dual[i][j] = rand() % (ROWS * COLS);
		}
	}
}