// 面试题 04.02. 最小高度树

// 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
// 示例:

// 给定有序数组: [-10,-3,0,5,9],

// 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

//           0
//          / \
//        -3   9
//        /   /
//      -10  5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildBST(int* nums, int left, int right){
    if(left>right)
        return NULL;
    else{
        int mid = (left+right)/2;
        struct TreeNode* pNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        pNode->val = nums[mid];
        pNode->left = buildBST(nums, left, mid-1);
        pNode->right  = buildBST(nums, mid+1, right);
        return pNode;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
   return buildBST(nums, 0, numsSize-1);
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
    // struct TreeNode *T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int numsSize = 5;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    nums[0]=-10;
    nums[1]=-3;
    nums[2]=0;
    nums[3]=5;
    nums[4]=9;
    struct TreeNode* T = sortedArrayToBST(nums, numsSize);
    preOrder(T);
    return 0;
}
