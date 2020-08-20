// 1108. IP 地址无效化

// 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本
// 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

// 输入：address = "1.1.1.1"
// 输出："1[.]1[.]1[.]1"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address){
    int lth = strlen(address)+6+1;
    char* ret = (char*)calloc(lth, sizeof(char));

    char* p = address;
    for (int i=0;i<lth;i++){
        if (*p == '.'){
            ret[i] = '[';
            ret[i+1] = '.';
            ret[i+2] = ']';
            i = i+2;
        }else{
            ret[i] = *p;
        }
        p = p+1;
    }
    ret[lth-1] = '\0';
    return ret;
}

int main(int argc, char const *argv[])
{
    char* address = "1.1.1.1";
    char* aa = defangIPaddr(address);

    for (int i=0; i<strlen(aa);i++){
        printf("%c", aa[i]);
    }
    printf("\n");
    return 0;
}
