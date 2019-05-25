/* C program by Joe Anthony Suarez for CS 1310 Fall 2015
 * Created on October 19, 2015.
 * Last edited on October 29, 2015.
 * This program will let two users play a game of Tic-Tac-Toe.
      .-----.
    .' -   - '.
   /  .-. .-.  \
   |  | | | |  |
    \ \o/ \o/ /
   _/    ^    \_
  | \  '---'  / |
  / /`--. .--`\ \
 / /'---` `---'\ \
 '.__.       .__.'
     `|     |`
      |     \
      \      '--.
       '.        `\
         `'---.   |
            ,__) /
             `..'
 * I think Casper wants to play, too. */
#include <stdio.h>

char ttt [3][3];   /* 3 x 3 array to make board for game. */
char player, play;       /* Hold users' character (either "X" or "O"), choice to
							restart another game. */
int i, j, win, count = 0;   /* Indexes for array; value for win; count number of
							   turns */



void displayBoards (void)   /* Print a "key" board and a "game" board. */
{
	printf ("\n\n");
	printf ("    1 | 2 | 3 \n"
			"   ---|---|---\n"
			"    4 | 5 | 6 \n"
			"   ---|---|---\n"
			"    7 | 8 | 9 \n");
	
	printf ("\n\n");
	printf ("    %c | %c | %c \n", ttt[0][0], ttt[1][0], ttt[2][0]);
	printf ("   ---|---|---\n");
	printf ("    %c | %c | %c \n", ttt[0][1], ttt[1][1], ttt[2][1]);
	printf ("   ---|---|---\n");
	printf ("    %c | %c | %c \n", ttt[0][2], ttt[1][2], ttt[2][2]);
}



int getAndCheckMove (void)   /* Get user's choice, and see if it is valid. */
{
	int choice = 0;   /* Hold user's choice on where to play on the board. */
	int winner;       /* Hold value to say if there's a winner. */
	
	do {
		printf ("\n\n");
		printf ("Please select a spot on the board: ");
		scanf ("%i", &choice);
		printf ("You chose spot \"%i\".\n", choice);
		switch (choice)   /* Assign the appropriate array index values based off
							 of user's choice. */
				{
					case 1:
							i = 0;
							j = 0;
							break;
					case 2:
							i = 1;
							j = 0;
							break;
					case 3:
							i = 2;
							j = 0;
							break;
					case 4:
							i = 0;
							j = 1;
							break;
					case 5:
							i = 1;
							j = 1;
							break;
					case 6:
							i = 2;
							j = 1;
							break;
					case 7:
							i = 0;
							j = 2;
							break;
					case 8:
							i = 1;
							j = 2;
							break;
					case 9:
							i = 2;
							j = 2;
							break;
					default:
							printf ("Sorry, your choice is not a valid board "
									"spot. Please try again.");
				}
	   } while (choice < 1 || choice > 9 || ttt[i][j] != ' ');   /* Keep asking
	   			for a choice while the user's choice is less than 1, greater
				than 9, or the selected spot is already taken. */
	ttt[i][j] = player;  /* Set the value to the player's character (either "X"
							or "O"). */
	count = count + 1;   /* Increment count. */
	winner = checkForWin();
	if (winner == 0)   /* If there is not a winner, switch the character. */
		{
			if (player == 'X')   /* If player = "X", switch player to "O". */
				player = 'O';
			else				 /* Player must be "O", so switch to "X". */
				player = 'X';
		}
	return (winner);
}



int checkForWin (void)   /* Check to see if there is a winner. */
{
	int final;   /* Final outcome */
	
	if ((ttt[0][0] == player && ttt[1][0] == player && ttt[2][0] == player) ||
	    (ttt[0][1] == player && ttt[1][1] == player && ttt[2][1] == player) ||
		(ttt[0][2] == player && ttt[1][2] == player && ttt[2][2] == player) ||
		(ttt[0][0] == player && ttt[0][1] == player && ttt[0][2] == player) ||
		(ttt[1][0] == player && ttt[1][1] == player && ttt[1][2] == player) ||
		(ttt[2][0] == player && ttt[2][1] == player && ttt[2][2] == player) ||
		(ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player) ||
		(ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player))
		/* There's 3-in-a-row in any of the eight possibilities (a winner). */
		final = 1;
	else	   /* There's a tie or the game is still in progress (no winner). */
		final = 0;
	return (final);
}



char restart (void)   /* Get choice on whether or not to start a new game. */
{
	char playChoice;
	
	printf ("Would you like to play another game? Type \"Y\" for Yes, or type "
			"\"N\" for No. ");
	getchar();
	scanf ("%c", &playChoice);
	printf ("You typed in \"%c\".\n\n", playChoice);
	return (playChoice);
}



void main (void)
{
	player = 'X'; /* Player "X" will make the first move. */
	play = 'Y';   /* Initially set to "Y" so that program initially executes. */
	
	printf ("Welcome to Tic-Tac-Toe! The rules are simple: try to get three of "
			"your\ncharacters in a row either horizontally, vertically, or "
			"diagonally. Be careful\nnot to focus too much on yourself; your "
			"opponent could be closer to a win than\nyou think!\n\n\n");
	printf ("The board directly below is the key for how to play. Type in the "
			"number to play in that spot.\n\n");
	while (play == 'Y')  /* While the player says "Yes" */
		{
			for (i = 0; i < 3; i++)   /* Set/reset all values in array equal to 
										 blank spaces. */
				for (j = 0; j < 3; j++)
					ttt[i][j] = ' ';
			while (win != 1 && count < 9) /* While there's no win and no tie. */
				{
					displayBoards();
					win = getAndCheckMove();
				}
			displayBoards();   /* Show the final board. */
			
			if (win == 1)   /* There is a winner. */
				printf ("\n\nPlayer \"%c\" is the winner!\n\n", player);
			else			/* There is a tie. */
				printf ("\n\nThe game has ended in a tie!\n\n");
				
			win = 0;        /* Reset win back to 0. */
			count = 0;      /* Reset count back to 0. */
			player = 'X';   /* Reset first move back to "X". */
			
			play = restart();
		}
	printf ("Thanks for playing!\n");
	getche();
}
