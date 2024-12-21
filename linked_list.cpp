#include "linked_list.h"

goods* makeNode(int x, int y, string a, string b, string c) {
    goods* newNode = new goods();
    newNode->setid(x);
    newNode->setquantity(y);
    newNode->setname(a);
    newNode->setentry_date(b);
    newNode->setexpired_date(c);
    newNode->next = NULL;
    return newNode;
}

void print_data(goods* head) {
    while (head != NULL) {
        int i = 1;
        cout << " | Serial: " << i;
        cout << " | Name: " << head->getname();
        cout << " | ID: " << head->getid();
        cout << " | Quantity: " << head->getquantity();
        cout << " | Entry date: " << head->getentry_date();
        cout << " | Expired date: " << head->getexpired_date();
        cout << " | Storage time: " << head->getstorage_time();
        cout << " | Time to exp: " << head->gettime_to_exp() << endl;
        head = head->next;
        i++;
    }
}

int size(goods* head) {
    int n = 0;
    while (head != NULL) {
        n++;
        head = head->next;
    }
    return n;
}

void find(goods*& head, int x) {
    goods* temp = head;
    while (temp->getid() != x) {
        temp = temp->next;
    }
    cout << " | Name: " << temp->getname();
    cout << " | ID: " << temp->getid();
    cout << " | Quantity: " << temp->getquantity();
    cout << " | Entry date: " << temp->getentry_date();
    cout << " | Expired date: " << temp->getexpired_date();
    cout << " | Storage time: " << temp->getstorage_time();
    cout << " | Time to exp: " << temp->gettime_to_exp() << endl;
}

void pushTop(goods*& head, int x, int y, string a, string b, string c) {
    goods* newNode = makeNode(x, y, a, b, c);
    newNode->next = head;
    head = newNode;
}

void popTop(goods*& head) {
    if (head == NULL) {
        return;
    }
    goods* temp = head;
    head = head->next;
    delete temp;
}

void popMid(goods*& head, int position) {
    int n = size(head);
    if (position < 1 || position > n + 1) {
        return;
    }
    if (position == 1) {
        popTop(head);
        return;
    }
    goods* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    goods* erase = temp->next;
    temp->next = erase->next;
    delete erase;
}

void edit(goods*& head, int id) {
    goods* temp = head;
    while (temp != NULL && temp->getid() != id) {
        temp = temp->next;
    }

    int choice;
    cout << "Enter number you want to edit (1-5): ";
    cout << "1. Name: " << temp->getname() << endl;
    cout << "2. Quantity: " << temp->getquantity() << endl;
    cout << "3. Entry Date: " << temp->getentry_date() << endl;
    cout << "4. Expired Date: " << temp->getexpired_date() << endl;
    cin >> choice;
    switch (choice) {
    case 1: {
        string newName;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        temp->setname(newName);
        break;
    }
    case 2: {
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        temp->setquantity(newQuantity);
        break;
    }
    case 3: {
        string newEntryDate;
        cout << "Enter new entry date (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, newEntryDate);
        temp->setentry_date(newEntryDate);
        break;
    }
    case 4: {
        string newExpiredDate;
        cout << "Enter new expired date (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, newExpiredDate);
        temp->setexpired_date(newExpiredDate);
        break;
    }
    }
}