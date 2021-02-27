// 3. 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串的长度。

// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

#include <stdio.h>
#include <string.h>

#define HASH_MAX 127

int lengthOfLongestSubstring(char * s){

    int s_lth = strlen(s);

    int window[HASH_MAX]={0};

    int left=0, right=0;
    int res = 0;
    while (right<s_lth){
        char c = s[right];
        right++;
        window[c]++;
        while (window[c]>1){
            char d=s[left];
            left++;
            window[d]--;
        }
        res = res>(right-left)?res:(right-left);
    }

    return res;
}

int main(int argc, char const *argv[]){
    char* s = "abcabcbb";

    int aa = lengthOfLongestSubstring(s);

    printf("结果: %d\n", aa);

}