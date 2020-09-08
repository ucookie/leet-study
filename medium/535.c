// 535. TinyURL 的加密与解密

// TinyURL是一种URL简化服务
// 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl 时，
// 它将返回一个简化的URL http://tinyurl.com/4e9iAk.

// 要求：设计一个 TinyURL 的加密 encode 和解密 decode 的方法
// 你的加密和解密算法如何设计和运作是没有限制的，
// 你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    return longUrl;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    return shortUrl;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);

int main(int argc, char const *argv[])
{
    char* url = "https://leetcode.com/problems/design-tinyurl";
    char* aa = encode(url);

    for (int i=0;i<strlen(aa);i++){
        printf("%c", aa[i]);
    }
    printf("\n");

    char* bb = decode(aa);
    for (int i=0;i<strlen(aa);i++){
        printf("%c", aa[i]);
    }
    printf("\n");

    return 0;
}
