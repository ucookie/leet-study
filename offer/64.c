// 剑指 Offer 64. 求1+2+…+n

// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// 输入: n = 3
// 输出: 6
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int sumNums(int n){
    n && (n += sumNums(n - 1));
    //&&如果第一个就为假就不会在看之后的条件。同理||中第一个为真也不会在执行后面的条件。
    return n;
    //根据这个实现了判断的效果，这样，当n为0的时候就会停止调用函数。同理也可以借此过滤，自增自减运算符。
    //上一个句中说的n是递归内层的形参的n。最外层的n是一个 n（初始状态）+（循环体）的形式。所以不会影响返回的值
}

int sumNums2(int n){
    // 充分利用了C/C++的指针算术运算，精妙的解答，如果真要说缺点的话，默认short是2个字节大小
    return (short*)n[(char(*)[n+1])0] - (short*)0;
}

int know2(){
    // 预备知识
    int a[6] = { 0, 1, 2, 3, 4, 5 };
    int *p = a;
    printf("%d %d\n", p[2], 2[p]);

    assert(p[2] == 2[p]);
    assert(&p[2] == &2[p]);

    // char a[n][n + 1]的结束地址
    // char (*p)[n + 1] = a;
    // assert(&a[n] == p[n]);
    // assert(&a[n] == n[p];
    // 类型转换：0 转换成指向大小n +1的数组的指针 (char (*)[n + 1]) 0 与上面的p作用相同。替换以后得到结束地址

    // char *begin = 0;
    // char (*p)[n + 1] = (char (*)[n + 1]) begin;
    // char *end = (char *)p[n];
    // printf("%d\n", (end - begin) >> 1);
}


int main(int argc, char const *argv[])
{
    know2();
    // int aa = sumNums(3);
    // printf("=%d\n", aa);
    return 0;
}
