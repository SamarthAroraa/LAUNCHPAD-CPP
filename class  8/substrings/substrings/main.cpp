//
//  main.cpp
//  substrings
//
//  Created by Samarth Arora on 14/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
void substring(string s){
    for(int j=0;j<s.length();j++){
    for(int i=0;i<s.length()-j;i++){
        cout<<s.substr(j,i+1)<<endl;
    }
    }
}

int main()
{
    string s;
    cin>>s;
    substring(s);
    
    return 0;
}
