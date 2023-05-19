#include "dmemory.h"

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