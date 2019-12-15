#include "Polynom.h"
#include <string>

using namespace std;

int PartOfStringToInt(string str, int& pos)
{
	int res;
	int j = pos;
	int count = 0;
	char *str2;
	string tmpstr;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		count++;
		j++;
	}
	tmpstr = str.substr(pos, count);
	str2 = new char[tmpstr.size() + 1];
	pos = j;
	for (j = 0; j < tmpstr.size() + 1; j++)
		str2[j] = tmpstr[j];
	res = strtod(str2, NULL);

	return res;
}

int Polynom::maxPower;

Polynom::Polynom()
{
	this->pHead = new List;
	this->pHead->monom.coef = 0;
	this->pHead->monom.power = -1;
	this->pHead->pNext = pHead;
}

Polynom::Polynom(char* strch)
{
	setlocale(LC_ALL, "Russian");
	string str(strch);
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || ((now >= '0') && (now <= '9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	List* listStart = new List;
	listStart->monom.power = -1;
	listStart->monom.coef = 0;
	List* currentPartOfList = listStart;
	i = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfList->pNext = new List;
		currentPartOfList = currentPartOfList->pNext;
		currentPartOfList->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfList->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfList->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if (tmpstr[j] == 'x');
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfList->monom.power = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfList->monom.power += maxPower * maxPower*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfList->monom.power += maxPower * maxPower * 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
	}
	currentPartOfList->pNext = listStart;
	this->pHead = listStart;
	this->SortByMaxPower();
}

Polynom::Polynom(string str)
{
	setlocale(LC_ALL, "Russian");
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || ((now >= '0') && (now <= '9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	List* listStart = new List;
	listStart->monom.power = -1;
	listStart->monom.coef = 0;
	List* currentPartOfList = listStart;
	i = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfList->pNext = new List;
		currentPartOfList = currentPartOfList->pNext;
		currentPartOfList->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfList->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfList->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if (tmpstr[j] == 'x');
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfList->monom.power = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfList->monom.power += maxPower * maxPower*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfList->monom.power += maxPower * maxPower * 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
	}
	currentPartOfList->pNext = listStart;
	this->pHead = listStart;
	this->SortByMaxPower();
}

Polynom::Polynom(const Polynom &polynom)
{
	this->pHead = new List;
	this->pHead->monom.coef = 0;
	this->pHead->monom.power = -1;
	List* tmp = new List;
	List* startTmp = tmp;
	List* curentList = polynom.pHead;
	curentList = curentList->pNext;
	if (curentList->monom.power == -1)
	{
		startTmp->pNext = this->pHead;
	}
	while (curentList->monom.power != -1)
	{
		tmp->pNext = new List;
		tmp = tmp->pNext;
		tmp->monom.coef = curentList->monom.coef;
		tmp->monom.power = curentList->monom.power;
		curentList = curentList->pNext;
	}
	this->pHead->pNext = startTmp->pNext;
	tmp->pNext = this->pHead;
}

Polynom::~Polynom()
{
	List *tmp = this->pHead;
	tmp = tmp->pNext;
	List *tmpDel;
	while (tmp->monom.power != -1)
	{
		tmpDel = tmp;
		tmp = tmp->pNext;
		delete tmpDel;
	}
	delete tmp;
}

void Polynom::SortByMaxPower()
{
	int maxDegree;
	int start = 1;
	List* tmp;
	List* prePointer=0;
	List* lastPointer=0;
	List* maxPointer=0;
	List* Pointer;
	int count = 0;
	tmp = this->pHead;
	tmp = tmp->pNext;
	while (tmp->monom.power != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	for (int j = 0; j < count; j++)
	{
		tmp = this->pHead;
		for (int i = 0; i < start; i++)
		{
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
		maxDegree = -1;
		while (tmp->monom.power != -1)
		{
			if (tmp->monom.power > maxDegree)
			{
				maxDegree = tmp->monom.power;
				maxPointer = tmp;
				prePointer = lastPointer;
			}
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
		tmp = this->pHead;
		for (int k = 0; k < start - 1; k++)
			tmp = tmp->pNext;
		if (tmp->pNext->monom.power != maxPointer->monom.power)
		{
			Pointer = tmp->pNext;
			prePointer->pNext = maxPointer->pNext;
			maxPointer->pNext = Pointer;
			tmp->pNext = maxPointer;
		}
		start++;
	}
}

Polynom Polynom::operator+(const Polynom &polynom)
{
	Polynom tmpPolynom;
	List* result = tmpPolynom.pHead;
	List* Pol1Link = this->pHead;
	Pol1Link = Pol1Link->pNext;
	List* Pol2Link = polynom.pHead;
	Pol2Link = Pol2Link->pNext;
	while ((Pol1Link->monom.power != -1) || (Pol2Link->monom.power != -1))
	{
		if (Pol1Link->monom.power < Pol2Link->monom.power)
		{
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol2Link->monom.power;
			result->monom.coef = Pol2Link->monom.coef;
			Pol2Link = Pol2Link->pNext;
		}
		else if (Pol1Link->monom.power > Pol2Link->monom.power)
		{
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol1Link->monom.power;
			result->monom.coef = Pol1Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
		}
		else if (Pol1Link->monom.power == Pol2Link->monom.power)
		{
			if ((Pol1Link->monom.coef + Pol2Link->monom.coef) == 0)
			{
				Pol1Link = Pol1Link->pNext;
				Pol2Link = Pol2Link->pNext;
				continue;
			}
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol1Link->monom.power;
			result->monom.coef = Pol1Link->monom.coef + Pol2Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
			Pol2Link = Pol2Link->pNext;
		}
	}
	result->pNext = tmpPolynom.pHead;

	return tmpPolynom;
}

Polynom Polynom::operator-(const Polynom &polynom)
{
	Polynom tmpPolynom;
	List* result = tmpPolynom.pHead;
	List* Pol1Link = this->pHead;
	Pol1Link = Pol1Link->pNext;
	List* Pol2Link = polynom.pHead;
	Pol2Link = Pol2Link->pNext;
	while ((Pol1Link->monom.power != -1) || (Pol2Link->monom.power != -1))
	{
		if (Pol1Link->monom.power < Pol2Link->monom.power)
		{
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol2Link->monom.power;
			result->monom.coef = Pol2Link->monom.coef;
			Pol2Link = Pol2Link->pNext;
		}
		else if (Pol1Link->monom.power > Pol2Link->monom.power)
		{
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol1Link->monom.power;
			result->monom.coef = Pol1Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
		}
		else if (Pol1Link->monom.power == Pol2Link->monom.power)
		{
			if ((Pol1Link->monom.coef - Pol2Link->monom.coef) == 0)
			{
				Pol1Link = Pol1Link->pNext;
				Pol2Link = Pol2Link->pNext;
				continue;
			}
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol1Link->monom.power;
			result->monom.coef = Pol1Link->monom.coef - Pol2Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
			Pol2Link = Pol2Link->pNext;
		}
	}
	result->pNext = tmpPolynom.pHead;

	return tmpPolynom;
}

Polynom Polynom::operator*(const Polynom &polynom)
{
	Polynom tmpPolynom;
	List* result = tmpPolynom.pHead;
	List* Pol1List = this->pHead;
	Pol1List = Pol1List->pNext;
	List* Pol2List = polynom.pHead;
	Pol2List = Pol2List->pNext;
	while (Pol1List->monom.power != -1)
	{
		while (Pol2List->monom.power != -1)
		{
			result->pNext = new List;
			result = result->pNext;
			result->monom.power = Pol1List->monom.power + Pol2List->monom.power;
			result->monom.coef = Pol1List->monom.coef * Pol2List->monom.coef;
			Pol2List = Pol2List->pNext;
		}
		
		Pol2List = polynom.pHead;
		Pol2List = Pol2List->pNext;
		

		Pol1List = Pol1List->pNext;
	}

	result->pNext = tmpPolynom.pHead;
	return tmpPolynom;

	/*int tr = tmpPolynom.maxPower + tmpPolynom.maxPower;
	Polynom trPolynom;
	List* ptr = trPolynom.pHead;
	double pre = 0.0;
	for (int i = tr; i != -1; i--)
	{
		do
		{
			if (result->monom.power == i)
			{
				pre += result->monom.coef;
			}
			result = result->pNext;

		} while (result->pNext != this->pHead);



		if (pre != 0.0)
		{
			ptr->pNext = new List;
			ptr = ptr->pNext;
			ptr->monom.power = i;
			ptr->monom.coef = pre;
			pre = 0.0;
		}
	}

	ptr->pNext = trPolynom.pHead;

	return trPolynom;*/
}

Polynom Polynom::operator=(const Polynom &polynom)
{
	this->pHead = new List;
	this->pHead->monom.coef = 0;
	this->pHead->monom.power = -1;
	List* tmp = new List;
	List* startTmp = tmp;
	List* curentList = polynom.pHead;
	curentList = curentList->pNext;
	if (curentList->monom.power == -1)
	{
		startTmp->pNext = this->pHead;
	}
	while (curentList->monom.power != -1)
	{
		tmp->pNext = new List;
		tmp = tmp->pNext;
		tmp->monom.coef = curentList->monom.coef;
		tmp->monom.power = curentList->monom.power;
		curentList = curentList->pNext;
	}
	this->pHead->pNext = startTmp->pNext;
	tmp->pNext = this->pHead;
	return *this;
}

void Polynom::ShowPolynom()
{
	List *tmp = this->pHead;
	tmp = this->pHead;
	tmp = tmp->pNext;
	if (tmp->monom.power == -1)
		cout << "0";
	while (tmp->monom.power != -1)
	{
		if (tmp->monom.coef != 1)
			cout << tmp->monom.coef;
		if ((tmp->monom.coef == 1) && (tmp->monom.power == 0))
			cout << tmp->monom.coef;
		if (tmp->monom.power / (maxPower*maxPower) > 0)
		{
			cout << "x";
			if (tmp->monom.power / (maxPower*maxPower) > 1)
				cout << "^" << tmp->monom.power / (maxPower*maxPower);
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				cout << "+";
	}
	cout << endl;
}

int Polynom::Calculate(int x)
{
	List *tmp = this->pHead;
	int count = 0;
	int res = 0;
	int tmpint;
	tmp = tmp->pNext;
	while (tmp->monom.power != -1)
	{
		count = tmp->monom.coef;
		tmpint = 1;
		if (tmp->monom.power / (maxPower*maxPower) != 0)
		{
			for (int i = 0; i < (tmp->monom.power / (maxPower*maxPower)); i++)
				tmpint *= x;
			count *= tmpint;
		}
		tmpint = 1;
		res += count;
		tmp = tmp->pNext;
	}
	return res;
}

string Polynom::PolynomToString()
{
	string str;
	List *tmp = this->pHead;
	int count = 0;
	tmp = tmp->pNext;
	while (tmp->monom.power != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	if (count == 0)
	{
		str = "0";
		return str;
	}
	tmp = this->pHead;
	tmp = tmp->pNext;
	for (int i = 0; i < count; i++)
	{
		if (tmp->monom.coef != 1)
			str += to_string(tmp->monom.coef);
		if ((tmp->monom.coef == 1) && (tmp->monom.power == 0))
			str += to_string(tmp->monom.coef);
		if (tmp->monom.power / (maxPower*maxPower) > 0)
		{
			str += "x";
			if (tmp->monom.power / (maxPower*maxPower) > 1)
			{
				str += "^";
				str += to_string(tmp->monom.power / (maxPower*maxPower));
			}
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				str += "+";
	}

	return str;
}
