#include <iostream>
#include "StackL.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void InitStack(StackL* s) {
	s->top = NULL;
}

int Push(StackL* s, double v) {   //��������� �� �������
	struct LE* p = (struct LE*)malloc(sizeof(struct LE));
	if (!p) return 0;
	p->next = s->top;
	p->v = v;
	s->top = p;
	return 1;
}

double Pop(StackL* s) {  //���������� �������
	struct LE* p;
	double x = 1e300;

	if (s->top) {
		p = s->top;
		s->top = s->top->next;
		x = p->v;
		free(p);
	}
	return x;
}



int IsEmptyStack(StackL const *s) {  //���� �� ����
	return s->top == NULL;
}

void Clear(StackL* s) {     //���� ���� �� ���� �� ������� �������
	while (!IsEmptyStack(s)) Pop(s);
}

void PrintStack(StackL const* s) { //������ �����
	struct LE* p;
	for (p = s->top; p; p = p->next)
		printf_s("%-7.3lf ", p->v);
}

void Destruct(StackL* s) {
	Clear(s);

}

int main() {
    StackL s;
    InitStack(&s);

    cout << "Enter number: ";
    char ch;
    int pos = 1;
    bool condition = true;


    while ((ch = cin.get()) != '\n') {
        if (isdigit(ch)) {
            double digit = ch - '0';
            Push(&s, digit);

            if ((pos % 2 == 1 && (int)digit % 2 != 0) ||
                (pos % 2 == 0 && (int)digit % 2 != 1)) {
                condition = false;
            }
            pos++;
        }
    }

    cout << "Reversed: ";
    while (!IsEmptyStack(&s)) {
        cout << Pop(&s);
    }
    cout << endl;


    cout << "Condition is " << condition << endl;

    Destruct(&s);
    return 0;
}