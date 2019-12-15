#ifndef __POLINOMS_H__
#define __POLINOMS_H__
#include <string>
#include <iostream>

using namespace std;

struct Monom
{
	double coef;     
	int power;       
};

struct List
{
	Monom monom;
	List* pNext;
};

class Polynom
{
	List* pHead;
	static int maxPower;

	void SortByMaxPower();     

public:
	Polynom();
	Polynom(char* strch);
	Polynom(string str);
	Polynom(const Polynom &polynom);
	~Polynom();

	static void SetMaxPower(unsigned int var)
	{
		if (var < 0)
			throw("Error power");
		else
			maxPower = var;
	}
	Polynom operator+(const Polynom &polynom);
	Polynom operator-(const Polynom &polynom);
	Polynom operator*(const Polynom &polynom);
	Polynom operator=(const Polynom &polynom);
	void ShowPolynom();
	string PolynomToString();
	int Calculate(int x);           
};

#endif
