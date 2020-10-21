#include <stdio.h>
#include <stdlib.h>


// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
// 你可以认为每种硬币的数量是无限的。


// 输入：coins = [1, 2, 5], amount = 11
// 输出：3
// 解释：11 = 5 + 5 + 1

int min(int a, int b){
    return (a<b)?a:b;
}

int coinChange(int* coins, int coinsSize, int amount){
    if (amount==0){
        return 0;
    }
    if (amount<0){
        return -1;
    }

    int* dp_table = (int*)malloc((amount+1)*sizeof(int));
    for (int i=0;i<=amount;i++){
        dp_table[i] = i+1;
    }

    dp_table[0] = 0;
    for (int i=1;i<=amount;i++){
        // 在所有的钱中, 找到最小的一个
        for (int p=0;p<coinsSize;p++){
            // 不合条件的跳过
            if ((i-coins[p]) < 0){
                continue;
            }
            // 跳过已经计算不合格的dp值
            if (dp_table[i-coins[p]]==i-coins[p]+1){
                continue;
            }
            dp_table[i] = min(dp_table[i], 1+dp_table[i-coins[p]]);
        }
    }
    return (dp_table[amount]==amount+1)?-1:dp_table[amount];
}


int main(int argc, char const *argv[])
{
    int coinsSize = 3;
    int* coins = (int*)malloc(coinsSize*sizeof(int));
    coins[0] = 1;
    coins[1] = 2;
    coins[2] = 5;
    int amount = 11;

    // int coinsSize = 1;
    // int* coins = (int*)malloc(coinsSize*sizeof(int));
    // coins[0] = 2;
    // int amount = 3;
    printf("结果= %d\n", coinChange(coins, coinsSize, amount));
    return 0;
}