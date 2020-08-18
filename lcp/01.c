// LCP 01. 猜数字
// 输入：guess = [1,2,3], answer = [1,2,3]
// 输出：3
// 解释：小A 每次都猜对了。

    // guess的长度 = 3
    // answer的长度 = 3
    // guess的元素取值为 {1, 2, 3} 之一。
    // answer的元素取值为 {1, 2, 3} 之一。

// 小A 和 小B 在玩猜数字。小B 每次从 1, 2, 3 中随机选择一个，小A 每次也从 1, 2, 3 中选择一个猜。他们一共进行三次这个游戏，请返回 小A 猜对了几次？
// 输入的guess数组为 小A 每次的猜测，answer数组为 小B 每次的选择。guess和answer的长度都等于3。

#include <stdio.h>

int game(int* guess, int guessSize, int* answer, int answerSize){
    int ret = 0;
    for (int i=0;i<guessSize;i++){
        if (guess[i]==answer[i]){
            ret++;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int* guess[3]={1,2,3};
    int* answer[3]={1,2,3};
    int aa = game(guess, 3, answer, 3);
    printf("->%d\n", aa);
    return 0;
}
