#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SinglyLinkedNode {
    int data;
    struct SinglyLinkedNode* next;
} SinglyLinkedNode;

typedef struct {
    SinglyLinkedNode* front;
    SinglyLinkedNode* rear;
    int size;
} Queue;

/**
 *  @brief 큐에 데이터를 추가합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  @param data
 *  큐에 추가할 데이터 값
 *  
 *  @return void
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 함수 종료
 *  @exception 새로운 노드 메모리 할당 실패 시
 *  "Error: Memory allocation is faild." 출력 후 함수 종료
 */
void enqueue(Queue* queue, int data) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return;
    }

    SinglyLinkedNode* new_node = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if( new_node == NULL ) {
        printf("Error: Memory allocation is faild.\n");
        return;
    }
    
    new_node->data = data;
    new_node->next = NULL;

    if( queue->size == 0 ) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;

    queue->size++;
}

/**
 *  @brief 큐에 먼저 추가한 데이터를 가져오고, 큐에서 해당 데이터를 제거합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return int
 *  큐에 먼저 추가한 데이터
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 -1 반환
 *  @exception queue가 비어있는 경우
 *  "Error: Queue is empty." 출력 후 -1 반환
 */
int dequeue(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return -1;
    }
    if( queue->size == 0 ) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    SinglyLinkedNode* remove_node = queue->front;
    int ret_val = remove_node->data;

    queue->front = queue->front->next;

    free(remove_node);
    queue->size--;

    return ret_val;
}

/**
 *  @brief 큐에 먼저 추가한 데이터를 가져옵니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return int
 *  큐에 먼저 추가한 데이터
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 -1 반환
 *  @exception queue가 비어있는 경우
 *  "Error: Queue is empty." 출력 후 -1 반환
 */
int peek(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return -1;
    }
    if( queue->size == 0 ) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    return queue->front->data;
}

/**
 *  @brief 큐가 비어있는지 여부를 반환합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return bool
 *  큐가 비어있으면 true, 비어있지 않으면 false 반환
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 false 반환
 */
bool is_empty(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return false;
    }

    return queue->size == 0;
}

/**
 *  @brief 큐를 비웁니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return void
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 함수 종료
 */
void clear(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return;
    }

    SinglyLinkedNode* remove_node;
    SinglyLinkedNode* cur_node = queue->front;
    while( cur_node != NULL ) {
        remove_node = cur_node;
        cur_node = cur_node->next;

        free(remove_node);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

/**
 *  @brief 큐의 데이터들을 출력합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return void
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 함수 종료
 */
void print(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return;
    }

    printf("List Based Queue(size %d): ", queue->size);
    SinglyLinkedNode* cur_node = queue->front;
    for( int i = 0; i < queue->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("\n");
}

int main(void) {
    // 큐 생성
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;

    // enqueue 테스트
    for( int i = 0; i < 3; i++ ) {
        printf("enqueue data %d > ", i);
        enqueue(&queue, i);
        print(&queue);
    }

    // is_empty 테스트
    printf("Queue is empty > %s\n", is_empty(&queue)? "yes" : "no");

    // peek 테스트
    printf("peek data > %d\n", peek(&queue));

    // dequeue 테스트
    for( int i = 0; i < 4; i++ ) {
        printf("dequeue data > %d\n", dequeue(&queue));
        print(&queue);
    }

    // enqueue 테스트
    for( int i = 0; i < 20; i++ ) {
        printf("enqueue data %d > ", i);
        enqueue(&queue, i);
        print(&queue);
    }

    // clear 테스트
    printf("clear queue > ");
    clear(&queue);
    print(&queue);

    // is_empty 테스트
    printf("Queue is empty > %s\n", is_empty(&queue)? "yes" : "no");

    return 0;
}
