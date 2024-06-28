#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DoublyLinkedNode {
    int data;
    struct DoublyLinkedNode* prev;
    struct DoublyLinkedNode* next;
} DoublyLinkedNode;

typedef struct {
    DoublyLinkedNode* front;
    DoublyLinkedNode* rear;
    int size;
} Deque;

/**
 *  @brief 데이터를 가지고 있는 새로운 노드를 생성합니다.
 *
 *  @param data
 *  생성할 노드의 데이터 값
 *
 *  @return DoublyLinkedNode*
 *  data 값을 가진 이중 연결 노드의 주소
 *
 *  @exception 메모리 할당 실패 시
 *  "Error: Memory allocation is faild." 출력 후 NULL 반환
 */
DoublyLinkedNode* create_node(int data) {
    DoublyLinkedNode* new_node = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
    if( new_node == NULL ) {
        printf("Error: Memory allocation is faild.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

/**
 *  @brief 덱의 맨 앞에 데이터를 추가합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  @param data
 *  덱에 추가할 데이터 값
 *  
 *  @return void
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 함수 종료
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void push_front(Deque* deque, int data) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return;
    }

    DoublyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( deque->size == 0 ) {
        deque->rear = new_node;
    } else {
        new_node->next = deque->front;
        deque->front->prev = new_node;
    }
    deque->front = new_node;

    deque->size++;
}

/**
 *  @brief 덱의 맨 뒤에 데이터를 추가합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  @param data
 *  덱에 추가할 데이터 값
 *  
 *  @return void
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 함수 종료
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void push_rear(Deque* deque, int data) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return;
    }

    DoublyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( deque->size == 0 ) {
        deque->front = new_node;
    } else {
        new_node->prev = deque->rear;
        deque->rear->next = new_node;
    }
    deque->rear = new_node;

    deque->size++;
}

/**
 *  @brief 덱의 맨 앞 데이터를 가져오고, 덱에서 해당 데이터를 제거합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return int
 *  덱의 맨 앞 데이터
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 -1 반환
 *  @exception deque이 비어있는 경우
 *  "Error: Deque is empty." 출력 후 -1 반환
 */
int pop_front(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return -1;
    }
    if( deque->size == 0 ) {
        printf("Error: Deque is empty.\n");
        return -1;
    }

    DoublyLinkedNode* remove_node = deque->front;
    int ret_val = remove_node->data;

    if( deque->size == 1 ) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(remove_node);
    deque->size--;

    return ret_val;
}

/**
 *  @brief 덱의 맨 뒤 데이터를 가져오고, 덱에서 해당 데이터를 제거합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return int
 *  덱의 맨 뒤 데이터
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 -1 반환
 *  @exception deque이 비어있는 경우
 *  "Error: Deque is empty." 출력 후 -1 반환
 */
int pop_rear(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return -1;
    }
    if( deque->size == 0 ) {
        printf("Error: Deque is empty.\n");
        return -1;
    }

    DoublyLinkedNode* remove_node = deque->rear;
    int ret_val = remove_node->data;

    if( deque->size == 1 ) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(remove_node);
    deque->size--;

    return ret_val;
}

/**
 *  @brief 덱의 맨 앞 데이터를 가져옵니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return int
 *  덱의 맨 앞 데이터
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 -1 반환
 *  @exception deque이 비어있는 경우
 *  "Error: Deque is empty." 출력 후 -1 반환
 */
int peek_front(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return -1;
    }
    if( deque->size == 0 ) {
        printf("Error: Deque is empty.\n");
        return -1;
    }

    return deque->front->data;
}

/**
 *  @brief 덱의 맨 뒤 데이터를 가져옵니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return int
 *  덱의 맨 뒤 데이터
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 -1 반환
 *  @exception deque이 비어있는 경우
 *  "Error: Deque is empty." 출력 후 -1 반환
 */
int peek_rear(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return -1;
    }
    if( deque->size == 0 ) {
        printf("Error: Deque is empty.\n");
        return -1;
    }

    return deque->rear->data;
}

/**
 *  @brief 덱이 비어있는지 여부를 반환합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return bool
 *  덱이 비어있으면 true, 비어있지 않으면 false 반환
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 false 반환
 */
bool is_empty(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return false;
    }

    return deque->size == 0;
}

/**
 *  @brief 덱을 비웁니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return void
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 함수 종료
 */
void clear(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return;
    }

    DoublyLinkedNode* remove_node;
    DoublyLinkedNode* cur_node = deque->front;
    while( cur_node != NULL ) {
        remove_node = cur_node;
        cur_node = cur_node->next;

        free(remove_node);
    }

    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

/**
 *  @brief 덱의 데이터들을 출력합니다.
 *  
 *  @param deque
 *  덱의 주소
 *  
 *  @return void
 *  
 *  @exception deque가 NULL인 경우
 *  "Error: Deque is NULL." 출력 후 함수 종료
 */
void print(Deque* deque) {
    if( deque == NULL ) {
        printf("Error: Deque is NULL.\n");
        return;
    }

    printf("Deque(size %d): ", deque->size);
    
    DoublyLinkedNode* cur_node = deque->front;
    for( int i = 0; i < deque->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", cur_node->data);

        cur_node = cur_node->next;
    }
    printf("\n");
}

int main(void) {
    // 덱 생성
    Deque deque;
    deque.front = NULL;
    deque.rear = NULL;
    deque.size = 0;

    // push_front 테스트
    for( int i = 0; i < 3; i++ ) {
        printf("push data %d at front > ", i);
        push_front(&deque, i);
        print(&deque);
    }

    // push_rear 테스트
    for( int i = 9; i < 17; i++ ) {
        printf("push data %d at rear > ", i);
        push_rear(&deque, i);
        print(&deque);
    }

    // is_empty 테스트
    printf("Deque is empty > %s\n", is_empty(&deque)? "yes" : "no");

    // peek_front 테스트
    printf("peek data at front > %d\n", peek_front(&deque));

    // peek_rear 테스트
    printf("peek data at back > %d\n", peek_rear(&deque));

    // pop_front 테스트
    for( int i = 0; i < 5; i++ ) {
        printf("pop data at front > %d\n", pop_front(&deque));
        print(&deque);
    }

    // pop_rear 테스트
    for( int i = 0; i < 5; i++ ) {
        printf("pop data at rear > %d\n", pop_rear(&deque));
        print(&deque);
    }

    // clear 테스트
    printf("clear deque > ");
    clear(&deque);
    print(&deque);

    // is_empty 테스트
    printf("Deque is empty > %s\n", is_empty(&deque)? "yes" : "no");

    // peek_front 테스트
    printf("peek data at front > %d\n", peek_front(&deque));

    // peek_rear 테스트
    printf("peek data at back > %d\n", peek_rear(&deque));

    // pop_front 테스트
    for( int i = 0; i < 5; i++ ) {
        printf("pop data at front > %d\n", pop_front(&deque));
        print(&deque);
    }

    // pop_rear 테스트
    for( int i = 0; i < 5; i++ ) {
        printf("pop data at rear > %d\n", pop_rear(&deque));
        print(&deque);
    }

    return 0;
}
