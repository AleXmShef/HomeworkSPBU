#include <iostream>
#include <string>

using namespace std;

struct node {
    int data;
    node *next = nullptr;
};

class Stack {
public:
    Stack (int a) {
        head=new node;
        head->data=a;
        head->next=NULL;
    }

    ~Stack() {
        while (head!=NULL){
            node* temp=head;
            head=head->next;
            delete temp;
        }
    }

    void push(int a) {
        if (head!=NULL){
            node* temp=new node;
            temp->data=a;
            temp->next=head;
            head=temp;
        }
    }

    int pop() {
        if (head!=NULL){
            node* temp=head;
            head=head->next;
            int a=temp->data;
            delete temp;
            return a;
        }
        else
            return NULL;
    }

    int top() {
        return head->data;
    }

public:
    node* head;
};
