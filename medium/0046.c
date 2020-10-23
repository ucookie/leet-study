// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(int* nums, int numsSize, int target)
{
    if (NULL == nums || 0 == numsSize) return 0;
    for (int i = 0; i < numsSize; i++) if (nums[i] == target) return 1;
    return 0;
}

// 路径：记录在 track 中
// 选择列表：nums 中不存在于 track 的那些元素
// 结束条件：nums 中的元素全都在 track 中出现
void backtrack(int*nums, int numsSize, int*track, int trackSize, int**res, int* resSize){
    // 结束条件
    if (trackSize==numsSize){
        int* _tmp_track = (int*)malloc(trackSize*sizeof(int));
        memcpy(_tmp_track, track, trackSize*sizeof(int));
        res[(*resSize)] = _tmp_track;
        (*resSize)++;
        return;
    }

    for (int i=0;i<numsSize;i++){
        if (contains(track, trackSize, nums[i])) continue;
        track[trackSize++]=nums[i]; // 做选择
        backtrack(nums, numsSize, track, trackSize, res, resSize);
        track[--trackSize]=0; // 撤销选择
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    if (nums == NULL || numsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    // 计算全排列的个数
    int lth=1;
    for(int i=1;i<=numsSize;++i) lth*=i;

    // 结果列表
    *returnSize=lth;
    *returnColumnSizes = (int*)malloc(lth*sizeof(int));
    for(int i=0; i< lth;i++) (*returnColumnSizes)[i] = numsSize;

    // 结果数组
    int** res=(int**)malloc(lth*sizeof(int*));
    memset(res, 0, lth*sizeof(int*));
    int resSize = 0; // 结果数组大小

    // 路径数组
    int* track=(int*)malloc(numsSize*sizeof(int));
    memset(track, 0, numsSize*sizeof(int));

    backtrack(nums, numsSize, track, 0, res, &resSize);

    return res;
}

int main(int argc, char const *argv[])
{
    int numsSize = 3;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    for (int i=0;i<numsSize;i++){
        nums[i] = i+1;
    }

    int* returnSize = (int*)malloc(1*sizeof(int));
    int** returnColumnSizes = (int**)malloc(numsSize*sizeof(int*));
    int** aa = permute(nums, numsSize, returnSize, returnColumnSizes);


    for (int i=0;i<*returnSize;i++){
        int* tmp = aa[i];
        for (int x=0;x<numsSize;x++){
            printf("-> %d, ", tmp[x]);
        }
        printf("\n");
    }
    printf("return:%d\n", *returnSize);

    return 0;
}