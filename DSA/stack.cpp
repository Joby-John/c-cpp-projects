#include<bits/stdc++.h>

using namespace std;

int main()
{

    stack<string>movies;
    movies.push("Dhoom");
    movies.push("chitti");
    cout<<movies.top();
    cout<<movies.empty();

    stack<string>games;
    games.push("redemption");
    games.push("COD");
    games.swap(movies);


    cout<<games.top();
    cout<<movies.top();
    return 0;
}