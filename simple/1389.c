// 1389. 按既定顺序创建目标数组
// 给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：

//     目标数组 target 最初为空。
//     按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
//     重复上一步，直到在 nums 和 index 中都没有要读取的元素。

// 请你返回目标数组。

// 题目保证数字插入位置总是存在。

// 输入：nums = [0,1,2,3,4], index = [0,1,2,2,1]
// 输出：[0,4,1,3,2]
// 解释：
// nums       index     target
// 0            0        [0]
// 1            1        [0,1]
// 2            2        [0,1,2]
// 3            2        [0,1,3,2]
// 4            1        [0,4,1,3,2]

// 1 <= nums.length, index.length <= 100
// nums.length == index.length
// 0 <= nums[i] <= 100
// 0 <= index[i] <= i

#include <stdio.h>
#include <stdlib.h>
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * indexSize);
    int tail = -1;
    for (int i = 0; i < indexSize; ++i) {
        ++tail;
        for (int j = tail; j > index[i]; --j) {
            ret[j] = ret[j - 1];
        }
        ret[index[i]] = nums[i];
    }
    *returnSize = indexSize;
    return ret;
}

int main(int argc, char const *argv[])
{
    int numsSize = 5;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    nums[0]=1;
    nums[1]=2;
    nums[2]=3;
    nums[3]=4;
    nums[4]=0;
    int indexSize = 5;
    int* index = (int*)malloc(indexSize*sizeof(int));
    index[0]=0;
    index[1]=1;
    index[2]=2;
    index[3]=3;
    index[4]=0;

    int* returnSize = (int*)malloc(sizeof(int));

    int* aa = createTargetArray(nums, numsSize, index, indexSize, returnSize);
    for (int i=0;i<*returnSize;i++){
        printf("%d,", aa[i]);
    }

    return 0;
}
