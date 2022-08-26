#include <iostream>
#include <cstring>

using namespace std;
struct Node {
    int rollNum;
    int marks;
    char name[20];
    struct Node *pointer;
};
Node* create();

Node *insert_beg(Node *head);
Node *insert_end(Node *head);
Node *insert_bet(Node *head, int position);
Node *delete_node(Node *head, int position);
void searchNode(Node *head, int roll);
void searchNodeByMarks(Node *head,int marks);

Node* create(){
    Node *p;
    int rollNum;
    int marks;
    char name[20];
    cout<<"Enter details :: \n \n";
    cout<<"Enter rollNum :";
    cin >> rollNum;
    cout<<"Enter marks :";
    cin >> marks;
    cout<<"Enter Name :";
    cin>>name;
    p = new Node;
    p->rollNum = rollNum;
    p->marks = marks;
    strcpy(p->name,name);
    p->pointer = NULL;
    return p;
}

void display(Node* head){
    Node *p;
    p = head;
    int i = 1;
    cout<<'\n'<<"Serial Number" << "\t\tRoll Num" << "\t\t" << "Marks" <<"\t\t"<< "Name"<<'\n';
    do{
        cout<<"\n   "<< i<<"\t\t\t"<< p->rollNum << "\t\t\t  " << p->marks <<"\t\t"<< p->name;
        p = p->pointer;
        i++;
    }while(p != NULL );
    cout<<endl;
}
void searchNode(Node *head, int roll){
    Node *node = head,*result = NULL ;
    while(node != NULL){
        if (roll == node->rollNum){
            result = node;
        }
        node = node->pointer;
    }
    node = head;
    int i = 1;
    while(node != NULL){
        if (node == result){
            cout<<'\n'<<"Serial Number" << "\t\tRoll Num" << "\t\t" << "Marks" <<"\t\t"<< "Name"<<'\n';
            cout<<"\n   "<< i<<"\t\t\t"<< node->rollNum << "\t\t\t  " << node->marks <<"\t\t"<< node->name;
        }
        node = node->pointer;
        i++;
    }

}
void searchNodeByMarks(Node *head,int marks){
    Node *node = head;
    bool flag = false ;
    int counter = 1;
    cout<<'\n'<<"Serial Number" << "\t\tRoll Num" << "\t\t" << "Marks" <<"\t\t"<< "Name"<<'\n';
    while(node != NULL) {
        if(node->marks == marks){
            cout<<"\n   "<< counter<<"\t\t\t"<< node->rollNum << "\t\t\t  " << node->marks <<"\t\t"<< node->name;
        }
        counter++;
        node = node->pointer;
    }
    cout<<'\n';

}
Node* delete_node(Node *head, int position){
    Node *prev = head,*node = head;
    int prevCounter = 0;
    int counter = 1;
    if(position > 1){
        while(counter < position){
            node = node->pointer;
            if(counter > 1){
                prev = prev->pointer;
                prevCounter++;
            }
            counter++;
        }
        prev->pointer = node->pointer;
        delete(node);
    }
    else if(position == 1){
        head = head->pointer;
        delete(node);
    }
    else{
        cout<<"Invalid position entered!";
    }
    return head;


}

Node* insert_beg(Node *head) {
    Node *node;
    node = create();
    node->pointer = head;
    return node;
}

Node* insert_end(Node *head){
    Node *p,*node;
    node = create();
    p = head;
    while(p->pointer != NULL){
        p = p->pointer;
    }
    p->pointer = node;
    return head;
}

Node* insert_bet(Node *head, int position){
    Node *p,*node,*prev;
    node = create();
    p = head;
    prev = head;
    int prevCounter = 0, counter = 1;
    while(counter < position){
        p = p->pointer;
        if (counter > 1){
            prev = prev->pointer;
            prevCounter++;
        }
        counter++;
    }
    prev->pointer = node;
    node->pointer = p;
    return head;
}


int main() {
    Node *head;
    head = create();
    int input = -1;
    while (input != 0){
        cout<<"\n0. Exit \n";
        cout<<"1. Insert \n";
        cout<<"2. Display \n";
        cout<<"3. Delete \n";
        cout<<"4. Search \n";
        cin>>input;
        switch(input){
            case 1:
                int input1;
                cout<<"\n0. Exit \n";
                cout<<"1. Insert at begging \n";
                cout<<"2. Insert in between \n";
                cout<<"3. Insert at the end \n";
                cin>>input1;
                switch(input1){
                    case 0:
                        break;
                    case 1:
                        head = insert_beg(head);
                        break;
                    case 2:
                        int position;
                        cout<<"Enter the position to input the entry ";
                        cin>>position;
                        head = insert_bet(head,position);
                        break;
                    case 3:
                        insert_end(head);
                        break;
                }
                break;
            case 2:
                display(head);
                break;
            case 0 :
                break;
            case 3:
                int position;
                cout<<"Enter the position to be deleted :";
                cin>>position;
                delete_node(head,position);
                break;
            case 4:
                int input2;
                cout<<"Search by \n";
                cout<<"1. Roll Number \n";
                cout<<"2. Marks \n";
                cin>>input2;
                switch(input2){
                    case 1:
                        int roll;
                        cout<<"Enter the roll number to be searched : ";
                        cin>>roll;
                        searchNode(head, roll);
                        break;
                    case 2:
                        int marks;
                        cout<<"Enter the roll number to be searched : ";
                        cin>>marks;
                        searchNodeByMarks(head,marks);
                        break;
                }

        }
    }

    return 0;
}
