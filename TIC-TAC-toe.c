#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 9
#define ROW 3
int DisplayInstruct()
{
    int Error;
    Error = printf("Welcome to the ring of the greatest intellectual competition of all time.\nYour brain and my processor will come together in a fight for the Board game \n\"TIC-TAC-toe\".\nTo make a move, enter a number between 0 and 8. The numbers clearly correspond\nto fields of the Board, as shown below:\n\n\t0 | 1 | 2\n\t---------\n\t3 | 4 | 5\n\t---------\n\t6 | 7 | 8\n\nGet ready for a battle, you pathetic squirrel man. The final battle is about to begin.\n\n");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN DisplayInstruct!!!");
      return 1;
    }
    return 0;
}
int AskYesNo(char *ResponseYesNo)
{
  int Error;
  if(ResponseYesNo == NULL)
  {
    printf("\n\n\t!!!ERROR IN AskYesNo!!!");
    return 1;
  }
  *ResponseYesNo = 'x';

  while ((*ResponseYesNo != 'y') && (*ResponseYesNo != 'n')&&(*ResponseYesNo != 'Y') && (*ResponseYesNo != 'N'))
  {
    Error = printf("Do you want to keep the first move? (y/n): ");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN main!!!\n\n\t!!!Error in the first printf!!!");
      return 2;
    }
    Error = scanf("%c", ResponseYesNo);
    if(Error == EOF)
    {
      printf("\n\n\t!!!ERROR IN AskYesNo!!!");
      return 3;
    }
    while (getchar () != '\n');
  }
  return 0;
}
int AskNumber(char *ResponseAskNumber)
{
  int Error, RetValue;
  char N;
	if(ResponseAskNumber == NULL)
	{
		printf("\n\n\t!!!ERROR IN AskNumber!!!");
		return 1;
	}
  do
  {
    Error = printf("\nYour move. Choose one of the fields (0-8): ");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN AskNumber!!!");
      return 2;
    }
    Error = RetValue = scanf ("%c", &N);
    if(Error == EOF)
    {
      printf("\n\n\t!!!ERROR IN AskNumber!!!");
  		return 3;
    }
    while (getchar () != '\n');
  } while (RetValue != 1 || (N < '0') || (N > '8'));
  *ResponseAskNumber = N - '0';
  return 0;
}
int DisplayBoard(char *Board)
{
    int Error;
    if(Board == NULL)
    {
      printf("\n\n\t!!!ERROR IN DisplayBoard!!!");
      return 1;
    }
    Error = printf("\n\t%c | %c | %c\n\t---------\n\t%c | %c | %c\n\t---------\n\t%c | %c | %c\n", Board[0], Board[1], Board[2], Board[3], Board[4], Board[5], Board[6], Board[7], Board[8]);
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN DisplayBoard!!!");
      return 2;
    }
    return 0;
}
int Winner(char *Board, char *Winner)
{
  if(Board == NULL)
  {
    printf("\n\n\t!!!ERROR IN Winner!!!");
    return 1;
  }
  if(Winner == NULL)
  {
    printf("\n\n\t!!!ERROR IN Winner!!!");
    return 2;
  }
  int j, i, Count=0;
  char WAYS_TO_WIN[][3] = {
	{ 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 }
  };
  for(i = 0; i < 8; i++)
  {
    if((Board[WAYS_TO_WIN[i][0]] == Board[WAYS_TO_WIN[i][1]]) && (Board[WAYS_TO_WIN[i][1]] == Board[WAYS_TO_WIN[i][2]]) && (Board[WAYS_TO_WIN[i][2]] != ' '))
    {
      *Winner = Board[WAYS_TO_WIN[i][0]];
      return 0;
    }
  }
  for (j=0;j<9;j++)
    {
      if(Board[j] == ' ') Count++;
    }
    if(Count == 0)
    {
      *Winner = ' ';
      return 0;
    }
  *Winner = 0;
  return 0;
}
int HumanMove(char *Board, char *h)
{
  if(Board == NULL)
  {
    printf("\n\n\t!!!ERROR IN HumanMove!!!");
    return 1;
  }
  if(h == NULL)
  {
    printf("\n\n\t!!!ERROR IN HumanMove!!!");
    return 2;
  }
  int Error;
  char Move;
  do
  {

    Error = AskNumber(&Move);
    if(Error != 0)
    {
    	printf("\n\n\t!!!ERROR IN HumanMove!!!");
      switch (Error)
      {
        case 3: printf("\n\n\t!!!Error in the first scanf!!!"); break;
        case 2: printf("\n\n\t!!!Error in the first printf!!!"); break;
        case 1: printf("\n\n\t!!!Invalid argument Move!!!"); break;
        default: break;
      }
    	return 3;
	}
    if (Board[Move] != ' ')
    {
      Error = printf("\nYou are funny man! This field already occupied. Choose another.\n");
      if(Error == 0)
      {
        printf("\n\n\t!!!ERROR IN HumanMove!!!");
        return 4;
      }
    }
  } while(Board[Move]!=' ');
  Board[Move] = *h;
  Error = printf("\nAll right...\n");
  if(Error = 0)
  {
    printf("\n\n\t!!!ERROR IN HumanMove!!!");
    return 5;
  }
  return 0;
}
int ComputerMove(char *Board, char Comp, char h)
{
  if(Board == NULL)
  {
    printf("\n\n\t!!!ERROR IN ComputerMove!!!");
    return 1;
  }
  if(Comp != 'X' && Comp != 'O')
  {
    printf("\n\n\t!!!ERROR IN ComputerMove!!!");
    return 2;
  }
  if(h != 'X' && h != 'O')
  {
    printf("\n\n\t!!!ERROR IN ComputerMove!!!");
    return 3;
  }
  int Error;
  char Move, Win;
  Error = printf("\nI will choose number field: ");
  if(Error == 0)
  {
    printf("\n\n\t!!!ERROR IN ComputerMove!!!");
    return 4;
  }
  for(Move = 0; Move < 9; Move++)
  {
    if (Board[Move]== ' ')
    {
      Board[Move] = Comp;
      Error = Winner(Board, &Win);
      switch (Error) {
        case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 5;
        case 2: printf("\n\n\t!!!Invalid argument Winner!!!"); return 5;
        default: break;
      }
      if (Win == Comp)
      {
        Error = printf("%d\n", Move);
        if(Error == 0)
        {
          printf("\n\n\t!!!ERROR IN ComputerMove!!!");
          return 6;
        }
        return 0;
      }
      Board[Move] = ' ';
    }
  }
  for( Move = 0; Move < 9; Move++)
  {
    if (Board[Move] == ' ')
    {
      Board[Move] = h;
      Error = Winner(Board, &Win);
      switch (Error) {
        case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 7;
        case 2: printf("\n\n\t!!!Invalid argument Winner!!!"); return 7;
        default: break;
      }
      if (Win == h)
      {
        Error = printf("%d\n", Move);
        if(Error == 0)
        {
          printf("\n\n\t!!!ERROR IN ComputerMove!!!");
          return 8;
        }
        Board[Move] = Comp;
        return 0;
      }
      Board[Move] = ' ';
    }
  }
  do
  {
    Move = rand()%9;
  }while (Board[Move] != ' ');
  Board[Move] = Comp;
  Error = printf("%d\n", Move);
  if(Error == 0)
  {
    printf("\n\n\t!!!ERROR IN ComputerMove!!!");
    return 9;
  }
  return 0;
}
int NextTurn(char *Turn)
{
  if(Turn == NULL)
  {
    printf("\n\n\t!!!ERROR IN NextTurn!!!");
    return 1;
  }
  if(*Turn == 'X')
  {
  	*Turn = 'O';
    return 0;
  }
  else
  {
  	*Turn = 'X';
    return 0;
  }
}
int CongrantWinner(char TheWinner, char Comp, char h)
{
  if((TheWinner != ' ') && (TheWinner != 'X') && (TheWinner != 'O'))
  {
    printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
    return 1;
  }
  if((Comp != 'X') && (Comp != 'O'))
  {
    printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
    return 2;
  }
  if((h != 'X') && (h != 'O'))
  {
    printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
    return 3;
  }
  int Error;
  if (TheWinner != ' ')
  {
    Error = printf("\nThree %c in a row!\n\n", TheWinner);
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
      return 4;
    }
  }
  else
  {
    Error = printf("\nDraw!\n");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
      return 5;
    }
  }
  if (TheWinner == Comp)
  {
    Error = printf("As I predicted, the victory once again remained with me.\nHere is another argument in favor of the fact that computers are superior to \npeople absolutely everything.\n");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
      return 6;
    }
  }
  if (TheWinner == h)
  {
    Error = printf("O no. That's impossible! Did you somehow manage to outsmart me, squirrel?\nI swear, I am the computer and Iwill never let that happen again!\n");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
      return 7;
    }
  }
  if (TheWinner == ' ')
  {
    Error = printf("You're incredibly lucky. friend: you managed to draw the game.\nRejoice in today's success! You're not gonna do it again tomorrow.\n");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN CongrantWinner!!!");
      return 8;
    }
  }
  return 0;
}
int main()
{
  int Move, Error, i;
  char TheWinner, GoFirst, h, Comp, Turn = 'X', Win;
  srand(time(NULL));
  Error = DisplayInstruct();
  switch (Error) {
    case 1: printf("\n\n\t!!!Error in the first printf!!!"); return 1;
    default: break;
  }
  char Board[NMAX];
  Error = AskYesNo(&GoFirst);
  switch (Error) {
    case 1: printf("\n\n\t!!!Invalid argument ResponseYesNo!!!"); return 2;
    case 2: printf(""); return 2;
    case 3: printf("\n\n\t!!!Error in the first scanf!!!"); return 2;
    default: break;
  }
  if(GoFirst == 'y' || GoFirst == 'Y')
  {
      Error = printf("\nWell, I'll give you a head start: play crosses.\n");
      if(Error == 0)
      {
        printf("\n\n\t!!!ERROR IN main!!!\n\n\t!!!Error in the second printf!!!");
        return 3;
      }
      h = 'X';
      Comp = 'O';
  }
  else
  {
    Error = printf("\n Your boldness kills you... I'll start.");
    if(Error == 0)
    {
      printf("\n\n\t!!!ERROR IN main!!!\n\n\t!!!Error in the third printf!!!");
      return 4;
    }
    h = 'O';
    Comp = 'X';
  }
  for (i = 0; i < 9;i ++)
  {
    Board[i] = ' ';
  }
  Error = DisplayBoard(Board);
  switch (Error) {
    case 1: printf("\n\n\t!!!Invalid argument ResponseYesNo!!!"); return 5;
    case 2: printf("\n\n\t!!!Error in  printf!!!"); return 5;
    default: break;
  }
  Error = Winner(Board, &Win);
  switch (Error) {
    case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 6;
    case 2: printf("\n\n\t!!!Invalid argument Winner!!!"); return 6;
    default: break;
  }
  while (Win != ' ' && Win != 'X' && Win != 'O')
  {
    if (Turn == h)
    {
      Error = HumanMove(Board, &h);
      switch (Error) {
        case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 7;
        case 2: printf("\n\n\t!!!Invalid argument h!!!"); return 7;
        case 3: return 7;
        case 4: printf("\n\n\t!!!Error in the first printf!!!"); return 7;
        case 5: printf("\n\n\t!!!Error in the second printf!!!"); return 7;
        default: break;
      }
    }
    else
    {
      Error = ComputerMove(Board, Comp, h);
      switch (Error) {
        case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 8;
        case 2: printf("\n\n\t!!!Invalid argument range Comp!!!"); return 8;
        case 3: printf("\n\n\t!!!Invalid argument range h!!!"); return 8;
        case 4: printf("\n\n\t!!!Error in the first printf!!!"); return 8;
        case 5: return 8;
        case 6: printf("\n\n\t!!!Error in the second printf!!!"); return 8;
        case 7: return 8;
        case 8: printf("\n\n\t!!!Error in the third printf!!!"); return 8;
        case 9: printf("\n\n\t!!!Error in the fourth printf!!!"); return 8;
        default: break;
      }
    }
    Error = DisplayBoard(Board);
    switch (Error) {
      case 1: printf("\n\n\t!!!Invalid argument ResponseYesNo!!!"); return 9;
      case 2: printf("\n\n\t!!!Error in  printf!!!"); return 9;
      default: break;
    }
    Error = NextTurn(&Turn);
    switch (Error) {
      case 1: printf("\n\n\t!!!Invalid argument Turn!!!"); return 10;
      default: break;
    }
    Error = Winner(Board, &Win);
    switch (Error) {
      case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 11;
      case 2: printf("\n\n\t!!!Invalid argument Winner!!!"); return 11;
      default: break;
    }
  }
  Error = Winner(Board, &Win);
  switch (Error) {
    case 1: printf("\n\n\t!!!Invalid argument Board!!!"); return 12;
    case 2: printf("\n\n\t!!!Invalid argument Winner!!!"); return 12;
    default: break;
  }
  TheWinner = Win;
  Error = CongrantWinner(TheWinner, Comp, h);
  switch (Error) {
    case 1: printf("\n\n\t!!!Invalid argument range TheWinner!!!"); return 13;
    case 2: printf("\n\n\t!!!Invalid argument range Comp!!!"); return 13;
    case 3: printf("\n\n\t!!!Invalid argument range h!!!"); return 13;
    case 4: printf("\n\n\t!!!Error in the first printf!!!"); return 13;
    case 5: printf("\n\n\t!!!Error in the second printf!!!"); return 13;
    case 6: printf("\n\n\t!!!Error in the third printf!!!"); return 13;
    case 7: printf("\n\n\t!!!Error in the fourth printf!!!"); return 13;
    case 8: printf("\n\n\t!!!Error in the fifth printf!!!"); return 13;
    default: break;
  }
  Error = system ("pause");
  if(Error == -1)
  {
  	printf("\n\n\t!!!Error in system (\"pause\")!!!");
  	return 14;
  }
  return 0;
}
