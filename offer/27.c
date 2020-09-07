// 剑指 Offer 27. 二叉树的镜像
// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

// 例如输入：

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// 镜像输出：

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

// 示例 1：
// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]

#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* mirrorTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}

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
    printf("\n");
    struct TreeNode* ret = mirrorTree(root);
    preOrder(ret);
    printf("\n");

    return 0;
}

