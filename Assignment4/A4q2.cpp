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
        ptr = new int[num];
    }
    Stack()
    {
        top = -1;
        size = 5;
        ptr = new int[5];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        // cout<<"is full"<<endl;
        // cout<<"top : "<<top<<"  range : "<<range<<endl;
        if (top == size - 1)
            return false;
        else
            return true;
    }
    void peek()
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
            cout << "Item on top : " << ptr[top] << endl;
    }
    void push(int n)
    {
        // cout<<"Hallo"<<endl;
        if (isFull())
        {
            top++;
            ptr[top] = n;
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
    void pop()
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