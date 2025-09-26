/**
 * @file mmap.cpp
 * @brief 演示如何获取 main 函数的地址，并通过函数指针调用。
 *        本程序定义了与 main 函数签名一致的函数指针类型，并输出 main 的地址。
 * @see [C/C++ 函数指针与 main 函数地址相关知识]
 * @author [NotSleeply]
 * @date 2025-09-26
 */

#include <iostream>
using namespace std;

/**
 * @brief
 * 虽然 main 签名特殊，但为了在其他函数中引用，最好有一个声明
 */
int main(int argc, char *argv[]);

/**
 * @brief
 * 获取 `main` 内存中的实际十六进制地址。
 *
 * @details
 * - 通过定义与 `main` 函数一致的函数指针类型(`MainFunctionPtr`)来获取`main`地址。
 *
 * @note
 * - `(void *)p_main` :
 *  若没有添加 `(void *)` 强制转换，通常会将其视为一个 `布尔值` 或 `普通的 void* 指针` 进行处理;处理非空指针，隐式转换为 true，最终被 cout 打印成了 `1`。
 *  添加 `(void *)` 后，会进行一次`显式的类型转换`，将其转换为 `通用数据指针 void*`。从而打印出实际的内存地址。
 *
 * @example
 * 运行结果示例（地址因环境而异）：
 *   main 函数的地址是: `0x10c6ab550`
 */
void funPmain()
{
  typedef int (*MainFunctionPtr)(int, char *[]);
  MainFunctionPtr p_main;
  p_main = &main;
  cout << "main 函数的地址是: " << (void *)p_main << endl;
}

int main(int argc, char *argv[])
{
  funPmain();
  return 0;
}