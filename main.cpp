#include <iostream>
#include <Windows.h>
#include "classMove.h"
#include "classPawn.h"
#include "classBaton.h"
#include "functionDraw.h"
#include "functionGeneratingThrow.h"
#include "functionPrintingResultsOfThrow.h"
#include "functionDecidingOrder.h"

using namespace std;

int main()
{
    int Board[20];
    for(int i=0;i<20;i++){
        Board[i]=0;
    }
    int Diagonal1[7];
    for(int i=0;i<7;i++){
        Diagonal1[i]=0;
    }
    int Diagonal2[7];
    for(int i=0;i<7;i++){
        Diagonal2[i]=0;
    }
    int tmp_array1[1], tmp_array2[1], tmp_array_initial[1];
    tmp_array1[0]=0;
    tmp_array2[0]=0;
    tmp_array_initial[0]=0;

    D0 d0;
    Gae gae;
    Geol geol;
    Yut yut;
    Mo mo;

    Pawn Pawn1(1);
    Pawn Pawn2(2);
    Pawn Pawn3(3);
    Pawn Pawn4(4);

    Move *myMove;
    Pawn *current_pawn;

    int first_number, second_number=0;
    int which_pawn;
    int who_won=0;
    int m=-1;
    int which_player, var_a, var_b;

    which_player=deciding_order(first_number, second_number, which_player, myMove, d0, gae, geol, yut, mo);
    system ("pause");

    while(who_won==0){
        system("CLS");
        draw(Board, Diagonal1, Diagonal2);
        cout<<endl<<endl<<endl<<endl<<endl;

        if(which_player==2) which_player=1;
        else if(which_player==1) which_player=2;
        if(which_player==1){
            var_a=1;
            var_b=2;
        }
        if(which_player==2){
            var_a=3;
            var_b=4;
        }

        cout<<"       "<<"Player "<<which_player<<"'s throw: "<<endl<<endl;

        second_number=generate_random_numbers(first_number, second_number);
        results_of_throw(second_number, myMove, d0, gae, geol, yut, mo);

        do{
            if(which_player==1){
                if(Pawn1.get_finished()==1) cout<<endl<<endl<<"       Pawn 1 has completed its path!"<<endl;
                if(Pawn2.get_finished()==1) cout<<endl<<endl<<"       Pawn 2 has completed its path!"<<endl;
            }
            if(which_player==2){
                if(Pawn3.get_finished()==1) cout<<endl<<endl<<"       Pawn 3 has completed its path!"<<endl;
                if(Pawn4.get_finished()==1) cout<<endl<<endl<<"       Pawn 4 has completed its path!"<<endl;
            }

        cout<<endl<<endl<<"       "<<"Which pawn do you want to move: ";
        cin>>which_pawn;

        if(which_player==1){
            try{
                if(which_pawn!=1&&which_pawn!=2){
                    throw "       Wrong input! You can only move Pawn 1 or Pawn 2!\n";
                    }
                    if(which_pawn==1&&Pawn1.get_finished()==1){
                        throw "       Wrong input! Pawn 1 has completed its path!\n";
                    }
                    if(which_pawn==2&&Pawn2.get_finished()==1){
                        throw "       Wrong input! Pawn 2 has completed its path!\n";
                    }
                }
            catch(const char* which_pawn){
            cerr<<which_pawn;
            cin.clear();
            cin.ignore();
            }
        }
        if(which_player==2){
            try{
                if(which_pawn!=3&&which_pawn!=4){
                    throw "       Wrong input! You can only move Pawn 3 or Pawn 4!\n";
                    }
                    if(which_pawn==3&&Pawn3.get_finished()==1){
                        throw "       Wrong input! Pawn 3 has completed its path!\n";
                    }
                    if(which_pawn==4&&Pawn4.get_finished()==1){
                        throw "       Wrong input! Pawn 4 has completed its path!\n";
                    }
                }
            catch(const char* which_pawn){
            cerr<<which_pawn;
            cin.clear();
            cin.ignore();
            }
        }

        cout<<endl;
        if(which_player==1){
            if(which_pawn==1) current_pawn=&Pawn1;
            if(which_pawn==2) current_pawn=&Pawn2;
            if(current_pawn -> get_finished()==1){
                if(which_pawn==1){
                    cout<<"       Moving Pawn 2";
                    for(int i=0;i<3;i++){
                        cout<<".";
                        Sleep(500);
                    }
                    which_pawn=2;
                    current_pawn=&Pawn2;
                }
                else if(which_pawn==2){
                    cout<<"       Moving Pawn 1";
                    for(int i=0;i<3;i++){
                        cout<<".";
                        Sleep(500);
                    }
                    which_pawn=1;
                    current_pawn=&Pawn1;
                }
            }
        }
        if(which_player==2){
            if(which_pawn==3) current_pawn=&Pawn3;
            if(which_pawn==4) current_pawn=&Pawn4;
            if(current_pawn -> get_finished()==1){
                if(which_pawn==3){
                    cout<<"       Moving Pawn 4";
                    for(int i=0;i<3;i++){
                        cout<<".";
                        Sleep(500);
                    }
                    which_pawn=4;
                    current_pawn=&Pawn4;
                }
                else if(which_pawn==4){
                    cout<<"       Moving Pawn 3";
                    for(int i=0;i<3;i++){
                        cout<<".";
                        Sleep(500);
                    }
                    which_pawn=3;
                    current_pawn=&Pawn3;
                }
            }
        }
        } while(which_pawn!=var_a&&which_pawn!=var_b);
        ///////////////////////////////////////////////  PLACING PAWN ON BOARD
        current_pawn -> set_strength(second_number);
        if(current_pawn -> get_starting_point()==1){
            tmp_array_initial[0]=Board[0];
            Board[0]=current_pawn -> get_number();
            current_pawn -> decrease_strength();
            current_pawn -> in_game();
            if(current_pawn -> get_strength()==0){
                if(which_player==1){
                    if(tmp_array_initial[0]==3) Pawn3.beaten();
                    if(tmp_array_initial[0]==4) Pawn4.beaten();
                    if(tmp_array_initial[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                    if(tmp_array_initial[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
                }
                if(which_player==2){
                    if(tmp_array_initial[0]==1) Pawn1.beaten();
                    if(tmp_array_initial[0]==2) Pawn2.beaten();
                    if(tmp_array_initial[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                    if(tmp_array_initial[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
                }
                tmp_array_initial[0]=0;
            }
        }
        ///////////////////////////////////////////////  MOVING PAWN ON BOARD
        for(int i=0;i<20;i++){
            if(Board[i]==current_pawn -> get_number()){
            m=i;
            break;
            }
        }
        if(m!=-1){
        while(current_pawn -> get_strength()>0){
            if(m==19){
                current_pawn -> finished_the_game();
                Board[19]=0;
                break;
            }
            tmp_array2[0]=Board[m+1];
            Board[m+1]=current_pawn -> get_number();
            Board[m]=tmp_array1[0];
            tmp_array1[0]=tmp_array2[0];
            tmp_array2[0]=0;
            current_pawn -> decrease_strength();
            if(m==0) Board[0]=tmp_array_initial[0];
            tmp_array_initial[0]=0;
            if(current_pawn -> get_strength()==0){
                if(which_player==1){
                    if(tmp_array1[0]==3) Pawn3.beaten();
                    if(tmp_array1[0]==4) Pawn4.beaten();
                    if(tmp_array1[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                    if(tmp_array1[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
                }
                if(which_player==2){
                    if(tmp_array1[0]==1) Pawn1.beaten();
                    if(tmp_array1[0]==2) Pawn2.beaten();
                    if(tmp_array1[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                    if(tmp_array1[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
                }
                tmp_array1[0]=0;
            }
            m++;
        }
        ////////////////////////////////////////////  PLACING PAWN ON DIAGONAL 1
        if(current_pawn -> get_strength()==0&&m==5){
            if(which_player==1){
                if(Diagonal1[0]==3) Pawn3.beaten();
                if(Diagonal1[0]==4) Pawn4.beaten();
                if(Diagonal1[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                if(Diagonal1[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
            }
            if(which_player==2){
                if(Diagonal1[0]==1) Pawn1.beaten();
                if(Diagonal1[0]==2) Pawn2.beaten();
                if(Diagonal1[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                if(Diagonal1[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
            }
            Diagonal1[0]=Board[5];
            Board[5]=0;
        }
        ////////////////////////////////////////////  PLACING PAWN ON DIAGONAL 2
        if(current_pawn -> get_strength()==0&&m==10){
            if(which_player==1){
                if(Diagonal2[0]==3) Pawn3.beaten();
                if(Diagonal2[0]==4) Pawn4.beaten();
                if(Diagonal2[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                if(Diagonal2[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
            }
            if(which_player==2){
                if(Diagonal2[0]==1) Pawn1.beaten();
                if(Diagonal2[0]==2) Pawn2.beaten();
                if(Diagonal2[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                if(Diagonal2[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
            }
            Diagonal2[0]=Board[10];
            Board[10]=0;
        }
        }
        m=-1;
        /////////////////////////////////////////////  MOVING PAWN ON DIAGONAL 1
        for(int i=0;i<7;i++){
            if(Diagonal1[i]==current_pawn -> get_number()){
            m=i;
            break;
            }
        }
        if(m!=-1){
        while(current_pawn -> get_strength()>0){
            if(m==5){
                ////////////////////////////////////////////  PLACING PAWN BACK ON BOARD
                if(which_player==1){
                    if(Board[14+current_pawn -> get_strength()]==3) Pawn3.beaten();
                    if(Board[14+current_pawn -> get_strength()]==4) Pawn4.beaten();
                    if(Board[14+current_pawn -> get_strength()]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                    if(Board[14+current_pawn -> get_strength()]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
                }
                if(which_player==2){
                    if(Board[14+current_pawn -> get_strength()]==1) Pawn1.beaten();
                    if(Board[14+current_pawn -> get_strength()]==2) Pawn2.beaten();
                    if(Board[14+current_pawn -> get_strength()]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                    if(Board[14+current_pawn -> get_strength()]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
                }
                Board[14+current_pawn -> get_strength()]=Diagonal1[5];
                Diagonal1[5]=0;
                break;
                ////////////////////////////////////////////  END OF PLACING PAWN BACK ON BOARD
            }
            tmp_array2[0]=Diagonal1[m+1];
            Diagonal1[m+1]=current_pawn -> get_number();
            Diagonal1[m]=tmp_array1[0];
            tmp_array1[0]=tmp_array2[0];
            tmp_array2[0]=0;
            current_pawn -> decrease_strength();
            if(m==0) Diagonal1[0]=0;
            if(current_pawn -> get_strength()==0){
                if(which_player==1){
                    if(tmp_array1[0]==3) Pawn3.beaten();
                    if(tmp_array1[0]==4) Pawn4.beaten();
                    if(tmp_array1[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                    if(tmp_array1[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
                }
                if(which_player==2){
                    if(tmp_array1[0]==1) Pawn1.beaten();
                    if(tmp_array1[0]==2) Pawn2.beaten();
                    if(tmp_array1[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                    if(tmp_array1[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
                }
                tmp_array1[0]=0;
            }
            m++;
        }
        ////////////////////////////////////////////  PLACING PAWN ON DIAGONAL 2
        if(current_pawn -> get_strength()==0&&m==3){
            if(which_player==1){
                if(Diagonal2[3]==3) Pawn3.beaten();
                if(Diagonal2[3]==4) Pawn4.beaten();
                if(Diagonal2[3]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                if(Diagonal2[3]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
            }
            if(which_player==2){
                if(Diagonal2[3]==1) Pawn1.beaten();
                if(Diagonal2[3]==2) Pawn2.beaten();
                if(Diagonal2[3]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                if(Diagonal2[3]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
            }
            Diagonal2[3]=Diagonal1[3];
            Diagonal1[3]=0;
        }
        }
        m=-1;
        /////////////////////////////////////////////  MOVING PAWN ON DIAGONAL 2
        for(int i=0;i<7;i++){
            if(Diagonal2[i]==current_pawn -> get_number()){
            m=i;
            break;
            }
        }
        if(m!=-1){
        while(current_pawn -> get_strength()>0){
            if(m==5){
                current_pawn -> finished_the_game();
                Diagonal2[5]=0;
                break;
            }
            tmp_array2[0]=Diagonal2[m+1];
            Diagonal2[m+1]=current_pawn -> get_number();
            Diagonal2[m]=tmp_array1[0];
            tmp_array1[0]=tmp_array2[0];
            tmp_array2[0]=0;
            current_pawn -> decrease_strength();
            if(m==0) Diagonal2[0]=0;
            if(current_pawn -> get_strength()==0){
                if(which_player==1){
                    if(tmp_array1[0]==3) Pawn3.beaten();
                    if(tmp_array1[0]==4) Pawn4.beaten();
                    if(tmp_array1[0]==1&&current_pawn -> get_number()==2) Pawn1.beaten();
                    if(tmp_array1[0]==2&&current_pawn -> get_number()==1) Pawn2.beaten();
                }
                if(which_player==2){
                    if(tmp_array1[0]==1) Pawn1.beaten();
                    if(tmp_array1[0]==2) Pawn2.beaten();
                    if(tmp_array1[0]==3&&current_pawn -> get_number()==4) Pawn3.beaten();
                    if(tmp_array1[0]==4&&current_pawn -> get_number()==3) Pawn4.beaten();
                }
                tmp_array1[0]=0;
            }
            m++;
        }
        }
        m=-1;

        second_number=0;

        if(Pawn1.get_finished()==1&&Pawn2.get_finished()==1){
            who_won=1;
        }
        if(Pawn3.get_finished()==1&&Pawn4.get_finished()==1){
            who_won=2;
        }

    }
    if(who_won==1) cout<<endl<<"       Player 1 won the game!"<<endl;
    if(who_won==2) cout<<endl<<"       Player 2 won the game!"<<endl;

    return 0;
}
