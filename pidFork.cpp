
/**
 * @file pidFork.cpp
 * @brief 演示 fork() 系统调用产生的进程状态及其 PID 关系。
 *        本程序通过两次 fork()，展示了进程树的分叉及各进程中变量的取值。
 * @see [05 - 程序与进程；进程管理 API [2025 南京大学操作系统原理]](https://www.bilibili.com/video/BV1fb97YsEWL/?spm_id_from=333.337.) 课程中 '1:07:50' 的题目 “fork：习题（1）
 * @author [NotSleeply]
 * @date 2025-09-25
 */

#include <iostream>
#include <unistd.h>
using namespace std;

/**
 * @brief
 * 执行两次 fork 并输出各进程的 PID 及 fork 返回值。
 *
 * @details
 *
 *
 * @note
 * - fork() 创建一个新进程，返回值为子进程的 PID（父进程中）或 0（子进程中）返回类型为pid_t。
 * - pid_t 是一个用于表示进程 ID 的数据类型，通常是一个整数类型。
 *
 * @example
 * 运行结果示例（实际 PID 可能不同）：
 * PID: 30387 | x: 30388 | y: 30389
 * PID: 30389 | x: 30388 | y: 0
 * PID: 30388 | x: 0     | y: 30390
 * PID: 30390 | x: 0     | y: 0
 */
int main(void)
{
  pid_t x = fork();
  pid_t y = fork();
  printf("PID: %-5d | x: %-5d | y: %-5d\n", getpid(), x, y);
}