## Double_POinter 二重指针

> Pointer Arrays (char *names[]) 指针数组 一个数组里面存的是字符指针
>
> Pointers and 2D Arrays (int (*scores)[]) 一个指针指向了一个int数组
>
> **Pointer Types Greatly Matter!!!**

`selection-sort-string.c` 
代码参考 [selection-sort-string.c](selection-sort-string.c)

`scores.c`

`echo.c`



### `const` 的作用
const修饰变量
```c
const int var = 0; //限定var不能被修改
var = 10;//报错 const int 不可以被修改
//initialization discards ‘const’ qualifier from pointer target type
int *ptr_var = &var;//这里会报warring,但十分不推荐这种写法
*ptr_var = 10; //注意这里确实可以修改var的值
```

const修饰指针变量
```c
int var = 10;
const int *ptr_var = &var;//指针类型 const int* 不能通过ptr_var间接修改var,                      
                          //但不代表var本身不能修改
*ptr_var = 100;// 这里会报错 
var = 100;//这里是没问题的
```

```c

//不能通过arr指针修改
void Print(const int *arr, int len) {...}

//提问 arr[10] = 10可行吗？
//答案： 等价于 *(arr + 10) = 10 ,也不能被修改，本质原因是*(arr + 10) 仍然是const int 
```
const int * 与 int * const
```c
const int *var;  // 不能通过该指针修改该地址的值，但可以修改这个指针本身

int var1 = 10;
int var2 = 20;
const int *ptr = &var1;  // ptr 是一个指向常量整数的指针

// *ptr = 30;  // 错误：不能通过 ptr 修改指向的值

ptr = &var2;  // 可以改变 ptr 的值，让它指向 var2

int * const var; //可以通过该指针修改该地址的值，但不能修改该指针指向的地址

int var1 = 10;
int var2 = 20;
int * const ptr = &var1;  // ptr 是一个常量指针，指向 var1

*ptr = 30;  // 可以修改 ptr 指向的值，即 var1 的值变为 30

// ptr = &var2;  // 错误：不能修改 ptr 的值（不能让它指向 var2）

```

`main函数的另一个原型`

```c
//argc: 参数的个数
//argv: 参数列表--->字符串数组 
//argv[0] ---> 该程序的名字 
//argv[1] ----> argv[c - 1];传递给main函数的参数,命令行参数
//argv[argc]:NULL pointer
int main(int argc, char *argv[]);{
    return 0;
}
```