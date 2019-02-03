#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "functionGeneratingThrow.h"
#include "classBaton.h"

int generate_binary_number(int first_number){

    srand(time(NULL));
    first_number=(std::rand()%1000);
    if(first_number%2==0)first_number=0;
    else(first_number=1);

    return first_number;
}

int generate_random_numbers(int first_number, int second_number){

    first_number=generate_binary_number(first_number);
    second_number+=first_number;
    Sleep(567);
    Baton B1(first_number);
    B1.draw_baton();

    first_number=generate_binary_number(first_number);
    second_number+=first_number;
    Sleep(433);
    Baton B2(first_number);
    B2.draw_baton();

    first_number=generate_binary_number(first_number);
    second_number+=first_number;
    Sleep(200);
    Baton B3(first_number);
    B3.draw_baton();

    first_number=generate_binary_number(first_number);
    second_number+=first_number;
    Sleep(400);
    Baton B4(first_number);
    B4.draw_baton();

    if(second_number==0) second_number=5;
    return second_number;
}
