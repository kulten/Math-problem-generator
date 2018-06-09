#include <iostream>
#include<random>
#include<conio.h>
#include<chrono>
#include<ctime>
using namespace std;
void addition(long n,long r1, long r2)
{
    long a,b,c,d;
  if(r1 > r2)
  {
      int t = r2;
      r2 = r1;
      r1 = t;
  }
  chrono::system_clock::time_point t = chrono::system_clock::now();
  time_t tp = chrono::system_clock::to_time_t(t);
  mt19937 ab(tp);
  uniform_int_distribution<> range(r1, r2);
  for(int i = 1; i <= n; i++)
  {

        a = range(ab);
        b = range(ab);
        c = a + b;
        cout<<"\nSum number: "<<i<<endl;
        cout<<a<<" + "<<b<<" = ?"<<endl;
        cout<<"What's the answer?\n";
        cin>>d;
        while(d!=c)
        {
            cout<<"\nWrong answer, try again\n";
            cin>>d;
        }
        cout<<"\Good job!\n";
  }
}
int main()
{
    int x;
    long y,z;
    cout<<"How many sums?\n";
    cin>>x;
    cout<<"\nWhat range should they be in?\n";
    cout<<"First number: ";
    cin>>y;
    cout<<"\nSecond number: ";
    cin>>z;
    cout<<"\ngot it! "<<x<<" math problems coming right up!\n";
    addition(x,y,z);
    getch();
}
