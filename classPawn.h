#ifndef CLASSPAWN_H_INCLUDED
#define CLASSPAWN_H_INCLUDED

class Pawn{
    int symbol;
    int move_by_how_much=0;
    int starting_point=1;
    int finished=0;
public:
    Pawn(int which_one);
    int get_number();
    void set_strength(int s);
    int get_strength();
    void decrease_strength();
    void in_game();
    void finished_the_game();
    int get_starting_point();
    int get_finished();
    void beaten();
};

#endif // CLASSPAWN_H_INCLUDED
