#include<iostream>
using namespace std;

class Apple{
    int i;
public:
    Apple(){
        i=0;
        cout<<"Inside Constructor\n";
    }
    ~Apple(){
        cout<<"Inside Destructor\n";
    }
};


int main(){
    int x=0;
    if(x==0){
        static Apple obj;
    }
    cout<<"End of main\n";
}
//当变量声明为static时，空间将在程序的生命周期内分配
//注意static_class和nostatic_class的析构函数的执行顺序