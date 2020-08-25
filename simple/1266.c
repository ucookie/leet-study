// 1266. 访问所有点的最小时间
// 平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi]。请你计算访问所有这些点需要的最小时间（以秒为单位）。

// 你可以按照下面的规则在平面上移动：

//     每一秒沿水平或者竖直方向移动一个单位长度，或者跨过对角线（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
//     必须按照数组中出现的顺序来访问这些点。

// 输入：points = [[1,1],[3,4],[-1,0]]
// 输出：7
// 解释：一条最佳的访问路径是： [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
// 从 [1,1] 到 [3,4] 需要 3 秒
// 从 [3,4] 到 [-1,0] 需要 4 秒
// 一共需要 7 秒
#include <stdio.h>
#include <stdlib.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int ret = 0, x_diff,y_diff;
    for (int i=0;i<pointsSize-1;i++){
        // 计算 x 坐标差
        if (points[i][0]<points[i+1][0]){
            x_diff = points[i+1][0] - points[i][0];
        }else{
            x_diff = points[i][0] - points[i+1][0];
        }
        // 计算 y 坐标差
        if (points[i][1]<points[i+1][1]){
            y_diff = points[i+1][1] - points[i][1];
        }else{
            y_diff = points[i][1] - points[i+1][1];
        }
        ret += x_diff>y_diff?x_diff:y_diff;
    }
    return ret;
}

int minTimeToVisitAllPoints2(int** points, int pointsSize, int* pointsColSize){
    int i, time=0, x_d, y_d;

    for(i=1;i<pointsSize;i++)
    {
        x_d = abs(points[i][0] - points[i-1][0]);  // 两点x坐标之差
        y_d = abs(points[i][1] - points[i-1][1]);  // 两点y坐标之差

        if(x_d < y_d)
            time += y_d;
        else
            time += x_d;
    }
    return time;
}


int main(int argc, char const *argv[])
{
    int pointsSize = 3;
    int** points = (int**)malloc(pointsSize*sizeof(int*));
    points[0] = (int*)malloc(2*sizeof(int));
    points[0][0] = 1;
    points[0][1] = 1;
    points[1] = (int*)malloc(2*sizeof(int));
    points[1][0] = 3;
    points[1][1] = 4;
    points[2] = (int*)malloc(2*sizeof(int));
    points[2][0] = -1;
    points[2][1] = 0;

    int* pointsColSize;
    int aa = minTimeToVisitAllPoints(points, pointsSize, pointsColSize);
    printf("==%d\n", aa);
    return 0;
}

