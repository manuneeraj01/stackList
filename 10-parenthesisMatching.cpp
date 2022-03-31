#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *S;

public:
    Stack();
    Stack(int size);
    void display();
    void push(char x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
    int isbalance(string exp); // parenthesis balanced or not
    ~Stack();
};

Stack ::~Stack()
{
    delete[] S;
}
Stack ::Stack()
{
    size = 5;
    S = new char[size];
    top = -1;
}
Stack ::Stack(int size)
{
    this->size = size;
    S = new char[size];
    top = -1;
}
int Stack ::stackTop()
{
    if (top == -1)
        return -1;
    else
        return S[top];
}
int Stack ::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int Stack ::isFull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}
void Stack ::display()
{
    if (isEmpty())
        cout << "stack is empty";
    else
    {
        for (int i = top; i >= 0; i--)
            cout << S[i] << " ";
    }
}
void Stack ::push(char x)
{
    if (isFull())
        cout << "Stack overflow";
    else
    {
        top++;
        S[top] = x;
    }
}
int Stack ::pop()
{
    int x = -1;
    if (isEmpty())
        cout << "stack underflow";
    else
    {
        x = S[top];
        top--;
    }
    return x;
}
int Stack ::peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0)
        cout << "invalid Position";
    else
        x = S[top - pos + 1];
    return x;
}

int Stack ::isbalance(string exp)
{
    // for curlybraces, sqaure bracket and parenthesis
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch;
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);
        else{
            if (isEmpty())
                return false;
            else if (exp[i] == '}' && S[top] == '{' || exp[i] == ')' && S[top] == '(' || exp[i] == ']' && S[top] == '[')
                pop();
        }
    }
    if (isEmpty())
        return 1;
    return 0;
}

// for parenthesis only
// for(int i=0; exp[i] != '\0';i++){
//     if(exp[i] == '(')
//         push(exp[i]);
//     else if(exp[i] == ')'){
//         if(isEmpty())
//             return 0;
//         else{
//             pop();
//         }
//     }
// }
// if(isEmpty())
//     return 1;
// return 0;

int strlen(string exp)
{
    int len = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
int main()
{
    string exp = "{([a+b]*[c-d])}}";
    // string exp = "((a+b)*(c-d))";
    int size = strlen(exp);
    // cout<<strlen(exp);
    Stack s(size);
    cout << s.isbalance(exp); // if 0: not a balanced parenthesis
                              // if 1: balanced paranthesis

    return 0;
}