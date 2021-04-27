/*56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/

#include <stdio.h>
#include <stdlib.h>


int Compare(const void* a, const void* b)
{
    int** a1 = (int**)a;
    int** b1 = (int**)b;
    // 起点相同的时候, 按照终点降序
    if (a1[0][0] == b1[0][0]) {
        return b1[0][1] - a1[0][1];
    }
    return a1[0][0] - b1[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(intervalsSize*sizeof(int*));
    // *returnSize=2;
    // printf(">>>%p\n",returnSize);
    return intervals;
}

int searchRange2(int* returnSize){
    int lth = 2;
    *returnSize = lth;
    return 0;
}


int main(int argc, char const *argv[])
{
    int intervalsSize = 4;
    int** intervals = (int**)malloc(intervalsSize*sizeof(int*));
    for (int i=0;i<intervalsSize;i++){
        intervals[i]=(int *)malloc(sizeof(int) * 2);
    }
    intervals[0][0]=1;
    intervals[0][1]=3;
    intervals[1][0]=2;
    intervals[1][1]=6;
    intervals[2][0]=8;
    intervals[2][1]=10;
    intervals[3][0]=15;
    intervals[3][1]=18;

    // int* intervalsColSize;
    int* returnSize;
    // int** returnColumnSizes;

    int a = searchRange2(returnSize);
    // int** aa = merge(intervals, intervalsSize,intervalsColSize,returnSize,returnColumnSizes);
    // for (int i=0;i<4;i++){
    //     for(int j=0;j<2;j++){
    //         printf("%d,",aa[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}