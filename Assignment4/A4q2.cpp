#include <iostream>
using namespace std;
class Stack
{
private:
    int size;
    int *ptr;
    int top;

public:
    Stack(int num) // parameterized constructor
    {
        top = -1;
        size = num;
        ptr = new int[num]; // dynamic array declaration
    }
    Stack() // parameterless constructor
    {
        top = -1;
        size = 5;
        ptr = new int[5];
    }
    bool isEmpty() // to check if stack is empty
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull() // to check if stack is full 
    {
        // cout<<"is full"<<endl;
        // cout<<"top : "<<top<<"  range : "<<range<<endl;
        if (top == size - 1)
            return false;
        else
            return true;
    }
    void peek() // to return the element on the top of the stack
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
            cout << "Item on top : " << ptr[top] << endl;
    }
    void push(int n)
    {
        if (isFull())
        {
            top++;
            ptr[top] = n; // in the ptr add add position of top i.e (-1)++
            cout << "Item Pushed on stack :" << n << endl;
            // cout<<"top : "<<top<<"  range : "<<range<<endl;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void print()
    {
        cout << "Items In Stack : " << endl;
        for (int i = top; i >= 0; i--)
            cout << "\t[ " << i << " ] : " << ptr[i] << endl;
    }
    void pop() // to remove the top element from stack.
    {
        int n;
        if (top != -1)
        {
            n = ptr[top];
            top--;
            cout << "Item Poped from stack :" << n << endl;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int menu()
    {
        int choice;
        cout << "------------------------------";
        cout << "\n\tMenu:\n\t1.Push()\n\t2.Pop()\n\t3.Peek()\n\t4.Print()\n\t5.Exit\nEnter Choice : ";
        cin >> choice;
        return choice;
    }

    ~Stack()
    {
        delete[] ptr;
        ptr = NULL;
    }
};
int main()
{
    Stack s(5);
    int choice, n;
    while ((choice = s.menu()) != 5)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Item to push : ";
            cin >> n;
            s.push(n);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.print();
            break;
        default:
            cout << "Enter a valid choice !" << endl;
        }
    }
};