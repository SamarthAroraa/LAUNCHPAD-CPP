//
//  main.cpp
//  BST
//
//  Created by Samarth Arora on 02/11/19.
//  Copyright © 2019 Samarth Arora. All rights reserved.
//

#include <iostream>
#include <climits>
#include <queue>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    
};
node* construct(node*root, int data){
    if(root==NULL){
        node* root=new node(data);
        //        root->data=data;
        return root;
    }
    if(data>root->data)
    {
        root->right=construct(root->right, data);
    }
    else{
        root->left=construct(root->left, data);
    }
    
    return root;
    
}
node* buildtree(int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
    int data;
    cin>>data;
    
  
        root=construct(root,data);
//        cin>>data;
    }
    
    return root;
    
}
void display_preorder(node* root){
    if(root==NULL){
        return;
    }
    //NLR

    cout<<root->data<<" ";
    display_preorder(root->left);

    
    display_preorder(root->right);
    
}
bool search(node* root, int data){
    if(root==NULL)
        return false;
    
    if(data==root->data)
        return true;
    if(data>root->data)
        if(search(root->right,data)) return true;
    return search(root->left,data);
    
    
}
node* buildtreee(node* root){
    int data;
    cin>>data;
    
    if(data == -1)
        return NULL;
    if(root == NULL){
        node*n = new node(data);
        root = n;
    }
    root->left = buildtreee(root->left);
    root->right = buildtreee(root->right);
    
    return root;
}
class List{
public:
    node* head;
    node* tail;
    
    List(){
        head=NULL;
        tail=NULL;
    }
};
List tree_list(node*&root){
    List temp;
    if(root==NULL){
        
        return temp;
    }
    
    
    if(root->left==NULL and root->right==NULL)
    {
        temp.head=root;
        temp.tail=root;
        return temp;
    }
    if(root->left!=NULL and root->right==NULL)
    {
        List temp2=tree_list(root->left);
        temp2.tail->left=root;
        temp.head=temp2.head;
        temp.tail=root;
        return temp;
        
    }
    if(root->left==NULL and root->right!=NULL)
    {
        
        List temp2=tree_list(root->right);
        root->left=temp2.head;
        temp.head=root;
        temp.tail=temp2.tail;
        
        return temp;
        
    }
    if(root->left!=NULL && root->right!=NULL){
        List temp_l=tree_list(root->left);
        List temp_r=tree_list(root->right);
        temp_l.tail->left=root;
        root->left=temp_r.head;
        temp.tail=temp_r.tail;
        temp.head=temp_l.head;
        return temp;
    }
    
    //    if(temp.head==NULL and temp.tail!=NULL)
    //        {
    //            temp.head=root;
    ////            temp.tail=root;
    //            return temp;
    //        }
    //    temp.tail->left=root;
    //    List temp_r=tree_list(root->right);
    //
    //    root->left=temp_r.head;
    //
    //    return temp;
    return temp;}
//void tree dismantle(node* root,node* prev)
//{   if(root->left==NULL)
//        return prev;
//
//
//    root->left=tree_dismantle(root->left,root);
//
//}
//void LevelOrder_nl(node * root){
//
//    queue<node *> q;
//
//    q.push(root);
//    q.push(NULL);
//
//    while (!q.empty()) {
//        if(q.front()==NULL){
//            cout<<endl;
//            if(!q.empty()){
//                q.push(NULL);
////                continue;
//            }
//            continue;
//
//        }
//
//        cout<<q.front()->data<<" ";
//        while(q.empty())
//            q.pop();
//        if(q.front()->left!=NULL){
//            q.push(q.front()->left);
//        }
//        if(q.front()->right!=NULL){
//            q.push(q.front()->right);
//        }
//
//            q.pop();
//
//
//
//
//
//
//    }
//}
int firstTimeVISITlevel=0;
void leftView(node* root,int level){
    if(root==NULL){
        return;
    }
    if(firstTimeVISITlevel==level){
        cout<<root->data<<" ";
        firstTimeVISITlevel++;
        
    }
    leftView(root->left, level+1);
    leftView(root->right, level+1);
    
}


void left_bound(node* root){
    if(root->left==NULL and root->left==NULL)
        return;
    cout<<root->data<<" ";
    if(root->left!=NULL){
        left_bound(root->left);
        return;
    }
    left_bound(root->right);
    
}

void right_bound(node* root){
    if(root->right==NULL and root->right==NULL)
        return;
    cout<<root->data<<" ";
    if(root->right!=NULL){
        left_bound(root->right);
        return;
    }
    left_bound(root->right);
    
}


bool checkbst(node* root,int l,int h){
    if(root==NULL)
        return true;
    if(root->data>=h or root->data<=l)
        return false;
    if(checkbst(root->left,l,root->data) and checkbst(root->right, root->data, h))
        return true;
    return false;}
void print_leaves(node* root){
    if(root->left==NULL and root->right==NULL){
        cout<<root->data<< " ";
        return;
    }
    print_leaves(root->left);
    print_leaves(root->right);
}

/// TIME COMPLEXITY  NOT OPTIMAL
/// @param i iterator
/// @param n as given
int catalan(int i,int n) {
    if(i>n)
        return 1;
    if(n==i){
        return catalan(1, n-1);
    }
    int left=catalan(1, i-1);
    int right=catalan(1, n-i);
    return left*right + catalan(i+1, n);
}
int maxi=0;
int max_sum_tree(node *root){
    if(root==NULL)
        return 0;
    
    int left=max_sum_tree(root->left);
    int right=max_sum_tree(root->right);
    if(left<0)
        left=0;
    if(right<0)
        right=0;
    if(left+right+root->data>maxi)
        maxi=left+right+root->data;
    return max(left+root->data,root->data+right);
}
void printlist(node* &head){
    while(head!=NULL)
    {cout<<head->data<<" ";
        
        head=head->left;
        
    }
    
    
}
class bst{
public:
    int size;
    int mini;
    int maxi;
    bool is_bst;
    bst(){
        size=0;
        mini=INT_MAX;
        maxi=INT_MIN;
        is_bst=true;
    }
};

bst largest(node* root){
    bst val;
    if(root==NULL)
        return val;
    
    
    
    
    bst temp_l=largest(root->left);
    bst temp_r=largest(root->right);
    if(temp_l.is_bst=false or temp_r.is_bst==false or root->data<temp_l.maxi or root->data>temp_r.mini)
    {    val.is_bst=false;
        val.size=max(temp_l.size,temp_r.size);
    }
    else{
        val.is_bst=true;
        val.size=temp_l.size+temp_r.size+1;
        if(root->data>val.maxi)
            val.maxi=root->data;
        if(root->data<val.mini)
            val.mini=root->data;
    }
    return val;
}
/// catalan call format---->  (1,n)
int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        node* root=NULL;
        root=buildtree(n);
        display_preorder(root);

    }
//    int
//    node* root=NULL;
//    ////    node* root=buildtree();
//    root=buildtreee(root);
//    display_preorder(root);
//    cout<<endl;
//    ////    display_preorder(n);
//    //    cout<<endl;
//    ////    LevelOrder_nl(root);
//    ////    cout<<search(n,42)<<endl;
//    ////    cout<<search(n,7)<<endl;
//    ////    cout<<checkbst(n, INT_MIN, INT_MAX);
//    ////    leftView(root, 0);
//    ////    cout<<endl;
//    //    left_bound(root);
//    //
//    //    print_leaves(root);
//    //    right_bound(root->right);
//    //    cout<<catalan(1,5);
//    int n = max_sum_tree(root);
//    List list=tree_list(root);
//    printlist(list.head);
//    bst ans =largest(root);
//    cout<<"\n"<<ans.size;
//    //    cout<<maxi;
    return 0;
    
    
}
//4
//3
//1
//-1
//-1
//2
//-1
//-1
//5
//6
//-1
//-1
//7
//-1
//-1
