// ArrayTestMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArrayT.h"
//#include "ArrayTHelper.h"
#include <iostream>#include <sstream>
#include <sstream>
using namespace std;

template<typename T>
std::ostream &operator<<( std::ostream &os,  ArrayT<T> &a ) 
{
	a.print(os);
   return os; // enables cout << x << y;
} //
template<typename T>
std::istream & operator>>(std::istream &is, ArrayT<T> &a)
{
	a.input(is);
	return is;
}

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
	cout <<endl;
	cout << "Operator <<" <<endl;
	cout << myAInt <<endl;
	cout <<endl;
	stringstream ss;
//	ss<<0<<"1 "<<"2 "<<3<<4<<5<<6<<7<<8<<9;
	ss<<"0 "<<"1 "<<"2 "<<"3 "<<"4 "<<"5 "<<"6 "<<"7 "<<"8 "<<"9 ";

	ss >> myAInt;
	cout <<endl;
	cout << "Operator << after >> " <<endl;
	cout << myAInt <<endl;
	getchar();
	return 0;
}

