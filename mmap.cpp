/**
 * @file mmap.cpp
 * @brief 06 - mmap 和进程的地址空间；入侵进程的地址空间 [2025 南京大学操作系统原理]
 * @see https://www.bilibili.com/video/BV1dzRAYLELh
 * @author [NotSleeply]
 * @date 2025-09-26
 */

#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
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
 * - `函数指针` 和 `数据指针 (void*)` 在 C++ 标准中是不同的类型，但将函数指针强制转换为 `void*` 是查看其内存地址的标准做法。
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

/**
 * @brief
 * 使用 mmap 将文件内容映射到进程地址空间，并输出文件内容。
 *
 * @details
 * 1. 使用 `open` 打开一个文件，获取文件描述符。
 * 2. 使用 `lseek` 获取文件大小。
 * 3. 使用 `mmap` 将文件映射到内存。
 * 4. 读取映射的内存并输出文件内容。
 *
 * @note
 * - `mmap`:需要知道映射的文件描述符、映射的大小、保护标志和映射类型等信息。
 *
 * @see [什么是 mmap](https://juejin.cn/post/7554270339796533286)
 *
 * @example
 * 假设 example.txt 内容为 "Hello, mmap!"，运行结果为：
 * File content:
 * Hello, mmap!
 */
void funMmap()
{
  // 打开文件
  int fd = open("./example.txt", O_RDONLY);
  if (fd == -1)
  {
    perror("open");
    return;
  }

  // 获取文件大小
  off_t file_size = lseek(fd, 0, SEEK_END);
  if (file_size == -1)
  {
    perror("lseek");
    close(fd);
    return;
  }
  lseek(fd, 0, SEEK_SET); // 重置文件指针

  // 映射文件到内存
  void *addr = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED)
  {
    perror("mmap");
    close(fd);
    return;
  }

  // 读取并输出所有字节
  if (file_size > 0)
  {
    printf("File content:\n");
    for (off_t i = 0; i < file_size; ++i)
    {
      putchar(((char *)addr)[i]);
    }
    putchar('\n');
  }
  else
  {
    printf("File is empty.\n");
  }

  // 取消映射并关闭文件
  munmap(addr, file_size);
  close(fd);
}

int main(int argc, char *argv[])
{
  funMmap();
  return 0;
}