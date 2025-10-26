# Lecture 7 函数的一些高级用法
本节讲函数的一些高级用法：默认参数、函数重载、函数模板、函数指针和引用、递归函数。

## 默认参数
和Python很像，函数中的参数可以设定默认参数，在不输入值时自动填充

注意，默认参数必须放在函数的尾部
```CPP
float norm(float x,float y,float z=0);

norm(3.0f,4.0f); // 这里z值就是0
```

## 函数重载
希望函数逻辑相同，但又能处理不同数据类型时，可以使用函数重载。给多个函数命同一个名字，会根据不同名字返回对应的数值
```CPP
int sum(int x, int y)
{
cout << "sum(int, int) is called" << endl; 
return x + y;
}

float sum(float x, float y) 
{
cout << "sum(float, float) is called" << endl; 
return x + y;
}

double sum(double x, double y) 
{
cout << "sum(double, double) is called" << endl; 
return x + y;
}
```

注意，函数重载不可有歧义

## 函数模板
函数模板减轻函数重载的负担

先定义，再实例化，有点像类（class）

显式的实例化，参数会自动推断
```CPP
// 模板，不会立即执行
template<typename T> 
T sum(T x, T y)
{
cout << "The input type is " << typeid(T).name() << endl; 
return x + y;
}

// instantiates sum<double>(double, double)
template double sum<double>(double, double);

// instantiates sum<char>(char, char), template argument deduced
template char sum<>(char, char);

// instantiates sum<int>(int, int), template argument deduced
template int sum(int, int);
```

隐式的实例化，不实例化函数，直接调用也可以自动推断然后实例化
```CPP
template<typename T> 
T sum(T x, T y)
{
cout << "The input type is " << typeid(T).name() << endl; 
return x + y;
}

// Implicitly instantiates sum<int>(int, int)
cout << "product = " << sum<int>(2.2f, 3.0f) << endl;

// Implicitly instantiates sum<float>(float, float)
cout << "product = " << sum(2.2f, 3.0f) << endl;
```

特例感觉就像函数模板+函数重载，对于自己定义的数据类型（用结构体或类时），需要写出运算逻辑，这部分课件没给代码，我后面有时间再补上

## 函数指针和引用
函数指针就是让一个变量可以随时调用各个函数

定义和调用：
```CPP
// 定义函数
float norm_l1(float x, float y);
float norm_l2(float x, float y);
// 定义函数指针，括号不能省
float (*norm_ptr)(float x, float y);
// 函数指针赋值的两种方法
norm_ptr = norm_l1; //Pointer norm_ptr is pointing to norm_l1
norm_ptr = &norm_l2; //Pointer norm_ptr is pointing to norm_l2
// 函数指针调用的两种方法
float len1 = norm_ptr(-3.0f, 4.0f); //function invoked
float len2 = (*norm_ptr)(-3.0f, 4.0f); //function invoked
```

函数指针可以当作参数传递，比如著名的排序函数：
```CPP
<stdlib.h>

void qsort( void *ptr, size_t count, size_t size, 
            int (*comp)(const void *, const void *) );
```

函数引用，感觉和上面没啥区别，就是在引用的时候得指定函数：
```CPP
float norm_l1(float x, float y); //declaration 
float norm_l2(float x, float y); //declaration

// 函数引用
float (&norm_ref)(float x, float y) = norm_l1; //norm_ref is a function reference

// 直接调用
norm_ref(-3,4)
```

## 递归函数
函数不断调用自己，也是算法题难点之一

难点在于递归过程和边界条件，以及复杂的分类讨论

一个简单的示例：
```CPP
int main() 
{
div2(1024.); // call the recursive function 
return 0;
}

void div2(double val) 
{ 
cout << "Entering val = " << val << endl;
if (val > 1.0)
	div2( val / 2); // function calls itself
else
	cout << "--------------------------" << endl;
cout << "Leaving val = " << val << endl;
}
```

