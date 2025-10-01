/**
 * @file precompile.c
 * @brief 条件编译演示
 * @see https://www.bilibili.com/video/BV1ZrazzzEs3
 * @author [NotSleeply]
 * @date 2025-10-01
 */

#include <stdio.h>

/**
 * @brief
 *    比较 `aa` 是否与 `bb` 相等并打印结果。
 *
 * @details
 *
 * - 使用预处理指令 `#if`, `#else`, `#endif` 进行条件编译。
 *
 * - 如果 `aa` 等于 `bb`, 则打印 "YES", 否则打印 "NO"。
 *
 * - 通过修改 `#define aa` 和 `#define bb` 的值可以测试不同的输出结果。
 *
 * @note
 * - 条件编译是 C/C++ 语言中的一种预处理机制，允许根据不同条件选择性地编译源代码的某些部分。
 *
 * - 使用 `gcc -E precompile.c | less` 可以查看预处理后的代码。
 * @example
 * 运行结果示例：
 * - 当什么都不定义是时，输出 "YES";
 * - 因为 `aa` 和 `bb` 都是没有定义的宏，默认值为 `NULL`, 所以 `aa == bb` 为真。
 */
void aaeqbb(void)
{
#if aa == bb
  printf("YES\n");
#else
  printf("NO\n");
#endif
}

int main()
{
  aaeqbb();
}