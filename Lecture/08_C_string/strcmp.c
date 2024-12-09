#include <stdio.h>

//按字典需比较 
//相等的时候返回0,s1>s2的时候返回正数，s1<s2的时候返回负数
int StrCmp(const char *s1, const char *s2);
int StrCmpStd(const char*s1, const char *s2);
int StrCmpGlibc(const char*s1, const char *s2);

int main() {
    return 0;
}


int StrCmp(const char *s1, const char *s2) {
    while (*s1 == *s2 && *s1 & *s2) {
        s1++;
        s2++;
    }
    //char 类型有可能是无符号也可能是有符号数 所以不能直接*s1 - *s2
    //crefrence里面建议全部解释成无符号数
    return *(unsigned char *)s1 - *(unsigned char *)s2;    
}