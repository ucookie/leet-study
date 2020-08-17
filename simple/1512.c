// 1512. 好数对的数目

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int numIdenticalPairs(int* nums, int numsSize);
int numIdenticalPairs(int* nums, int numsSize){
    // 统计相同的元素有多少个, 然后计算Cn2的组合数
    int combination[101] = {0};
    for (int i=0;i<numsSize;i++){
        combination[nums[i]]++;
    }

    int ret = 0;
    for (int i=1;i<=100;i++){
        if (combination[i] > 1){
            ret = ret + (combination[i]*(combination[i]-1))/2;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int numsSize = 4;
    int* nums = (int *)malloc(numsSize * sizeof(int));
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 1;
    int aa = numIdenticalPairs(nums, numsSize);
    printf("-->%d\n", aa);
    return 0;
}
