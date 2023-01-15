#include<iostream>
using namespace std;

void f(const int i){
    i=10;
    cout<<i<<endl;
}

int main(){
    f(1)
}