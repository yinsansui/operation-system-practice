/*数据类型文件*/
#ifndef _TYPE_H
#define _TYPE_H
// 无符号 8 位类型
typedef unsigned char u8_t;
// 无符号 16 位类型
typedef unsigned short u16_t;
// 无符号 32 位类型
typedef unsigned int u32_t;
// 无符号 64 位类型
typedef unsigned long long u64_t;
// 有符号 8 位类型
typedef char s8_t;
// 有符号 16 位类型
typedef short s16_t;
// 有符号 32 位类型
typedef int s32_t;
// 有符号 64 位类型
typedef long long s64_t;

typedef long sint_t;
typedef unsigned long uint_t;
// CPU 中的标志
typedef u64_t cpuflg_t;

typedef unsigned long adr_t;
typedef unsigned long size_t;

typedef u64_t bool_t;
typedef u64_t dev_t;
typedef const char* str_t;
typedef char char_t;
typedef unsigned long drv_t;
typedef unsigned long mrv_t;
typedef sint_t drvstus_t;

// static 关键字会让其修饰的变量或者方法对其他源文件隐藏
// inline 关键字会建议编译器将方法作为内联函数
#define KLINE static inline

typedef void (*intheader_t)();
typedef drv_t (*i_headle_t)(uint_t int_nr);
typedef drv_t (*f_headle_t)(uint_t int_nr, void* sframe);
typedef void (*syscall_t)();
typedef drv_t (*dev_op_t)();
typedef mrv_t (*msg_op_t)();
typedef void* exception_t;
typedef char_t* va_list_t;

// 定义访问标识符
// PUBLIC 表示可以被全局访问到，由于在 C 语言中默认就是可以被全局访问的，所以后面为空
#define PUBLIC
// PRIVATE 表示只能被当前源文件访问，对其他源文件隐藏
#define private static
// EXTERN 表示引用其他源文件中所定义的
#define EXTERN extern
#define KEXTERN extern

// 定义结果常量
// NULL 表示没有
#define NULL 0
// TRUE 表示成功
#define TRUE 1
// FALSE 表示失败
#define FALSE 0
// __attribute__ 是 GUN C 的特性，可以用来设置函数属性、变量属性和类型属性
// regparm 是告诉编译器要用多少个寄存器来传递函数参数，最多为 3 个，分别是 EAX、EDX、ECX
#define REGCALL __attribute__((regparm(3)))
// 
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

#define P4G_ALIGN(x) ALIGN(x,0x1000)

#endif
