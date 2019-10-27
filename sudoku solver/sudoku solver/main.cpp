//
//  main.cpp
//  sudoku solver
//
//  Created by Samarth Arora on 07/10/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
//#define n 9
using namespace std;
bool isSafe(int board[100][100],int x,int y,int entry,int n){
    //check bottom vertical
    for(int i =x+1;i<n;i++){
        if(board[i][y]==entry)
            return false;
        
        }
    //check up vertical
    for(int i=0;i<x;i++){
        if(board[i][y]==entry)
            return false;
        
    }
    //check left horzontal
  for(int j=0;j<y;j++){
         if(board[x][j]==entry){
             return false;
         }
     }
    //check right horizontal
    for(int j=y+1;j<n;j++){
        if(board[x][j]==entry){
            return false;
        }
    }
    //check box
    int i=3*(x/3);
    int j=3*(y/3);
    for(int m=i;m<i+3;m++){
        for(int s=j;s<j+3;s++){
            if(board[m][s]==entry)
                return false;
        }
    }
    return true;
    
}

void print_board(int n,int board[100][100]){
//    cout<<"********************************"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        
    }
//    cout<<"**********************************"<<endl;
}
bool place_next(int board[100][100],int i,int col,int n){
    if(i>=n-1 and col>=n){
        print_board(n,board);
        return true;
    }
    
//    for(int i=row;i<n;i++){
        if(col==n){
            col=0;
            i++;
        }
        if(board[i][col]==0){
        for(int e=1;e<=9;e++){
            if(isSafe(board, i, col, e,n)){
                board[i][col]=e;
                if(place_next(board, i, col+1,n))
                    return true;
            
            board[i][col]=0;
        
        }
        
        
    }
//            return false;
            

    }
        else
            return place_next(board, i, col+1,n);
    

    
    return false;
}
int main()
{
    int n;
    cin>>n;
    int board[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    place_next(board, 0, 0,n);
    
    return 0;
}
