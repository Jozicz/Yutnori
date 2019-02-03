#include <iostream>
#include "functionDraw.h"

using namespace std;

void draw(int board[],int diagonal1[],int diagonal2[]){
    cout<<"       ";
    if(board[10]!=0&&diagonal2[0]==0) cout<<board[10]<<"        ";
    if(board[10]==0&&diagonal2[0]!=0) cout<<diagonal2[0]<<"        ";
    else cout<<board[10]<<"        ";
    for(int i=9;i>5;i--){
        cout<<board[i]<<"        ";
    }
    if(board[5]!=0&&diagonal1[0]==0) cout<<board[5];
    if(board[5]==0&&diagonal1[0]!=0) cout<<diagonal1[0];
    else cout<<board[5];
    cout<<endl<<endl<<endl<<endl;
    cout<<"       ";
    cout<<"      "<<diagonal2[1]<<"                                "<<diagonal1[1];
    cout<<endl<<endl;
    cout<<"       ";
    cout<<board[11]<<"                                            "<<board[4];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<"             "<<diagonal2[2]<<"                  "<<diagonal1[2];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<board[12]<<"                                            "<<board[3];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<"                      ";
    cout<<diagonal2[3];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<board[13]<<"                                            "<<board[2];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<"             "<<diagonal1[4]<<"                  "<<diagonal2[4];
    cout<<endl<<endl<<endl;
    cout<<"       ";
    cout<<board[14]<<"                                            "<<board[1];
    cout<<endl<<endl;
    cout<<"       ";
    cout<<"      "<<diagonal1[5]<<"                                "<<diagonal2[5];
    cout<<endl<<endl<<endl<<endl;
    cout<<"       ";
    for(int i=15;i<20;i++){
        cout<<board[i]<<"        ";
    }
    cout<<board[0];
}
