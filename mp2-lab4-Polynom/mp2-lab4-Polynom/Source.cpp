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
	cout << "Введите максимальную степень монома" << endl;
	cin >> power;
	cout << "Введите начальный полином" << endl;
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
		cout << "          Меню" << endl;
		cout << "1. Показать все полиномы" << endl;
		cout << "2. Показать выбранный полином" << endl;
		cout << "3. Ввести новый полином" << endl;
		cout << "4. Сложить полиномы" << endl;
		cout << "5. Вычесть полиномы" << endl;
		cout << "6. Умножить полином на полином" << endl;
		cout << "7. Ввести коэффициент x и вычислить полином" << endl;
		cout << "0. Выйти из программы" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Полиномы:" << endl;
			for (int i = 0; i < currentAmountOfPolynoms; i++)
			{
				cout << i << ". ";
				PolArray[i].ShowPolynom();
			}
			break;
		case 2:
			cout << "Введите индекс выводимого полинома" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			cout << "Полином: ";
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
			cout << "Введите индекс 1 складываемого полинома" << endl;
			cin >> choice2;
			cout << "Введите индекс 2 складываемого полинома" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] + PolArray[choice3];
			cout << "Получившийся полином: ";
			result.ShowPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс 1 вычитаемого полинома" << endl;
			cin >> choice2;
			cout << "Введите индекс 2 вычитаемого полинома" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] - PolArray[choice3];
			cout << "Получившийся полином: ";
			result.ShowPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс умножаемого полинома:" << endl;
			cin >> choice2;
			cout << "Введите индекс умножаемого полинома:" << endl;
			cin >> choice3;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			if ((choice3 < 0) || (choice3 >= currentAmountOfPolynoms))
				break;
			result = PolArray[choice2] * PolArray[choice3];
			cout << "Получившийся полином: ";
			result.ShowPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс полинома для вычисления:" << endl;
			cin >> choice2;
			if ((choice2 < 0) || (choice2 >= currentAmountOfPolynoms))
				break;
			PolArray[choice2].ShowPolynom();
			cout << "Введите х:" << endl;
			cin >> x;
			resultCalculate = PolArray[choice2].Calculate(x);
			cout << "Получившийся результат: " << resultCalculate << endl;
			break;
		case 0:
			return 0;
		}
	}
}