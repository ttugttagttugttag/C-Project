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
void push(Stack *s, element * data);
element* pop(Stack *s);

int main() {
    int check;
    Stack s;
    char *data;
    char *search;

    initStack(&s);

    do {
        printf("계획 추가/제거 : 1, 계획 검색 : 2, 종료 : 3\n");
        scanf("%d", &check);

        if(check == 1) {
            printf("추가 또는 제거할 계획을 입력하세요.\n");
            scanf("%s", data);
            push(&s, data);
        }
        else if(check == 2){
            printf("검색 할 계획을 입력하세요.\n");
            scanf("%s", search);
        }
        else if(check != 3) {
            printf("잘못된 메세지 입니다.\n");
        }
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

void push(Stack *s, element * data) {
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    for (int i = 0; i < strlen(data); ++i) {
        s->data[++s->top][i] = data[i];
    }
}

element* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("계획을 추가 할 수 있습니다.");
        return 0;
    }
    return s->data[s->top--];
}