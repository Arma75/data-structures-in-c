#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SinglyLinkedNode {
    int data;
    struct SinglyLinkedNode* next;
} SinglyLinkedNode;

typedef struct {
    SinglyLinkedNode* head;
    SinglyLinkedNode* tail;
    int size;
} SinglyLinkedList;

/**
 *  @brief 데이터를 가지고 있는 새로운 노드를 생성합니다.
 *
 *  @param data
 *  생성할 노드의 데이터 값
 *
 *  @return SinglyLinkedNode*
 *  data 값을 가진 단일 연결 노드의 주소
 *
 *  @exception 메모리 할당 실패 시
 *  "Error: Memory allocation is faild." 출력 후 NULL 반환
 */
SinglyLinkedNode* create_node(int data) {
    SinglyLinkedNode* new_node = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if( new_node == NULL ) {
        printf("Error: Memory allocation is faild.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/**
 *  @brief 특정 위치의 노드의 주소를 반환합니다.
 *
 *  @param list
 *  단일 연결 리스트 주소
 *  @param index
 *  찾으려는 노드의 위치 값(0부터 list->size - 1까지)
 *
 *  @return SinglyLinkedNode*
 *  특정 위치의 노드의 주소
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 NULL 반환
 *  @exception index가 0보다 작거나 list->size - 1 보다 큰 경우
 *  "Error: Index out of bounds." 출력 후 NULL 반환
 */
SinglyLinkedNode* get_at_index(SinglyLinkedList* list, int index) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return NULL;
    }
    if( index < 0 || index >= list->size ) {
        printf("Error: Index out of bounds.\n");
        return NULL;
    }

    SinglyLinkedNode* cur_node = list->head;
    while( index-- > 0 ) {
        cur_node = cur_node->next;
    }

    return cur_node;
}

/**
 *  @brief 특정 데이터를 가진 노드의 주소를 반환합니다.
 *
 *  @param list
 *  단일 연결 리스트 주소
 *  @param data
 *  찾으려는 노드의 data 값
 *
 *  @return SinglyLinkedNode*
 *  특정 data를 가진 노드의 주소.
 *  특정 data를 가진 노드가 없으면 NULL.
 *  특정 data를 가진 노드가 여러개인 경우 그 중 첫번째 노드의 주소 반환.
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 NULL 반환
 */
SinglyLinkedNode* get_by_value(SinglyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return NULL;
    }

    SinglyLinkedNode* cur_node = list->head;
    while( cur_node != NULL && cur_node->data != data ) {
        cur_node = cur_node->next;
    }

    return cur_node;
}

/**
 *  @brief 단일 연결 리스트의 맨 앞에 새로운 노드를 추가합니다.
 *
 *  @param list
 *  단일 연결 리스트 주소
 *  @param data
 *  추가할 노드의 data 값
 *
 *  @return void
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void prepend(SinglyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    SinglyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( list->size == 0 ) {
        list->tail = new_node;
    } else {
        new_node->next = list->head;
    }
    list->head = new_node;

    list->size++;
}

/**
 *  @brief 단일 연결 리스트의 맨 뒤에 새로운 노드를 추가합니다.
 *
 *  @param list
 *  단일 연결 리스트 주소
 *  @param data
 *  추가할 노드의 data 값
 *
 *  @return void
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void append(SinglyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    SinglyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( list->size == 0 ) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    list->size++;
}

/**
 *  @brief 특정 위치에 새로운 노드를 추가합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  @param data
 *  추가할 노드의 data 값
 *  @param index
 *  추가하려는 위치 값(0부터 list->size까지)
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception index가 0보다 작거나 list->size 보다 큰 경우
 *  "Error: Index out of bounds." 출력 후 NULL 반환
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void insert(SinglyLinkedList* list, int data, int index) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }
    if( index < 0 || index > list->size ) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    if( index == 0 ) {
        prepend(list, data);
    } else if( index == list->size ) {
        append(list, data);
    } else {
        SinglyLinkedNode* prev_node = get_at_index(list, index - 1);
        SinglyLinkedNode* new_node = create_node(data);
        if( new_node == NULL ) {
            return;
        }

        new_node->next = prev_node->next;
        prev_node->next = new_node;

        list->size++;
    }
}

/**
 *  @brief 단일 연결 리스트의 맨 앞에 있는 노드를 제거합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 */
void remove_front(SinglyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    SinglyLinkedNode* remove_node = list->head;

    if( list->size == 1 ) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
    }

    free(remove_node);
    list->size--;
}

/**
 *  @brief 단일 연결 리스트의 맨 뒤에 있는 노드를 제거합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 */
void remove_back(SinglyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    SinglyLinkedNode* remove_node = list->tail;

    if( list->size == 1 ) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        SinglyLinkedNode* prev_node = get_at_index(list, list->size - 2);
        prev_node->next = NULL;
        list->tail = prev_node;
    }

    free(remove_node);
    list->size--;
}

/**
 *  @brief 특정 위치의 노드를 제거합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  @param index
 *  삭제하려는 위치 값(0부터 list->size - 1까지)
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 *  @exception index가 0보다 작거나 list->size - 1 보다 큰 경우
 *  "Error: Index out of bounds." 출력 후 NULL 반환
 */
void remove_at_index(SinglyLinkedList* list, int index) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }
    if( index < 0 || index >= list->size ) {
        printf("Error: Index out of bounds.\n");
        return;
    }

    if( index == 0 ) {
        remove_front(list);
    } else if( index == list->size - 1 ) {
        remove_back(list);
    } else {
        SinglyLinkedNode* prev_node = get_at_index(list, index - 1);
        SinglyLinkedNode* remove_node = prev_node->next;

        prev_node->next = remove_node->next;

        free(remove_node);
        list->size--;
    }
}

/**
 *  @brief 특정 데이터를 가진 노드를 제거합니다.
 *  특정 데이터를 가진 노드가 여러개인 경우 그 중 첫번째 노드를 제거합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  @param data
 *  제거할 노드의 data 값
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 *  @exception data 값을 가진 노드가 없는 경우
 *  "Error: Data does not exist." 출력 후 함수 종료
 */
void remove_by_value(SinglyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    SinglyLinkedNode* prev_node = NULL;
    SinglyLinkedNode* remove_node = list->head;
    while( remove_node != NULL && remove_node->data != data ) {
        prev_node = remove_node;
        remove_node = remove_node->next;
    }

    if( remove_node == NULL ) {
        printf("Error: Data does not exist.\n");
        return;
    }

    if( remove_node == list->head ) {
        remove_front(list);
    } else if( remove_node == list->tail ) {
        remove_back(list);
    } else {
        prev_node->next = remove_node->next;

        free(remove_node);
        list->size--;
    }
}

/**
 *  @brief 단일 연결 리스트가 비어있는지 여부를 반환합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  
 *  @return bool
 *  list가 비어있으면 true, 비어있지 않으면 false 반환
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 false 반환
 */
bool is_empty(SinglyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return false;
    }

    return list->size == 0;
}

/**
 *  @brief 단일 연결 리스트를 초기화합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 */
void clear(SinglyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    SinglyLinkedNode* remove_node;
    SinglyLinkedNode* cur_node = list->head;
    while( cur_node != NULL ) {
        remove_node = cur_node;
        cur_node = cur_node->next;

        free(remove_node);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 *  @brief 단일 연결 리스트의 데이터들을 출력합니다.
 *  
 *  @param list
 *  단일 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 */
void print(SinglyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    printf("Singly Linked List(size %d): ", list->size);

    SinglyLinkedNode* cur_node = list->head;
    for( int i = 0; i < list->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", cur_node->data);

        cur_node = cur_node->next;
    }

    printf("\n");
}

int main(void) {
    // 단일 연결 리스트 생성
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    // append 테스트
    for( int i = 0; i <= 3; i++ ) {
        printf("append data %d > ", i);
        append(list, i);
        print(list);
    }

    // prepend 테스트
    for( int i = 0; i <= 3; i++ ) {
        printf("prepend data %d > ", i);
        prepend(list, i);
        print(list);
    }

    // insert 테스트
    for( int i = 2; i <= 8; i += 2 ) {
        printf("insert data %d at index %d > ", i, i);
        insert(list, i, i);
        print(list);
    }

    // is_empty 테스트
    printf("List is empty? > %s\n", is_empty(list)? "yes" : "no");

    // get_at_index 테스트
    for( int i = 0; i < 7; i++ ) {
        printf("get data at index %d > ", i * 2);
        SinglyLinkedNode* node = get_at_index(list, i * 2);
        if( node != NULL ) {
            printf("%d\n", node->data);
        }
    }

    // remove_at_index 테스트
    for( int i = 12; i >= 0; i -= 3 ) {
        printf("remove at index %d > ", i);
        remove_at_index(list, i);
        print(list);
    }

    // remove_by_value 테스트
    for( int i = 0; i < 4; i++ ) {
        printf("remove data 2 > ");
        remove_by_value(list, 2);
        print(list);
    }

    // remove_front 테스트
    printf("remove at front > ");
    remove_front(list);
    print(list);

    // remove_back 테스트
    printf("remove at back > ");
    remove_back(list);
    print(list);
    
    // clear 테스트
    printf("clear list > ");
    clear(list);
    print(list);

    // is_empty 테스트
    printf("List is empty? > %s\n", is_empty(list)? "yes" : "no");

    // 단일 연결 리스트 메모리 해제
    free(list);

    return 0;
}
