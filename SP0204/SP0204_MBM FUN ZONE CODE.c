#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define WON 0
#define LOSE 1
int main( ){
	// THIS CODE IS COMPATIBLE FOR HALF SCREEN
        // In this main function we used simple switch case pattern to jump on the another functions of our team details and another is to enter the fun zone
	    int ch,press;
        char choice;
		system("cls");
        printf("\n\n");
        printf("\t\t\t\tHola peeps!!\n\n");
        printf("We the team members of SP0204 are here to introduce you with an exciting arena\nof MBM . \n\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *            MBM FUN ZONE              *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n\n");
		   
        printf("press 1 . for entering into FUN ZONE\n\n");
        printf("press 2 . To get familar with our team members\n\n");
        printf("press 0 .  To exit\n\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&press);
        switch(press){
        	case 0:
        		exit(0);
        		break;
        	case 1:
        		enterfun_zone();
        		break;
        		case 2:
        			team_details();
        			break;
        			default:
        				printf("invalid choice.....");
		}


	return 0;
}



int enterfun_zone(){
// In this enterfun_zone function we also used a simple switch case pattern to jump on the functions of our game.....
	int ch;

	while(1){
		system("cls");
		printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *       WELCOME TO MBM FUN ZONE        *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n\n");
		printf("1. TIC TAC TOE\n");
		printf("2. MATCHSTICK GAME\n");
		printf("3. FORTUNE TRIO \n");
		printf("4. KAUN BANEGA BOLLYWOOD STAR\n");
		printf("5. FIND THE MYSTERY NUMBERS\n");
		printf("6. DICE ROLLER GAME\n");
		printf("7. GO TO HOME PAGE\n\n");
		printf("enter your choice:");
		scanf("%d", &ch);

		switch(ch){

				case 1:
					tic_tac_toe();
					break;
					case 2:
						matchstick_game();
						break;
				  case 3:
				  	trio();
				  	break;
				  	case 4:
				  		kbbs();
				  		break;
				    case 5:
				    	mystery_numbers();
				    	break;
				    	case 6:
				    		dice_roller();
				    		break;
				    		case 7:
				    			main();
				    			break;
		}
	}
	return 0;
}

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

int tic_tac_toe()
{   // here is our first game that is tic_tac_toe() which is made by our whole team 
    int player = 1, i, choice;
     i=checkwin();
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("   Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("   Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
   {
        printf("   ==>\aPlayer %d win ", --player);

        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';

    
    }

    else{
        printf("   ==>\aGame draw");
         square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
       
    }
    printf("\n\npress enter to go back to fun page");
    getch();
   
    return 0;
}

int checkwin()
{ // this function is made to check the winning of player 
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*********
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********/


void board()
{
    system("cls");
      printf("     ***WELCOME TO THE GAME***\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t   Tic Tac Toe");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    printf("   Player 1 (X)  -  Player 2 (O)\n\n");


    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);

    printf("\t|     |     |     |\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}

int matchstick_game()
{ // this game is made by Khushbu Bijawat and the rules of this game is mentioned below in the code
	srand(time(0));
int mstick=21,user,computer;
system("cls");
printf("                    ***WELCOME TO THE GAME***\n\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *           MATCHSTICK GAME            *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("\nRULES:\nThere are 21 matchsticks\n\nThe computer asks the player to pick 1, 2, 3, 4 or 5 matchsticks.\n\nAfter the person picks,the computer does its picking.\n\nwhoever is forced to pick up the last matchstick losses the game...\n\nYou can pick minimum 5 sticks at a time");
while(1)
{
      printf("\n\n--------------------------------------------------------------------------------\n");
	printf("\n your turn %c\n",1);


	printf("\n pick stick:");
	scanf("%d",&user);
	mstick=mstick-user;
		if(mstick<1)
	{
		printf("\n Oops last stick is for you");
		printf("\n you lost this game, better luck for next time");
		break;
	}
	if(user>5)
	{
		printf("\n you cannot pick more than 5 sticks at a time ,try again");
		continue;
	}
	computer= (rand()%5)+1;
	printf("\n computer picked %d sticks", computer);
	mstick=mstick-computer;
		if(mstick<=1)
	{
		printf("\n you won%c",2);
		break;
	}


	}

	printf("\n\n THANK YOU%c",3);
	printf("\n\nEnter any key to go back to fun page:");
		getch();

}

int trio(){
	// this is an fun activity which consist three intresting activities like know about your zodiac sign, future prediction & personality traits and this game is made by Karishma Sharma
// In this game we also used the switchcase pattern to enter the functions of these three activities
int option,dob,z,day,month,fortune_cookie;
char str1[10] , c,ans,C;
char colour;
   system("cls");
   printf("                    ***WELCOME TO THE GAME***\n\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *            FORTUNE TRIO              *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf(" About the game:-\n");
printf("\nSo as the name tells ,this game consists of three games :\n 1. Zodiac Teller \n 2. Future prediction \n 3. Personality Traits ");
printf("\n\n#INSTRUCTIONS: \n");
printf("\n|| %c In Zodiac teller you are supposed to enter your birth date and month number .\n   For ex- 7  in date and 3 in month says 7 march ,your zodiac will be displayed according to it .\n",2);
printf("\n|| %c In Future prediction you are supposed to enter your favourite number between [0 to 10], and you got to know about your future.\n ",2);
printf("\n|| %c In Personality traits , you are required to enter a colour from given options , then according to that color it will display your about your personality.\n",2);

printf("\nEnter your name : \t");
scanf("%s",str1);
system("cls");
printf("\n\n\n\n\n\n\n\n \t********************************************************\n");
printf(" \t*                                                      *\n");
printf(" \t*                                                      *\n");
printf(" \t*          Here we go!!!!!!!!!!!%c                      *\n",2);
printf(" \t*                                                      *\n");
printf(" \t*                                                      *\n");
printf(" \t*           press enter to continue...                 *\n");
printf(" \t*                                                      *\n");
printf(" \t*                                                      *\n");
printf(" \t********************************************************");

do{
        getch();
        system("cls");
printf("\n\nEnter the number of what you want to know : \n");
printf("\n press 1 -  to know your zodiac sign\n");
printf("\n press 2 -  future prediction\n");
printf("\n press 3 -  personality traits\n");
printf("\n press 4 -  to go back to home page\n");
scanf("%d",&option);
switch(option){
	case 4:
		enterfun_zone();
		break;
case 1:
	// In the first activity we have to enter our birth date to know our zodiac sign
        printf("Enter birth day\n");
             scanf("%d",&day);
        printf("enter birth month\n");
             scanf("%d", &month);
    if(month > 12 && month < 0 || day > 31 && day < 1 )  {
          printf("invalid month and day\n"); }
    else if(month == 10 && day>=23||month == 11 && day<=21)
          {
               printf("\nYour zodiac sign is scorpion and your birthstone is topaz\n");
               printf("Scorpio is one of the most misunderstood signs of the zodiac.\n Because of its incredible passion and power, Scorpio is often mistaken for a fire sign.\n In fact, Scorpio is a water sign that derives its strength from the psychic, emotional realm.\n");}
       else if(month == 9  && day >=23 || month == 10 && day <= 22)
           {
               printf("\nYour zodiac sign is libra and your birthstone is opal\n");
               printf("Libra is an air sign represented by the scales (interestingly, the only inanimate object of the zodiac), an association that reflects Libra's fixation on balance and harmony.\n Libra is obsessed with symmetry and strives to create equilibrium in all areas of life. \n");
          }
       else if(month == 8  && day >=23 || month == 9  && day <= 22)
          {
               printf("\nYour zodiac sign is virgo and your birthstone is sapphire\n");
               printf("Virgo is an earth sign historically represented by the goddess of wheat and agriculture, an association that speaks to Virgo’s deep-rooted presence in the material world.\n Virgos are logical, practical, and systematic in their approach to life.\n This earth sign is a perfectionist at heart and isn’t afraid to improve skills through diligent and consistent practice.\n");
         }
       else if(month == 7  && day >=23 || month == 8  && day <= 22)
          {
               printf("\nYour zodiac sign is leo and your birthstone is peridot\n");
               printf("Roll out the red carpet because Leo has arrived.\n Leo is represented by the lion and these spirited fire signs are the kings and queens of the celestial jungle.\n They’re delighted to embrace their royal status: Vivacious, theatrical, and passionate, Leos love to bask in the spotlight and celebrate themselves\n");
          }
       else if(month == 6  && day >=21 || month == 7  && day <= 22)
          {
          printf("\nYour zodiac sign is cancer and your birthstone is ruby\n");
          printf("Cancer is a cardinal water sign.\n Represented by the crab, this crustacean seamlessly weaves between the sea and shore representing Cancer’s ability to exist in both emotional and material realms.\n Cancers are highly intuitive and their psychic abilities manifest in tangible spaces: \nFor instance, Cancers can effortlessly pick up the energies in a room.\n");
          }
       else if(month == 5  && day >=21 || month == 6  && day <= 20)
          {
          printf("\nYour zodiac sign is gemini and your birthstone is pearl\n");
          printf("Have you ever been so busy that you wished you could clone yourself just to get everything done? That’s the Gemini experience in a nutshell. Appropriately symbolized by the celestial twins, this air sign was interested in so many pursuits that it had to double itself.\n");
          }
       else if(month == 4  && day >=20 || month == 5  && day <= 20)
          {
          printf("\nYour zodiac sign is taurus and your birthstone is emerald\n");
          printf("Taurus is an earth sign represented by the bull.\n Like their celestial spirit animal, Taureans enjoy relaxing in serene, bucolic environments surrounded by soft sounds, soothing aromas, and succulent flavors.\n");
          }
       else if(month == 3  && day >=21 || month == 4  && day <= 19)
          {
          printf("\nYour zodiac sign is aries and your birthstone is aries\n");
          printf("Aries loves to be number one, so it’s no surprise that these audacious rams are the first sign of the zodiac. \nBold and ambitious, Aries dives headfirst into even the most challenging situations.\n");
          }
      else if(month == 2  && day >=19 || month == 3  && day <= 20)
          {
          printf("\nYour zodiac sign is pisces and your birthstone is aquamarine\n");
          printf("Pisces characters are regarded for being among the most sympathetic of the zodiac signs, and they will go to great lengths to ensure the happiness of those around them.\n They're also creative and imaginative.\n Pisces are sympathetic and sensitive to others' feelings.\n");
          }
       else if(month == 1  && day >=20 || month == 2  && day <= 18)
          {
          printf("\nYour zodiac sign is Aquarius and your birthstone is amethyst\n");
          printf("Despite the \"aqua\" in its name, Aquarius is actually the last air sign of the zodiac.\n Aquarius is represented by the water bearer, the mystical healer who bestows water, or life, upon the land.\n Accordingly, Aquarius is the most humanitarian astrological sign.\n");
          }
      else if(month == 12 && day >=22 || month == 1  && day <= 19)
          {
          printf("\nYour zodiac sign is Capricorn and your birthstone is garnet\n");
          printf("The last earth sign of the zodiac, Capricorn is represented by the sea goat, a mythological creature with the body of a goat and the tail of a fish.\n Accordingly, Capricorns are skilled at navigating both the material and emotional realms.\n");
          }
      else if(month == 11 && day >=22 || month == 12 && day <= 21)
          {
          printf("\nYour zodiac sign is saggitarius and your birthstone is turquoise\n");
          printf("Represented by the archer, Sagittarians are always on a quest for knowledge.\n The last fire sign of the zodiac, Sagittarius launches its many pursuits like blazing arrows, chasing after geographical, intellectual, and spiritual adventures.\n");
          }
else
 printf("\nERROR");
break;
case 2:
	// in this activity we have to enter our lucky number from 1 to 10 to know about our future
    printf("\n\nTaddahhh!! welcome to mystry world ! there's something special for you %c%c \n\n",1,3);
    printf("Enter your lucky number from [1 to 10] to know about your future:\n");
    scanf("%d",&fortune_cookie);
      if(fortune_cookie ==1){
          printf("you will get old, lonely and have 3 cats named Buddy, Jim, and Fernando.That's sad!\n\n");}
      else if(fortune_cookie ==2){
          printf("you will move to paris after you get married. You will have three kids, two boys, and one girl, and you will have a golden retriever. Amazing! I guess it's happy ever after%c ", 3); }
      else if(fortune_cookie == 3){
          printf("you will not be very wealthy but with a steady job. You will be married and have no kids. You will live in suburban village in connecticut. What can I say more...\n\n");}
      else if(fortune_cookie == 4){
          printf("The picture is getting clearer....OK, I see it! You will be a millionaire. You will make $1,000,000 a year or more. You will live in a mansion of about 9,000 square feet. You will have three kids. Your cars will be a Range Rover, a Lamborghini and an Aston Martin. You will die at age 60 from smoking and drinking too much.\n\nOh my god, my crazy crystal ball shatters, Scotty beam me up.\n\nDon't like what my crazy crystal ball foretold for you?\n\nNo worries! This was just for fun. YOU CONTROL\n\nYOUR FUTURE! So make the most of it! Good luck!%c\n\n",2);}
      else if(fortune_cookie ==5){
          printf("Everything has finally fallen into place and you will get to adopt a pet to keep you company! It may not be the pet of your dreams in the beginning, but you'll quickly realize how important its role is in your life.\n\n");}
      else if(fortune_cookie == 6){
          printf("If you haven't already, you will find your Charming and live in a beautiful and magical world of flower petals, bunnies, and cupcakes. Almost everything will work out for you. Together you will slay any obstacles that arise!\n\n");}
      else if(fortune_cookie == 7){
          printf("You will be vampire soon. It's all just star to make some distance from your loved ones...you are dangerous for them.\n\n");}
      else if(fortune_cookie == 8){
          printf("you will get a lottery of 1 billion rupee..and from that money you will open a software company and will marry to a daughter of richest man of world....That's quite intresting.%c\n\n",2);}
      else if(fortune_cookie == 9){
          printf("you are a dog lover and you will adopt 10 different breed dogs...and your life will be going so happily with all these cute dogs.That's great..%c\n\n ", 1);}
      else if(fortune_cookie == 10){
          printf("You will become an politician in future.....and do the great changes for the welfare for your country...you will become the unforgettable politician for your country that's really good.%c \n\n", 1);}
       break;


case 3:
	
// In this activity we have to enter our favourite colour to know about our personality
  while(colour<=5){
    	system("cls");
		printf("CHOOSE YOUR FAVOURITE COLOUR FROM BELOW OPTIONS:\n");
		printf("1. BLACK\n");
		printf("2. RED\n");
		printf("3. YELLOW \n");
	    printf("4. PINK \n");
	    printf("5. PURPLE\n");
	    printf("6. exit\n\n");
		printf("enter your favourite colour to know your personality traits\n or press 6 to exit%c : ",1);
		scanf("%d", &colour);
	    system("cls");
    switch(colour){
    	case 1:
    		black();
    		break;
    		case 2:
    			red();
    			break;
    			case 3:
    				yellow();
    				break;
    				case 4:
    					pink();
    					break;
    					case 5:
    						purple();
    						break;

    						default:
    							printf("\n\n\t\t\tTHANK YOU%c...!\n\t\t\tHope you enjoyed it...%c\n",3,2);
    							break;
}
}
}
printf("\t\t\nPress C to continue.... \n or \n\n\t\tPress any Key To Exit\n");

scanf("%c",&c);
getch();
}
while(ans == 'c','C');

  return 0;
}
int black(){
system("cls");
        printf("BLACK\n\nBlack can mean so many different things: boldness, uniqueness, mystery, intrigue, and power. But it can also mean unhappiness, darkness, sadness, pain, or grief. Black is associated with death and mourning, but can also be associated with strength, luxury, and intensity.\n\n");
        printf("Personality traits of black:\n\nBold\nRisk-taker\nPerhaps a little impulsive at times\nSerious \(maybe a little too serious)\n You are strong and command a sense of respect from your peers\nYou are trustworthy\nPerhaps a little intimidating\n");
      getch();
      return 0;
   }

   int red(){
            printf("RED \n\nRed is a bold color choice that's been associated with excitement, passion, danger, thrill, energy, and action. \nYou may notice that some brands use red for their \"call to action\" buttons (\"order now,\" \"shop now\" etc.). This is because red is an intense color that is able to provoke strong emotions which can encourage you to buy things.\nPersonality traits of red:\nBold\nThrill-seeker\nAdventure-lover\nCan be a little impulsive\ncan be perceived as intimidating\n");
      getch();
	   return 0;
        }

    int yellow(){
           printf("YELLOW\n\nHappiness, positivity, and warm summer sun is what yellow reminds us of. Brands may use a splash of yellow in their logo to make you feel happy when you see their products. Many \"free shipping\" icons on websites may be yellow to attract you to something that is cheerful and positive.\n");
           printf("\nPersonality traits of yellow:\nA positive spirit\nOptimistic\nCheerful\nAdventurous\nCalming for those around them\nInfectious smiles and happiness that spreads to each person they encounter\n");
     getch();
	  return 0;
      }

   int pink(){
           printf("PINK\n\nPink is often associated with femininity, playfulness, and love, but pink can also be perceived as a somewhat immature color. You will notice a lot of pink in a child's toy packaging or brands to signal playful, whimsical fun. Other brands (Victoria Secret for example) have signified the color to mean something cute, fun, playful\n");
           printf("\nPersonality traits of pink:\nFun\nPlayful\nMaybe a little naive\nYou wear your heart on your sleeve and aren't afraid to express your emotions\nLove and family are important to you\n");
         getch();
		 return 0;
          }

  int purple(){
          printf("PURPLE\n\nPurple can be connected to royalty, power, privilege, wisdom, and spirituality. Purple can be something of a frustrating color as well, as it can cause feelings of frustration or be perceived as arrogant - this is why websites and brands (Hallmark, Yahoo) will use a splash of purple or mix purple with a warmer tone such as white.\n");
          printf("\nPersonality traits of purple:\n\nQuick-witted\nCraves own identity\nLoves unique things and wants to stand out from the pack\nDances to the music no one else can hear\nYou thrive on creativity and inspiration strikes you randomly, allowing you to tune out the world and focus on it\n");
 getch();
  return 0;
   }


 int kbbs()
{ 
// it is an simple and intresting quiz game on bollywood which is made by Aparna Jain
//In this quiz there are 10 questions on bollywood movies if we know the correct answer then we got 3 marks and if submit the wrong answer then we got -1 marks and if want help then we have only two options left just like the lifeline 50-50 in kbc and then after using that lifeline you got the correct answer then you got 2 marks 
int score=0;
int answer;

system("cls");
   printf("                      ***WELCOME TO THE GAME***\n\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *    KAUN BANEGA BOLLYWOOD STAR        *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("\nRULES:- \n\n #1. The game has 10 questions..... \n\n#2. You get +3 for each correct answer & -1 for each wrong/invalid answer and \n 0 for not answering.\n");
printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

printf("Press any key to play the game\n");
getch();
        system("cls");

printf("\n\nQ1)Which movie is this popular line from:  %cdosti ka ek usool hai madam no sorry ,no thank you.%c? \n", 34,34);
printf("[1]Kuch kuch hota hai\t[2]Dilwale dulhania le jayenge\n[3] Maine pyar kiya\t[4]Andaz apna apna\n");
scanf("%d", &answer);

if(answer==3)
{
printf("That is Correct!%c\n", 2);
score=score+3;
printf(" you got %d marks\n",score);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Maine pyar kiya \t [2] Kuch kuch hota hai\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score=score+2;
		printf("You got %d marks\n",score);
	}
	else
	{
		printf("Wrong answer..!\n");
		score=score-1;
		printf("You got %d marks\n",score);
	}

}
}
if(answer==2)
{
score=score+0;
printf(" you got %d marks\n\n",score);
}
printf("-----------------------------------------------------\n");
printf("\nQ2) What was the name of HOD of ICE college in %c3 idiots%c?\n", 34,34);
printf("[1] Virus\t[2] silencer\n[3] phunsung\t[4] Chatur\n");
scanf("%d", &answer);

int score2=0;
if(answer==1)
{
printf("That is Correct!%c\n",2);
score2=score2+3;
printf(" you got %d marks\n",score2);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Virus \t [2] Silencer\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score2=score2+2;
		printf("You got %d marks\n",score2);
	}
	else
	{
		printf("Wrong answer..!\n");
		score2=score2-1;
		printf("You got %d marks\n",score2);
	}

}
}
if(answer==2)
{
score2=score2+0;
printf(" you got %d marks\n\n",score2);
}

printf("-----------------------------------------------------\n");
printf("\nQ3) What game do they play on the train in ye Jawaani hai diwaani movie?\n");
printf("[1] Never have i ever\t[2] Dumb charades\n[3] antakshari\t[4] dumsaraj\n");
scanf("%d", &answer);

int score3=0;
if(answer==1)
{
printf("That is Correct!%c\n",2);
score3=score3+3;
printf(" you got %d marks\n",score);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Never have i ever \t [2] Dumb charades\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score3=score3+2;
		printf("You got %d marks\n",score3);
	}
	else
	{
		printf("Wrong answer..!\n");
		score3=score3-1;
		printf("You got %d marks\n",score3);
	}

}
}
if(answer==2)
{
score3=score3+0;
printf(" you got %d marks\n\n",score3);
}
printf("-----------------------------------------------------\n");
printf("\nQ4) What was the name of the circus in movie %cPhir Hera Pheri%c?\n", 34,34);
printf("[1] The Great Ramayan Circus\t[2] The Great Golden Circus\n[3] The Great Carniwal Circus\t[4] The Great Royal Circus\n");
scanf("%d", &answer);

int score4=0;
if(answer==4)
{
printf("That is Correct!%c\n",2);
score4=score4+3;
printf(" you got %d marks\n",score4);

}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] The Great Royal Circus \t [2] The Great Ramayan circus \n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score4=score4+2;
		printf("You got %d marks\n",score4);
	}
	else
	{
		printf("Wrong answer..!\n");
		score4=score4-1;
		printf("You got %d marks\n",score4);
	}

}
}
if(answer==2)
{
score4=score4+0;
printf(" you got %d marks\n\n",score4);
}

printf("-----------------------------------------------------\n");
printf("\nQ5) Fill in the blank- %cIss kahani mai Emotion hai,___hai,Tragedy hai%c (movie-->sholay)\n",34,34);
printf("[1] Action\t[2] Romance\n[3] Drama\t[4] Feeling\n");
scanf("%d", &answer);

int score5=0;
if(answer==3)
{
printf("That is Correct!%c\n",2);
score5=score5+3;
printf(" you got %d marks\n",score5);
}
else
{
printf("Wrong Answer..!\n");
printf("\n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Drama \t [2] Action\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score5=score5+2;
		printf("You got %d marks\n",score5);
	}
	else
	{
		printf("Wrong answer..!\n");
		score5=score5-1;
		printf("You got %d marks\n",score5);
	}

}
}
if(answer==2)
{
score5=score5+0;
printf(" you got %d marks\n\n",score5);
}

printf("-----------------------------------------------------\n");
printf("\nQ6) What was the victory symbol of shersaah%c?\n",3);
printf("[1] Oh yeah yeah\t[2] Durge mata ki jay\n[3] Ye Dil%c maange more\t[4] Jai Hind\n",3);
scanf("%d", &answer);

int score6=0;
if(answer==3)
{
printf("That is Correct!%c\n",2);
score6=score6+3;
printf(" you got %d marks\n",score6);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Ye Dil%c maange more \t [2] Durge mata ki jay\n",3);
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score6=score6+2;
		printf("You got %d marks\n",score6);
	}
	else
	{
		printf("Wrong answer..!\n");
		score6=score6-1;
		printf("You got %d marks\n",score6);
	}

}
}
if(answer==2)
{
score6=score6+0;
printf(" you got %d marks\n\n",score6);
}

printf("-----------------------------------------------------\n");
printf("\nQ7) What is the name of the village where Vivek and sadhna after marriage (movie-->Hum saath saath hain)?\n");
printf("[1] Ramgarh\t[2] Raypur\n[3] Surygarh\t[4] Rampur\n");
scanf("%d", &answer);

int score7=0;
if(answer==4)
{
printf("That is Correct!%c\n",2);
score7=score7+3;
printf(" you got %d marks\n",score7);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options from which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Rampur \t [2] Ramgarh\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score7=score7+2;
		printf("You got %d marks\n",score7);
	}
	else
	{
		printf("Wrong answer..!\n");
		score7=score7-1;
		printf("You got %d marks\n",score7);
	}

}
}
if(answer==2)
{
score7=score7+0;
printf(" you got %d marks\n\n",score7);
}

printf("-----------------------------------------------------\n");
printf("\nQ8) Nisha plans a 'special seat' for Prem and his friends when they arrive for the wedding. what is so special about the seat (Movie-->Hum aapke hai kaun)\n");
printf("[1] It's stuffed with papad\t[2] It is broken\n[3] It is not covered properly\t[4] It is away from the crowd\n");
scanf("%d", &answer);

int score8=0;
if(answer==1)
{
printf("That is Correct!%c\n",2);
score8=score8+3;
printf(" you got %d marks\n",score8);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options in which you have to answer:");
scanf("%d",&answer);
printf("\n");

if(answer==1)
{
	printf("[1] It is stuffed with papad\t [2] It is broken\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score8=score8+2;
		printf("You got %d marks\n",score8);
	}
	else
	{
		printf("Wrong answer..!\n");
		score8=score8-1;
		printf("You got %d marks\n",score8);
	}

}
}
if(answer==2)
{
score8=score8+0;
printf(" you got %d marks\n\n",score8);
}

printf("-----------------------------------------------------\n");
printf("\nQ9) Who tells the story of Anjali and Rohit to little Anjali in movie %cKuch kuch hota hai%c?\n",34,34);
printf("[1] Her grandmother\t[2] Rohit\n[3] a letter which is given by her mom with a gift\t[4] Her teacher\n");
scanf("%d", &answer);

int score9=0;
if(answer==3)
{
printf("That is Correct!%c\n",2);
score9=score9+3;
printf(" you got %d marks\n",score9);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options in which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1]  A leeter which is given by her mom with a gift\t [2] her grandmother\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score9=score9+2;
		printf("You got %d marks\n",score9);
	}
	else
	{
		printf("Wrong answer..!\n");
		score9=score9-1;
		printf("You got %d marks\n",score9);
	}

}
}
if(answer==2)
{
score9=score9+0;
printf(" you got %d marks\n\n",score9);
}

printf("-----------------------------------------------------\n");
printf("\nQ10) Who did change the silencer's speech? \n");
printf("[1] Rancho\t[2] Farhan\n[3] Raju\t[4] Virus\n");
scanf("%d", &answer);

int score10=0;
if(answer==1)
{
printf("That is Correct!%c\n",2);
score10=score10+3;
printf(" you got %d marks\n",score10);
}
else
{
printf("Wrong Answer..!\n");
printf(" \n");
printf("do you want any help?\n");
printf("[1] Yes \t [2] No \n");
printf("you will be given two options in which you have to answer:");
scanf("%d",&answer);
printf(" \n");

if(answer==1)
{
	printf("[1] Rancho \t [2] Raju\n");
	scanf("%d",&answer);

	if(answer==1)
	{
		printf("That is correct!%c\n",2);
		score10=score10+2;
		printf("You got %d marks\n",score10);
	}
	else
	{
		printf("Wrong answer..!\n");
		score10=score10-1;
		printf("You got %d marks\n",score10);
	}

}
}
if(answer==2)
{
score10=score10+0;
printf(" you got %d marks\n",score10);
}

 int Total =score+score2+score3+score4+score5+score6+score7+score8+score9+score10;

printf("\n Your Total Score is %d out of 30%c\n", Total,3 );

if(Total>25)
{
printf("Huree! you are the real star of Bollywoood %c\n",1);
}
if((Total>20)&&(Total<25))
{
	printf("You have good knowledge about movies%c\n",3);
}
if((Total>10)&&(Total<20))
{
	printf("it's not good .Better luck next time..!\n");
}
if(Total<10)
{
	printf("It seems that you are not interested in movies.\n");
}
printf("Thank you for playing the game .Have a nice day!%c",1);
printf("\n\nEnter any key to go back in fun page:");
getch();
return 0;
}

char box[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };

int win();
void block();

int mystery_numbers()
{ //It is the MYSTERY NUMBERS GAME which is made by KHUSHI PUROHIT
// It is very intresting game in this game you have to guess that which stars consist the hidden number if you found all the hidden numbers in 7 or less than 7 flips then you win otherwise you loose...
char name[10];
system("cls");
 printf("                    ***WELCOME TO THE GAME***\n\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *         MYSTERY NUMBERS GAME         *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("RULES:\n 1. it's very easy game....you only have to find the 5 numbers which is\n hidden behind the stars(*).\n\n 2. so you can see these 9 blocks and in which 5 out of 9 stars have hidden \nnumbers whereas other 4 stars have their hidden alphabet.\n\n 3. You only have to do the one task that is you have to find all the 5 numbers in 7 or less than 7 flips to win the game.....\n\n 4. To flip the star you have to enter the numbers in the sequence like to flip the 1st star you have to enter the number 1 as well as for the others also.%c \n\n BEST OF LUCK\n ", 2);
     printf("\nENTER YOUR NAME:");
	 scanf("%s", name);
	 system("cls");

    int player = 1, i, choice;
    int count=0;

    char  mark[9]= {'1', '2', '3', '4', '5', 'a', 'b', 'c', 'd'};
    do
    {


        block();
        printf("enter the star sequence number to flip the star:");
        scanf("%d", &choice);

        if (choice == 1 && box[1] == '*')
            box[1] = 'a';

        else if (choice == 2 && box[2] == '*')
            box[2] = '1';

        else if (choice == 3 && box[3] == '*')
            box[3] = 'b';

        else if (choice == 4 && box[4] == '*')
            box[4] = 'c';

        else if (choice == 5 && box[5] == '*')
            box[5] = '2';

        else if (choice == 6 && box[6] == '*')
            box[6] = '3';

        else if (choice == 7 && box[7] == '*')
            box[7] = 'd';

        else if (choice == 8 && box[8] == '*')
            box[8] = '4';

        else if (choice == 9 && box[9] == '*')
             box[9] = '5';

        else
        {
            printf("   Invalid move ");

            getch();
        }
        count++;
        i = win();



    }while (i ==  - 1);{


    block();


    if (i == 1)
        printf("you guessed it in %d attempts\n\n  press enter for result....\n\n", count);
    getch();
}
     if (count<=7){
     	printf("you guessed it in less than 7 flips\n\n*** YOU WON %c ***", 2);
     	box[1]='*';
     	box[2]='*';
        box[3]='*';
     	box[4]='*';
     	box[5]='*';
     	box[6]='*';
        box[7]='*';
     	box[8]='*';
     	box[9]='*';

	 }
	 else {
	 	printf("you guessed numbers in more than 7 flips\n\n **BETTER LUCK NEXT TIME**");
	 	box[1]='*';
     	box[2]='*';
        box[3]='*';
     	box[4]='*';
     	box[5]='*';
     	box[6]='*';
        box[7]='*';
     	box[8]='*';
     	box[9]='*';

	 }
	 printf("\nEnter any key to go back in fun page:");
	 getch();
    return 0;
}


int win()
{ // This code is to check the winning of the player
	if(box[2]== '1' && box[5]== '2' && box[6]== '3' && box[8]== '4' && box[9]== '5')
	  return 1;

	  else
	  return -1;
}


/*********
FUNCTION TO DRAW BOARD OF MYSTERY NUMBER GAME
********/


void block()
{
   system("cls");
    

	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t   FLIP THE STAR");



    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", box[1], box[2], box[3]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", box[4], box[5], box[6]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", box[7], box[8], box[9]);

    printf("\t|     |     |     |\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}


int rollDice(){
	// It is the code of the DICE_ROLLER_GAME which is made by KHUSHI BANSAL 
	// rules of this game is mentioned below in the code..
	int roll = (rand() % 6) + 1;
	return roll;
	}

int playGame(){
	srand(time(0));
	int dice1,dice2;
	char name[20];
	int output;
	printf("\t\t\tENTER YOUR NAME:");
	scanf("%s",name);
	system("cls");

	printf("\nPress ENTER to roll the dice:[ENTER]\n");
	getch();

	dice1 = rollDice();
	dice2 = rollDice();
	int sum = dice1 + dice2;
	int point;
	printf("\n\nDices throw  %d,%d respectively\n",dice1,dice2);
	printf("Sum is %d\n\n",sum);
	if(sum==7 || sum==11)
	output = WON;
	else if(sum==2 ||sum==3 ||sum==12)
	output = LOSE;
	else{
		point =sum;
		printf("\n\nNow you have to play for game point.\n");
		printf("Get gamepoint %d to win.\n",sum);
		printf("Press ENTER to roll  the dices.\n\n");
		getch();
		output=playforpoint(point);
	}
	return output;

}
 int playforpoint(int point){
 	int dice1 ;
	int dice2 ;
	int sum ;
	int  nguess=2;
	while(1){
	dice1=rollDice();
	dice2=rollDice();
	sum=dice1+dice2;
	printf("\n\nDices throw %d ,%d respectively\n",dice1,dice2);
	printf("Sum is %d\n",sum);
	if(sum==point)
	{printf("\n\nYou Won in %d attempts\n",nguess);
	return WON;
	getch();
	break;
	}
	else if(sum==7||sum==11)
	{
	return LOSE;
	getch();
	break;
	}
    else
	{
	printf("\nRoll dice again.Press [ENTER]\n\n");
	getch();
	}nguess++;

	}

 }

int dice_roller(){
	char f;
	system("cls");
 printf("                    **%cWELCOME TO THE GAME%c**\n\n",2,2);
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *           DICE ROLLER GAME           *\n");
printf("              *\t\t\t\t\t     *\n");
printf("              *\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");

	printf("\n\n***RULES: Read them before playing ***\n\n");
	printf("#1. Player has to throw the dices and note the sum.\n\n");
	printf("#2.If the sum is 7 or 11 in the first attempt then you win!!\n\n");
	printf("#3.BUT if the sum is 2,3 or 12 in the first attempt then you lose!!\n\n");
	printf("#4. If any other number then above,you will have to play for game point!!!\n\n");
	printf("#5.Game point will be the sum you get in first attempt.");
	printf("You will have to get game point in order to win.\n\n");
	printf("BUT here's also a CATCH,if you get 7 or 11 before gamepoint you simply lose!!\n\n");

	int result = playGame();
	switch(result)
{
		case (WON):
		 printf("\n\n**CONGRATS,You won the game!!%c**\n",1);

		 break;
	    case (LOSE):
	     printf("\n\n**SORRY,You lose the game!!\n\n\n\t\t\tBetter Luck Next Time%c%c**\n",1,3);

		 break;
			}
			printf("\nEnter any key to go back to fun page:");
			getch();
	return 0;

}

struct student{
	char name[50];
	char branch[50];
	char project[50];
	int year;
};
int team_details(){
	// This code is written for the details of all the team members......
	system("cls");
	printf(" \n \n \t*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n");
	printf("        *\t\t\t\t      *\n");
	printf("\t*\t TEAM MEMBER DETAILS\t      *\n");
		printf("        *\t\t\t\t      *\n");
	printf(" \t*\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd*\n\n");
	printf("\n\t 1. Khushi Purohit \n");
	printf("\tBRANCH    - Computer Science:\n");
	printf("\tPROJECT   - Mystery Number Game \n");
	printf("\tYear      - 1st\n\n");

	printf("\t 2.Karishma Sharma \n");
	printf("\tBRANCH    - IT:\n");
	printf("\tPROJECT   - Zodiac Sign\n" );
	printf("\tYear      - 1st\n\n");

 	printf("\t 3.Khushi Bansal\n ");
	printf("\tBRANCH    - Computer Science:\n");
	printf("\tPROJECT   - Dice Roller\n");
	printf("\tYear      - 1st\n\n");

	printf("\t 4.Aparna Jain \n");
	printf("\tBRANCH    - Computer Science:\n");
	printf("\tPROJECT   - Bollywood Trivia\n");
	printf("\tYear      - 1st\n\n");

	printf("\t 5.Khushbu Bijawat \n"); 
	printf("\tBRANCH    - Computer Science:\n ");
	printf("\tPROJECT   - Matchstick Game \n");
    printf("\tYear      - 1st\n\n");

	printf("\n Press enter to go back to homepage:\n");
 getch();
 return main();

}

