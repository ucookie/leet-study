#include <stdio.h>
#include <stdlib.h>

int fib(int N){
    if (N==0){
        return 0;
    }
    if (N==1){
        return 1;
    }

    int* nums = (int*)malloc((N+1)*sizeof(int));
    nums[0]=0;
    nums[1]=1;
    for (int i=2;i<=N;i++){
        nums[i] = nums[i-1] + nums[i-2];
    }
    return nums[N];
}

int main(int argc, char const *argv[])
{
    printf("->%d\n", fib(10));
    return 0;
}