// 1528. 重新排列字符串

// 给你一个字符串 s 和一个 长度相同 的整数数组 indices 。

// 请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。

// 返回重新排列后的字符串。

// 输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
// 输出："leetcode"
// 解释：如图所示，"codeleet" 重新排列后变为 "leetcode"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * restoreString(char * s, int* indices, int indicesSize){
    char* ret = (char* )calloc(indicesSize+1,sizeof(char));
    for (int i=0;i<indicesSize;i++){
        ret[indices[i]]=s[i];
    }
    ret[indicesSize] = '\0';
    return ret;
}

int main(int argc, char const *argv[])
{
    char*s = "codeleet";
    int indices[8] = {4,5,6,7,0,2,1,3};
    char* aa = restoreString(s, indices, 8);
    for (int i=0;i<strlen(aa);i++){
        printf("%c,", aa[i]);
    }
    return 0;
}
