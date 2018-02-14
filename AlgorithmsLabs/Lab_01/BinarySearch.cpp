#include <stdio.h>
#include "BinarySearch.h"

struct Result binarySearch(size_t n, double a[], double x)
{
	/* ����� ������� �������� � ������� */
	size_t first = 0;
	/* ����� �������� � �������, ���������� �� ��������� */
	size_t last = n;

	/* ��������� ��������, �������, � ��������, ����� �������� � �� ����� ��. ����! */
	if (n == 0) {
		/* ������ ���� */
		return NOTFOUND(0);
	}
	else if (a[0] > x) {
		/* ������� ������� ������ ���� � ������� */
		return NOTFOUND(0);
	}
	else if (a[n - 1] < x) {
		/* ������� ������� ������ ���� � ������� */
		return NOTFOUND(n);
	}

	/* ���� ��������������� ������� ��������, first < last */
	while (first < last) {
		size_t mid = first + (last - first) / 2;

		if (x <= a[mid])
			last = mid;
		else
			first = mid + 1;
	}

	/* ���� �������� �������� if (n == 0) � �.�. � ������ ������ -
	* ������, ��� �����������������!
	*/
	if (/* last < n && */ a[last] == x) {
		/* ������� ������� ������. last - ������� ������ */
		return FOUND(last);
	}
	else {
		/* ������� ������� �� ������. �� ���� ��� ����� ���� ���
		* �������� �� �������, �� ��� ����� - last.
		*/
		return NOTFOUND(last);
	}
}