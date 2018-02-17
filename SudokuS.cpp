/* This program deals with the solving of a sudoku solver.

                                              ---------------------
                                             | HARSHINEE SRIRAM    |
                                             | ROLL NUMBER 31      |
                                             | XI A                |
                                             | Delhi Public School |         |
                                              ---------------------

Steps involved are:

1. Find a cell with least number of legal moves.
2. Assign the first legal number to it.
3. Then finds the next cell with least number of legal moves.
4. When a dead end is encountered, it assign the next legal number in step 2.


Working:

1.The Algorithm first visits each empty cell and assign it a priority value based on the number of legal moves by checking row, column, and 3x3 box constraints.
2.The legal moves are checked by comparing numbers 1 to 9 with each row, column and 3x3 box constraints.
3.After assigning the priority value to each empty cell, it assigns the empty cell with the least priority value.
4.For easy puzzles the priority value of the empty cells is mostly one, so the puzzle is easily solved by just assigning each empty cell with the correct value one by one.
5.But if the least priority value is greater than one, it assigns the empty cell with first legal number, and places a tracker variable on it. And proceed in the same way.
6.A dead end is encountered when an empty cell have no legal moves. In this case the algorithm assigns the empty cell with the tracker variable with the next possible number and deletes all the cells which are entered after the empty cell with the tracker variable.
7.The tracker variables record the sequence in which different empty cells are assigned with values. They are used to delete and modify the incorrect cells.

And hence the Algorithm finds the correct solution for each valid Sudoku puzzle.
                                        **/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
int main()
{
    system("cls");
 int num[10][10],x=3,y=4,i,j,k,l,ii,jj,prior[10][10],rep[10][10],temp=1,repetion=0;
 cout<<"Enter all the elements and enter '0' at missing places, minimum number of clues: 17. \n\n";
 for(i=1;i<10;i++)
 {
  cout<<"|---|---|---|---|---|---|---|---|---|\n"
      <<"|   |   |   |   |   |   |   |   |   |\n";
 }
 cout<<"|---|---|---|---|---|---|---|---|---|";
 for(i=1;i<10;i++)
 {
  for(j=1;j<10;j++)                             //Accepting elements from user
  {
   ENTER:
   gotoxy(x,y);
   rep[i][j]=0;
   num[i][j]=getche();
   num[i][j]-=48;
   if(num[i][j]==(-40))
   {
    if(j!=1){x-=4;j--;}
    else{x=35;y-=2;i--;j=9;}
    if(i==0){goto END;}
    gotoxy(x,y);
    cout<<" ";
    goto ENTER;
   }
   if(num[i][j]<0||num[i][j]>9)
   {
    cout<<"WRONG ENTRY";
    goto END;
   }
   if(j==9){y+=2;x=3;}
   else{x+=4;}
  }
 }
 cout<<"\n\n\n\nMAKE SURE YOU'VE ENTERED THE PUZZLE CORRECTLY !!!"
     <<"\nPress any key to know the solution.";
 getch();
 NEW_PRIORITY:
 for(i=1;i<10;i++)                  //PRIORITY SETTER
 {
  for(j=1;j<10;j++)
  {
   if(num[i][j]==0)
   {
    temp=1;
    prior[i][j]=0;
    AGAIN2:
    if(temp>9&&prior[i][j]==0)
    {
     for(k=81;k>0;k--)
     {
      for(i=1;i<10;i++)
      {
       for(j=1;j<10;j++)
       {
	if(rep[i][j]==k&&prior[i][j]==1)
	{
	 num[i][j]=0;
	 rep[i][j]=0;
	 repetion--;
	 continue;
	}
	else if(rep[i][j]==k&&prior[i][j]>1)
	{
	 prior[i][j]--;
	 repetion--;
	 temp=num[i][j];
	 temp++;
	 cout<<".";
	 goto AGAIN;
	}
       }
      }
     }
    }
    else if(temp>9)
    {temp=0;continue;}
    if(i<4){ii=0;}
    else if(i>6){ii=6;}
    else{ii=3;}
    if(j<4){jj=0;}
    else if(j>6){jj=6;}
    else{jj=3;}
    for(k=1;k<4;k++)
    {
     for(l=1;l<4;l++)
     {
      if(temp==num[k+ii][l+jj]&&i!=k+ii&&j!=l+jj)
      {
       temp++;
       goto AGAIN2;
      }
     }
    }
    for(k=1;k<10;k++)
    {
     if((temp==num[i][k]&&j!=k)||(temp==num[k][j]&&i!=k))
     {
      temp++;
      goto AGAIN2;
     }
    }
    prior[i][j]++;
    temp++;
    goto AGAIN2;
   }
  }
 }
 for(k=1;k<10;k++)   //CHECKING
 {
  for(i=1;i<10;i++)
  {
   for(j=1;j<10;j++)
   {
    if(num[i][j]==0&&prior[i][j]==k)
    {
     temp=1;
     AGAIN:
     num[i][j]=temp;
     if(i<4){ii=0;}
     else if(i>6){ii=6;}
     else{ii=3;}
     if(j<4){jj=0;}
     else if(j>6){jj=6;}
     else{jj=3;}
     for(k=1;k<4;k++)
     {
      for(l=1;l<4;l++)
      {
       if(num[i][j]==num[k+ii][l+jj]&&i!=k+ii&&j!=l+jj)
       {temp++;goto AGAIN;}
      }
     }
     for(k=1;k<10;k++)
     {
      if((num[i][j]==num[i][k]&&j!=k)||(num[i][j]==num[k][j]&&i!=k))
      {temp++;goto AGAIN;}
     }
     repetion++;
     rep[i][j]=repetion;
     goto NEW_PRIORITY;
    }
   }
  }
 }
 system("cls");
 cout<<"The solution for SUDOKU puzzle is:\n\n";
 cout<<" |---|---|---|---|---|---|---|---|---|\n";
 for(i=1;i<10;i++)                                              //Displaying the elements
 {
  for(j=1;j<10;j++)
  {
   if(num[i][j]!=0)
   {cout<<" | "<<num[i][j];}
   else{cout<<" |  ";}
  }
  cout<<" |\n |---|---|---|---|---|---|---|---|---|\n";
 }
 END:
 getch();
 return 0;
}
