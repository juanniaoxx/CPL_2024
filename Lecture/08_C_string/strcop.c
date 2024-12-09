//拷贝字符串

#include <stdio.h>

void StrCopy1(char *dest, const char *src);
void StrCopy2(char *dest, const char *src);
void StrCopy3(char *dest, const char *src);
void StrCopy4(char *dest, const char *src);
void StrCopy5(char *dest, const char *src);
void StrCopy6(char *dest, const char *src);
char *StrCopyStd(char *dest,const char *src);

int main() {
    return 0;
}

// *dest只需要指向一个足够大的空间即可
//*src 需要指向一个以 ‘\0’结尾即需要是一个C_string
void StrCopy1(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

void StrCopy2(char *dest, const char *src) {
    int i = 0;

    //先赋值再比较
    while ((dest[i] = src[i]) != '\0') i++;
}

void StrCopy3(char *dest, const char *src) {
    int i = 0;

    //dest[i]: *(dest + i)
    while ((*(dest + i) = *(src + i)) != '\0') i++;
}

void StrCopy3(char *dest, const char *src) {
    //dest[i]: *(dest + i)
    while ((*dest = *src) != '\0') {
        dest++;
        src++;
    };
}
void StrCopy5(char *dest, const char *src) {

    //后缀++ >前缀++  = 解引用
    //*(dest++) = *(src++) --->*(src++) ---->解引用的是dest,src
    //而非解 dest + 1 和 src + 1
     while ((*dest++ = *src++) != '\0');
}

void StrCopy6(char *dest, const char *src) {
    while (*dest++ = *src++) ;
}

//标准库版本 返回被拷贝地址的首地址
char *StrCopyStd(char *dest,const char *src) {
    for (char *s = dest; (*s++ = *src++) != '\0'; );
    return dest;

}