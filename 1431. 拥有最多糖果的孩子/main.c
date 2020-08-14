#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    if (candies == NULL || candiesSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    bool* ret = (bool*)malloc(candiesSize * sizeof(bool));
    if (ret == NULL) {
        return NULL;
    }

    int maxNum = 0;
    for (int i = 0; i < candiesSize; ++i) {
        maxNum = maxNum > candies[i] ? maxNum : candies[i];
    }

    for (int i = 0; i < candiesSize; ++i) {
        ret[i] = candies[i] + extraCandies >= maxNum ? true : false;
    }

    *returnSize = candiesSize;
    return ret;
}

int main()
{
    int candiesSize = 5;
    int* candies = (int *)malloc(candiesSize * sizeof(int));
    int extraCandies = 3;
    int* returnSize = (int *)malloc(candiesSize * sizeof(int));

    candies[0] = 2;
    candies[1] = 3;
    candies[2] = 5;
    candies[3] = 1;
    candies[4] = 3;

    bool* aa = kidsWithCandies(candies, candiesSize, extraCandies, returnSize);
    for(int i=0;i<candiesSize;i++)
    {
        printf(":%d\n", aa[i]);
    }
}



