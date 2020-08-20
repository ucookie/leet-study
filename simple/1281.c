// 1281. 整数的各位积和之差

#include <stdio.h>
#include <stdlib.h>

// 给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

// 输入：n = 234
// 输出：15
// 解释：
// 各位数之积 = 2 * 3 * 4 = 24
// 各位数之和 = 2 + 3 + 4 = 9
// 结果 = 24 - 9 = 15
// 1 <= n <= 10^5

int subtractProductAndSum(int n){
    int sum=0,product=1,tmp=0;
    while (n)
    {
        tmp = n%10;
        product = product*tmp;
        sum = sum+tmp;
        n = n/10;
    }
    return (product-sum);
}

int main(int argc, char const *argv[])
{
    int aa = subtractProductAndSum(234);
    printf("%d\n", aa);
    return 0;
}
