#include <iostream>
#include "classMove.h"

using namespace std;

    void D0::move_(){
        cout<<move_by;
    }
    int D0::strength_of_move(){
        return move_by;
    }

    void Gae::move_(){
        cout<<move_by;
    }
    int Gae::strength_of_move(){
        return move_by;
    }

    void Geol::move_(){
        cout<<move_by;
    }
    int Geol::strength_of_move(){
        return move_by;
    }

    void Yut::move_(){
        cout<<move_by;
    }
    int Yut::strength_of_move(){
        return move_by;
    }

    void Mo::move_(){
        cout<<move_by;
    }
    int Mo::strength_of_move(){
        return move_by;
    }

    void uni(Move *how_much){
    cout<<endl<<"       "<<"You move by: ";
    how_much -> move_();
}
