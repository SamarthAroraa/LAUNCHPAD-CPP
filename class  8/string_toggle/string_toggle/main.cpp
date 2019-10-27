//
//  main.cpp
//  string_toggle
//
//  Created by Samarth Arora on 14/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

string toggle(string& str){
    for(int i=0;i<str.length();i++)
    {
        int ascii=str[i];
        if(ascii<=90 and ascii>=65){
            str[i]+=32;
        }
        else if(ascii>=97 and ascii<=122)
            str[i]-=32;
    }
    return str;
    
}

int main()
{

    string str = "sAmaRth";
    
    
    cout<<toggle(str)<<endl;

}

