#include <iostream>
#include <stdlib.h>
using namespace std;

int choice,row,column, assign_turn = 0;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
bool draw = false;

void display_board()
{
    
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void player_turn()
{
    if(assign_turn%2 == 0)
    {
        cout << "Player[1] = X Turn ";
    }
    else if(assign_turn%2 != 0)
    {
        cout << "Player[2] = O Turn ";
    }

    cout << "Please choose your postion";
    cin>>choice;

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }
    cout << row << column;

    if(assign_turn%2 == 0 && board[row][column] != 'X' && board[row][column] != 'O' )
    {
        cout<<"Here";
        board[row][column] = 'X';
         assign_turn ++ ;
    }

    else if(assign_turn%2 != 0 && board[row][column] != 'X'  && assign_turn%2 != 0 && board[row][column] != 'O' )
    {
        board[row][column] = 'O';
         assign_turn ++ ;
    }
    else 
    {
        cout<<"Box already filled!n Please choose another!!nn";
        player_turn();
    }


     
     display_board();


}

bool game_over()
{
    for(int i = 0; i < 3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;
    
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;
    

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;

    
}
int main()
{
     

     int max = 0%2;
     cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
     while(game_over())
     {
         display_board();
         player_turn();
         game_over();
     }
    
    if(assign_turn %2 == 0 && draw == false)
    {
        cout<<"nnCongratulations!Player with 'O' has won the game";
    }
    else if(assign_turn %2 != 0 && draw == false)
    {
        cout<<"nnCongratulations!Player with 'X' has won the game";
    }
    else
    {
        cout<<"nnGAME DRAW!!!nn";
    }
}