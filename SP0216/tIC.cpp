#include<iostream>
#include<stdlib.h>
using namespace std;

int login(){
	string username;
	string password;
	int loginattempt;
	// use loop for login when wrong pass or user
	while (loginattempt<5){
		cout<<"******************************************"<<endl;
		cout<<"              simple login              "<<endl;
		cout<<"******************************************"<<endl;
		cout<<"enter username"<<endl;
		cin>>username;
		cout<<"enter password"<<endl;
		cin>>password;
		//here we make username and password
		if( username=="SP0216" && password=="1234567890"){
			cout<<"WELCOME TO SP0216";
			break;
		}
		else{
			cout<<"please check your username and password,TRY AGAIN!!"<<endl;
			loginattempt++;
		}
		if(loginattempt==5){
			cout<<"SORRY! Too many login .... You cannot login continue";
			return 0;
		}
	}
}

char square[10]={'0','1','2','3','4','5','6','7','8','9'};

/*function to retuen game status:-
  (  1- game is over with result
    -1- game is in progress
     0- game draw
  ) 
*/
int checkwin(); 

void displayboard(); //for draw a structure of the game
int main()
{
	login();
         
	int player = 1,i,choice;

    char pointmark;
    do
    {
        displayboard();
        player=(player%2)?1:2;

        cout << "\nPlayer " << player << ", enter a number:  ";
        cin >> choice;

        pointmark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = pointmark;
        else if (choice == 2 && square[2] == '2')

            square[2] = pointmark;
        else if (choice == 3 && square[3] == '3')

            square[3] = pointmark;
        else if (choice == 4 && square[4] == '4')

            square[4] = pointmark;
        else if (choice == 5 && square[5] == '5')

            square[5] = pointmark;
        else if (choice == 6 && square[6] == '6')

            square[6] = pointmark;
        else if (choice == 7 && square[7] == '7')

            square[7] = pointmark;
        else if (choice == 8 && square[8] == '8')

            square[8] = pointmark;
        else if (choice == 9 && square[9] == '9')

            square[9] = pointmark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.get();
        }
        i=checkwin();

        player++;
    }while(i==-1);
    displayboard();
    if(i==1)
        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";
        
    cin.get();
    return 0;
}
int checkwin(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1; 
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else 
		return -1;	
}


 void displayboard()
{
	system("cls");
	cout<<"\n\t\t    -----------------------"<<endl;
	cout<<"\t\t\t  TIC TAC TOE"<<endl;
	cout<<"\t\t    -----------------------"<<endl;
	cout<<"\n\t\t    Player1(X) vs Player2(o)"<<endl;
	cout<<"\n\t\t           |       |   "<<endl;
	cout<<"\t\t        "<<square[1]<<"  |   "<<square[2]<<"   |   "<<square[3]<<endl;
	cout<<"\t\t      _____|_______|_____"<<endl;
	cout<<"\t\t           |       |   "<<endl;
	cout<<"\t\t        "<<square[4]<<"  |   "<<square[5]<<"   |   "<<square[6]<<endl;
	cout<<"\t\t      _____|_______|_____"<<endl;
	cout<<"\t\t           |       |   "<<endl;
	cout<<"\t\t        "<<square[7]<<"  |   "<<square[8]<<"   |   "<<square[9]<<endl;
	cout<<"\t\t           |       |       "<<endl;
}
//SHASHANK VYAS
//MOHIT AGARWAL
//SWATI
