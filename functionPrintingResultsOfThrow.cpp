#include <iostream>
#include <typeinfo>
#include "functionPrintingResultsOfThrow.h"

using namespace std;

void results_of_throw(int second_number, Move *myMove, D0 d0, Gae gae, Geol geol, Yut yut, Mo mo){
cout<<endl<<"       "<<"You got: ";
if(second_number==1){
        myMove = dynamic_cast<D0 *>(&d0);
        cout<<typeid(d0).name() << endl;

        Move *pointer=&d0;
        uni(pointer);
    }

    if(second_number==2){
        myMove = dynamic_cast<Gae *>(&gae);
        cout<<typeid(Gae).name() << endl;

        Move *pointer=&gae;
        uni(pointer);
    }

    if(second_number==3){
        myMove = dynamic_cast<Geol *>(&geol);
        cout<<typeid(Geol).name() << endl;

        Move *pointer=&geol;
        uni(pointer);
    }

    if(second_number==4){
        myMove = dynamic_cast<Yut *>(&yut);
        cout<<typeid(Yut).name() << endl;

        Move *pointer=&yut;
        uni(pointer);
    }

    if(second_number==5){
        myMove = dynamic_cast<Mo *>(&mo);
        cout<<typeid(Mo).name() << endl;

        Move *pointer=&mo;
        uni(pointer);
    }
}
