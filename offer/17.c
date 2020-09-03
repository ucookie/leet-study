// 剑指 Offer 17. 打印从1到最大的n位数

// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
// 输入: n = 1
// 输出: [1,2,3,4,5,6,7,8,9]

// 说明：
//     用返回一个整数列表来代替打印
//     n 为正整数
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* printNumbers2(int n, int* returnSize){
    int size=(int)(pow(10.0,n)-1);
    int *output=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        output[i]=i+1;
    }
    *returnSize=size;
    return output;
}


int* printNumbers(int n, int* returnSize){
    int end_num = 1;
    while (n>0)
    {
        end_num *= 10;
        n--;
    }

    *returnSize = end_num-1;
    int* ret = (int*)malloc(*returnSize*sizeof(int));

    for (int i=0;i<*returnSize;i++){
        ret[i] = i+1;
    }

    return ret;
}


int main(int argc, char const *argv[])
{
    int* returnSize;
    int* aa = printNumbers2(1, returnSize);

    for (int i=0;i<*returnSize;i++){
        printf("%d,", aa[i]);
    }
    return 0;
}
