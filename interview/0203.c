// 面试题 02.03. 删除中间节点

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


void deleteNode(struct ListNode* node) {
    struct ListNode *tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    free(tmp);
}


int main(int argc, char const *argv[])
{

    struct ListNode *p = (struct ListNode* )malloc(sizeof(struct ListNode));
	if (p == NULL){return -1;}

    struct ListNode *_p = p;

    // 待删除节点
    struct ListNode *d = NULL;

    for (int i=0;i<6;i++){
        struct ListNode *_new = (struct ListNode* )malloc(sizeof(struct ListNode));
        _new->val = i;
        _new->next = NULL;
        _p->next = _new;
        _p = _new;
        if (i==3){
            d = _new;
        }
    }


    deleteNode(d);

    struct ListNode *tmp = p->next;
    while (tmp)
    {
        printf("->%d,%p\n", tmp->val, tmp);
        tmp = tmp->next;
    }


    return 0;
}


// 实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

// 示例：
// 输入：单向链表a->b->c->d->e->f中的节点c
// 结果：不返回任何数据，但该链表变为a->b->d->e->f

