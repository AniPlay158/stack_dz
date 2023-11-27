#include <iostream>
using namespace std;

class DynamicArrayStack 
{
private:
    int* ar;
    int capacity;
    int top;

public:
  
    DynamicArrayStack(int size) 
    {
        capacity = size;
        ar = new int[capacity];
        top = -1; 
    }

    ~DynamicArrayStack() 
    {
        delete[] ar;
    }

    bool IsEmpty() const
    {
        return top == 0;
    }

    bool IsFull() const
    {
        return top == capacity - 1;
    }

    void Push(int value) 
    {
        if (IsFull()) 
        {
            cout << "The stack is full. Cannot add element.\n";
            return;
        }
        ar[++top] = value;
    }

    void Pop()
    {
        if (IsEmpty()) 
        {
            cout << "The stack is empty. The item cannot be deleted.\n";
            return;
        }
        --top;
    }

    int Peek() 
    {
        if (IsEmpty()) 
        {
            cout << "The stack is empty. There is no top.\n";
            return -1;
        }
        else
            return ar[top];
    }

    bool Contains(int value) 
    {
        for (int i = 0; i <= top; ++i) 
        {
            if (ar[i] == value) 
            {
                return true;
            }
        }
        return false;
    }

    void print() {
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    srand(time(0));
    DynamicArrayStack stack(5);
    while (!stack.IsFull())
        stack.Push(rand() % 90 + 10);

    stack.print();

    cout << "//////////\n";

    cout << "Top of the stack: " << stack.Peek() << endl;
    stack.Pop();
    cout << "Top of the stack after removing an element: " << stack.Peek() << endl;

    int search_value = 44;
    if (stack.Contains(search_value)) {
        cout << "Element " << search_value << " found on the stack.\n";
    }
    else {
        cout << "Element " << search_value << " not found on the stack.\n";
    }

    stack.print();
}