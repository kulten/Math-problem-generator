#include <iostream>
#include<random>
#include<conio.h>
#include<chrono>
#include<ctime>
#include<string>
#include<algorithm>
using namespace std;
int comparestr(string s)
{
    string add = "addition";
    string sub = "subtraction";
    int b = 0;
    if((s.compare(add))==0)
    {
        return 1;
    }
    else if((s.compare(sub))==0)
    {
        return 2;
    }
    else
    {
        return b;
    }
}
void change(long &a,long &b)
{
    int t = b;
      b = a;
      a = t;
      return;
}
void randn(long &x,long &y,long num1,long num2)
{
    long c;
    chrono::system_clock::time_point t = chrono::system_clock::now();
  time_t tp = chrono::system_clock::to_time_t(t);
  mt19937 ab(tp);
  uniform_int_distribution<> range(num1,num2);
  x = range(ab);
  y = range(ab);
  return;

}
void subtraction(long n,long r1,long r2)
{
    cout<<"\ngot it! "<<n<<" subtraction problems coming right up!\n";
    long a=0,b=0,c,d;
  if(r1 > r2)
  {
      change(r1,r2);
  }
  for(int i = 1; i <= n; i++)
  {

        randn(a,b,r1,r2);
        c = a - b;
        cout<<"\nSum number: "<<i<<endl;
        cout<<a<<" - "<<b<<" = ?"<<endl;
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
void addition(long n,long r1, long r2)
{
    cout<<"\ngot it! "<<n<<" addition problems coming right up!\n";
    long a=0,b=0,c,d;
  if(r1 > r2)
  {
      change(r1,r2);
  }
  for(int i = 1; i <= n; i++)
  {

        randn(a,b,r1,r2);
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
    int x,sel;
    long y,z;
    string ch;
    cout<<"Addition or Subtraction?\n";
    cout<<"Choice: ";
    cin>>ch;
    transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
    sel = comparestr(ch);
    cout<<"\nHow many sums?\n";
    cin>>x;
    cout<<"\nWhat range should they be in?\n";
    cout<<"First number: ";
    cin>>y;
    cout<<"\nSecond number: ";
    cin>>z;
    if(sel ==1)
    {
    addition(x,y,z);
    }
    else if(sel ==2)
    {
        subtraction(x,y,z);
    }
    getch();
}
