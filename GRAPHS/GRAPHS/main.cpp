
#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
//class elem{
//    int data;
//    bool visited;
//    elem(int data){
//        this->data=data;
//        visited=false;una
//    }
//
//};

template <typename T>
class Graph{
    
    void dsfhelper(T node, unordered_map<T, bool> &visited, list<T>&result){
        visited[node]=true;
        
        for (T neighbour:adjList[node]) {
            if(!visited[neighbour])
            dsfhelper(neighbour,visited,result);
        }
        result.push_front(node);
        return;
    }
    public:
    
    
    
    
    unordered_map< T,list<T> > adjList;
    
    bool ispossible(T a,T b){
        bool ret=0;
        for(auto n: adjList[a])
            if(n==b)
                return 1;
        return 0;
    }

    Graph(){

    }

    void addEdge(T u,T v,bool bidir = true){
        adjList[u].push_back(v);

        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void display(){
        for(auto vertex:adjList){
            cout<<vertex.first<<" -> ";

            for(T node:vertex.second){
                cout<<node<<" ,";
            }
            cout<<endl;
        }
    }
    void dfsTopologicalSort(T src){
        unordered_map<T, bool> visited;
        list<T> result;

        dsfhelper(src, visited, result);
        for(auto node:adjList){
            if(!visited[node.first])
        dsfhelper(node.first,visited,result);
        }
        for(T item:result){
            cout<<item<<" ";
        }
        cout<<endl;
        
    }
};


unordered_map<int, bool> visited;

void level_order_print(Graph<int> g,int source){
    queue<int> q;
//    q.push(source);
    visited[source]=true;
    cout<<source<<" ";
//    q.pop(source);
    for(auto node:g.adjList[source]){
        q.push(node);
        
        visited[node]=true;
    }
    while (!q.empty()) {
        int top=q.front();
        for(auto node:g.adjList[top]){
        if(visited[node]==0)
        {q.push(node);
            
            visited[node]=true;
        }
            
        }
        
            q.pop();
        cout<<top<<" ";
        
        
    }
    
}



int min_distance_bw(Graph<int> g,int source,int end){
    queue<int> q;
    unordered_map<int, int> dist;
//    q.push(source);
    dist[source]=0;
//    cout<<source<<" ";
//    q.pop(source);
    for(auto node:g.adjList[source]){
        deb(node)
        q.push(node);
        if(dist[node]==0)
        dist[node]=dist[source]+1;
    }
    while (!q.empty()) {
        int top=q.front();
        for(auto node:g.adjList[top]){
            if(dist[node]==0 and node!=source){
            q.push(node);
                deb(node);
//            if(!dist[node])
            dist[node]=dist[top]+1;
            }
        }
//        for(auto node:g.adjList[top]){
//        if(visited[node]==0)
//        {q.push(node);
//
//            visited[node]=true;
//        }
//
//        }
        
            q.pop();
//        cout<<top<<" ";
        
        
    }
//    for(auto d:dist){
////        cout<<d.first<<"--"<<d.second<<" ";
//    }

    return dist[end];
    
}
//unordered_map<int, bool> visitedd;

void inorder_print(unordered_map<int, bool>& visited,int source,Graph<int> g,unordered_map<int, bool> &done){
    done[source]=true;
    cout<<source<<" ";
    visited[source]=1;
    for(auto node:g.adjList[source]){
        if(!visited[node])
        {inorder_print(visited, node, g,done);}
        
    }
    
    return;
    
}
// print_level_sort_oreder(unordered_map<int, bool>& done, int source,Graph<int> g){
//int journeyhelper(int node,unordered_map<int, bool> &visited, int &cnt, Graph<int> g){
//    visited[node]= true;
//
//    for(auto iter: g.adjList[node]){
//        cnt+=journeyhelper(iter, visited, cnt, g);
//    }
//
//    return cnt;}
//int journeymoon(Graph<int> g){
//    unordered_map<int, bool> visited;
//    int n=g.adjList.size();
//
//    for(auto n: g.adjList){
//        if(!visited[n.first])
//        {
//            int count=0;
//            journeyhelper(n.first,visited,count,g);
//        }
//    }
//
//
//}

void gen_board(Graph<int> &g,int start,int end){
    for(int i=start;i<end;i++){
    
        for(int j=1;j<=6;j++){
            int upper=i+j;
            if(upper>end){
                upper=end;
                g.addEdge(i, upper,false);
            }
        }
    }
    
}
int main(){

     Graph<int> g;

//     g.addEdge(1,2);
//     g.addEdge(1,3);
//     g.addEdge(2,3);
//     g.addEdge(3,4);
//     g.addEdge(1, 5);
//     g.addEdge(4, 5);
//     g.addEdge(3, 5);
//     g.addEdge(5, 6);
//    g.addEdge(100, 101);
//    g.addEdge(100, 102);
//    g.addEdge(102, 101);
    
//    g.addEdge(1, 3,false);
//    g.addEdge(2, 3,false);
//    g.addEdge(3, 4,false);
//    g.addEdge(3, 5,false);
//    g.addEdge(4, 6,false);
//    g.addEdge(5, 6,false);
//    gen_board(g, 0, 36);
//    g.addEdge(2, 15);
//    g.addEdge(14, 35);
//    cout<<min_distance_bw(g, 0, 36)<<endl;
//     g.dfsTopologicalSort(1);

//    Graph<string> g;
//    g.addEdge("Coding Blocks","Java");
//    g.addEdge("Coding Blocks","Python");
//    g.addEdge("Coding Blocks","Django");
//    g.addEdge("Pranav","Coding Blocks");
//
//    g.display();
//    level_order_print(g, 1);
//    cout<<min_distance_bw(g, 6, 3);
//    unordered_map<int, bool> done;
//    for(auto node:g.adjList){
//        if(done[node.first]==0){
//    inorder_print(visited, node.first, g,done);
//        done[node.first]=true;
//            cout<<endl;
//        }
        
//    }
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        
    }
    cin>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        
        cin>>a>>b;
        g.addEdge(a, b);
    }
    int cand1,cand2;
    cin>>cand1>>cand2;
    cout<<g.ispossible(cand1,cand2);
    return 0;
}
