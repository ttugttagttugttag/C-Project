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
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("    계획 추가 : 1, 계획 확인 : 2, 종료 : 3     \n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("수행할 목록을 선택하세요 : ");
        scanf("%d", &check);

        if(check == 1) {
            printf("추가할 계획을 입력하세요 : ");
            push(&s);
        }
        else if(check == 2){
            printf("완료한 계획을 입력하세요.\n");
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
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    scanf("%s", s->data[++s->top]);
}

element* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("계획을 추가 할 수 있습니다.");
        return 0;
    }

    return s->data[s->top--];
}

// 모든 계획 출력
void printStack(Stack *s){
    printf("현재 계획\n");
    for (int i = 0; i <= s->top; ++i) {
        printf("");
        printf("%s\n", s->data[i]);
    }
}