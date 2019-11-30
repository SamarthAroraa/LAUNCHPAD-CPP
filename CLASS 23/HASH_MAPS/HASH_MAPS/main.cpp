//
//  main.cpp
//  HASH_map1S
//
//  Created by Samarth Arora on 09/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;
void print_inters(vector<int> a, vector<int> b)
{
    unordered_map<int, int> map;
    for(int i = 0; i < a.size(); i++){
        map[a[i]]++;
        }
    for(int i = 0; i < b.size(); i++){
        if(map[b[i]] != 0){
            cout << b[i] << endl;
            map[b[i]]--;
        }
    }
    
    
    return;
    
    
}
void union_sets(vector<int> a, vector<int> b){
    unordered_map<int, int> m;
    for(int i = 0 ; i < a.size() ; i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.size() ;i++){
        m[b[i]]++;
    }
    for(auto n:m){
        if(n.second!=0){
        cout<<n.first<<" ";
        m[n.first]=0;
//        n.second=0;
        }
    
    }
   
    cout<<endl;
    return;}


bool sum_subz(vector<int> a){
    unordered_map<int, bool> sum_present;
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum_present.find(sum)!=sum_present.end())
            return true;
        sum_present[sum]=1;
        
    }return false;
}

int count_sub_k(vector<int> a,int k){
  unordered_map<int, int> sum_present;

    int sum=0,count=0;
    sum_present[sum]++;
     for(int i=0;i<a.size();i++){
         sum+=a[i];
         if(sum_present.find(sum-k)!=sum_present.end())
             count+=sum_present[sum-k];
         sum_present[sum]++;
         
     }return count;
}

int count_maxsub_k(vector<int> a,int k){
  unordered_map<int, int> sum_index;
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        sum_index[sum]=i;
    }
    
    

}

class data{
    
public:
    int low;
    int high;
    int length;
    bool present;
    data(){
        low=0;
        high=0;
        length=1;
        present=0;
    }
};

int longest_cons(vector<int > a){
    int maxlen=INT_MIN;
    unordered_map<int, data> map;
    for(int i=0;i<a.size();i++){
        map[a[i]].present=1;
        if(map[a[i]-1].present and map[a[i]+1].present){
            map[a[i]].low=map[a[i]-1].low;
             map[a[i]].high=map[a[i]+1].high;
            
            int currlen=map[a[i]].high-map[a[i]].low;
            map[a[i]].length=currlen;
            
//            int x=map[a[i]].le
            map[a[i]+1].high=map[a[i]].high;
            map[a[i]+1].low=map[a[i]].low;
            map[a[i]+1].length=map[a[i]].length;
            map[a[i]-1].high=map[a[i]].high;
            map[a[i]-1].low=map[a[i]].low;
            map[a[i]-1].length=map[a[i]].length;
            
            
            if(currlen>maxlen)
                maxlen=currlen;
            int lex=map[a[i]].low;
            int hex=map[a[i]].high;
            map[lex].high=map[a[i]].high;
            map[lex].low=map[a[i]].low;
            map[lex].length=map[a[i]].length;
            map[hex].high=map[a[i]].high;
            map[hex].low=map[a[i]].low;
            map[hex].length=map[a[i]].length;
            
        }
        else if(map[a[i]-1].present and !map[a[i]+1].present)
        {
//            map[a[i]].low=map[a[i]-1].low;
             map[a[i]-1].high++;
            map[a[i]].high=map[a[i]-1].high;
            map[a[i]].low=map[a[i]-1].low;

            int currlen=map[a[i]].high-map[a[i]].low;
            map[a[i]].length=currlen;

            if(currlen>maxlen)
                maxlen=currlen;
            int lex=map[a[i]].low;
            int hex=map[a[i]].high;
            map[lex].high=map[a[i]].high;
            map[lex].low=map[a[i]].low;
            map[lex].length=map[a[i]].length;
            map[hex].high=map[a[i]].high;
            map[hex].low=map[a[i]].low;
            map[hex].length=map[a[i]].length;
            
        }
        else if(!map[a[i]-1].present and map[a[i]+1].present)
                {
                    map[a[i]+1].low=a[i];
                    
//                     map[a[i]-1].high=a[i];
                    map[a[i]].high=map[a[i]+1].high;
                    map[a[i]].low=map[a[i]+1].low;

                    int currlen=map[a[i]].high-map[a[i]].low;
                    map[a[i]].length=currlen;

                    if(currlen>maxlen)
                        maxlen=currlen;
                    int lex=map[a[i]].low;
                    int hex=map[a[i]].high;
                    map[lex].high=map[a[i]].high;
                    map[lex].low=map[a[i]].low;
                    map[lex].length=map[a[i]].length;
                    map[hex].high=map[a[i]].high;
                    map[hex].low=map[a[i]].low;
                    map[hex].length=map[a[i]].length;
                    
                }
        else if(!map[a[i]-1].present and !map[a[i]+1].present)
                        {
                            map[a[i]].low=a[i];
                            map[a[i]].high=a[i];

                            
                        }
    }
    
    return maxlen+1;
    
}
int main()
{
    
    vector<int> a;
    vector<int> b;
    
    a.push_back(1);
    a.push_back(2);
//    a.push_back(2);

    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    b.push_back(8);
    b.push_back(9);
    b.push_back(2);
    b.push_back(2);
    vector<int> d={2,3,0,0,0,0,0,0,1,2};
    b.push_back(3);
    b.push_back(7);
    
    vector<int> c={1,23,24,25,26,27,2,22,3,33,4,234,5};
    cout<<longest_cons(c)<<endl;
    
    cout<<count_sub_k(d,3);
    cout<<'\n'<<count_maxsub_k(d, 3);
//    print_inters(a, b);
    
//    for(int i=0;i<a.size();i++){
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<b.size();i++){
//    cout<<b[i]<<" ";
//    }
//    cout<<endl;
//
//    union_sets(a, b);


    
    return 0;
    
}
