#include<iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std ;

string player_name ;
bool pay_half_skip = true ;
bool skip = true ;
long cash = 0;
long question_price = 100 ;
int question_no = 1 ;
int consective = 0;
int right_answer = 0 ;
int wrong_answer = 0 ;

void result();
void game_rules();
void ask_random_question();
void check_answer(char answer , char correct_answer);

struct Question 
{
     string question ;
     string option_a ;
     string option_b ;
     string option_c;
     string option_d ;
     char answer ;
     bool availability ;

};

Question questions[20] ; 

void ask_random_question() {
    srand(time(0));
    while(true) {
        system("cls");
        int number = rand()%20;             
        if(questions[number].availability) {
            questions[number].availability = false;
            cout<<"===================================================================================================="<<endl;
            cout<<"=============================     KAUN BANEGA CROREPATI SHOW      =================================="<<endl;
            cout<<"===================================================================================================="<<endl;
            cout<<endl;
			cout<<"This Question No.  "<<question_no<<"  is for $ "<<question_price<<endl<<"\t\t\t\tYour balance is $  "<<cash<<endl<<endl;
            cout<<"Life Lines : ";
            if(pay_half_skip)
              cout<<"\th =>Pay Half and Skip";
            if(skip)
              cout<<"\tl =>Leave Questions";
              cout<<endl<<endl;
            cout<<"===================================================================================================="<<endl;
            cout<<"==========================================  CHOOSE OPTION  ========================================="<<endl;
            cout<<"===================================================================================================="<<endl;
            cout<<questions[number].question<<endl<<endl;
            cout<<"a) " <<questions[number].option_a<<"\t\t b) "<<questions[number].option_b<<endl<<endl;
            cout<<"c) " <<questions[number].option_c<<"\t\t d) "<<questions[number].option_d<<endl<<endl;
            
			char answer = _getch();
            answer = tolower(answer);
            cout<<endl;
            question_no ++;
            check_answer(answer,questions[number].answer);
            break;

        }
    }
}
void check_answer(char answer , char correct_answer){

 if(answer == correct_answer)  {
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"CONGRATULATION...!   Your answer is correct...\a"<<endl<<endl;
        cout<<"You earned $  :  "<<question_price<<endl;
        cout<<"Press any key to continue... "<<endl;
        _getch();
        right_answer++;
        consective++;
        cash = cash + question_price;

    }
    else if((answer =='h')&&(pay_half_skip))  {
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"You choose the lifeline 'Pay Half and Skip'"<<endl<<endl;
        cout<<"You loose $  :  "<<question_price/4 <<endl;
        cout<<"Press any key to continue... "<<endl;
        _getch();
        cash = cash -(question_price/4);
        pay_half_skip = false;

    }

    else if((answer =='l')&&(skip))  {
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"______________________________________________________________________________________________________"<<endl;
         cout<<"You choose the lifeline 'Leave Question'"<<endl<<endl;
        cout<<"You loose $ 0 "<<endl;
        cout<<"Press any key to continue... "<<endl;
        _getch();
        skip = false;
    } 

    else{
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"______________________________________________________________________________________________________"<<endl;
        cout<<"SORRY...! your answer is wrong..."<<endl<<endl;
        cout<<"You loose $  :  "<<question_price/2<<endl;
        cout<<"Press any key to continue... "<<endl;
        _getch();
        wrong_answer++;
        consective = 0;
        cash = cash - (question_price/2);
    }

    question_price = question_price*2;
    if(consective == 3)
        pay_half_skip = true;
    if(consective == 5) 
        skip = true;

}

void result(){
double percentage;
    percentage = right_answer*5;
    system("cls");
    cout<<"______________________________________________________________________________________________________"<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                             RESULTS                                                  "<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl<<endl<<endl;
    cout<<"Player Name     : \t "<<player_name<<endl<<endl;
    cout<<"Right Answer    : \t"<<right_answer<<endl<<endl;
    cout<<"Wrong Answer    : \t"<<wrong_answer<<endl<<endl;
    cout<<"Average         : \t"<<percentage<<"%"<<endl<<endl;
    if(cash>0)
    cout<<"Winning Amount  : \t"<<cash<<endl<<endl;
    else
    cout<<"Lossing Amount  : \t"<<cash<<endl<<endl<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl;
    cout<<"_________________________________    THANKS FOR PLAYING   ____________________________________________"<<endl;
    cout<<"______________________________________________________________________________________________________"<<endl;
    _getch();


}

void game_rules(){
cout<<"=========================================================================================================="<<endl;
	cout<<"===================================      RULES AND REGULATIONS     ==================================="<<endl;
	cout<<"======================================================================================================"<<endl;
	cout<<"01.THERE ARE TOTAL 20 QUESTIONS IN THIS GAME."<<endl;
	cout<<"02.THERE ARE ONLY TWO LIFELINES WHICH YOU CAN USE AT ANY STAGE OF THE GAME."<<endl;
	cout<<"03.PAY HALF & SKIP MEANS YOU HAVE TO PAY 1/4% OF CURRENT QUESTION."<<endl;
	cout<<"04.LEAVE QUESTION MEANS YOU CAN LEAVE A QUESTION WITHOUT ANY DEDUCTION."<<endl;
	cout<<"05.IF YOU ATTEMPT 3 CONSECUTIVE RIGHT ANSWERS PAY HALF & SKIP WILL RESCUED."<<endl;
	cout<<"06.IF YOU ATTEMPT 5 CONSECUTIVE RIGHT ANSWERS LEAVE QUESTION WILL RESCUED."<<endl;
	cout<<"07.AFTER EVERY QUESTION THE AMOUNT OF QUESTION WILL BE DOUBLE."<<endl;
	cout<<"08.IF THE ANSWER IS WRONG HALF AMOUNT QUESTION DEDUCTS FROM YOUR BALANCE."<<endl;
	cout<<"09.PRESS H FOR PAY HALF & SKIP HELPLINE AND L FOR LEAVE QUESTION HELPLINE."<<endl;
	cout<<"10.PRESS A,B,C OR D TO ANSWER ANY QUESTION."<<endl;
	cout<<"=========================================================================================================="<<endl;
	cout<<"===================================     PRESS ANY KEY TO START     ======================================="<<endl;
	cout<<"=========================================================================================================="<<endl;
	
	
	_getch();
    
}






int main()
{
  system("cls") ;
    questions[0]={"Which operator is used in priority check?" , "operator<","operator>","operator)","operator!",'a',true};
   questions[1]={"Which of the following approach is used by C++?","top-down","bottom-up","left-right","right-left",'b',true};
   questions[2]={"Which is the correct syntax for declaring a allocator?","template < class T > class allocator","template < class T > class","template class allocator","template class()",'a',true};
   questions[3]={"Which of the following accesses a variable in structure *b?","b->var","b.var","b-var","b>var",'a',true};
   questions[4]={"Which of the following header file is required for creating and reading data files?","ofstream.h","fstream.h","ifstream.h","console.h",'b',true};
   questions[5]={"Which of the following operator is used with this pointer to access members of a class?","!",".","->","~",'c',true};
   questions[6]={"Setprecision require which of the following header file?","stdlib.h","iomanip.h","console.h","conio.h",'b',true};
   questions[7]={"In which of the following we cannot overload the function?","return function","caller","called function","main function",'a',true};
   questions[8]={"What can be used to input a string with blank space?","inline","getline","putline","setline",'b',true};
   questions[9]={"Which of the following cannot be a friend? ","class","friend","object","operator function",'c',true};
   questions[10]={"What is the syntax of a friend function?","friend class1, class2;","friend class;","friend class","class()",'a',true};
   questions[11]={"Which is used to iterate over containers?","associator iterator type","data type of objects","return type of variables","name of the variables",'a',true};
   questions[12]={"Which of the following is not a fundamental type is not present in C but present in C++?","int","float","bool","void",'c',true};
   questions[13]={"How to declare a wide character in the string literal?","L prefix","I prefix","W prefix","Z prefix",'a',true};
   questions[14]={"What is the use of reference member type in allocator?","Point to an element","Quantities of element","Reference to an element","Sequence of an element",'c',true};
   questions[15]={"What is the main feature of locale in C++?","Portability","Reliability","Sustainability","all of the above",'c',true};
   questions[16]={"what will be the output of the following C++ code? \n #include <iostream> \n using namespace std; \n void sqaure (int *x, int *y){ \n x = (*x) -- (*y);\n } \n int main(){ \n int number = 30; \n (&number, &number) \ncout<<number;\n}","870","30","error","segmentation fault",'a',true};
   questions[17]={"Which of the following features must be supported by any programming language to beacome a pure object-oriented-programming language?","Encapsulation","Inheritance","Polymorphism","All of the above",'d',true};
   questions[18]={"Who is the creator of C++ language?","Dennis Ritchie","Ken Thompson","Bjarne Stroustrup","Brian Kernighan",'c',true};
   questions[19]={"The C++ language is _____ object-oriented language.","pure","not","semi or partial","none of the above",'c',true};

   
   
 cout<<"__________________________________________________________________________________________________________\n"<<endl;
 cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  "<<endl;
for (int i = 0; i < 5; i++)
{cout<<" *                                                                                                       *"<<endl ;}

cout<<" *    *        *       *   * * * * *   *            * * * *     * * *     *        *     * * * * *       *"<<endl;
cout<<" *     *      * *     *    *           *          *           *       *   * *     * *    *               *"<<endl;
cout<<" *      *    *   *   *     * * * * *   *          *           *       *   *  *   *  *    * * * * *       *"<<endl;
cout<<" *       *  *     * *      *           *          *           *       *   *   * *   *    *               *"<<endl;
cout<<" *         *       *       * * * * *   * * * * *    * * * *     * * *     *    *    *    * * * * *       *"<<endl;

for (int i = 0; i < 5; i++)
{cout<<" *                                                                                                       *"<<endl;}
 cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl; 
 cout<<"__________________________________________________________________________________________________________"<<endl;
for (int i = 0; i < 3; i++)
{
    cout<<"." ;
    Sleep(1000) ;
}

system("cls");

cout<<"_________________________________________________________________________________________________________________\n"<<endl ;

cout<<"\n"<<endl ;
cout<<"      *     *       *       *       *    *     *      *  * * *       *       *     *   * * * *     * * *       *     "<<endl;
cout<<"      *   *        * *      *       *    * *   *      *      *      * *      * *   *   *         *            * *    "<<endl;
cout<<"      * *         * * *     *       *    *  *  *      * * *  *     * * *     *  *  *   * * * *   *  *  *     * * *   "<<endl;
cout<<"      *   *      *     *    *       *    *   * *      *      *    *     *    *   * *   *         *     *    *     *  "<<endl;
cout<<"      *     *   *       *     * * *      *     *      * * *  *   *       *   *     *   * * * *     * * *   *       * "<<endl;
cout<<"\n"<<endl ;

cout<<"                 * * *   * * * *     * * *     * * * *   * * * *  * * * *      *      * * * * *   *                  "<<endl;
cout<<"              *          *      *  *       *   *      *  *        *      *    * *         *       *                  "<<endl;
cout<<"              *          * * * *   *       *   * * * *   * * * *  * * * *    * * *        *       *                  "<<endl;
cout<<"              *          *   *     *       *   *   *     *        *         *     *       *       *                  "<<endl;
cout<<"                * * *    *     *     * * *     *     *   * * * *  *        *       *      *       *                  "<<endl;
cout<<"\n"<<endl ;

cout<<"                              * * * *   *     *     * * *    *       *       *                                  "<<endl;
cout<<"                              *         *     *   *       *   *     * *     *                                   "<<endl;
cout<<"                              * * * *   * * * *   *       *    *   *   *   *                                    "<<endl;
cout<<"                                    *   *     *   *       *     * *     * *                                     "<<endl;
cout<<"                              * * * *   *     *     * * *        *       *                                      "<<endl;


cout<<"\n"<<endl ;

cout<<" ____________________________________________________________________________________________________________________"<<endl;

for (int i = 0; i < 3; i++)
{
    cout<<"." ;
    Sleep(1000) ;
}
system("cls") ;
cout<<"ENTER YOUR NAME : ";
cin>>player_name ;
for (int i = 0; i < 3; i++)
{
    cout<<"." ;
    Sleep(1000) ;
}

system("cls") ;

game_rules() ;
while (true)
{
 if(question_no >20)   
   break ;

ask_random_question() ;

}
result() ;
    return 0 ;
}
