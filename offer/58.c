// 剑指 Offer 58 - II. 左旋转字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

char* reverseLeftWords(char* s, int n){
    int lth = strlen(s);
    int _lth = lth - n;
    char* ret = (char* )calloc(lth+1,sizeof(char));// +1 为了给 '\0'留空间

    for (int i=0;i<lth;i++){
        if (i<n){
            ret[i+_lth] = s[i];
        }else{
            ret[i-n] = s[i];
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    char* s = "lrloseumgh";
    int n = 6;

    char* aa = reverseLeftWords(s, n);
    for (int i=0;i<strlen(s);i++){
        printf("%c", aa[i]);
    }
    printf("\n");
    return 0;
}
