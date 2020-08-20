// LCP 06. 拿硬币

// 桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。
// 示例 1：
//     输入：[4,2,1]
//     输出：4
//     解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。
// 示例 2：
//     输入：[2,3,10]
//     输出：8
// 限制：
//     1 <= n <= 4
//     1 <= coins[i] <= 10

#include <stdio.h>
#include <stdlib.h>

int minCount(int* coins, int coinsSize);
int minCount(int* coins, int coinsSize){
    int ret = 0;

    for(int i=0;i<coinsSize;i++){
        if (coins[i] % 2 == 0){
            ret += coins[i] / 2;
        }else{
            ret += coins[i] / 2 + 1;
        }
        printf("%d\n", coins[i]);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int coins[3] = {4,2,1};
    int aa = minCount(&coins, 3);
    printf("->%d\n", aa);
    return 0;
}
