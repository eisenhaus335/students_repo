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
Node* insertNext(Node* node, Node* next) {
    next->next = node->next;
    node->next = next;
    
    return next;
}


//Fungsi nya bergantung pada lokasi locate. Jadi ada ketergantungan terhadap algoritma locate untuk step-1 agar insertBefore bekerja dengan baik
Node* insertBefore(Node* node, Node* next) {
    if(node == head || node == NULL) {
        head = next;
        next->next = node;
        return next;
    }
    next->next = node->next;
    node->next = next;
    
    return next;
}

//Trik javascript atau Rust. Passing parameter lewat function. 'last' menyimpan node yang lalu
Node* locate(char *data, Node* last, Node* node) {
    if(node == NULL) return NULL;
    
    if(!strcmp(data, node->data)) {
        if(last != NULL) return last;
        return node;
    }
    return locate(data, node, node->next);
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
            cout << "[==Membuat Head Baru==]" << endl;
        } else {
            ptr->next = temp;
            ptr = ptr->next;
        }
    } while(strlen(masukan) > 0);
    
    if(head == NULL) return 0;

    ptr = head;
    while(ptr != NULL) printNext(ptr);
    
    do {
        cout << "Data yang anda cari: "; fgets(masukan, sizeof(masukan), stdin);

        if(masukan[0] == '\n' && masukan[0] == ' ') break;

        ptr = locate(masukan, NULL, head);
        if(ptr == NULL) {
            cout << "Not Found";
            continue;
        }

        char data[10]; 
        cout << "Data yang disisipkan: "; fgets(masukan, sizeof(masukan), stdin);

        temp = (struct Node *) malloc(sizeof(struct Node));
        
        strcpy(temp->data, masukan);
        temp->next = NULL;
  
        insertBefore(ptr, temp);

        ptr = head;
        while(ptr != NULL) printNext(ptr);
    } while(strlen(masukan) > 0);
    
    return 0;
}
