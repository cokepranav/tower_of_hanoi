// tower hanoi can be expanded to 3 parts or movements 1st= movement from/between source and dest
// 2nd movement between source and auxilary
//3rd is between auxilary and destination
#include <bits/stdc++.h>
typedef long long lli;
#define rep(i, a, b) for (i = a; i < b; i++)
using namespace std;

class Stack
{
private:
    vector<lli> items;
    lli capacity;
    lli top;

public:
    Stack(lli size)
    {
        capacity = size;
        items.resize(size);
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(lli value)
    {
        if (top == capacity - 1)
        {
            cout << "stack overflow!" << endl;
        }
        items[++top] = value;
    }

    int peek()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return items[top];
    }

    void pop()
    {
        if (isEmpty())
            return;
        top--;
    }
};

void moveDisk(char from, char to, lli disk)
{
    cout << "Move the disk " << disk << " from " << from << " to " << to << endl;
}

void move(Stack &src, Stack &des, char s, char d)
{
    lli top1 = src.peek();
    src.pop();
    lli top2 = des.peek();
    des.pop();
    if (top1 == INT_MIN)
    {
        src.push(top2);
        moveDisk(d, s, top2);
    }
    else if (top2 == INT_MIN)
    {
        des.push(top1);
        moveDisk(s, d, top1);
    }
    else if (top1 > top2)
    {
        src.push(top1);
        src.push(top2);
        moveDisk(d, s, top2);
    }
    else
    {
        des.push(top2);
        des.push(top1);
        moveDisk(s, d, top1);
    }
}

void towerOfHanoiIterative(lli noOfDisks, Stack &src, Stack &aux, Stack &des)
{
    lli i, noOfMoves = pow(2, noOfDisks) - 1;
    char s = 'S', a = 'A', d = 'D';
    if (noOfDisks % 2 == 0)
    {
        swap(a, d);
    }
    for (i = noOfDisks; i >= 1; i--)
    {
        src.push(i);
    }
    rep(i, 1, noOfMoves + 1)
    {
        if (i % 3 == 1)
        {
            move(src, des, s, d);
        }
        else if (i % 3 == 2)
        {
            move(src, aux, s, a);
        }
        else
        {
            move(aux, des, a, d);
        }
    }
}

int main()
{
    lli n = 2;
    Stack src = Stack(n);
    Stack aux = Stack(n);
    Stack des = Stack(n);

    towerOfHanoiIterative(n, src, aux, des);
    return 0;
}