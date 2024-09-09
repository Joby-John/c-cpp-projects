//#include<bits/stdc++.h>
#include<queue>
#include<string>
#include<iostream>

using namespace std;
struct comparator
{
    bool operator()(int a ,int b)
    {
        return a%2==1;
    }
};

int main()
{
    queue<string>games;
    games.push("Red dead");
    games.push("COD");
    games.push("Prince of persia");
    games.pop();
    cout<<games.front();

    cout<<games.back();

    priority_queue<int, vector<int>, comparator>percents;
    percents.push(50);
    percents.push(34);
    percents.push(58);
    percents.push(10);
    percents.push(27);
    
    


    for(int i = 0; i<percents.size();)
    {
        cout<<percents.top()<<" ";
        percents.pop();
    }
    return 0;
}