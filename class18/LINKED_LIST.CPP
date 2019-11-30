#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = nullptr;
    }
};

void insertathead(node* &head,int data)
{
    node* n = new node(data);
    n->next = head;
    head = n;

}
void insertattail(node* &head,int data){
    node* temp=head;
    if(temp==nullptr){
        insertathead(head,data);
        return;
    }
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
        node*n = new node(data);
        temp->next = n;

}
void printlist(node*head){
    node*curr=head;
    cout<<curr->data<<"<--"<<endl;
    curr=curr->next;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
cout<<endl;}
int lent(node* head){

    int len=0;
    node* temp=head;
    if(temp==nullptr)
    return 0;
    while(temp->next!=nullptr){
        temp=temp->next;
        len++;
    }
    len++;
return len;}

bool search(node*head,int query){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==query){
            return true;
        }
    temp=temp->next;
}
return false;}

void insertatm(node* &head,int data,int m){
    int count=0;
    node*temp=head;
    if(m==0){
        insertathead(head,data);
        return ;
    }
    while(count < m-1)
    {
        if(temp->next==nullptr)
        break;
        temp=temp->next;
        count++;
    }
    // 1 2 3 4
    node* n=new node(data);

    n->next=temp->next;
    temp->next=n;
}
void deletehead(node* &head){
    node* temp=head;
    head=head->next;
    delete temp;

}
void deletetail(node* &head){
    node* temp=head->next;
    node* n=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;

    }
    node* del=temp;
    temp->next=nullptr;
    delete del;



}
void delatn(node* head,int index){
    int counter=0;
    node* temp=head;
    if(head==nullptr)
    return;

    while(counter<index-1){
        temp=temp->next;
        counter++;

    }
    node* j=temp->next;
    temp->next=temp->next->next;

    delete j;
}
bool recsearch(node* point,int data){

    if(point==nullptr)
    return false;


    if(point->data==data)
    return true;
    return recsearch(point->next,data);
}
//RECURSIVE REVERSION OF A LINKED LIST
node* getlast(node* head){
    node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp;
}
node* reverse(node* &curr,node* &head){
  //base
  if(head==nullptr or head->next==nullptr)
  return head;

  if(curr->next==nullptr){
      return curr;
  }
  //rec
    node* recursionResult = reverse(curr->next,head);
    // node* curr = head;
    curr->next->next=curr;
    curr->next=nullptr;
    return  recursionResult;
}


void iter_reverse(node* &head){
    node* p=nullptr;
    node* c=head;
    node* n=c->next;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;

    }
head=p;
return;
}
node* mergelist(node*head_a,node*head_b){
    node*tempa=head_a;
    node* tempb=head_b;
    node*newhead;
    if(tempa->next->data<tempb->next->data){
        newhead=tempa;
        tempa=tempa->next;

    }
    else{
    newhead=tempb;
    tempb=tempb->next;
}
    node*tempc=newhead;
    while(tempa->next!=nullptr and tempb->next!=nullptr){
        if(tempa->data<=tempb->data){
            tempc->next=tempa;
            tempc=tempc->next;
            tempa=tempa->next;
        }
        else{
            tempc->next=tempb;
            tempc=tempc->next;
            tempb=tempb->next;

        }
    }
    while(tempa->next!=nullptr){

            tempc->next=tempa;
            tempc=tempc->next;
            tempa=tempa->next;
        }
        while(tempb->next!=nullptr){

                tempc->next=tempb;
                tempc=tempc->next;
                tempb=tempb->next;
            }
return newhead;}

node* recursive_merge(node* heada, node*headb){
if(heada==nullptr)
return headb;
else if(headb==nullptr)
return headb;
node* c;
 if(heada->data<headb->data)
 {c=heada;
 c->next=recursive_merge(heada->next,headb);

}
else{
    c=headb;
    c->next=recursive_merge(heada,headb->next);
}

return c;
}
node* findmid(node* head){
    node*p1=head;
    node* p2=head;
    while(p1->next!=nullptr or p1->next->next!=nullptr){
        p1=p1->next->next;
        p2=p2->next;
    }
return p2;
}



node* mergesort(node* head){
//base

if(head->next==nullptr or head==nullptr){
    return head;
}
// node*end=getlast(node*head);
node*mid= findmid(head);
node*n =mid->next;
mid->next=nullptr;
head=mergesort(head);
n=mergesort(n);

node* nw=mergelist(head,n);
return nw;
}
int main(){

    node* head = nullptr;
    node* headb=nullptr;
    insertathead(head,7);
    insertathead(head,6);
    insertathead(head,4);
    insertattail(head,7);
    insertatm(head,3,1);
    printlist(head);
    insertathead(headb,5);
    insertathead(headb,7);
    insertathead(headb,8);
    insertattail(headb,22);
    insertatm(headb,4,1);
    printlist(headb);

    // node* temp=getlast(head);
    // iter_reverse(head);
    // printlist(head);
    // head=reverse(temp,head);
    // printlist(head);
    // printlist()
    node* c=mergesort(head);
    printlist(c);
    cout<<endl;
    // cout<<head->data;
    cout<<recsearch(head,0);
    // delatn(head,2);
    // deletehead(head);
    // // deletetail(head);
    // printlist(head);
    // cout<<"lenght:"<<lent(head);
    cout<<endl;
    // cout<<search(head,3)<<endl;
    return 0;
}
