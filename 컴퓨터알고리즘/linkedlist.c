#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode * link;
}ListNode;

typedef struct{
    ListNode* head;
    int length;
}LinkedListType;

void init(LinkedListType* L){
    L->head = NULL;
}

void addFirst(LinkedListType* L, int item){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data=item;
    node->link=L->head;
    L->head = node;
    L->length++;
}

void add(LinkedListType* L, int pos, int item){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i=0; i<pos-1; i++){
        before=before->link;
    }
    node->data=item;
    node->link = before->link;
    before->link=node;
    L->length++;
}

void addLast(LinkedListType* L, int item){
    int pos = L->length;
    add(L, pos, item);
}

int removed(LinkedListType *L, int pos)
{
	ListNode* before = L->head;
	for (int i = 1; i < pos - 1; i++)
		before = before->link;

	int item;
	if (pos == 1)
	{
		item = before->data;
		L->head = before->link;
	}
	else {
		item = before->link->data;
		before->link = before->link->link;
	}
	L->length--;
	return item;
}

int removeFirst(LinkedListType* L)
{
	ListNode* first = L->head;
	int item = first->data;
	L->head = first->link;
	L->length--;
	return item;
}

int removeLast(LinkedListType *L)
{
	ListNode* before = L->head;
	for (int i = 1; i <= L->length - 2; i++)
		before = before->link;
	int item = before->link->data;
	before->link = NULL;
	L->length--;
	return item;
}

int get(LinkedListType* L, int pos){
    ListNode* p =L->head;
    for(int i=1;i<pos;i++){
        p=p->link;
    }
    return p->data;
}

void set(LinkedListType* L, int pos, int item){
    ListNode* p =L->head;
    for(int i=1;i<pos;i++){
        p=p->link;
    }
    p->data=item;
}

void printList(LinkedListType* L){
    for(ListNode* p = L->head; p!=NULL ; p=p->link)
        printf("[%d] -> ", p->data);
    printf("\n");
}

int main()
{
    LinkedListType list;
    init(&list);
    
    addFirst(&list,10); printList(&list);
    addFirst(&list,20); printList(&list);
    addFirst(&list,30); printList(&list);
    
    add(&list, 1, 40); printList(&list);
    add(&list, 1, 50); printList(&list);
    add(&list, 3, 60); printList(&list);
    
    addLast(&list, 20); printList(&list);
    addLast(&list, 70); printList(&list);
    
    int pos;
    scanf("%d", &pos);
    
    removed(&list, pos); printList(&list);
    removeLast(&list); printList(&list);
    removeFirst(&list); printList(&list);
}
