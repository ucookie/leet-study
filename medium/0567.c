// 567. 字符串的排列
// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

// 换句话说，第一个字符串的排列之一是第二个字符串的子串。

// 输入: s1 = "ab" s2 = "eidbaooo"
// 输出: True
// 解释: s2 包含 s1 的排列之一 ("ba").

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_MAX 127

bool checkInclusion(char * s1, char * s2){
    int s1_lth = strlen(s1);
    int s2_lth = strlen(s2);

    int need[HASH_MAX] = {0};
    int window[HASH_MAX] = {0};

    for (int i=0; i<s1_lth;i++) need[s1[i]]++;
    int need_size = 0;
    for (int i=0;i<HASH_MAX;i++) if (need[i]!=0) need_size++;

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, len = __INT_MAX__;
    while (right< s2_lth){
        char c = s2[right];
        right++;
        if(need[c]){
            window[c]++;
            if (window[c]==need[c]) valid++;
        }
        while (right-left>=s1_lth){
            // 判断符合条件退出
            if (valid==need_size) return true;

            char d = s2[left];
            left++;
            if (need[d]){
                if (window[d]==need[d]) valid--;
                window[d]--;
            }
        }

    }

    return false;
}

int main(int argc, char const *argv[])
{
    char* s1 = "ab";
    char* s2 = "eidbaooo";

    bool aa = checkInclusion(s1, s2);
    printf("结果:%d\n", aa);
    return 0;
}
