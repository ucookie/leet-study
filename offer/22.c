// 剑指 Offer 22. 链表中倒数第k个节点

// 输入一个链表，输出该链表中倒数第k个节点。
// 为了符合大多数人的习惯，本题从1开始计数，
// 即链表的尾节点是倒数第1个节点。
// 例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
// 示例：
// 给定一个链表: 1->2->3->4->5, 和 k = 2.
// 返回链表 4->5.


#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
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
    return p;
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

    struct ListNode* ret = getKthFromEnd(head, 2);

    while (ret!=NULL)
    {
        printf("%d,", ret->val);
        ret=ret->next;
    }
    printf("\n");

    return 0;
}
