// ArrayTestMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArrayT.h"
#include "ArrayTHelper.h"
//#include "ArrayTHelper.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Person;
ostream & operator<<(std::ostream &, Person &);
istream & operator>>(istream &, Person &);
class Person
{
	friend std::ostream & operator<<(std::ostream &os, Person& p);
	friend std::istream & operator>>(istream &is, Person & p);
public:
	Person(string n="noname", int a=99):name(n),age(a){}
private:
	string name;
	int age;
};
/*
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
*/
std::ostream & operator<<(std::ostream &os, Person & p)
{
	os << p.name <<":"<< p.age;
	return os;
}
std::istream & operator>>(std::istream &is, Person & p)
{
	// probably suboptimal
	string text;
	size_t pos;
	stringstream tempStream;
	is >>text;
	pos=text.find(":");
	string myName=text.substr(0,pos);
	string myAge=text.substr(pos+1);
	int a;
	tempStream <<myAge;
	tempStream >> a;
	p.age=a;
	p.name=myName;
	//os << p.name <<":"<< p.age;
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
	// Try a person
	Person dave("dave",18);
	ArrayT<Person> daves(5,dave);
	cout << "Direct call to print" << endl;
	daves.print(std::cout);
	cout <<endl;
	daves[2]=Person(); //default person
	cout << "Modify w/ [2], print w/ <<"<<endl;
	cout << daves;
	cout <<endl;

	getchar();
	
	string pValues="kat:4";
	stringstream pStream(pValues);
	pStream >> daves[1];
	cout << "Print Person after >> kat"<<endl;
	cout << daves;
	getchar();
	// same as above multiple, animals are people too :)
	pStream.clear();
	string pValuesOther="bird:23 turtle:88";
	stringstream pStreamOther(pValuesOther);
	pStream << "bird:23 " << " turtle:88 ";
	pStreamOther >> daves[2]>> daves[3];
	cout << "Print Person after multiple>> kat"<<endl;
	cout << daves;
	getchar();
	return 0;
}

