// WinFormsTemplate.cpp: ������� ���� �������.

#include "stdafx.h"
#include "MainForm.h"
#include <time.h>

using namespace Lab_03;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew MainForm());
	return 0;
}
