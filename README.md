# leet-study

学习学习

### 1链表模板
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

### 2维数组模板
```c
#include <stdio.h>
#include <stdlib.h>
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


### 3二叉树模板
```c
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preOrder(struct TreeNode* T)
{
    if(T != NULL) {
        printf("%d ", T->val);  //访问根节点
        preOrder(T->left);    //先根序遍历左子树
        preOrder(T->right);    //先根序遍历右子树
    }
}


int main(int argc, char const *argv[])
{
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 4;

    struct TreeNode* l;
    struct TreeNode* r;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right->val = 7;

    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 1;
    root->left->right->val = 3;

    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 6;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 9;

    preOrder(root);
    return 0;
}
```



# 检查

```sh
gcc -O -g -fsanitize=address 0752.c && ./a.out

```

# 字符串常用
```c
// 判断字符串相等
int isEquals(char* a, char* b){
    int aLth = strlen(a);
    int bLth = strlen(b);
    if (aLth!=bLth) return 0;

    int lth = aLth<bLth?aLth:bLth;
    for (int i=0;i<lth;i++){
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

```