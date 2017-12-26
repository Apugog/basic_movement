# include<iostream>
# include <stdio.h>
# include <conio.h>
# define h 40
# define w 40
 
char scr[h][w];
using namespace std;
void display_screen() //displays the global matrix scr
{
  int k;
	for(int i=0;i<h;i++)
	{  k=0; 
	    while(k<15)    //for centering the screen blank spaces
		   {
		   	 cout<<"  ";
		   	 k++;
		   }
		for(int j=0;j<w;j++)
		{  
		  cout<<scr[i][j];
		}
		
		cout<<"\n";
	}	
}
void initialize_screen() //intializes the screen with spaces
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scr[i][j]=' ';
		}
	}
}
void swap(int i,int j,int l,int m) //moves a single point in screen by swapping blank spaces
{ 
    char temp;
  	temp = scr[i][j];
  	scr[i][j]=scr[l][m];
  	scr[l][m]=temp;
}
void delay(int i) //built delay function very rough aprroximation i=1 means 1sec delay
{ 
  int j,k;
   j=0;
	while(j<i)
	{   k=0;
		while(k<400000000)
		{
			k++;
		}
		j++;
	}
}
void transpose()  //transposes the entire screen matrix 
{  
   int x;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(i<j)
			{
			   x=scr[i][j];
			   scr[i][j]=scr[j][i];
			   scr[j][i]=x;
		    }
		}
	}	
}
void upside_down() //turns the screen matrix upside down
{
	int x;
  	for(int i=0;i<h/2;i++)
	{
		for(int j=0;j<w;j++)
		{
			x=scr[i][j];
			scr[i][j]=scr[h-i][j];
			scr[h-i][j]=x;
		}
	}	
}
int main()
{   
    int cha,x=0,y=0;
    char ch;
    initialize_screen();
	scr[0][0]='x';
    while(1)
    {
       
        if ( kbhit() )
            {
                ch = getch();
                cha = ch;
                if(cha=='w')
                {
	              swap(x,y,x-1,y);
	              x--;
                }
                if(cha=='a')
                {
	              swap(x,y,x,y-1);
	              y--;
                }
                if(cha=='s')
                {
	              swap(x,y,x+1,y);
	              x++;
                }
                if(cha=='d')
                {
	              swap(x,y,x,y+1);
	              y++;
                }
                
            }
   	  
      display_screen();  
	  delay(0.001);    
      system("cls");  
    }
    return 0;
 }

