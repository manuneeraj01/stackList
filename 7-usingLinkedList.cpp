#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    struct Node *next;
};

class stack{
    private:
    Node *top = NULL;
    public:
    // stack();
    int isEmpty();
    int isFull();
    int stacktop();
    void display();
    void push(int x);
    int pop();
    int peek(int pos);
    ~stack();
};

stack :: ~stack(){
    Node *p = top;
    while(top){
        top = top->next;
        delete p;
        p = top;
    }
}
int stack :: isEmpty(){
    return top?0:1;
}

int stack :: isFull(){
    Node *t = new Node;
    int r = t?1:0;
    delete t;
    return r;
}

int stack :: stacktop(){
    return top?top->data:-1;
}

void stack :: display(){
    Node *p = top;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
        
}

void stack :: push(int x){
    Node *t;
    t = new Node;
    if(t == NULL)
        cout<<"stack overflow";
    else{
        
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack :: pop(){
    int x = -1;
    Node *p = top;
    if(top == NULL)
        cout<<"stack underflow";
    else{
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

int stack :: peek(int pos){
    Node *p = top;
    for(int i=0; i<pos-1 && p!=NULL; i++){
        p = p->next;
    }
    if(pos)
        return p->data;
    return -1;
}
int main(){
    stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    cout<<endl;
    cout<<s.pop()<<endl;;
    s.display();
    cout<<"\n"<<s.peek(2)<<endl;
    s.display();
    return 0;
}