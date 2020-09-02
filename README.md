# leet-study

学习学习

### 链表模板
```c
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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

    while (head!=NULL)
    {
        printf("%d,", head->val);
        head=head->next;
    }
    printf("\n");
    return 0;
}

```

### 1维数组模板
```c
int main(int argc, char const *argv[])
{
    int numsSize = 4;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    for (int i=0;i<numsSize;i++){
        nums[i] = i+1;
    }
    int* returnSize;
    int* aa = decompressRLElist(nums, numsSize, returnSize);
    for (int i=0;i<*returnSize;i++){
        printf("-> %d,", aa[i]);
    }
    printf("\n");
    return 0;
}
```
