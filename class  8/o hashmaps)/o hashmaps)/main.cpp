//
//  main.cpp
//  o hashmaps)
//
//  Created by Samarth Arora on 14/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
char frqmax(string s){
    vector<int> frq(256,0);
    for(int i=0;i<s.length();i++){
        int ascii=s[i];
        frq[ascii]++;
    }
    char maxc=-1;
   int  max=-1;
    for(int i=0;i<256;i++){
        if(frq[i]>max) {max=frq[i];
            maxc=(char)i;}
    }
    
    return maxc;
}
int main()
{
    string s;
    cin>>s;
    cout<<frqmax(s);
    return 0;
}
