// 438. 找到字符串中所有字母异位词
// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100

// 说明：
// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。

// 输入:
// s: "cbaebabacd" p: "abc"

// 输出:
// [0, 6]

// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize){
    int idx_lth = 0;



    *returnSize = idx_lth;
    int* idx_list = (int*)malloc(idx_lth*sizeof(int));


    return idx_list;
}

int main(int argc, char const *argv[])
{
    char* s = "cbaebabacd";
    char* p = "abc";
    int* returnSize;

    int* aa = findAnagrams(s, p, returnSize);
    for (int i=0;i<*returnSize;i++){
        printf("%d,", aa[i]);
    }
    printf("\n");
    return 0;
}
