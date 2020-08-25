// 1295. 统计位数为偶数的数字
// 给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

// 输入：nums = [12,345,2,6,7896]
// 输出：2
// 解释：
// 12 是 2 位数字（位数为偶数）
// 345 是 3 位数字（位数为奇数）
// 2 是 1 位数字（位数为奇数）
// 6 是 1 位数字 位数为奇数）
// 7896 是 4 位数字（位数为偶数）
// 因此只有 12 和 7896 是位数为偶数的数字


    // 1 <= nums.length <= 500
    // 1 <= nums[i] <= 10^5
#include <stdio.h>
#include <stdlib.h>

int findNumbers(int* nums, int numsSize){
    int ret = 0;

    for (int i=0;i<numsSize;i++){
        int tmp = 0;
        int num = nums[i];
        while(num>0){
            num = num / 10;
            tmp++;
        }
        if (tmp % 2 == 0){
            ret++;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int numsSize = 5;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    nums[0]=12;
    nums[1]=345;
    nums[2]=2;
    nums[3]=6;
    nums[4]=7896;

    int aa = findNumbers(nums, numsSize);
    printf("->%d\n", aa);
    return 0;
}
