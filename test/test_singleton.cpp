#include<iostream>
#include"kernel/pearl_public.h"
using namespace pearl::code_design::design_model;
int main() {
    Singleton &p = Singleton::GetInStance();
    Singleton &p2 = Singleton::GetInStance();
    if(&p==&p2){
        cout<<"same"<<endl;
    }
    else {
        cout<<"unique"<<endl;       
    }
	return 0;
}