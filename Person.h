#ifndef PESRON_H
#define PESRON_H
#include<iostream>
#include <sstream>

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
#endif // PERSON_H
