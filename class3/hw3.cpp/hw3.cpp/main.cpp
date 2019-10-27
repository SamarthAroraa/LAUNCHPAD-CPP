I//
//  main.cpp
//  hw3.cpp
//
//  Created by Samarth Arora on 25/08/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

float sqrt(int n){
    float k=1.0;
    while(k*k<=n){
        k++;
    }
    k--;

    while(k*k<=n){
        k+=0.009;
    }
    k-=0.009;
    return k;

}
int main(){
    int n;
    cin>>n;
    cout<<sqrt(n)<<endl;
    return 0;
    
}

