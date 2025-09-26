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
 * - `pid_t x = fork();`: P0(30387) 进程调用 fork() 创建子进程 P1(30388)。
 * P0(30387) 中 x = P1.PID (30388);
 * P1(30388) 中 x = 0。
 *
 * - `pid_t y = fork();`: P0 和 P1 进程各自调用 fork() 创建子进程 P2(30389) 和 P3(30390)。
 * P0(30387) 中 y = P2.PID (30389);
 * P1(30388) 中 y = P3.PID (30390);
 * P2(30389) 和 P3(30390) 中 y = 0。
 *
 * @note
 * - `fork()` :创建一个新进程，返回值为子进程的 PID 或 0, 返回类型为`pid_t`,定义在`<unistd.h>`.
 *
 * - `pid_t` :是一个用于表示进程 ID 的数据类型，通常是一个整数类型.
 *
 * @example
 * 运行结果示例：(无法确定的 PID ; 进程调度是随机的)
 * `P0`: PID: 30387 | x: 30388 | y: 30389
 * `P2`: PID: 30389 | x: 30388 | y: 0
 * `P1`: PID: 30388 | x: 0     | y: 30390
 * `P3`: PID: 30390 | x: 0     | y: 0
 */
void fork1(void)
{
  pid_t x = fork();
  pid_t y = fork();
  printf("PID: %-5d | x: %-5d | y: %-5d\n", getpid(), x, y);
}

/**
 * @brief
 * 执行两次循环，每次循环调用 fork() 并输出当前进程的 PID 及 fork 返回值。
 *
 * @details
 * - 循环体内每次调用 fork()，当前进程会再创建一个子进程。
 * - 由于循环，每次 fork 后进程数会倍增，最终共产生 4 个进程。
 *
 * @example
 * 运行结果示例：(无法确定的 PID ; 进程调度是随机的)
 *  P0 | PID: 57419 | nextPid: 57420
 *  P1 | PID: 57419 | nextPid: 57421
 *  P0 | PID: 57420 | nextPid: 0
 *  P1 | PID: 57421 | nextPid: 0
 *  P1 | PID: 57420 | nextPid: 57422                                                                                                                    6325
 *  P1 | PID: 57422 | nextPid: 0
 *
 */
void fork2(void)
{
  for (int i = 0; i < 2; i++)
  {
    pid_t nextPid = fork();
    printf(" P%d | PID: %-5d | nextPid: %-5d\n", i, getpid(), nextPid);
  }
}

int main(void)
{
  fork2();
}