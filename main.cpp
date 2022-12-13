#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_SIZE 30
#define MAX_WORD 100
typedef char element;

typedef struct stack{
    int top;
    element data[MAX_SIZE][MAX_WORD];
}Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *data);
element* pop(Stack *s);
int search(char target[], Stack* s);
void printStack(Stack *s);
char search_data[21];
void checkStack(Stack *s);

int main() {
    int check, n = 0;
    char data[MAX_WORD];
    Stack s;

    initStack(&s);

    do {
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("    계획 추가 : 1, 계획 확인 : 2, 종료 : 3     \n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("수행할 목록을 선택하세요 : ");
        scanf("%d", &check);

        if(check == 1) {
            printf("추가할 계획을 입력하세요(최대 20글자) : ");
            scanf("%s", data);
            push(&s, data);
        }
        else if(check == 2){
            printf("완료한 계획을 입력하세요.\n");
            checkStack(&s);
        }
        else if(check != 3) {
            printf("잘못된 메세지 입니다.\n");
        }
        system("cls");
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

void push(Stack *s, char* data) {
    if (isFull(s)) {
        printf("더 이상 계획을 추가 할 수 없습니다.");
        return;
    }
    s->top++;
    for (int i = 0; (s->data[s->top][i] = data[i]); i++);
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
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("%s\n", s->data[i]);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    }
}

void checkStack(Stack *s){
    scanf("%s", search_data);
    char* datalist[MAX_SIZE];
    int j1 = 0;
    for (int i = 0; i <= s->top; ++i) {
        datalist[i] = pop(s);
        int i1 = strcmp(datalist[i], search_data);
        if (i1 == 0) {
            j1 = i-1;
            break;
        }

    }
    for (int i = j1; i >= 0; i--) {
        push(s, datalist[i]);
    }

}