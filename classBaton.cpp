#include <iostream>
#include "classBaton.h"

using namespace std;

    Baton::Baton(int x){
        binary_throw=x;
    }
    void Baton::draw_baton(){
        if(binary_throw==1){
            cout<<"       "<<" ---------------------------"<<endl;
            cout<<"       "<<"| B1                        |"<<endl;
            cout<<"       "<<" ---------------------------"<<endl;
        }
        if(binary_throw==0){
            cout<<"       "<<" ---------------------------"<<endl;
            cout<<"       "<<"| B1   작     석     개  |"<<endl;
            cout<<"       "<<" ---------------------------"<<endl;
        }
    }

