#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *S;
    public:
    Stack();
    Stack(int size);
    void display();
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
};

Stack :: Stack(){
    size = 5;
    S = new int[size];
    top = -1;
}
Stack :: Stack(int size){
    this->size = size;
    S = new int[size];
    top = -1;
}

int Stack :: stackTop(){
    if(top == -1)
        return -1;
    else    
        return S[top];
}

int Stack :: isEmpty(){
    if(top == -1)
        return 1;
    else    
        return 0;
}

int Stack :: isFull(){
    if(top == size-1)
        return 1;
    else
        return 0;
}

void Stack :: display(){
    if(isEmpty() == 1)
        cout<<"stack is empty";
    else{
        for(int i = top; i>=0; i--)
            cout<<S[i]<<" ";
    }
}

void Stack :: push(int x){
    if(isFull() == 1)
        cout<<"Stack overflow";
    else{
        top++;
        S[top] = x;
    }
}

int Stack :: pop(){
    int x = -1;
    if(isEmpty() == 1)
        cout<<"stack underflow";
    else{
        x = S[top];
        top--;
    }
    return x;
}

int Stack :: peek(int pos){
    int x=-1;
    if(top-pos+1 < 0)
        cout<<"invalid Position";
    else    
        x = S[top-pos+1];
    return x;
}
int main(){
    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    cout<<endl;
    cout<<s.peek(1);

    return 0;

}