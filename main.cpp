#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30
typedef char element;

typedef struct stack{
    int top;
    element data[MAX_SIZE][100];
}Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s);
element* pop(Stack *s);
int search(char target[],stack* s);
void printStack(Stack *s);

int main() {
    int check;
    Stack s;
    char *search_data;

    initStack(&s);

    do {
        printf("계획 추가 : 1, 계획 제거 : 2, 종료 : 3\n");
        scanf("%d", &check);

        if(check == 1) {
            printf("추가 또는 제거할 계획을 입력하세요.\n");
            push(&s);
        }
        else if(check == 2){
            printf("검색 할 계획을 입력하세요.\n");
            scanf("%s", search_data);
        }
        else if(check != 3) {
            printf("잘못된 메세지 입니다.\n");
        }
        printStack(&s);

    } while(check != 3);
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

void push(Stack *s) {
    char * data;
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    scanf("%s", data);
    s->top++;
    if(search(data, s) != 1){
        strcpy(s->data[s->top] , data);
    }

    // 저장할 계획 입력
}

void push2(Stack *s,char data[]) {
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    strcpy(s->data[++s->top],data);
}

element* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("계획을 추가 할 수 있습니다.");
        return 0;
    }

    return s->data[s->top--];
}

int search(char target[],stack* s){
    element* NS;
    NS = pop(s);
    if(strcmp(target,NS) == 0){
        return 1;
    }
    search(target,s);
    push2(s,target);

}

// 모든 계획 출력
void printStack(Stack *s){
    printf("현재 계획\n");
    for (int i = 0; i <= s->top; ++i)
        printf("%s\n", s->data[i]);
}