//
//  main.cpp
//  HW
//
//  Created by Samarth Arora on 29/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;

int steps(int start,int end){
    if(start==end){
        return 1;
        }
    if(start>end)
        return 0;
    
    //rec
    int sum=0;
    int b=end-start;
    if(b>end)
        b=end;
    for(int i=1;i<=b;i++){
        sum+=steps(start+i,end);
    }
    return sum;}
int fact(int n)
{
    //base
    if(n<=1)
        return 1;
    
    //rec
    return n*fact(n-1);
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    m--;
    n--;
    
    int ways1=steps(0, m);
    int ways2=steps(0,n);
    cout<<ways1<<" "<<ways2;
    int k;
//    int wc1=fact(ways1)/(2*fact(ways1-2));
//    int wc2=fact(ways2)/(2*fact(ways2-2));
    int j;
    if(ways2<ways1)
        j=ways2;
    else
        j=ways1;
    if(ways1>1 or ways2>1)
    k=ways1*ways2*2-j;
    else if(ways2==1 and ways2==1)
        k=1;
    else
        k=ways1*ways2*2;
    cout<<endl<<k;
    return 0;
}
