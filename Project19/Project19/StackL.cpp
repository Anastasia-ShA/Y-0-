#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;

struct Single_List {
    int Data;
    Single_List* Next;
};

void Make_Single_List(int n, Single_List** Head) {
    if (n > 0) {
        (*Head) = new Single_List();
        cout << "Введите значение: ";
        cin >> (*Head)->Data;
        (*Head)->Next = NULL;
        Make_Single_List(n - 1, &((*Head)->Next));
    }
}

void Print_Single_List(Single_List* Head) {
    if (Head != NULL) {
        cout << Head->Data << "\t";
        Print_Single_List(Head->Next);
    }
    else cout << "\n";
}

bool IsOrdered(Single_List* Head) {
    if (Head == NULL || Head->Next == NULL)
        return true;

    bool vozrastanie = true;
    bool ybivanie = true;
    Single_List* current = Head;

    while (current->Next != NULL) {
        if (current->Data > current->Next->Data)
            vozrastanie = false;
        if (current->Data < current->Next->Data)
            ybivanie = false;
        current = current->Next;
    }

    return vozrastanie || ybivanie;
}

Single_List* RemoveNegatives(Single_List* Head) {
    Single_List* current = Head;
    Single_List* prev = NULL;

    while (current != NULL) {
        if (current->Data < 0) {
            if (prev == NULL) {
                Head = current->Next;
                delete current;
                current = Head;
            }
            else {
                prev->Next = current->Next;
                delete current;
                current = prev->Next;
            }
        }
        else {
            prev = current;
            current = current->Next;
        }
    }

    return Head;
}

int main() {
    setlocale(0, "Russian");
    Single_List* Head = NULL;
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    Make_Single_List(n, &Head);

    cout << "Список: ";
    Print_Single_List(Head);

    if (IsOrdered(Head)) {
        cout << "Список упорядочен.\n";
    }
    else {
        cout << "Список не упорядочен.\n";
    }

    Head = RemoveNegatives(Head);
    cout << "Список после удаления отрицательных элементов: ";
    Print_Single_List(Head);

    return 0;
}