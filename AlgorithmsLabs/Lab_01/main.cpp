#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "NeutonPolinom.h"
#include <conio.h>
#include <math.h>
#include "BinarySearch.h"
#include "iostream"

#define X_INITIAL 0.0f
#define POINT_NUMBER 20
#define POINT_STEP_X 1

double f(double x)
{
	return sin(M_PI / 6 * x);
}

void GenerateTable(double *x, double *y)
{
	x[0] = X_INITIAL;
	y[0] = f(X_INITIAL);
	for (int i = 1; i < POINT_NUMBER; i++)
	{
		x[i] = x[i - 1] + POINT_STEP_X;
		y[i] = f(x[i]);
	}
}

void PrintTable(double *x, double *y)
{
	printf("====VALUE TABLE====\n");
	for (int i = 0; i < POINT_NUMBER; i++)
	{
		printf("%7.3f...%7.3f\n", x[i], y[i]);
	}
	printf("===================\n");
}

int main(void)
{
	double x[POINT_NUMBER];
	double y[POINT_NUMBER];

	GenerateTable(x, y);
	PrintTable(x, y);

	double argX = 0;
	int argN = 1;

	std::cout << "Input polinomial degree: ";
	std::cin >> argN;
	std::cout << "Input X argument: ";
	std::cin >> argX;

	printf("\n");

	if (argN > POINT_NUMBER)
	{
		printf("Not enough points in table to proceed.\n");
		_getch();
		return -1;
	}

	Result bs_result = binarySearch(POINT_NUMBER, x, argX);
	int pos = bs_result.pos;

	if (bs_result.isFound)
	{
		printf("Interpolated F(X) = %3.3f\n", y[bs_result.pos]);		
	}
	else
	{
		double *x_pol = (double*)malloc(sizeof(double)* (argN + 1));
		double *y_pol = (double*)malloc(sizeof(double)* (argN + 1));
		int offset_right = -(argN + 1) / 2;
		int offset_left = (argN + 1) / 2;
		if ((argN + 1) % 2 == 1)
			offset_left++;

		if (pos + offset_right < 0)
		{				
			pos += -pos - offset_right;
			offset_left += -pos - offset_right;
			offset_right += -pos - offset_right;
		}
		//printf("Offset right: %d, pos: %d, offset_left: %d\n", offset_right, pos, offset_left);

		if (pos + offset_left > POINT_NUMBER - 1)
		{
			offset_right -= pos + offset_left - POINT_NUMBER;
			offset_left -= pos + offset_left - POINT_NUMBER;
			pos -= pos + offset_left - POINT_NUMBER;
		}

		for (int j = 0, i = pos + offset_right; i < pos + offset_left; i++, j++)
		{			
			x_pol[j] = x[i];
			y_pol[j] = y[i];
			//printf("i = %d, x = %3.3f, y = %3.3f\n", i, x_pol[j], y_pol[j]);
		}
		NeutonPolinom polinom = NeutonPolinom(argN, x_pol, y_pol);
		double result = polinom.Calculate(argX);
		printf("Interpolated F(X) = %3.3f\n", result);
	}

	printf("Actual F(X) = %3.3f\n", f(argX));

	_getch();
}