#include "Polynom.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string strIn;
	unsigned int power;
	int x;
	Polynom PolArray[50];
	int choice;
	int choice2;
	int choice3;
	int resultCalculate;
	int currentAmountOfPolynoms = 1;
	cout << "������� ������������ ������� ������" << endl;
	cin >> power;
	cout << "������� ��������� �������" << endl;
	cin >> strIn;
	Polynom result;
	try
	{
		Polynom::SetMaxPower(power);
		Polynom Polinom(strIn);
		PolArray[0] = Polinom;
	}
	catch (char* ch)
	{
		cout << ch << endl;
		return 1;
	}
	while (true)
	{
		cout << endl;
		cout << "          ����" << endl;
		cout << "1. �������� ��� ��������" << endl;
		cout << "2. �������� ��������� �������" << endl;
		cout << "3. ������ ����� �������" << endl;
		cout << "4. ������� ��������" << endl;
		cout << "5. ������� ��������" << endl;
		cout << "6. �������� ������� �� �������" << endl;
		cout << "7. ������ ����������� x � ��������� �������" << endl;
		cout << "0. ����� �� ���������" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "��������:" << endl;
			for (int i = 0; i < currentAmountOfPolynoms; i++)
			{
				cout << i << ". ";
				PolArray[i].ShowPolynom();
			}
			break;
		case 2:
			cout << "������� ������ ���������� ��������" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			cout << "�������: ";
			PolArray[choice2].ShowPolynom();
			break;
		case 3:
			cin >> strIn;
			try
			{
				Polynom Polinom(strIn);
				PolArray[currentAmountOfPolynoms] = Polinom;
				currentAmountOfPolynoms++;
			}
			catch (char* ch)
			{
				cout << ch << endl;
			}
			break;
		case 4:
			cout << "������� ������ 1 ������������� ��������" << endl;
			cin >> choice2;
			cout << "������� ������ 2 ������������� ��������" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] + PolArray[choice3];
			cout << "������������ �������: ";
			result.ShowPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				PolArray[currentAmountOfPolynoms] = result;
				currentAmountOfPolynoms++;
			}
			break;
		case 5:
			cout << "������� ������ 1 ����������� ��������" << endl;
			cin >> choice2;
			cout << "������� ������ 2 ����������� ��������" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] - PolArray[choice3];
			cout << "������������ �������: ";
			result.ShowPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				PolArray[currentAmountOfPolynoms] = result;
				currentAmountOfPolynoms++;
			}
			break;
		case 6:
			cout << "������� ������ ����������� ��������:" << endl;
			cin >> choice2;
			cout << "������� ������ ����������� ��������:" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] * PolArray[choice3];
			cout << "������������ �������: ";
			result.ShowPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> choice3;
			if (choice3 == 0)
				break;
			if (choice3 == 1)
			{
				PolArray[currentAmountOfPolynoms] = result;
				currentAmountOfPolynoms++;
			}
			break;
		case 7:
			cout << "������� ������ �������� ��� ����������:" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			PolArray[choice2].ShowPolynom();
			cout << "������� �:" << endl;
			cin >> x;
			resultCalculate = PolArray[choice2].Calculate(x);
			cout << "������������ ���������: " << resultCalculate << endl;
			break;
		case 0:
			return 0;
		}
	}
}