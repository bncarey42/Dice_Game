/*
This program simulates a standard game of street dice
Written by Ben Carey

The rules are as follows

        1. Place a bet.
        2. On the first roll if a 7 or 11 is rolled, YOU WIN!
            However, if a 2, 3, or 12 is rolled YOU LOSE.
        3. If the game has not been won or lost yet the first roll becomes your points.
        4. Rolls continue until you either:
            roll your point in which case YOU WIN
               -or-
            roll a 7 in which case YOU LOSE
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

	int dice1, dice2, roll1, rolln, j;
	int p = 1;
	int c = 1;
	int pc = 0;
	int b = 0;
	float money = 10;
	float bet;

    srand(time(NULL)); //initiates the random number series

while(1){

while(p == 1){
    if( pc < 1){
    printf("The rules of this game are simple: \n \n"
        " First place a bet. \n \n On the first roll if a 7 or 11 is rolled, YOU WIN!\n"
        " However, if a 2, 3, or 12 is rolled YOU LOSE. \n \n"

        " If the game has not been won or lost yet the first roll becomes your points.\n"
        " rolls continue until you either: \n"
        "  roll your point(in which case YOU WIN \n"
        "   -or- \n"
        "  roll a 7 in which case YOU LOSE \n");
    printf("Enter 1 to not see these instructions again\n");
    scanf("%d", &pc);
    }

    printf("You have $ %.2f \n", money);
    printf("Input your bet \n");
    scanf("%f", &bet);

    if(bet > money){
        printf("I'm sorry you can't bet more than you have. \n");
        printf("THE BANK IS CLOSED!");
        return 0;
    }
    else{
        money = money - bet;
    }

    printf("Enter 0 to roll \n");
    scanf("%d", &j);

    roll1 = 0;

    c = 1;
    printf("Roll Number: %d \n", c);
    // On the first roll if a 7 or 11 is rolled, YOU WIN! However, if a 2, 3, or 12 is rolled YOU LOSE.
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;

    roll1 = dice1 + dice2;

    printf("Dice 1 = %d \n", dice1);
    printf("Dice 2 = %d \n", dice2);

    if(roll1 == 7){
        printf("%d! YOU WIN! \n", roll1);
        money = money + bet*2;
        printf("You now have $ %.2f \n", money);
        b = 2;
    }
    if(roll1 == 11){
        printf("%d! YOU WIN! \n", roll1);
        money = money + bet*2;
        printf("You now have $ %.2f \n", money);
        b = 2;
    }
    if(roll1 == 2){
        printf("Awe shucks! %d! You Lose... \n", roll1);
        printf("You now have $ %.2f \n", money);
        b = 1;
    }
    if(roll1 == 3){
        printf("Awe shucks! %d! You Lose... \n", roll1);
        printf("You now have $ %.2f \n", money);
        b = 1;
    }
    if(roll1 == 12){
        printf("Awe shucks! %d! You Lose... \n", roll1);
        printf("You now have $ %.2f \n", money);
        b = 1;
    }

    //if the game has not been won or lost yet the first roll becomes your "point"
    if( b == 0) {
    printf("Your score is: %d \n", roll1);
    printf("Enter 0 to roll again \n" );
    scanf( "%d" , &p );
    }
    else{
        b = 0;
        p = 2;
    }

} //end p=1

    while(p == 0) {
/*
    rolls continue until you either:
        roll your point(in which case you win)
        -or-
        roll a 7 in which case your lose
*/
        ++c;

        printf("Roll Number: %d \n", c);
        printf("Your score is: %d \n", roll1);

        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        rolln = dice1 + dice2;

        printf("Dice 1 = %d \n", dice1);
        printf("Dice 2 = %d \n", dice2);
        printf("%d \n", rolln);

        if(rolln == roll1){
            printf("%d! You Win! \n", rolln);
            p = 2;
            money = money + bet*2;
            printf("You now have $ %.2f \n", money);
        }
        if(rolln == 7){
            printf("%d... You Lose \n", rolln);
            printf("You now have $ %.2f \n", money);
            p = 2;
        }
    } // end p=0

while( p == 2){
    //ask to play again

    printf( "Play again? \n" "Enter 0 to try your luck again 1 to end \n" );
    scanf( "%d" , &j );

		if ( j == 1 ){
			return 0;
		}
        else{
        p=1;
        }
} //End p=2
} // End while 1

} // End Main
