// 1470. 重新排列数组

// 输入：nums = [1,2,3,4,4,3,2,1], n = 4
// 输出：[1,4,2,3,3,2,4,1]

#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize);
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ret = (int* )malloc(numsSize * sizeof(int));

    if (nums == NULL || numsSize == 0){
        return ret;
    }

    // 遍历目标数组
    for (int i=0;i<numsSize;i=i+2){
        ret[i] = nums[i/2];
        ret[i+1] = nums[n+i/2];
    }
    *returnSize = numsSize;
    return ret;
}

int main(int argc, char const *argv[])
{
    int n = 2;
    int numsSize = n*2;
    int* nums = (int* )malloc(numsSize * sizeof(int));
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 2;
    nums[3] = 2;
    int* returnSize;

    int* aa = shuffle(nums, numsSize, n, returnSize);
    for (int i=0;i<numsSize;i++){
        printf("->:%d\n", aa[i]);
    }

    return 0;
}


