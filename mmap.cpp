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
 * 获取 main 函数的地址，并通过函数指针类型输出该地址。
 *
 * @details
 * - 定义 MainFunctionPtr 类型，与 main 函数签名一致：`int (*)(int, char*[])`
 * - 通过 p_main = &main 获取 main 的地址。
 * - 使用 cout 输出 main 函数的地址（注意：main 的行为和可移植性与普通函数略有不同）。
 *
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