#include <cstdlib>
#include <iostream>
#include "functionDecidingOrder.h"
#include "functionGeneratingThrow.h"
#include "functionPrintingResultsOfThrow.h"

using namespace std;

int deciding_order(int first_number, int second_number, int which_player, Move *myMove, D0 d0, Gae gae, Geol geol, Yut yut, Mo mo){
    int who_goes_first;
    do{
        second_number=0;
        who_goes_first=0;
        cout<<"      Player 1:"<<endl<<endl;
        second_number=generate_random_numbers(first_number, second_number);
        results_of_throw(second_number, myMove, d0, gae, geol, yut, mo);
        who_goes_first=second_number;
        first_number=0;
        second_number=0;
        cout<<endl<<endl<<"      Player 2:"<<endl<<endl;
        second_number=generate_random_numbers(first_number, second_number);
        results_of_throw(second_number, myMove, d0, gae, geol, yut, mo);
    }
    while(who_goes_first==second_number);

    if(who_goes_first<second_number){
        cout<<endl<<endl<<"      Player 1 goes first!"<<endl;
        which_player=2;
    }
    else {
        cout<<endl<<endl<<"      Player 2 goes first!"<<endl;
        which_player=1;
    }
    return which_player;
}
