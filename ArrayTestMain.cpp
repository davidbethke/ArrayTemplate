// ArrayTestMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArrayT.h"
//#include "ArrayTHelper.h"
#include <iostream>

using namespace std;

template<typename T>
std::ostream &operator<<( std::ostream &os,  ArrayT<T> &a ) 
{
	a.print(os);
   return os; // enables cout << x << y;
} //

int main()
{
	ArrayT<int> myAInt(10,5);
	//cout << myAInt << endl;
	myAInt[8]=99;
	for (int i=0;i<myAInt.getSize();++i)
		cout <<myAInt[i]<< " ";
	cout <<endl;
	cout << "Direct call to print" << endl;
	myAInt.print(std::cout);
	cout << "Operator <<" <<endl;
	cout << myAInt <<endl;
	getchar();
	return 0;
}

