// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]

// 输入：nums = [], target = 0
// 输出：[-1,-1]

#include <stdio.h>
#include <stdlib.h>

int findBound(int* nums, int numsSize, int target, int isLeft){
    int left = 0;
    int right = numsSize;

    while (left<right)
    {
        int mid = (left+right)/2;
        if (nums[mid]==target){
            if (isLeft){ right = mid; }else{ left = mid+1; }
        }else if (nums[mid]>target)
        {
            right = mid;
        }else if (nums[mid]<target)
        {
            left = mid+1;
        }
    }

    // 找右边界，是从左边缩，计算左的时候是提前加1了,需要减去才是当前元素的位置
    if (!isLeft){ left--; }
    if (left >= numsSize || left < 0) {
        return -1;
    }

    return nums[left] == target ? left : -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int lth = 2;
    *returnSize = 2;
    int* ret = (int*)malloc(lth*sizeof(int));
    ret[0] = findBound(nums, numsSize, target, 1);
    ret[1] = findBound(nums, numsSize, target, 0);
    return ret;
}

void searchRange2(int* returnSize){
    int lth = 2;
    *returnSize = lth;
}

int* searchRange3(int* nums, int numsSize, int target, int* returnSize){
    int lth = 2;
    *returnSize = 2;
    printf("2->%p\n", returnSize);
    int* ret = (int*)malloc(lth*sizeof(int));
    ret[0] = findBound(nums, numsSize, target, 1);
    ret[1] = findBound(nums, numsSize, target, 0);
    return ret;
}

int main(int argc, char const *argv[])
{
    //示例1
    // int numsSize = 6;
    // int* nums = (int*)malloc(numsSize*sizeof(int));
    // nums[0] = 5;
    // nums[1] = 7;
    // nums[2] = 7;
    // nums[3] = 8;
    // nums[4] = 8;
    // nums[5] = 10;

    // 示例2
    int numsSize = 1;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    nums[0] = 1;

    int *returnSize;
    // searchRange2(returnSize);
    printf("1->%p\n", returnSize);
    int* aa= searchRange3(nums, numsSize, 1, returnSize);
    printf("3->%p\n", returnSize);
    // int *aa = searchRange(nums, numsSize, 1, returnSize);
    // for (int i=0;i<*returnSize;i++){
    //     printf("-> %d,", aa[i]);
    // }

    printf("\n");
    return 0;
}
