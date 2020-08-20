// 237. 删除链表中的节点

// 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为要被删除的节点 。
// 现有一个链表 -- head = [4,5,1,9]，它可以表示为:
// 输入：head = [4,5,1,9], node = 5
// 输出：[4,1,9]
// 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.


    // 链表至少包含两个节点
    // 链表中所有节点的值都是唯一的。
    // 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
    // 不要从你的函数中返回任何结果。

/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode *tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    free(tmp);
}

int main(int argc, char const *argv[])
{
    struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    struct ListNode* d;
    struct ListNode* t;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 4;
    p = p->next;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 5;
    p = p->next;
    d = p;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 1;
    p->next->next = NULL;

    deleteNode(d);

    t = head;
    while (t!=NULL)
    {
        printf("%d\n", t->val);
        t = t->next;
    }

    return 0;
}
