//
//  main.cpp
//  gas_distance
//
//  Created by Samarth Arora on 20/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
bool initchek(int gas[],int dist[],int i){
    if(gas[i]>=dist[i]){
        return  true;
    }
    else return false;
    
}

int start(int gas[],int dist[],int n){
    int s=0,d=0;
    int start=-1;
    
    for(int i=0;i<n;i++){
        int prevs=s;
        int am=gas[i]-dist[i];
        if(am>0)
            s+=am;
        else d+=am;
            
        if(prevs<=0 and s>0){
            start=i;
        }
        
        
        
    }
    if(d<=s)
    return  start;
    else return -1;
}
int main()
{
    int gas[]={4,6,7,4};
    int dist[]={6,5,3,5};
    cout<<start(gas,dist,4);
    
    return 0;
}

