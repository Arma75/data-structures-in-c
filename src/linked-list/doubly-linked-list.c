#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DoublyLinkedNode {
    int data;
    struct DoublyLinkedNode* prev;
    struct DoublyLinkedNode* next;
} DoublyLinkedNode;

typedef struct {
    DoublyLinkedNode* head;
    DoublyLinkedNode* tail;
    int size;
} DoublyLinkedList;

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
 *  @brief 특정 위치의 노드의 주소를 반환합니다.
 *
 *  @param list
 *  이중 연결 리스트 주소
 *  @param index
 *  찾으려는 노드의 위치 값(0부터 list->size - 1까지)
 *
 *  @return DoublyLinkedNode*
 *  특정 위치의 노드의 주소
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 NULL 반환
 *  @exception index가 0보다 작거나 list->size - 1 보다 큰 경우
 *  "Error: Index out of bounds." 출력 후 NULL 반환
 */
DoublyLinkedNode* get_at_index(DoublyLinkedList* list, int index) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return NULL;
    }
    if( index < 0 || index >= list->size ) {
        printf("Error: Index out of bounds.\n");
        return NULL;
    }

    DoublyLinkedNode* cur_node = list->head;
    while( index-- > 0 ) {
        cur_node = cur_node->next;
    }

    return cur_node;
}

/**
 *  @brief 특정 데이터를 가진 노드의 주소를 반환합니다.
 *
 *  @param list
 *  이중 연결 리스트 주소
 *  @param data
 *  찾으려는 노드의 data 값
 *
 *  @return DoublyLinkedNode*
 *  특정 data를 가진 노드의 주소.
 *  특정 data를 가진 노드가 없으면 NULL.
 *  특정 data를 가진 노드가 여러개인 경우 그 중 첫번째 노드의 주소 반환.
 *
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 NULL 반환
 */
DoublyLinkedNode* get_by_value(DoublyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return NULL;
    }

    DoublyLinkedNode* cur_node = list->head;
    while( cur_node != NULL && cur_node->data != data ) {
        cur_node = cur_node->next;
    }

    return cur_node;
}

/**
 *  @brief 이중 연결 리스트의 맨 앞에 새로운 노드를 추가합니다.
 *
 *  @param list
 *  이중 연결 리스트 주소
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
void prepend(DoublyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    DoublyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( list->size == 0 ) {
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
    }
    list->head = new_node;

    list->size++;
}

/**
 *  @brief 이중 연결 리스트의 맨 뒤에 새로운 노드를 추가합니다.
 *
 *  @param list
 *  이중 연결 리스트 주소
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
void append(DoublyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    DoublyLinkedNode* new_node = create_node(data);
    if( new_node == NULL ) {
        return;
    }

    if( list->size == 0 ) {
        list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
    }
    list->tail = new_node;

    list->size++;
}

/**
 *  @brief 특정 위치에 새로운 노드를 추가합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
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
 *  "Error: Index out of bounds." 출력 후 함수 종료
 *  @exception 새로운 노드 생성에 실패한 경우
 *  함수 종료
 */
void insert(DoublyLinkedList* list, int data, int index) {
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
        DoublyLinkedNode* next_node = get_at_index(list, index);
        DoublyLinkedNode* prev_node = next_node->prev;
        DoublyLinkedNode* new_node = create_node(data);
        if( new_node == NULL ) {
            return;
        }

        new_node->prev = prev_node;
        prev_node->next = new_node;

        new_node->next = next_node;
        next_node->prev = new_node;

        list->size++;
    }
}

/**
 *  @brief 이중 연결 리스트의 맨 앞에 있는 노드를 제거합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 */
void remove_front(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    DoublyLinkedNode* remove_node = list->head;

    if( list->size == 1 ) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        DoublyLinkedNode* next_node = list->head->next;
        next_node->prev = NULL;
        list->head = next_node;
    }

    free(remove_node);
    list->size--;
}

/**
 *  @brief 이중 연결 리스트의 맨 뒤에 있는 노드를 제거합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 *  @exception list의 size가 0인 경우
 *  "Error: List is empty." 출력 후 함수 종료
 */
void remove_back(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    DoublyLinkedNode* remove_node = list->tail;

    if( list->size == 1 ) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        DoublyLinkedNode* prev_node = list->tail->prev;
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
 *  이중 연결 리스트 주소
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
 *  "Error: Index out of bounds." 출력 후 함수 종료
 */
void remove_at_index(DoublyLinkedList* list, int index) {
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
        DoublyLinkedNode* remove_node = get_at_index(list, index);
        DoublyLinkedNode* prev_node = remove_node->prev;
        DoublyLinkedNode* next_node = remove_node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        free(remove_node);
        list->size--;
    }
}

/**
 *  @brief 특정 데이터를 가진 노드를 제거합니다.
 *  특정 데이터를 가진 노드가 여러개인 경우 그 중 첫번째 노드를 제거합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
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
void remove_by_value(DoublyLinkedList* list, int data) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }
    if( list->size == 0 ) {
        printf("Error: List is empty.\n");
        return;
    }

    DoublyLinkedNode* remove_node = list->head;
    while( remove_node != NULL && remove_node->data != data ) {
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
        DoublyLinkedNode* prev_node = remove_node->prev;
        DoublyLinkedNode* next_node = remove_node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        free(remove_node);
        list->size--;
    }
}

/**
 *  @brief 이중 연결 리스트가 비어있는지 여부를 반환합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return bool
 *  list가 비어있으면 true, 비어있지 않으면 false 반환
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 false 반환
 */
bool is_empty(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return false;
    }

    return list->size == 0;
}

/**
 *  @brief 이중 연결 리스트를 비웁니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 */
void clear(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    DoublyLinkedNode* remove_node;
    DoublyLinkedNode* cur_node = list->head;
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
 *  @brief 이중 연결 리스트의 데이터들을 출력합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 */
void print(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    printf("Doubly Linked List(size %d): ", list->size);

    DoublyLinkedNode* cur_node = list->head;
    for( int i = 0; i < list->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", cur_node->data);

        cur_node = cur_node->next;
    }

    printf("\n");
}

/**
 *  @brief 이중 연결 리스트의 데이터들을 역순으로 출력합니다.
 *  
 *  @param list
 *  이중 연결 리스트 주소
 *  
 *  @return void
 *  
 *  @exception list가 NULL인 경우
 *  "Error: List is NULL." 출력 후 함수 종료
 */
void reverse_print(DoublyLinkedList* list) {
    if( list == NULL ) {
        printf("Error: List is NULL.\n");
        return;
    }

    printf("Doubly Linked List(size %d): ", list->size);

    DoublyLinkedNode* cur_node = list->tail;
    for( int i = 0; i < list->size; i++ ) {
        if( i > 0 ) {
            printf(" -> ");
        }
        printf("%d", cur_node->data);

        cur_node = cur_node->prev;
    }

    printf("\n");
}

int main(void) {
    // 이중 연결 리스트 생성
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
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
        DoublyLinkedNode* node = get_at_index(list, i * 2);
        if( node != NULL ) {
            printf("%d\n", node->data);
        }
    }

    // get_by_value 테스트
    for( int i = 3; i <= 5; i++ ) {
        printf("get data %d > ", i);
        DoublyLinkedNode* node = get_by_value(list, i);
        if( node != NULL ) {
            printf("%d\n", node->data);
        } else {
            printf("NULL\n");
        }
    }

    // reverse_print 테스트
    printf("print >\t\t");
    print(list);
    printf("reverse print >\t");
    reverse_print(list);

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

    // 이중 연결 리스트 메모리 해제
    free(list);

    return 0;
}
