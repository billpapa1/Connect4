#include <stdio.h>
#include <stdlib.h>


#define ROWS	6  //how many rows the board will have
#define COLS 	7  //how many columns the board will have
#define GOAL	4  //this is how many in the row columns , rows or diagonals disks have to be

char GameBoard[ROWS][COLS]; //The 2D dimensional array that will hold the disks.
char help[] = "Write the Number according to the column you want to place your disk"; // a helping message to the user to understand where to place his disk
char columns[] = "  1   2   3   4   5   6   7  ";  // To instruct the user where to place his disk - columns
char hrzbar[] = "[---|---|---|---|---|---|---]"; // horizontal bar used everytime to create an interface for the connect 4 game
int box = 0; //initialising the variable box
char disk = 'A'; // name of the first disk used
char confirm;
//all the methods used
void initBoard();
void checkBoard();
void board();
void selectPos();
void fillBoard();
int check(char disk);
void clearScreen(); // unused method that clears the board

main()
        {
            // running the methods needed to start the game
            initBoard();
            checkBoard();
            board();

            while (1)
            {
                printf("Player %c,It's your turn!\n", disk);  // message to notify the corresponding player when is his/her turn
                selectPos();
                printf("\n\n");
                board();



                if (check('A'))  // if the method check which concludes the winner returns 1 for disk A then player 1 is the winner
                {
                    printf("\n\nPlayer A wins!"); // message to show which player won
                    printf("\n\n Exiting the game! ");
                    exit(EXIT_SUCCESS);


                }

                if (check('B')) // if the method check which concludes the winner returns 1 for disk A then player 1 is the winner
                    {
                        printf("\n\nPlayer B wins! "); // message to show which player won
                        printf("\n\n Exiting the game! ");
                        exit(EXIT_SUCCESS);

                    }
                }
        }


    void exit(int status);
// unused method for clearing the screen- board
    void clearScreen(){
        for (int i = 0; i < 30; i++)
            putchar('\n');
            fflush(stdout);;
    }


    // creating the interface , adding a spot for the user to add the disk
    void initBoard()
        {
            // fill the scores with the empty character:
            int i, j;

            for (i = 0; i < ROWS; i++)
            {
                for (j = 0; j < COLS; j++)
                {
                    GameBoard[i][j] = ' ';
                }
            }
        }

    void checkBoard()
        {
            // print the initialized scores
            // the board is not printed yet
            int i, j;

            for (i = 0; i < ROWS; i++)
            {
                for (j = 0; j < COLS; j++)
                {
                    printf("%c ", GameBoard[i][j]);
                }
                printf("\n");
            }
        }

    void board()
       {
        // shows the board and the disks according to current game:

        printf("%s\n", columns);
        printf("%s\n", hrzbar);


            int i, j; // variables used in loops

            for (i = 0; i < ROWS; i++) // goes through the number of the ROWS
            {
                for (j = 0; j < COLS; j++)  // goes through the number of the COLUMNS
                {
                    printf("| %c ", GameBoard[i][j]);
                }
                printf("|\n"); //
                printf("%s\n", hrzbar); //prints the hrzbar interface
            }
            printf("%s\n", help); // prints the helping message underneath the board
        }


    void selectPos()
    {
    char userInput; // takes the char the user inputs

        while (1) //while the user does that
        {
            // a message to inform the user that he needs to select which column to place the disk
            printf("\nChoose the column you want to place the disk: ");
            scanf(" %c", &userInput);  // accepting the user input
            switch(userInput)
            {
                // several cases to accept all the possible columns the user will choose
                case '1':
                    box = 0;  // first column
                    break;
                case '2':
                    box = 1; // second column
                    break;
                case '3':
                    box = 2; // third column
                    break;
                case '4':
                    box = 3; // fourth column
                    break;
                case '5':
                    box = 4; // fifth column
                    break;
                case '6':
                    box = 5; // sixth column
                    break;
                case '7':
                    box = 6; // seventh columna
                    break;
                default:
                    box = 200; // random number out of bounds (out of the bounds of the 2D array)
                    printf("\nThis column does not exist ! You Try again.\n\n"); // if the user input is not what expected.
                    board();
            }
                // use of break and escape the (while) loop if the right number was selected from the user:
                if ((box >= 0 && box <= 6) && (GameBoard[0][box] == ' ')) // if the specific position entered by the user is free then it will be filled with the according X or O
                {
                    fillBoard(); // calling the method to identify if there is any other disk in the way
                    disk = (disk == 'A') ? 'B' : 'A'; // adding disks with the names A and B
                    break;
                }
         }
    }
    //This method is called to clarify that the disks will start from the bottom of this board, from the ROW-5. If a disk is added then it will start from ROW 4. And goes on.
    void fillBoard()
        {
            // fills the box according to what's already in there:
            int level ; //lowest level or bottom of the board , starting from the lowest part of the board

            for (level = ROWS-1; level >= 0; level--) // when the loop ends level goes one off because a spot was filled with a disk
            {
                if (GameBoard[level][box] == ' ') // checks if the specific spot is empty
                {
                    GameBoard[level][box] = disk; // add the disk
                    break;
                }
            }
}

    int check(char disk)
        {
            // checks for a 4-disk row, column or diagonal . This is all the allowed ways for the players to win.

            // algorithm to check for 4-disk rows
            // each of the rows has 4 different ways to connect 4, 1 more than the columns

            int i, j, n;
            int counter;
            int ways = 4; // there are 4 ways to connect 4
            // checking all the rows
            for (i = 0; i < ROWS; ++i)
            {
                for (j = 0; j < ways; ++j)
                {
                    counter = 0; //setting counter to 0
                    for (n = 0; n < GOAL ; ++n)
                    {
                        if (GameBoard[i][j + n] == disk) counter++; // if the next box in the row has a disk then it adds the counter 1
                    }
                    if (counter == GOAL) // if there are 4 in the row which is the GOAL
                        return 1;  //returning good news to print
                }
             }


            // algorithm to check for 4-disk in the column section
            // each of the  column has 3 different ways to connect 4
            ways = 3;  // there are  3 ways to connect 4 in a column
            //checking all the columns
            for (j = 0; j < COLS; j++)
            {
                for (i = 0; i < ways; i++)
                {
                    counter = 0; //setting the counter to 0
                    for (n = 0; n < GOAL; n++)
                    {
                        if (GameBoard[i + n][j] == disk) counter++; // is the next column has a disk it will add 1 to the counter
                    }
                    if (counter == GOAL) return 1; // if the counter reach to be the goal which is 4 then it means that 4 disks were found in a row in the same column
                }
            }

            // check for all diagonals ways to win

            int dg, ag;
            for (i = 1; i < ROWS-1; i++)
            {
                for (j = 1; j < COLS-1; j++)
                {

                    // left-leaning diagonals   // [0,0],[1,1],[2,2],[3,3]
                    //                          // [2,0],[3,1],[4,2][5,3]
                                                // [5,6],[4,5],[3,4],[2,3]
                    counter = 0;
                    // left-towards-up:
                    for (dg = i, ag = j; (dg >= 0) || (ag >= 0); dg--, ag--) // starting from left going upwards/right
                    {
                        if (GameBoard[dg][ag] == disk) // first check will be 0,0 which means checking the first/down to the left box of the board then going to the first diagonal of the right

                        {
                            counter++;
                            if (counter == GOAL) return 1; //if the counter reach the number if Goal then the player can win
                        }
                        else
                            break;
                    }
                    // right-towards-down
                    for (dg = i+1, ag = j+1; (dg <= ROWS-1) || (ag <= COLS-1); dg++, ag++) //
                    {
                        if (GameBoard[dg][ag] == disk)
                        {
                            counter++;
                            if (counter == GOAL) return 1;
                        }
                        else
                            break;
                    }

                    // right-leaning diagonals
                    counter = 0;
                    // left-towards-down:
                    for (dg = i, ag = j; (dg <= ROWS-1) || (ag >= 0); dg++, ag--)
                    {
                        if (GameBoard[dg][ag] == disk)
                        {
                            counter++;
                            if (counter == GOAL) return 1;
                        }
                        else
                            break;
                    }
                    // right-towards-up:
                    for (dg = i-1, ag = j+1; (dg >= 0) || (ag <= COLS-1); dg--, j++)
                    {
                        if (GameBoard[dg][ag] == disk)
                        {
                            counter++;
                            if (counter == GOAL) return 1;
                        }
                        else
                            break;
                    }

                }
            }

         return 0;
      }
