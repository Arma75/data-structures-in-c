# 목차
+ [`연결 리스트(Linked List)`](#연결-리스트linked-list)
   	1. [**단일 연결 리스트**(Singly Linked List)](#단일-연결-리스트singly-linked-list)
   	2. [**단일 순환 연결 리스트**(Singly Circular Linked List)]
   	3. [**이중 연결 리스트**(Doubly Linked List)]()
   	4. [**이중 순환 연결 리스트**(Doubly Circular Linekd List)]()
+ `스택(Stack)`
   	1. [**배열 기반 스택**(Array Based Stack)]()
   	2. [**리스트 기반 스택**(List Based Stack)]()
+ `큐(Queue)`
   	1. [**배열 기반 큐**(Array Based Queue)]()
   	2. [**리스트 기반 큐**(List Based Queue)]()
   	3. [**순환 큐**(Circular Queue)]()
   	4. [**덱**(Deque)]()
+ `트리(Tree)`
   	1. [**트리**(Tree)]()
   	2. [**이진 트리**(Binary Tree)]()
   	3. [**이진 탐색 트리**(Binary Search Tree)]()
   	4. [**트라이**(Trie)]()
+ `그래프(Graph)`
	1. [**무방향 그래프**(Undirected Graph)]()
 	2. [**방향 그래프**(Directed Graph)]()
  	3. [**가중치 그래프**(Weighted Graph) ]()
+ `해시 테이블(Hash Table)`
    1. [**해시 테이블**(Hash Table)]()

# 연결 리스트(Linked List)
## 단일 연결 리스트(Singly Linked List)
### 구조체 선언
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
### 함수 목록
|NO|METHOD                                                              |DESCRIPTION
|-:|:-------------------------------------------------------------------|:--
| 1|SinglyLinkedNode* create_node(int data)                             |데이터를 가지고 있는 새로운 노드를 생성합니다.
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
