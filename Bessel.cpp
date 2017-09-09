#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>
#include<conio.h>
#include<iostream>
#include<Windows.h>

#define WINDOWS 1

void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

using namespace std;

int main()
{
int n;                          // no. of terms.
int i,j;                        // Loop variables
float ax[10];                   // 'X' array limit 9
float ay[10];                   // 'Y' array limit 9
float x;                        // User Query for what value of X
float y;                      // Calculated value for coressponding X.
float h;                        // Calc. Section
float p;                        // Calc. Section
float diff[20][20];             // to store Y
float y1,y2,y3,y4;              // Formulae variables.

clrscr();
cout<<"\t\t !! BESSELS INTERPOLATION FORMULA !! ";
// Input section.
cout<<"\n\n Enter the no. of terms -> ";
cin>>n;

// Input Sequel for array X
cout<<"\n\n Enter the value in the form of x -> ";
// Input loop for X.
for(i=0;i<n;i++)
   {
   cout<<"\n Enter the value of x%d -> "<<i+1;
   cin>>ax[i];
   }

// Input sequel for array Y.
cout<<"\n\n Enter the value in the form of y -> ";
// Input loop for Y.
for(i=0;i<n;i++)
   {
   cout<<"\n Enter the value of y%d -> "<<i+1;
   cin>>ay[i];
   }

// Inputting the required value quarry
cout<<"\n\n Enter the value of x for ";
cout<<"\n which u want the value of y -> ";
cin>>x;

// Calculation and processing section.
h=ax[1]-ax[0];
for(i=0;i<n-1;i++)
   diff[i][1]=ay[i+1]-ay[i];

for(j=2;j<=4;j++)
   for(i=0;i<n-j;i++)
      diff[i][j]=diff[i+1][j-1]-diff[i][j-1];

i=0;
do
 {
 i++;
 }
while(ax[i]<x);

i--;
p=(x-ax[i])/h;
y1=p*diff[i][1];
y2=p*(p-1)*(diff[i][2]+diff[i-1][2])/4;
y3=p*(p-1)*(p-0.5)*diff[i-1][3]/6;
y4=(p+1)*p*(p-1)*(p-2)*(diff[i-2][4]+diff[i-1][4])/48;

// Taking sum
y=ay[i]+y1+y2+y3+y4;

// Outut Section
cout<<"\n When x = %6.2f , y = %6.8f"<<x<<y;

// Invoke user watch halt function
cout<<"\n\n\n\t\t\t !! PRESS ENTER TO EXIT !! ";
getch();
return 0;
}


