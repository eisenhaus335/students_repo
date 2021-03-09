#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;


struct Node {
    char data[10];
    Node* next;

};

Node *temp, *head = NULL, *ptr = NULL, *last = NULL;

void printAll() {
    while(ptr != NULL) {
        cout << "cell: " << ptr << " " << ptr->data << " " << ptr->next << endl;
        ptr = ptr->next;
    }
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
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            ptr = head;
        } else {
            ptr->next = temp;
            ptr = temp;
        }
    } while(strlen(masukan) > 0);

    ptr = head;
    printAll();

    do {
        cout << "Data yang dihapus: "; fgets(masukan, sizeof(masukan), stdin);
        if(masukan[0] == '\n' || masukan[0] == ' ') break;

        ptr = head;
        find(masukan);

        if(last != NULL) last->next = ptr->next;
        if(ptr == head) head = ptr->next;
        delete ptr;

        ptr = head;
        printAll();
    } while(strlen(masukan) > 0);

    return 0;
}
