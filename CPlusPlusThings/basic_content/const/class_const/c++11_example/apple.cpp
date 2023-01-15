class Apple
{
private:
    int people[100];
public:
    Apple(int i);
    //使用c++11标准编译
    static const int apple_number=10;
    //const int apple_number=10;
    void take(int num) const; //用const对成员函数进行声明，表示这个函数不会修改类中的任何数据成员。
    //如果在编写const成员函数时，不小心作了修改数据成员的操作，或者调用了其它非const成员函数，编译器将指出错误，这无疑会提高程序的健壮性。
    int add(int num);
    int add(int num) const;
    int getCount() const;

};

/*
    被const声明的成员函数的几点规则
    a.在类中被const声明的成员函数只能访问const成员函数，而非const函数可以访问任意的成员函数，包括const成员函数
    b.在类中被const声明的成员函数不可以修改对象的数据。它在编译时，以是否修改成员数据为依据，进行检查
    c.加上mutable修饰符的数据成员，对于任何情况下通过任何手段都可修改，自然此时的const成员函数是可以修改它的
*/