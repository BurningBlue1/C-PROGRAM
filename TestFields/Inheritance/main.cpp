#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
 
	string _name;
	int _age;
	char _sex;
 
	void Print()
	{
		cout << "_name  _age  _sex" << endl;
	}
	
};
 
class Student :public Person
{
public:
	void Print()
	{
		cout << "_id" << endl;
	}
protected :
	string _id;
};

int main(){
    Student s;
	s.Print(); // 子类调用自己的打印函数
	s.Person::Print(); // 子类调用父类的打印函数
	return 0;
}  

