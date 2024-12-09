## C语言程序设计：现代方法

### chapter 3格式化输入/输出

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
> 通常情况下数组长度必须用`常量表达式`定义,但C99中，有时候也可以实用哦个非常量表达式
>
> ```c
>     int n = 0;
>     scanf("%d", &n);
>     int a[n];
> 
>     for (int i = 0; i < n; i++) {
>         a[i] = i;
>         printf("%d ", a[i]);
>     }
> ```

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



