//
//  main.cpp
//  is palindrome)_strings
//
//  Created by Samarth Arora on 14/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>


using namespace std;

bool isPalind(string s)

{
    bool res=true;
    int n=s.length();
    for(int i=0;i<=n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            res=false;
            break;
        }
    }
    
    return res;}
int main()
{
    string s;
    cin>>s;
    cout<<isPalind(s);
    return 0;
    
}
