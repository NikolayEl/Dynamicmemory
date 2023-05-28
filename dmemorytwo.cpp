#include "dmemory.h"

void FillRand(double** arr_dual, int ROWS, const int COLS)
{

	for (int i = 0; i < ROWS; i++)
	{
		FillRand(arr_dual[i], COLS);
	}
}
void FillRand(int** arr_dual, int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		FillRand(arr_dual[i], COLS);
	}
}

void FillRand(char** arr_dual, int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		FillRand(arr_dual[i], COLS);
	}
}