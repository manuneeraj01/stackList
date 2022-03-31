#include <iostream>
#include<cstring>
using namespace std;

class stack
{
private:
    char *A;
    int size;
    int top;

public:
    stack();
    void push(char x);
    char pop();
    int stackTop();
    int isEmpty();
    int isFull();
    void display();
    int isOperand(char x);
    int outStackPre(char x);//to know about the out stack precedence of operator
    int inStackPre(char x);//to know about the in stack precedence of operator
    string conversion(string infix);//infix to postfix
    ~stack();
};

stack ::stack()
{
    size = 10;
    top = -1;
    A = new char[size];
}
stack ::~stack()
{
    delete[] A;
}

int stack ::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int stack ::isFull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}
int stack ::stackTop()
{
    if (isEmpty())
        return -1;
    else
        return A[top];
}
void stack::push(char x)
{
    if (isFull())
        cout << "stack overflow";
    else
    {
        top++;
        A[top] = x;
    }
}
char stack ::pop()
{
    int x;
    if (isEmpty())
        cout << "stack underflow";
    else
    {
        x = A[top];
        top--;
    }
    return x;
}
void stack ::display()
{
    if (isEmpty())
        cout << "stack is empty";
    else
    {
        for (int i = top; i >= 0; i--)
            cout << A[i]<<" ";
    }
}

int stack :: isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x=='^' || x == '(' || x==')')
        return 0;
    else
        return 1;
}

int stack :: outStackPre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^' )
        return 6;
    else if(x == '(' )
        return 7;
    else if(x == ')' )
        return 0;

}

int stack :: inStackPre(char x){
    if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '^' )
        return 5;
    else if(x == '(' )
        return 0;
    // else if(x == ')' )
    //     return 0;

}

int strlen(string arr){
    int l=0;
    for(int i=0; arr[i] !='\0'; i++)
        l++;
    cout<<l;
    return l;
}
string stack :: conversion(string infix){
    int i,j;
    i=j=0;
    int ptr=0;
    char *postfix = new char[strlen(infix)+1];
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(outStackPre(infix[i]) > inStackPre(stackTop()))
                push(infix[i++]);
            else{
                if(stackTop()=='(' && infix[i] == ')' || stackTop()==')')
                    pop();
                else
                    postfix[j++] = pop();        
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop(); 
        ptr++; 

    }
    postfix[j] = '\0';
    cout<<endl<<ptr<<endl;
    size = j;
    return postfix;

}
int main()
{
    stack s;
    string infix = "((a+b)*c)-d^e^f";
    // string infix = "a+b*c-d/e";
    cout<<s.conversion(infix);

    return 0;
}