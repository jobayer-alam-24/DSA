#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node * next;
        Node * prev;
    Node(int value)
    {
        val = value;
        next = NULL;
        prev = NULL;
    }
};
class myQueue
{
    private:
        Node * head = NULL, * tail = NULL;
        int size = 0;
    public:
        void push(int value)
        {
            Node * newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
                size++;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
        }
        void pop()
        {
            int qSize = getSize(); 
            if(qSize == 0) return;
            if(qSize == 1)
            {
                delete head;
                head = NULL;
                tail = NULL;
                size--;
                return;
            }
            Node * delNode = head;
            head = head->next;
            head->prev = NULL;
            delete delNode;
            size--;
        }
        int front()
        {
            if(getSize() == 0) return -1;
            return head->val;
        }
        int getSize()
        {
            return size;
        }
        bool empty()
        {
            if(getSize() == 0) return true;
            return false;
        }
};
class myStack
{
    private:
        Node * head = NULL, * tail = NULL;
        int size = 0;
    public:
        void push(int value)
        {
            Node * newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
                size++;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
        }
        void pop()
        {
            if(getSize() == 0) return;
            Node * delNode = tail;
            tail = tail->prev;
            if(tail == NULL) head = NULL;
            delete delNode;
            size--;
        }
        int top()
        {
            if(getSize() == 0) return -1;
            return tail->val;
        }
        int getSize()
        {
            return size;
        }
        bool empty()
        {
            if(getSize() == 0) return true;
            return false;
        }
};
int main() {
    // Stack & Queue Implementaion using Doubly Linked List
    myStack s;
    myQueue q;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
