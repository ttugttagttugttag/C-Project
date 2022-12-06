#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30
typedef char element;

typedef struct stack{
    int top;
    element data[MAX_SIZE][100];
}Stack;

int main() {

}

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, element * data) {
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    for (int i = 0; i < strlen(data); ++i) {
        s->data[++s->top][i] = data[i];
    }
}

element* pop(Stack *s){
    if (isEmpty(s)) {
        printf("계획을 추가 할 수 있습니다.");
        return 0;
    }
    return s->data[s->top--];
}