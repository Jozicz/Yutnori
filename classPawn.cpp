#include "classPawn.h"

Pawn::Pawn(int which_one){
        symbol=which_one;
    }
    int Pawn::get_number(){
        return symbol;
    }
    void Pawn::set_strength(int s){
        move_by_how_much=s;
    }
    int Pawn::get_strength(){
        return move_by_how_much;
    }
    void Pawn::decrease_strength(){
        move_by_how_much--;
    }
    void Pawn::in_game(){
        starting_point=0;
    }
    void Pawn::finished_the_game(){
        finished=1;
    }
    int Pawn::get_starting_point(){
        return starting_point;
    }
    int Pawn::get_finished(){
        return finished;
    }
    void Pawn::beaten(){
        starting_point=1;
    }
