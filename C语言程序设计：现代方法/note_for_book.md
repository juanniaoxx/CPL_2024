## C语言程序设计：现代方法

### chapter 3格式化输入/输出

> ### `gtchar()`的返回值为`int`而非`char`
>
> ```c
> char ch = getchar(); // 是合理的，只是发生了隐藏的类型转换而已
> int ch = getchar(); // 未发生强制类型转换
> ```
>
> 看一下getchar()的签名
>
> ```c
> int getchar( void )
> ```

### chapter 4 表达式

> [!Important]
>
> ["C operator Precedence"](https://en.cppreference.com/w/c/language/operator_precedence)

> [!Tip]
>
> C更多的强调表达式而非语句。

> [!Note]
>
> C/C++的`%`只和==左操作数==有关  [c99表明除法结果趋零截尾]
>
> 左右操作数只能是==整数==
>
> > %的本质是 $a \% b=a-(a/b)\times b$
>
> ```c
>     printf("1 %% 2 = %d\n", 1 % 2);
>     printf("-1 %% 2 = %d\n", -1 % 2);
>     printf("1 %% -2 = %d\n", 1 % -2);
>     printf("-1 %% -2 = %d\n", -1 % 2);
> 
> // output
> 1 % 2 = 1
> -1 % 2 = -1
> 1 % -2 = 1   //右操作数为负数，但结果为正
> -1 % -2 = -1 //左右操作数均为负数，结果应该是正数
> ```

**赋值语句的左操作数必须是==左值(lvalue)==**

> 左值（lvalue)
>
> 左值表示**对象[^1]**，而不是常量或者计算的结果。

> ### 前缀++与后缀++
>
> `prefix`: 先对变量进行自增，然后返回自增后的值
>
> `postfix`:先返回变量当前的值，然后对变量进行自增
> ==重点区别优先级顺序==

> [!Warning]
>
> `未定义行为 (undefined behavior)`
>
> 是指程序的代码没有明确的意义或行为，而标准也没有规定该代码的行为会产生什么结果。换句话说，当程序运行到未定义行为的代码时，**编译器不对结果负责**，程序可能会出现任何后果，包括但不限于崩溃、错误结果、甚至正常运行。



[^1]: C语言中对象(Object):region of data storage in the execution environment, the contents of which can represent values



### 选择语句 与 循环

> [!Note]
>
> `!` < 逻辑运算符 `&&`  `||`  < 关系运算符 < 算术运算符



> ### 悬空else ---- if-else 配对问题
>
> ```c 
> if (y != 0)
>     if ( x != 0)
>         result = x /y;
> else 
>     printf("Error: y is equal to 0\n");
> ```
>
> C标准规定`else`语句必须与离它最近且为匹配的`if`匹配,与形式缩进无关。

> #### C99布尔值
>
> ```c 
> _Bool flag;  //_Bool是(无符号)整数类型
> ```
>
> ```c
> #include <stdbool.h>  
> bool flag; //  same as _Bool flag;
> flag = false;
> flag = true;
> ```

> #####  `break` VS `continue`
>
> `break` 会直接跳出循环
>
> ```c
> while (1) {
>     //...
>     break;
> }
> // break 后直接到第5行
> ```
>
> `continue` 只是跳出本次循环
>
> ```c
> while(1) { // 跳转到循环入口
>     // ...
>     continue;
> }
> 
> ```

> ### goto 语句
>
> 在C99之前 goto可以跳转到任何地方，但C99后，goto语句不可以跳过`变长数组的声明`
>
> 即使这样 ==不推荐在任何代码里面使用goto==



### chapter 7 基本类型

> ##### 有符号数溢出 VS 无符号溢出
>
> 有符号整数运算中发生溢出时，程序的行为是`未定义的`
>
> 无符号整数运算中发生溢出时，结果是有定义的：`正确答案对2^n取模`

`size_t sizeof 运算符` 允许程序获取存储指定类型所需要的内存空间

 ```c
 typerdef unsigned size size_t;
 printf("Size of int: %zu\n", sizeof(int)); // 使用%zu显示sizeof
 ```

### chapter 8 数组

数组名本质是`指针`

比较常见的数组使用方式有

```c
for (i = 0; i < N; i++)
    	a[i] = 0;

for (i = 0; i < N; i++)
    	scanf("%d",&a[i]); // 注意如果使用a[i]则需要取地址 

```

> #### `[]` 🍬
>
> `[]`的本质是指针运算的语法糖🍬
>
> ```c
> a[i]   等价于  *(a + i)
> ```

> #### 指示器(C99)
>
> 一种特殊的初始化数组的方式
>
> ```c
> int a[15] = {[2] = 29, [9] = 7, [14] = 48};
> ```



> ##### 变长数组（C99)
>
> 通常情况下数组长度必须用`常量表达式`定义,但C99中，有时候也可以可以是常量表达式
>
> ```c
>  int n = 0;
>  scanf("%d", &n);
>  int a[n];
> 
>  for (int i = 0; i < n; i++) {
>      a[i] = i;
>      printf("%d ", a[i]);
>  }
> ```
>
> > [!note]
> >
> > 变长数组的长度在运行时候确定，但在数组的生命周期内仍然是固定长度的。
> >
> > 如果需要动态扩展数组长度需要`malloc`

> ##### C99 复合字面量
>
> ```c
> // 指向有5个元素的数组的第一个元素的指针
> int *p = (int [])(3, 0, 3, 4, 1); 
> ```
>
> **其生命周期限定在表达式的执行期间，使用完后会被销毁。**

### chapter 9 函数

> C语言 典型的`按值传递`

> ### 变长数组形式参数
>
> 下面的声明是合法的
>
> ```c
> int sum_array_1(int n, int a[n]); //  n用于指明变长数组的长度
> int sum_array_2(int n, int a[*]); // 可以用 * 代替数组长度
> int sum_array_3(int , int [*]); // 省去形参名字
> ```
>
> 但下面这种声明是==非法==的
>
> ```c
> int sum_array_worse(int a[n], int n); // error:
> ```
>
> 

> #### `static`使用于参数
>
> 用于庙宇数组a的长度至少保证是3
>
> ```c
> int sum_array_static(int a[static 3], int n) {
>     // ......
> }
> ```
>
> `对于多维数组，static仅可用于第一纬`

> #### 泛型选择`C1X`
>
> ```c
> _Generic( 表达式, 泛型关联列表)
> ```
>
> `sin 不同类型选择`
>
> ```c
> #define generic_sin(x) _Generic((x),\
>                         float: sinf,\
>                         double: sin,\
>                         long double: sinl,\
>                         float _Complex: csinf,\
>                         double _Complex: csin,\
>                         long double _Complex: csinl)(x)
> ```



###  chapter 10 程序结构

> ###### 可供参考的单文件结构
>
> - #include 指令;
> - #define 指令;
> - 类型定义;
> - 外部变量的声明;
> - 除main函数以外的函数原型;
> - main函数的定义
> - 其他函数的定义 // 采用盒型注释解释函数



> ## `exit(0)` vs `return 0`
>
> 对于`main`函数内的这两个函数效果一致，都是结束程序。
>
> 但位于其他位置的二者有区别
>
> `return 0` 如果是合法返回值会跳会调用者，如果非法，编译不通过。
>
> `exit(0)` 在任何位置都会直接结束程序

### 指针(11)、指针与数组、字符串、高级应用(12、17)

> ##### 关于指针最关键的点：确认类型

> ## 为啥要引入指针
>
> - C语言默认是按值传递参数，有时候修改修改参数就很不方便。
> - 把函数从非一等公民转换为函数指针，从而能和变量一样操作
> - 已经和内存的直接操作（动态内存管理、实现的复杂的数据结构....)
> - 用指针操作数组更高效

> ### 永远不要返回自动局部变量的指针
>
> ```c 
> int *f(void) {
>     int i; 
>     // ....
>     return &i;
> }
> ```
>
> 使用`static`可以使得代码合法，但不一定合理。
>
> ```c
> int *f(void) {
>     static int  i; 
>     // ....
>     return &i;
> }
> ```

指针与数组的关系，一句话:**数组的名字就是指向数组的第一个元素的指针**

> ##### 二维数组的名字
>
> `int a[3][3]`
>
> 类比一下一维数组，二维数组的名字是指向`a[0][0]`的`int *`类型的指针吗？
>
> <span style="color:red">错误</span>
>
> 要理解，C语言底层是没有啥二维数组（多纬），只有一维数组。
>
> ![image-20241209100123783](assets/二维数组.png)
>
> 所以`a->a[0]` 即二维数组的名字是一个指向数组的指针类型为`int (*)[3]` 

   

> #### C99中的指针和变长数组
>
> 指向一维变长数组的情况
>
> ```c
> void f(int n) {
>     int a[n], *p;
>     p = a;
>     // ....
> }
> ```
>
> 指向二维变长数组的情况
>
> ```c
> void f(int m, int n) {
>     int a[m][n], *(p)[n];
>     p = a;
> }
> ```
>
> 回顾一下指向二维数组名字的类型是啥？
>
> 此时p具有 **变量修改类型[^2]**

[^2]: 变量修改类型的声明必须出现在函数体内部或者函数原型中

**C风格字符串** C的字符串本质是`字符数组`且以`\0`结尾

> ## 字符串拼接(splicing)
>
> 传统上使用`\`来连接两个字符串，但由于该字面串必须从下一行的起始位置继续。会破环缩进风格
>
> ```c
> printf("When you come to a fork in the road, take it.
> --Yogi Berra");
> ```
>
> 现在一般采用如下规则`当两条或更多条字面串相邻时（仅用空白字符分割），编译器会把它们合并成一条字符串`
>
> ```c
> // 可以保存缩进风格
> printf("When you come to a fork in the road, take it. "
> 	        "--Yogi Berra");
> ```

> ### 注意，不可以通过指针修改字符串字面量

```c
char *p = "abc";

*p  = "d"; // 非法
```

原因参考课程Note，字面串存储与只读区域内。

> #### 风格：字符串定义
>
> ```c
> #define  STR_LEN 80 
> // ...
> char str[STR_LEN + 1];
> ```
>
> 定义长度的时候会声明字符串的元素个数，但在声明string的时候会把末尾的`\0`加上。
>
> ```c
> char date4[] = "June 14"; // 用初始化器定义的字符串长度可以省去，但以后不可以修改长度。
> ```

> ### 指向字符串的指针，与字符串名字的类型
>
> ```c
> char str[STR_LEN + 1];
> ```
>
> `str`的类型是啥？ ------- `char *`，字符串的本质是一维字符数组。根据数组与指针的关系可以知道，数组名为指向第一个元素(char)的指针,即`char *`
>
> 那么指向字符串的指针是啥类型呢?
>
> ```c
> (?)p =  &str;
> ```
>
> str的类型是`char *`是个指针，所以p是<span style="color:blue">指向指针的指针</span> ----> `char **`
>
> ```c
> char **p = &str;
> ```

> # <string.h>
>
> - strcpy函数 `char *strcpy(char *dest, const char *src)` <span style="color:red">字符串复制</span>
>   - 返回值`char *` 返回指向dest的指针
>   - `strncpy` [更安全的版本] `char *strncp( char *dest, const char *src, size_t count);`
> - [strlen](https://en.cppreference.com/w/c/string/byte/strlen)函数 `size_t strlen(const char *str)` <span style="color:red">字符串长度</span>
>   - 返回str第一个空字符之前的字符个数（不包括空字符）
> - [strcat](https://en.cppreference.com/w/c/string/byte/strcat)函数 `char *strcat(char *dest, const char *src)` <span style="color:red">字符串拼接</span>
>   - 把src的内容追加到dest的末尾，并返回指向dest的指针
> - [strcmp](https://en.cppreference.com/w/c/string/byte/strcmp)函数 `int strcmp(const char *lhs, const char* rhs)` <span style="color:red">字符串比较</span>
>   - 按字典序比较 [本质按ASCII码比较]
>     - 大写字母小于小写字母
>     - 数字全都小于字母
>     - 空白符号小于所有打印字符
>   - lhs > rhs ---> 大于0 , lhs == rhs ----> 0, lhs < rhs ----> 小于0

> #### 风格化建议
>
> - 搜索字符串结尾的空字符
>
> ```c
> // s 最终会指向空字符
> while (*s)
>     s++;
> 
> // s最终会指向空字符的下一个位置
> while (*s++)
>     ;
> ```
>
> - 字符串复制
>
> ```c
> while ((*p++ = *s2++) != 0)
>     ;
> ```
>
> - 字符串数组（不采用二维数组，而采用指针数组）
>
> ```c
> char *planets[] = {"Mercury", "Venus", "Earth",
>                           "Mars", "Jupiter", "Saturn",
>                           "Uranus", "Neptune", "Pluto"};
> ```
>
> ![image-20241209113224106](assets/字符串数组.png)

> ##### 程序参数（命令行参数）
>
> C语言main有两个原型
>
> ```c
> int main(void); // 通常情况
> int main(int argc, char *argv[]);  // 接受命令行参数
> ```
>
> - argc : 参数个数
> - argv : 参数向量 
>   - 特别的argv[0] 指向 程序名
>   - argv[1]---argv[n-1]命令行参数

> # 内存分配函数 <stdlib.h>
>
> - malloc 函数 ---- 分配内存块，但是不会对内存块进行初始化
>
> 函数签名 `void *malloc(size_t size);`
>
> - calloc 函数 ----- 分配内存块，并且对内存块进行清零
>
> 函数签名 `void *calloc( size_t num, size_t size);`
>
> - realloc 函数 ----- 调整先前分配的内存块大小
>
> 函数签名 `void *realloc(void *ptr, size_t new_size);`
>
> 一种malloc更常见的规范，避免硬编码
>
> ```c
> int *p = NULL;
> p = malloc(n *sizeof (*p) ); // 创建n个元素的整数数组
> ```

> ### 动态分配的内存一定要记得`free()`

> ## 悬空指针
>
> free()后会导致悬空指针，需要特别注意。
>
> ```c
> char *p = malloc(4 * sizeof char);
> char *pp = p;
> // ...
> free(p);
> // 此时p 和pp都成了悬空指针
> strcpy(p, "abc"); // 会导致为定义行为
> ```
>
> 常用解决办法
>
> - 使用前判断指针是否为NULL ---> 使用指针前尽量保证指针有效
>
> ```c
> char *p = malloc(4 * sizeof char);
> char *pp = p;
> // ...
> free(p);
> // 此时p 和pp都成了悬空指针
> if (p != NULL) strcpy(p, "abc";)
> ```

> #### 受限指针（restricted pointer）
>
> ```c
> int *restrict p;
> ```
>
> 如果p指向的对象之后需要修改，不能通过p以外的任何方式访问（让另一个指针指向同一个对象，或者让指针p指向命名变量）。
>
> **memcpy and memmove**
>
> 函数签名 `void *memcpy(void * restrict s1, const void * restrict s2, size_t n);`
>
> 函数签名 `void *memmove(void *s1, const void * s2, size_t n);`
>
> 区别`memcpy` 的参数是带`restrict`的受限指针，而`memmove`是普通的指针。
>
> > ### `memcpy`的dest 和 src 不能相同 【由受限指针保证】

> #### 弹性数组成员 fiexible array member
>
> 目的：**动态结构体数组**
>
> ```c
> struct vstring {
>     int len;
>     char chars[]; // 可以定义一个长度为0的数组
> };
> 
> struct vstring *str = malloc(sizeof(struct vstring) * n);
> str -> len = n;
> ```
>
> > [!important]
> >
> > 弹性数组在结构内并不占空间
> >
> > 弹性数组成员必须出现在结构的最后，而且结构必须至少还有一个其他成员。
> >
> > 复制弹性数组成员的结构时，其他成员会被复制但不复制弹性数组本身。
>
> > ### 弹性数组是不完整类型（incomplete type）



### 声明 

> # 声明的构成
>
> 1. 存储类型: auto、static、extern和register。
> 2. 类型限定符 const、volatile、（c99）restrict、(c1x)_Atomic
> 3. 类型制定符 类似于int, double...
> 4. 函数制定符 (c99) `inline` (c1x)_Noreturn
> 5. 声明符  变量名字
> 6. 初始化器 初始化值

> [!important]
>
> 变量的性质：`存储期` `作用域` `链接`

> ### 默认性质
>
> - 在块内部定义的变量 `自动存储期(auto)`  `块组用域` `无链接`
> - 在程序的最外层（任意块外部） `静态存初期(static)` `文件作用域` `外部链接`



> ## 存储类型（四个）
>
> `auto` 只对属于块的变量有效，大多数情况下为默认的。具有auto的变量始终为`块作用域`并且`无链接`
>
> `static` 可用于全部变量，并且无需考虑变量的声明位置。 
>
> 	- 作用于**块外部**，说明变量的存储周期变成静态，具有`内部链接` , `文件作用域`
> 	- 作用于**块内部**，只是把变量的存储周期变成静态,`无链接`, `块作用域`
>
> > [!Note]
> >
> > 关于static的一些小tips
> >
> > - 块内`static`变量只在程序执行前初始化一次，而`auto`每次出现都会初始化一次
> > - 每次函数被递归调用的时候，它都会获得一组全新的`auto`变量。但是，如果函数含有`static`变量，那么此函数的全部调用都可以共享这个`static`变量。
> > - 虽然函数不应该返回指向`auto`变量的指针，但函数返回指向`static`变量的指针是没有问题的
>
> `extern` 
>
> ```c
> extern int i; // 表明i这个变量可能在这个文件，也可能在别的文件处已经定义过了
> 
> extern int j = 1; // 这是变量j的定义----> 防止多个extern声明用不同的方法对变量进行初始化。
> ```
>
> 确定`extern`的链接类型并不容易,通常来说
>
> - 出现在文件中较早的位置（任何函数定义的外部）声明为extern,此时一般为内部链接
> - 否则，为外部链接
>
> `register` ； ==建议==编译器把该变量放到寄存器中而非栈帧中。
> 注:寄存器是没有地址的，所以对用`register`定义的变量取地址(&)是不合法的
>
> **函数的存储类型 --- `extern` 和 `static`**
>
> 函数默认具有extern类型，默认外部链接。使用static可以让函数具有内部链接。
>
> ```c
> extern int  f(int i);
> static int g(int i);
> int h(int i); 
> ```
>
> 其中`f` `h` 均可以被定义它的文件之外的文件调用，但`g`不可能。
>
> 注：使用函数指针仍然可以调用`g`

> ##### `const` 类型限定符
>
> <span style="color:red">const用来声明一些“只读”变量</span>
>
> const的难点在于理解const限定的是那一部分
>
> > ## 典型例子
> >
> > `const int *` 和`int * const`的区别
> >
> > ```c
> > int i = 2;
> > const int *ptr_i = &i;
> > int * const ptr_j = &i;
> > ```
> >
> > 解读变量定义/声明的办法从内到外
> >
> > ```markdo
> > const int *ptr_i
> > 			|          |    |-------> 指针
> > 			|         |------------> 指向整数
> >   |-----------------------> 限定int                
> >   即不能通过该指针去修改这个变量,但指针指向可变。
> > ```
> >
> > ```markdo
> > int * const ptr_j
> > 		|     |     |-----------> const修饰指针
> > 		|      |------------------> 指针
> >  |------------------------->指向int类型
> >  即这个指针不可彼变，但指针指向的内容可以变
> > ```

复杂类型声明见[10 function Pointer note](../Lecture/10_function_pointer/note.md)

> ##### `inline` 内联函数
>
> **内联表明编译器把函数的每一次调用都用函数的机器指令来代替**
>
> 注意`inline`也只是建议，而非强制。
>
> 对具有外部链接的内联函数有如下限制
>
> - 函数不能定义可改变的static变量
> - 函数不能引用具有内部链接的变量
>
> 关于GCC，仅仅通过-O命令行选项进行请求优化的时候，才会对函数进行内联

### 预处理

gcc使用`-E`查看预处理器产生的代码

> # 预处理指令
>
> - 宏定义 `#define` 定义一个宏 `#undef` 删除一个宏
> - 文件包含 `#include`
> - 条件编译 `#if`. `ifdef`、`#ifndef`、`#elif`、`#else`和`#endif` 

`简单的宏`

```c
#define  N 100
#defien  N_W 100;

// .....
int a[N]; // 会被正确展开为a[100]
int a[N_W]; // 会被错误展开为100; 
// 虽然编译器可能会直接在第二行error
```

`带参数的宏`

[#define 指令 (带参数的宏)] ==#define 标识符($x_1,x_2,\dots,x_n$) 替换列表==

> ### 注意标识符后面必须==紧挨==括号

```c
#defien  MAX(x,y) ((x)>(y)?(x):(y))
#define IS_EVEN(n) ((n)%2==0)

// 可以如下使用
i = MAX(j + k, m - n);
if (IS_EVEN(I)) i++;
```

两个不常用的运算符号`#` `##`

注意：仅仅能在宏中使用

`# ` 将宏1的一个参数转化为字面串

`##` 将两个记号`黏合`

> #### 关于宏的括号
>
> - 如果宏的替换列表中有运算符，那么始终要把替换列表放到括号中
> - 如果宏有参数，每个参数每次在替换列表中出现的时候都要放到括号中去
>   - 虽然不放可能没问题，但谁能保证编译器总能如我所愿呢？

> ##### 条件编译
>
> ==#if 常量表达式==
>
> // .....
>
> ==#endif==
>
> 注意 `#if`会把为定义过的标识符当0使用
>
> ==#if defined DEBUG== // 仅当DEBUG被定义为宏时为真
>
> // .....
>
> ==#endif==
>
> 等价于
>
> ==#ifdef 标识符==
>
> // ....
>
> ==#endif==
