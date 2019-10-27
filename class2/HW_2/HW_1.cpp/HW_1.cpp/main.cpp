//
//  main.cpp
//  HW_1.cpp
//
//  Created by Samarth Arora on 24/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
void genstar(int n){
    int mar=2*n-1;
    for(int i=1;i<=n;i++){
        int s=n-i;
        for(int j=1;j<=s;j++)
            cout<<" ";
        for(int j=1;j<=mar-2*s;j++)
            cout<<"*";
        cout<<endl;
        
    }
    for(int i=n;i>=1;i--){
        int s=n-i;
        for(int j=1;j<=s;j++)
            cout<<" ";
        for(int j=1;j<=mar-2*s;j++)
            cout<<"*";
        cout<<endl;}
    
}
int main()
{
    int n;
    cin>>n;
    genstar(n);
    return 0;}
