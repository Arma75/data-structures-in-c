#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

typedef struct {
    int data[QUEUE_SIZE + 1];
    int front;
    int rear;
} Queue;

bool is_empty(Queue* queue);
bool is_full(Queue* queue);

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
 *  @exception queue가 가득 찬 경우
 *  "Error: Queue is full." 출력 후 함수 종료
 */
void enqueue(Queue* queue, int data) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return;
    }
    if( is_full(queue) ) {
        printf("Error: Queue is full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % (QUEUE_SIZE + 1);
    queue->data[queue->rear] = data;
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
    if( is_empty(queue) ) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    queue->front = (queue->front + 1) % (QUEUE_SIZE + 1);
    return queue->data[queue->front];
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
    if( is_empty(queue) ) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    return queue->data[(queue->front + 1) % (QUEUE_SIZE + 1)];
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

    return queue->front == queue->rear;
}

/**
 *  @brief 큐가 가득 찼는지 여부를 반환합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return bool
 *  큐가 가득 찼으면 true, 가득 차지 않았으면 false 반환
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 false 반환
 */
bool is_full(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return false;
    }

    return queue->front == (queue->rear + 1) % (QUEUE_SIZE + 1);
}

/**
 *  @brief 큐에 담긴 데이터의 개수를 반환합니다.
 *  
 *  @param queue
 *  큐의 주소
 *  
 *  @return int
 *  큐에 담긴 데이터의 개수
 *  
 *  @exception queue가 NULL인 경우
 *  "Error: Queue is NULL." 출력 후 -1 반환
 */
int size(Queue* queue) {
    if( queue == NULL ) {
        printf("Error: Queue is NULL.\n");
        return -1;
    }

    if( queue->front <= queue->rear ) {
        return queue->rear - queue->front;
    } else {
        return (QUEUE_SIZE + 1) + queue->rear - queue->front;
    }
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

    queue->front = 0;
    queue->rear = 0;
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
    
    printf("Circular Queue(size %d, capacity %d): ", size(queue), QUEUE_SIZE);
    int idx = queue->front;
    while( idx != queue->rear ) {
        if( idx != queue->front ) {
            printf(" -> ");
        }

        idx = (idx + 1) % (QUEUE_SIZE + 1);
        printf("%d", queue->data[idx]);
    }
    printf("\n");
}

int main(void) {
    // 큐 생성
    Queue queue;
    queue.front = 0;
    queue.rear = 0;

    // enqueue 테스트
    for( int i = 0; i < 6; i++ ) {
        printf("enqueue data %d > ", i);
        enqueue(&queue, i);
        print(&queue);
    }

    // is_empty 테스트
    printf("Queue is empty > %s\n", is_empty(&queue)? "yes" : "no");
    // is_full 테스트
    printf("Queue is full > %s\n", is_full(&queue)? "yes" : "no");

    // peek 테스트
    printf("peek data > %d\n", peek(&queue));

    // dequeue 테스트
    for( int i = 0; i < 2; i++ ) {
        printf("dequeue data > %d\n", dequeue(&queue));
        print(&queue);
    }

    // clear 테스트
    printf("clear queue > ");
    clear(&queue);
    print(&queue);

    // is_empty 테스트
    printf("Queue is empty > %s\n", is_empty(&queue)? "yes" : "no");
    // is_full 테스트
    printf("Queue is full > %s\n", is_full(&queue)? "yes" : "no");

    return 0;
}
