# 목차
+ [**`연결 리스트(Linked List)`**](#연결-리스트linked-list)
   	- [`단일 연결 리스트(Singly Linked List)`](#단일-연결-리스트singly-linked-list)
	- [`단일 순환 연결 리스트(Singly Circular Linked List)`]()
   	- [`이중 연결 리스트(Doubly Linked List)`]()
  	- [`이중 순환 연결 리스트(Doubly Circular Linekd List)`]()
+ [**`스택(Stack)`**]()
   	- [`배열 기반 스택(Array Based Stack)`]()
   	- [`리스트 기반 스택(List Based Stack)`]()
+ [**`큐(Queue)`**]()
   	- [`배열 기반 큐(Array Based Queue)`]()
   	- [`리스트 기반 큐(List Based Queue)`]()
   	- [`순환 큐(Circular Queue)`]()
   	- [`덱(Deque)]()
+ [**`트리(Tree)`**]()
   	- [`트리(Tree)`]()
   	- [`이진 트리(Binary Tree)`]()
   	- [`이진 탐색 트리(Binary Search Tree)`]()
   	- [`트라이(Trie)`]()
+ [**`힙(Heap)`**]()
   	- [`최소 힙(Min Heap)`]()
   	- [`최대 힙(Max Heap)`]()
   	- [`우선순위 큐(Priority Queue)`]()
+ [**`그래프(Graph)`**]()
	- [`무방향 그래프(Undirected Graph)`]()
 	- [`방향 그래프(Directed Graph)`]()
  	- [`가중치 그래프(Weighted Graph)`]()
+ [**`해시 테이블(Hash Table)`**]()
    - [`해시 테이블(Hash Table)`]()

<br/>
<br/>

# 연결 리스트(Linked List)
```mermaid
graph TD;
    Linked-List-->Singly-Linked-List;
    Linked-List-->Singly-Circular-Linked-List;
    Linked-List-->Doubly-Linked-List;
    Linked-List-->Doubly-Circular-Linekd-List;
```
## 단일 연결 리스트(Singly Linked List)
### Declaration
```c
typedef struct SinglyLinkedNode {
    int data;
    struct SinglyLinkedNode* next;
} SinglyLinkedNode;

typedef struct {
    SinglyLinkedNode* head;
    SinglyLinkedNode* tail;
    int size;
} SinglyLinkedList;
```
### Method
|NO|METHOD                                                              |DESCRIPTION
|-:|:-------------------------------------------------------------------|:--
| 1|SinglyLinkedNode* create_node(int data)                             |새로운 노드를 생성합니다.
| 2|SinglyLinkedNode* get_at_index(SinglyLinkedList* list, int index)   |특정 위치의 노드의 주소를 반환합니다.
| 3|SinglyLinkedNode* get_by_value(SinglyLinkedList* list, int data)    |특정 데이터를 가진 노드의 주소를 반환합니다.
| 4|void prepend(SinglyLinkedList* list, int data)                      |단일 연결 리스트의 맨 앞에 새로운 노드를 추가합니다.
| 5|void append(SinglyLinkedList* list, int data)                       |단일 연결 리스트의 맨 뒤에 새로운 노드를 추가합니다.
| 6|void insert(SinglyLinkedList* list, int data, int index)            |특정 위치에 새로운 노드를 추가합니다.
| 7|void remove_front(SinglyLinkedList* list)                           |단일 연결 리스트의 맨 앞에 있는 노드를 제거합니다.
| 8|void remove_back(SinglyLinkedList* list)                            |단일 연결 리스트의 맨 뒤에 있는 노드를 제거합니다.
| 9|void remove_at_index(SinglyLinkedList* list, int index)             |특정 위치의 노드를 제거합니다.
|10|void remove_by_value(SinglyLinkedList* list, int data)              |특정 데이터를 가진 노드를 제거합니다.
|11|bool is_empty(SinglyLinkedList* list)                               |단일 연결 리스트가 비어있는지 여부를 반환합니다.
|12|void clear(SinglyLinkedList* list)                                  |단일 연결 리스트를 초기화합니다.
|13|void print(SinglyLinkedList* list)                                  |단일 연결 리스트의 데이터들을 출력합니다.

### Prototype
```c
/**
 *  @brief 새로운 노드를 생성합니다.
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
SinglyLinkedNode* create_node(int data);

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
SinglyLinkedNode* get_at_index(SinglyLinkedList* list, int index);

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
SinglyLinkedNode* get_by_value(SinglyLinkedList* list, int data);

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
void prepend(SinglyLinkedList* list, int data);

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
void append(SinglyLinkedList* list, int data);

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
void insert(SinglyLinkedList* list, int data, int index);

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
void remove_front(SinglyLinkedList* list);

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
void remove_back(SinglyLinkedList* list);

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
void remove_at_index(SinglyLinkedList* list, int index);

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
void remove_by_value(SinglyLinkedList* list, int data);

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
bool is_empty(SinglyLinkedList* list);

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
void clear(SinglyLinkedList* list);

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
void print(SinglyLinkedList* list);
```
