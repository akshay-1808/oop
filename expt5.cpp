#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Linklist
{
private:
    Node *head;
    Node *createNode()
    {
        Node *newnode;
        newnode = new Node();
        // newnode->data=data;
        return newnode;
    }
    void initNode(Node *nd, int data)
    {
        nd->data = data;
        nd->next = NULL;
    }

public:
    Linklist()
    {
        head = NULL;
    }
    ~Linklist()
    {
        Node *temp, *t;
        temp = head;
        while (temp->next != NULL)
        {
            t = temp;
            temp = temp->next;
            delete t;
        }
    }
    void addBeg(int data)
    {
        Node *newnode;
        newnode = createNode();
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void addEnd(int data)
    {
        Node *newnode, *current;
        newnode = createNode();
        current = head;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
        }
    }
    Node *deleteBeg()
    {
        Node *temp;
        temp = head;
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            head = head->next;
            // temp->next=NULL;
            // return temp;
            delete temp;
            return temp;
        }
    }
    Node *deleteEnd()
    {
        Node *curr, *prev;
        curr = head;
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            // prev->next=NULL;
            // return curr;
            delete curr;
        }
    }
    void traverse()
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    Node *search(int key)
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};
int main()
{
    int ch, data, key, ans;
    Linklist l1;

    while (1)
    {
        cout << "1.Add begin" << endl
             << "2.Add end" << endl
             << "3.Delete begin" << endl
             << "4.Delete end" << endl
             << "5.Traverse" << endl
             << "6.Search" << endl
             << "7.Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter data to add in list:";
            cin >> data;
            l1.addBeg(data);
            break;
        case 2:
            cout << "enter data to add in list:";
            cin >> data;
            l1.addEnd(data);
            break;
        case 3:
            l1.deleteBeg();
            break;
        case 4:
            l1.deleteEnd();
            break;
        case 5:
            l1.traverse();
            break;
        case 6:
            cout << "Enter the key to search:";
            cin >> key;
            if (l1.search(key))
            {
                cout << "Key found in the list." << endl;
            }
            else
            {
                cout << "Key not found in the list." << endl;
            }
        }
    }

    return 0;
}