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
        maxElement = a;
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
            if (a > maxElement) {
                maxElement = a;
            }
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
        maxElement = 0;
        node* temp = head;
        for(;;) {
            if (temp->data > maxElement)
                maxElement = temp->data;
            if (temp->next == nullptr) break;
            else temp = temp->next;
        }
    }

    int getMaxElement() {
        return maxElement;
    }

public:
    node* head;
    int maxElement = 0;
};


int main()
{
    Stack MyStack();

	return 0;
}
