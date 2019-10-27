//
//  main.cpp
//  HANOI.CPP
//
//  Created by Samarth Arora on 08/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int count=0;

void move(string f,string t,int disk){
    cout<<"Move ring "<<disk<<" from "<<f<<" to "<<t<<endl;
    ::count++;
}
void hanoi(int n,string f,string t, string h){
    if(n==0){
        return;
    }

    hanoi(n-1, f, h, t);
    move(f,t,n);
    hanoi(n-1, h, t, f);
}
int main()
{
    int n;
    cin>>n;

    hanoi(n,"A","B","C");
//    cout<<::count;
    return 0;
}
