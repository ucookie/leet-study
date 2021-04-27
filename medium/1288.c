/*
1288. 删除被覆盖区间
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
在完成所有删除操作后，请你返回列表中剩余区间的数目。
输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
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

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int i;
    int cnt, end;
    qsort(intervals, intervalsSize, sizeof(int*), Compare);

    end = intervals[0][1];
    cnt = 1;
    for (i = 1; i < intervalsSize; i++) {
        if (end < intervals[i][1]) {
            cnt++;
            end = intervals[i][1];
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int intervalsSize = 3;
    int** intervals = (int**)malloc(intervalsSize*sizeof(int*));
    for (int i=0;i<intervalsSize;i++){
        intervals[i]=(int *)malloc(sizeof(int) * 2);
    }
    intervals[0][0]=1;
    intervals[0][1]=4;
    intervals[1][0]=1;
    intervals[1][1]=6;
    intervals[2][0]=2;
    intervals[2][1]=8;
    for (int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%d,",intervals[i][j]);
        }
        printf("\n");
    }

    int* intervalsColSize;
    int aa = removeCoveredIntervals(intervals, intervalsSize,intervalsColSize);
    printf("-->%d\n",aa);
    return 0;
}