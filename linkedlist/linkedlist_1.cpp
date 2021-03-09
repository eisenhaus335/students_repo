#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Node {
    char data[10];
    Node* next;
};

Node *temp, *head = NULL, *ptr = NULL;

//Sihir Fungsi Rekursif
Node* insertNext(Node* node, Node *next) {
    node->next = next;
    ptr = next;
}

Node* locate(char *data, Node* node) {
    if(node == NULL) return NULL;
    if(strcmp(data, node->data)) locate(data, node->next);
    
    else return node;
}

void printNode(Node* node) {
    cout << "cell: " << ptr << " " << ptr->data << " " << ptr->next << endl;
}

Node* printNext(Node* node) {
    printNode(node);
    ptr = node->next;
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
        } else insertNext(ptr, temp);
    } while(strlen(masukan) > 0);
    
    if(head == NULL) return 0;

    ptr = head;
    while(ptr != NULL) printNext(ptr);
    
    do {
        cout << "Data yang anda cari: "; fgets(masukan, sizeof(masukan), stdin);
        ptr = locate(masukan, head);
        
        if(ptr == NULL) {
            //Harus nya throw error tapi karena malas urus try catch jadi tulis aja Not Found
            cout << "Not Found" << endl;
            break;
        }
        printNode(ptr);
    } while(strlen(masukan) > 0);
    
    return 0;
}
