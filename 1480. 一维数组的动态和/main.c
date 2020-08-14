#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://leetcode-cn.com/problems/running-sum-of-1d-array/

int* runningSum(int* nums, int numsSize, int* returnSize);
int* runningSum(int* nums, int numsSize, int* returnSize){

    int* ret = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;
    if (numsSize > 0)
    {
        ret[0] = nums[0];
        for(int i=1; i<numsSize; i++)
        {
            ret[i] = ret[i-1] + nums[i];
        }
    }

    return ret;
}

int main()
{
    int* nums = (int *)malloc(sizeof(int));
    int numsSize = 4;
    int* returnSize = (int *)malloc(sizeof(int));

    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;

    int* aa = runningSum(nums, numsSize, returnSize);
    for(int i=0;i<*returnSize;i++)
    {
        printf(":%d\n", aa[i]);
    }
}

