#include<stdio.h>

//使用const保护其内部的值不会被修改
int Strlen1(const char *s);
int Strlen2(const char *s);
int Strlen3(const char *s);

int main() {
    return 0;
}

//第一种最简单的思路，遍历一边字符串
int Strlen1(const char *s) {
    int len = 0;
    
    while (s[len] != '\0') {
        len++;
    }
    
    return len;
}

//第二个版本 简化循环体内部
int Strlen2(const char *s) {
    int len = 0; // '\0' 是不包含在长度内的

    while (s[len++] != '\0') ;

    return len - 1;

}

//第三个版本 
int Strlen3(const char *s) {
    int len = -1;

    while (s[++len != '\0'] ) ;

    return len;
}

//标准库的版本 指针运算
size_t StrLenStd(const char *s) {
    const char *sc;
    for (sc = s; *sc != '\0'; ++sc);

    return sc -s;
}

//s字符串的长度和max的最小值 
size_t StrNlen(const char *s, size_t max ){
    size_t count = 0;

    while (max && *s ) {
        count++;
        s++;
        max--;
    }

    return count;
}