#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
  float x[20],y[20],f,s,h,d,p;
  int j,i,n;
  cout<<"enter the value of n :";
  cin>>n;
  cout<<"enter the elements of x:";
  for(i=1;i<=n;i++)
   {
        cin>>x[i];
         }
                   cout<<"enter the elements of y:";
               for(i=1;i<=n;i++)
               {
              cin>>y[i];                  
                }
  h=x[2]-x[1];
  cout<<"Enter the value of f:";
  cin>>f;
s=(f-x[1])/h;
p=1;
d=y[1];                                  
for(i=1;i<=(n-1);i++)
 {
                   for(j=1;j<=(n-i);j++)
                    {
                          y[j]=y[j+1]-y[j];
                            
                    }
                    p=p*(s-i+1)/i;
                    d=d+p*y[1];
 }                         
cout<<"For the value of x=%6.5f THe value is %6.5f"<<f<<d;
 getch();
 return 0;
}
