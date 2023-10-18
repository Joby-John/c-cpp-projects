#include<iostream>

using namespace std;

int main(){ 
//     string intro;
//     int marksInMaths, a= 5, b = 7;
//     cout<<"Enter your name"<<endl;
//     cin>>intro;
//     cout<<"Enter your score"<<endl;
//     cin>>marksInMaths;

// cout<<"Hi "<<intro<<endl<<"Score is: "<<marksInMaths;

// cout<<"Lets test it:";
// cout<<"Whats "<<a<<"+"<<b<<":"<<a+b<<endl;
// cout<<"Whats "<<a<<"-"<<b<<":"<<a-b<<endl;
// cout<<"Whats "<<a<<"x"<<b<<":"<<a*b<<endl;
// cout<<"Whats "<<a<<"/"<<b<<":"<<a/b<<endl;
// cout<<"Whats "<<a<<"%"<<b<<":"<<a%b<<endl;

//conditionals
int age;
cout<<"Enter your age"<<endl;
cin>>age;
if (age>150)
{
    cout<<"Invalid age";
}
else if (age>=18)
{
    cout<<"You can vote";
}
else
{
    cout<<"You cannot vote";
}

return 0;
}