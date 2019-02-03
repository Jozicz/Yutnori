#ifndef CLASSMOVE_H_INCLUDED
#define CLASSMOVE_H_INCLUDED

class Move{
public:
    virtual void move_()=0;
    virtual int strength_of_move()=0;
};

class D0:public Move{
private:
    int move_by=1;
public:
    void move_();
    int strength_of_move();
};

class Gae:public Move{
private:
    int move_by=2;
public:
    void move_();
    int strength_of_move();
};

class Geol:public Move{
private:
    int move_by=3;
public:
    void move_();
    int strength_of_move();
};

class Yut:public Move{
private:
    int move_by=4;
public:
    void move_();
    int strength_of_move();
};

class Mo:public Move{
private:
    int move_by=5;
public:
    void move_();
    int strength_of_move();
};

void uni(Move *how_much);

#endif // CLASSMOVE_H_INCLUDED
