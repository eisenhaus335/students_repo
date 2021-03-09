#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;


struct Node {
    char data[10];
    Node* next;
    Node* prev;
};

Node *temp, *head = NULL, *ptr = NULL, *last = NULL;

void printAll(Node* center) {
    do {
        cout << "cell: " << ptr << " " << ptr->data << " " << ptr->next << endl;
        ptr = ptr->next;
    } while(ptr != NULL && ptr != center);
}
void find(char* data) {
    ptr = head;
    do {
        if(ptr->next == NULL) break;

        if(!strcmp(data, ptr->data)) break;
        last = ptr;
        ptr = ptr->next;
    } while(ptr != NULL);
}

void printNext(Node* node) {
    ptr = node;
    do {
        cout << "cell: " << ptr << " " << ptr->data << " " << ptr->next << endl;
        ptr = ptr->next;
    } while(ptr != NULL && ptr != node);
}

void printPrev(Node* node) {
    ptr = node;
    do {
        cout << "cell: " << ptr << " " << ptr->data << " " << ptr->next << endl;
        ptr = ptr->prev;
    } while(ptr != NULL && ptr != node);
}

int main() {
    char masukan[10];
    
    do {
        cout << "Input Data: "; fgets(masukan, sizeof(masukan), stdin);
        if(masukan[0] == '\n' || masukan[0] == ' ') break;

        temp = (struct Node *) malloc(sizeof(struct Node));
        
        strcpy(temp->data, masukan);
        temp->next = NULL;
        temp->prev = NULL;
        
        if(head == NULL) {
            head = temp;
            last = temp;
        } else {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
    } while(strlen(masukan) > 0);

    cout << "Data Cetak Maju: " << endl; 
    printNext(head);
    cout << endl;
    cout << "Data Cetak Mundur: " << endl;
    printPrev(last);
    cout << endl;

    return 0;
}
