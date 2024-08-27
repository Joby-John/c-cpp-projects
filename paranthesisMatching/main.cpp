#include<bits/stdc++.h>

using namespace std;

bool paranthesisMatch(string s)
{
    vector<char>stackk;

    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == '(')
        {
            stackk.push_back('(');
        }
        else if (s[i] == ')')
        {
            if(!stackk.empty() && stackk.back() == '(')
            {
               stackk.pop_back();
            }
            else{
                stackk.push_back(s[i]);
            }
        }
    }

    int n = stackk.size();

    if(n == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    bool result = paranthesisMatch("(())");

    if(result == true)
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}