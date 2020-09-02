// 面试题 02.02. 返回倒数第 k 个节点


// 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
// 注意：本题相对原题稍作改动
// 示例：
// 输入： 1->2->3->4->5 和 k = 2
// 输出： 4
// 说明：
// 给定的 k 保证是有效的。
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


int kthToLast(struct ListNode* head, int k){
    struct ListNode* p=head;
    while (k!=0)
    {
        k--;
        head = head->next;
    }

    while (head!=NULL)
    {
        p = p->next;
        head = head->next;
    }

    return p->val;
}


int main(int argc, char const *argv[])
{
    struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode* p = head;
    for (int i=2;i<=5;i++){
        struct ListNode* _new = (struct ListNode* )malloc(sizeof(struct ListNode));
        _new->val = i;
        p->next=_new;
        p=_new;
    }
    p->next = NULL;

    int aa = kthToLast(head, 2);
    printf("-->%d", aa);
    // while (head!=NULL)
    // {
    //     printf("%d,", head->val);
    //     head=head->next;
    // }
    // printf("\n");

    return 0;
}
