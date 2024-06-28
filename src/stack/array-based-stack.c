#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5

typedef struct {
    int data[STACK_SIZE];
    int size;
} Stack;

/**
 *  @brief 스택에 데이터를 추가합니다.
 *  
 *  @param stack
 *  스택의 주소
 *  @param data
 *  스택에 추가할 데이터 값
 *  
 *  @return void
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 함수 종료
 *  @exception stack이 가득 찬 경우
 *  "Error: Stack is full." 출력 후 함수 종료
 */
void push(Stack* stack, int data) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return;
    }
    if( stack->size == STACK_SIZE ) {
        printf("Error: Stack is full.\n");
        return;
    }

    stack->data[stack->size++] = data;
}

/**
 *  @brief 스택에 마지막으로 추가한 데이터를 가져오고, 스택에서 해당 데이터를 제거합니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return int
 *  스택에 마지막으로 추가한 데이터
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 -1 반환
 *  @exception stack이 비어있는 경우
 *  "Error: Stack is empty." 출력 후 -1 반환
 */
int pop(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return -1;
    }
    if( stack->size == 0 ) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    return stack->data[--stack->size];
}

/**
 *  @brief 스택에 마지막으로 추가한 데이터를 가져옵니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return int
 *  스택에 마지막으로 추가한 데이터
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 -1 반환
 *  @exception stack이 비어있는 경우
 *  "Error: Stack is empty." 출력 후 -1 반환
 */
int peek(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return -1;
    }
    if( stack->size == 0 ) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    return stack->data[stack->size - 1];
}

/**
 *  @brief 스택이 비어있는지 여부를 반환합니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return bool
 *  스택이 비어있으면 true, 비어있지 않으면 false 반환
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 false 반환
 */
bool is_empty(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return false;
    }

    return stack->size == 0;
}

/**
 *  @brief 스택이 가득 찼는지 여부를 반환합니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return bool
 *  스택이 가득 찼으면 true, 가득 차지 않았으면 false 반환
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 false 반환
 */
bool is_full(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return false;
    }

    return stack->size == STACK_SIZE;
}

/**
 *  @brief 스택을 비웁니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return void
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 함수 종료
 */
void clear(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return;
    }

    stack->size = 0;
}

/**
 *  @brief 스택의 데이터들을 출력합니다.
 *  
 *  @param stack
 *  스택의 주소
 *  
 *  @return void
 *  
 *  @exception stack이 NULL인 경우
 *  "Error: Stack is NULL." 출력 후 함수 종료
 */
void print(Stack* stack) {
    if( stack == NULL ) {
        printf("Error: Stack is NULL.\n");
        return;
    }

    printf("Array Based Stack(size %d, capacity %d): ", stack->size, STACK_SIZE);
    for( int i = 0; i < stack->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", stack->data[i]);
    }
    printf("\n");
}

int main(void) {
    // 스택 생성
    Stack stack;
    stack.size = 0;

    // push 테스트
    for( int i = 0; i < 6; i++ ) {
        printf("push data %d > ", i);
        push(&stack, i);
        print(&stack);
    }

    // is_empty 테스트
    printf("Stack is empty > %s\n", is_empty(&stack)? "yes" : "no");
    // is_full 테스트
    printf("Stack is full > %s\n", is_full(&stack)? "yes" : "no");

    // peek 테스트
    printf("peek data > %d\n", peek(&stack));

    // pop 테스트
    for( int i = 0; i < 2; i++ ) {
        printf("pop data > %d\n", pop(&stack));
        print(&stack);
    }

    // clear 테스트
    printf("clear stack > ");
    clear(&stack);
    print(&stack);

    // is_empty 테스트
    printf("Stack is empty > %s\n", is_empty(&stack)? "yes" : "no");
    // is_full 테스트
    printf("Stack is full > %s\n", is_full(&stack)? "yes" : "no");

    return 0;
}
