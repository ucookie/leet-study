// 1290. 二进制链表转整数

// 给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

// 请你返回该链表所表示数字的 十进制值 。


// 输入：head = [1,0,1]
// 输出：5
// 解释：二进制数 (101) 转化为十进制数 (5)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int getDecimalValue(struct ListNode* head){
    int number=0;
    struct ListNode*p=head;
    // 每次的本身乘以当前的进制
    while(p!=NULL)
    {
        number=number*2+p->val;
        p=p->next;
    }

    return number;

}

int main(int argc, char const *argv[])
{
    struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    struct ListNode* d;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 1;
    p = p->next;
    d = p;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 1;
    p = p->next;

    p->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->next->val = 0;
    p = p->next;
    p->next = NULL;

    int aa = getDecimalValue(d);
    printf("=%d\n", aa);
    // while (d!=NULL)
    // {
    //     printf("%d\n", d->val);
    //     d = d->next;
    // }

    return 0;
}
