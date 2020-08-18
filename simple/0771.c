// 771. 宝石与石头
// 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
// J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

// 输入: J = "aA", S = "aAAbbbb"
// 输出: 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numJewelsInStones(char * J, char * S){
    int ret = 0;

    int map[128] = {0};
    for (int i=0;i<strlen(J);i++){
        map[J[i]] = 1;
    }

    for (int i=0;i<strlen(S);i++){
        if (map[S[i]] == 1){
            ret++;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int aa = numJewelsInStones("aA", "aAAbbbb");
    printf("->%d\n", aa);
    return 0;
}
