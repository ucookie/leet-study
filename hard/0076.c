// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 76.

// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

// 输入：s = "a", t = "a"
// 输出："a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAX 127

char * minWindow(char* s, char* t){
    int s_lth = strlen(s);
    int t_lth = strlen(t);

    int need[HASH_MAX] ={0};
    int window[HASH_MAX] = {0};

    // 初始化目标字典
    for (int i=0; i<t_lth;i++){
        need[t[i]]++;
    }
    // 统计满足条件的个数
    int need_size = 0;
    for (int i=0;i<HASH_MAX;i++) {
        if (need[i]!=0) need_size++;
    }

    int left = 0, right = 0;
    int valid = 0; // 满足need条件的个数

    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = __INT_MAX__;

    while (right<s_lth){
        // c 是待移入字符
        char c = s[right];

        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        if (need[c]){
            window[c]++;
            if (window[c]==need[c]){
                valid++;
            }
        }

        // 判断左边是否收缩
        while (valid==need_size){
            // 更新最小子串
            if (right - left < len){
                start = left;
                len = right - left;
            }
            // d 是移除窗口的字符
            char d = s[left];
            left++;
            if (need[d]){
                if (window[d]==need[d]){
                    valid--;
                }
                window[d]--;
            }
        }
    }

    if (len==__INT_MAX__){
        return "";
    }

    char* ret = (char*)malloc(sizeof(char)*(len+1));
    *ret = '\0';
    strncat(ret, s+start, len);
    return ret;
}


int main(int argc, char const *argv[])
{
    // char* s = "ADOBECODEBANC";
    // char* t = "ABC";

    char* s = "aa";
    char* t = "aa";

    // char* s = "acbbaca";
    // char* t = "aba";

    char* aa = minWindow(s, t);
    for (int i=0;i<strlen(s);i++){
        printf("%c", s[i]);
    }
    printf("\n");
    for (int i=0;i<strlen(aa);i++){
        printf("%c", aa[i]);
    }
    printf("\n");
    return 0;
}
