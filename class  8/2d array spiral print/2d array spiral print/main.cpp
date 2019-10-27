//
//  main.cpp
//  2d array spiral print
//
//  Created by Samarth Arora on 08/09/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int arr[6][6];
    int k=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            arr[i][j]=k++;
            
        }
    }
    int i;
    
    int minc=0;
    int minr=0;
    int maxc=5;
    int maxr=5;
    
    int swtch=0;
    k=0;
    while(k<36){
    switch (swtch) {
        case 0:
            for(i=minr;i<=maxr;i++)
            {
                cout<<arr[i][minc]<<" ";
            }
            minc++;
            break;
            
        case 1:
            for(i=minc;i<=maxc;i++){
                cout<<arr[maxr][i]<<" ";
            }
            maxr--;
            break;
        case 2:
            for(i=maxr;i>=minr;i--){
                cout<<arr[i][maxc]<<" ";
            }
            maxc--;
            break;
            
        case 3:
            for(i=maxc;i>=minc;i--){
                cout<<arr[minr][i]<<" ";
            }
            minr++;
            break;
            
        default:
            break;
    }
        k++;
        swtch=k%4;
    
    }
    
    return 0;
}
