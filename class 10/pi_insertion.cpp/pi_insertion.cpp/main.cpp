//
//  main.cpp
//  pi_insertion.cpp
//
//  Created by Samarth Arora on 22/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

string addtolast(string str){
    //bse case
    if(str.length()==0)
        return str;
    
//recursive
    string sr=addtolast(str.substr(1));
    if(str[0]!='x')
    {
        return str[0]+sr;
    }
    else
        return sr+str[0];
}
int main()
{
    string input="xxpxbced";
    cout<<addtolast(input);
    return 0;
}
