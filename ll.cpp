#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node (int data, Node* next){
        this->data=data;
        this->next=next;
    }
    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

Node* deleteHead(Node* head){
    if(head==NULL) return head;

    Node* temp=head;
    head=head->next;
    delete temp;

    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

Node* deleteKthEle(Node* head, int k){
    if(head==NULL) return head;

    if(k==1){
        // Node* temp=head;
        // head=head->next;
        // delete temp;
        // return head;
        deleteHead(head);
    }
    else{
        Node* pre=NULL;
        Node* temp=head;
        int count=1;
        while(temp!=NULL){
            if(count==k){
                pre->next=pre->next->next;
                delete temp;
                break;
            }
            count++;
            pre=temp;
            temp=temp->next;
        }
        return head;
    }
}

Node* deleteByVal(Node* head, int val){
    if(head==NULL) return head;

    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    else{
        Node* pre=NULL;
        Node* temp=head;
        int count=1;
        while(temp!=NULL){
            if(temp->data==val){
                pre->next=pre->next->next;
                delete temp;
                break;
            }
            count++;
            pre=temp;
            temp=temp->next;
        }
        return head;
    }
}

Node* insertAtHead(Node* head, int val){
    // Node* temp=new Node(val, head);
    // return temp;
    return new Node(val, head);
}

Node* insertAtLast(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        Node* newNode=new Node(val);
        temp->next=newNode;
        return head;
    }
}

Node* insertAtKthEle(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val,head);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(val, head);
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* newNode=new Node(val, temp->next);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    } 
    return head;
}

//~ insert before the value of x
Node* insertBeforeVal(Node* head, int val, int x){
    if(head==NULL){
        return NULL;
    }
    if(head->data==x){
        return new Node(val, head);
    }
    Node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* newNode=new Node(val, temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int lengthOfLL(Node* head){
    Node* temp=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

int search(Node* head, int key){
    Node* temp=head;
    while(temp){
        if(temp->data==key) return 1;
        temp=temp->next;
    }
    return 0;
}


Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main() {
    Node* head = nullptr;
    int choice;
    int value, k, x;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Last" << endl;
        cout << "3. Insert at Kth Element" << endl;
        cout << "4. Insert Before Value" << endl;
        cout << "5. Delete Head" << endl;
        cout << "6. Delete Tail" << endl;
        cout << "7. Delete Kth Element" << endl;
        cout << "8. Delete by Value" << endl;
        cout << "9. Print Linked List" << endl;
        cout << "10. Length of Linked List" << endl;
        cout << "11. Search" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                head = insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                head = insertAtLast(head, value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> k;
                head = insertAtKthEle(head, value, k);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value before which to insert: ";
                cin >> x;
                head = insertBeforeVal(head, value, x);
                break;
            case 5:
                head = deleteHead(head);
                break;
            case 6:
                head = deleteTail(head);
                break;
            case 7:
                cout << "Enter position of element to delete: ";
                cin >> k;
                head = deleteKthEle(head, k);
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                head = deleteByVal(head, value);
                break;
            case 9:
                print(head);
                break;
            case 10:
                cout << "Length of Linked List: " << lengthOfLL(head) << endl;
                break;
            case 11:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(head, value)) {
                    cout << "Found" << endl;
                } else {
                    cout << "Not Found" << endl;
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
