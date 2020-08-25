// 1313. 解压缩编码列表
// 给你一个以行程长度编码压缩的整数列表 nums 。

// 考虑每对相邻的两个元素 [freq, val] = [nums[2*i], nums[2*i+1]] （其中 i >= 0 ），每一对都表示解压后子列表中有 freq 个值为 val 的元素，你需要从左到右连接所有子列表以生成解压后的列表。

// 请你返回解压后的列表。



// 示例：

// 输入：nums = [1,2,3,4]
// 输出：[2,4,4,4]
// 解释：第一对 [1,2] 代表着 2 的出现频次为 1，所以生成数组 [2]。
// 第二对 [3,4] 代表着 4 的出现频次为 3，所以生成数组 [4,4,4]。
// 最后将它们串联到一起 [2] + [4,4,4] = [2,4,4,4]。


    // 2 <= nums.length <= 100
    // nums.length % 2 == 0
    // 1 <= nums[i] <= 100
#include <stdio.h>
#include <stdlib.h>

int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    // step1. 计算长度
    int lth = 0;
    for (int i=0;i<numsSize;i=i+2){
        lth += nums[i];
    }
    *returnSize = lth;

    int* ret = (int*)malloc(lth*sizeof(int));

    // step2. 生成数列
    int flag = 0;
    for (int i=0;i<numsSize;i=i+2){
        for (int j=0;j<nums[i];j++){
            ret[flag] = nums[i+1];
            flag ++;
        }
    }

    return ret;
}

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

