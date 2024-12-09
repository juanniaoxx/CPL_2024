### Function Pointer and Declaration Statement

> # 主要内容
>
> 1. 函数指针 通过(qsort函数和bsearch函数)
> 2. 类型声明与解读（如何解读一个复杂的类型，以及用typerdef简化类型名）

先看`qsort`函数的签名

```c
void qsort(void * ptr, size_t count, size_t siez,
          		   	    int (*comp)(const void*, const void*));
```

一眼就发现了一个神奇的东西`int (*comp)(....)` 解读类型，从名字往外解读

```markdown
int ( * comp )  (.....) 
			|      |-------> `*|` 表明是一个指针
			|                    |---------> (.....)带参数表示是一个函数
			|--------------------------------------> 表明函数返回值为int

```

总的来说，定义了一个`指向接受两个参数为(void *)，返回值为int的函数的指针` 即`函数指针`

> ## 为啥要引入函数指针
>
> C语言不像python或函数式编程语言，函数并非为一等公民(first class citizens),并不能作为函数的参数与返回值使用[不存在所谓高阶函数]，不能赋值，不能成为数组类型。
>
> 但指针、变量等等对象，是一等的。如果需要传递函数，必须把函数转换为指针，从汇编层面来看，所谓调用函数(cell funciton)也是一次`jump`,只需要传递该函数的地址便可以，这就引入了函数指针。



#### 第一个例子 `Itegrate` -- 积分函数

$\int_a^bf(x)dx$  需要一个函数表示积分号，并且需要接受一个函数作为参数。

```c
// 伪代码定义
returnTyper Itegrate(valueTyper a, valueType b, function f);
// 关键在与如何传入这个f
```

模仿`qsort`里面的`comp`

```c
// 返回值为double 接受一个double的函数指针
double (*f) (double);
```

> ### 区别 
>
> `double *f(double)` 是一个接受double返回double*的函数
>
> `double (*f)(double)` 是一个接受double返回double的函数指针

```c
double Itergrate(int low, int high, double(*f)(double)); //这样就声明好了这个积分函数
// 问题又来了，实现的时候如何调用这个函数指针呢？
```

```c
double Itergrate(int low, int high, double(*f)(double)) {
    double interval = (high + low ) / NUM_OF_PARTITIONS;
    
    double sum = 0;
    for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
        double xi = low + i * interval;
        // double yi = (*f)(xi); 
        // double yi = (**********f)(xi); // 也对
        double yi = f(xi); 
        // 在函数调用/函数中，函数名被隐式转换为函数指针，所以这里可以不用显式解引用
        sum += yi * interval;
    }
}

// 调用案例
Integrate(low, high, sin); // 传入sin也不需要取地址----> 函数名默认转换为了函数指针
```



> #####  把函数放入数组
>
> `double (*funcs[])(double)`
>
> ```mark
> double  ( * funcs [ ] )( double )
> 						|            |            |----|-------> 方括号优先级高，表明这是一个数组
> 						|           |----------------|--------> 数组元素是指针
>   |                           |---------> 指针指向一个参数为double返回类型为double的函数
>   |-------------------------------------> 函数返回值                           
> ```
>
> double (*funcs[])(double) = {sin, cos, square};
>
> 可以和普通的数组一样使用
>
> ```c
> for (int i = 0; i < 3; i++) {
>     Intergrate(low, high, func[i]);
> }
> ```

> ### 一些例外
>
> `sizeof 函数名` 是`未定义行为` ---> sizeof 不会把函数吗转换为函数指针
>
> `&sin` ---> 会得到sin的地址 ----> 不会被影式转换为函数指针，否则会报错。&+地址是错误的



#### 第二个例子 `qsort` C语言内部实现的快速排序

让我们回到`qsort`的声明

```c
void qsort(void * ptr, size_t count, size_t size,
          		   	    int (*comp)(const void*, const void*));
```

来解释一下参数的含义：

- `void *ptr` 指向该数组的指针，因为不知道待排序数组的类型，只能使用void*(能被转换为任意类型的指针)
- `size_t (unsigned long int) count `待排序数组的元素个数
- `size_t size` 待排序数组元素的大小
- `int (\*comp)(const void\*, const void*) `
  - 同`void *ptr`一样，不能提前知道待排序数组的类型，只能传入最一般的`void*`
  - 这个函数的作用确定比较方法，不同的类型有不同的排序方法，甚至自定义比较准则。
  - 一般来说返回值
    - `0` 相等
    - `<0` 小于
    - `>0` 大于

```c
// 使用qsort的案例
// 第一步要定义比较函数
int (*comp)(const void* left, const void* right);

//案例一：比较两个整数
// left, right: int *
int (*comp)(const void*left, const void* right) {
    // 主要用left和right 自己要明白它们实际类型是啥东西
    int left_val = *left;
    int right_val = *right;
   				
    return (left_val > right_val) - (left_val < right_val);
}

//案例二：比较两个字符串
//此时关键点再与left 和 right实际类型是啥？
//left , right : char **
int (*comp_sring)(const void* left, const void* right) {
    
    char * const *left_str_ptr = left;
    char * const *right_str_ptr = right;
    
    return strcmp(*left_str_ptr, *right_str_ptr);
}

// 一个很常见的错误
int (*comp_sring)(const void* left, const void* right) {
    
    char *left_str_ptr = *left;
    char *right_str_ptr = *right;
    
    return strcmp(left_str_ptr, right_str_ptr);  // 这个结果没有排序效果
}

```

> ##### typedef简化函数指针
>
> `typedef int(*)(const void*, const void *) comp` 看上去很符合`typedef`的定义，但实际上会被编译器报错
>
> ```c
> typedef int(*comp)(const void*, const void *);  // 这才是被编译器接受
> ```



#### 第三个例子`Bsearch` 内置二分查找

先看签名

```c
void* bsearch(const void *key, const void *ptr, size_t count, size_t size, 
             	     int(*comp)(cosnt void*, const void*))
 
```

第一个问题这个`const void *key`是啥？

还是同样的问题，设计这个函数的人并不知道会被传入啥样的参数，只能选择传入`void*`来保证转换不会出现问题。

> [!Note]
>
> `const void key`是非法的，不能用void定义一个类型，所以只能传入`void *`

> ##### 把函数（指针）作为返回值
>
> 这个并不容易写对
>
> ```c
> int (*fun(bool is_right))(int x);
> ```
>
> 解读一下这个声明
>
> ```mark
> int ( * fun (bool is_right) )( int  x );
> 							|      |        |---------------------|---------> 括号优先级高，表明这是一个函数,参数为bool类型
> 							|      |-----------------------------|----------> 返回值为指针类型
>  |                                   |------------> 指针指向一个接受int返回int的函数
>  |-------------------------------------------------> 返回int                                   
> ```
>
> 尽量采用`typedef`简化定义
>
> ```c
> typedef  int (*Funptr)(int x);
> Funptr func(bool is_right);
> ```



