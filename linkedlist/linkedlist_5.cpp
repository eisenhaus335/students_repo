#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;


struct Node {
    char data[10];
    Node* next;

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
int main() {
    char masukan[10];
    
    do {
        cout << "Input Data: "; fgets(masukan, sizeof(masukan), stdin);
        if(masukan[0] == '\n' || masukan[0] == ' ') break;

        temp = (struct Node *) malloc(sizeof(struct Node));
        
        strcpy(temp->data, masukan);
        temp->next = head;

        if(head == NULL) {
            head = temp;
            head->next = head;
            ptr = head;
        } else {
            ptr->next = temp;
            ptr = temp;
        }
    } while(strlen(masukan) > 0);

    ptr = head;
    printAll(ptr);

    do {
        cout << "Cari Nama: "; fgets(masukan, sizeof(masukan), stdin);
        if(masukan[0] == '\n' || masukan[0] == ' ') break;

        find(masukan);
        printAll(ptr);
    } while(strlen(masukan) > 0);

    return 0;
}
