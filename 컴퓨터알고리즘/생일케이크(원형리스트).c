#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int elem;
    struct ListNode * link;
}ListNode;

typedef struct{
    ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL;
}

ListNode* getNode() {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    return node;
}

LinkedListType* buildList(LinkedListType* L, int n){
    ListNode* p = getNode();
    L->head=p;
    p->elem=1;
    for (int i = 2; i <= n; i++) {
        p->link = getNode();
        p = p->link;
        p->elem=i;
    }
    p->link=L->head;
    return L;
}

int runSimulation(LinkedListType* L, int n, int k){
    ListNode* p = L->head;
    while(p!=p->link){
        for(int i=1; i<k; i++){
            p=p->link;
        }
        ListNode* pnext=p->link;
        p->link=p->link->link;
        free(pnext);
        p=p->link;
    }
    return p->elem;
}

int candle(int n, int k){
    LinkedListType list;
    init(&list);
    buildList(&list,n);
    int idx = runSimulation(&list, n, k);
    return idx;
}

int main()
{
    int num = candle(7,3);
    printf("%d", num);
}
