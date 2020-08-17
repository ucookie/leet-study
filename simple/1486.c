// 1486. 数组异或操作

// 给你两个整数，n 和 start
// 数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

// 输入：n = 5, start = 0;
// 输出：8
// 解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
//      "^" 为按位异或 XOR 运算符。
#include <stdio.h>
#include <stdlib.h>
int xorOperation(int n, int start){
    int num;
    int ret = 0;
    for (int i=0;i<n;i++){
        num = start + 2*i;
        ret = ret ^ num;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int start =0;
    int aa = xorOperation(n, start);
    printf("结果:%d\n", aa);
    return 0;
}
