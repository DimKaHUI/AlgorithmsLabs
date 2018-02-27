#pragma once

#define TOLERANCE 0.001f

class Spline
{
private:
	int point_amount;       // ���������� �����
	double *pnt_x, *pnt_y;  // ������� �������� �����
	double *a, *b, *c, *d;  // ������������
	void Calculate�oefficients();    // ������� ��� ���������� �������������
public:
	Spline(double *x, double *y, int count);
	~Spline();

	double calculate(double x);
};

