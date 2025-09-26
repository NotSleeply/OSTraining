#include <iostream>
using namespace std;

// 【关键修正点 1】：前向声明 main 函数
// 虽然 main 签名特殊，但为了在其他函数中引用，最好有一个声明
int main(int argc, char *argv[]);

// 1. 定义一个与 main 函数签名匹配的函数指针类型
typedef int (*MainFunctionPtr)(int, char *[]);

void funPmain()
{
  // 2. 声明一个函数指针变量
  MainFunctionPtr p_main;

  // 3. 将 main 函数的地址赋值给指针
  p_main = &main; // 现在编译器知道 main 的存在了

  cout << "main 函数的地址是: " << p_main << endl;
}

// 【关键修正点 2】：main 函数的定义
int main(int argc, char *argv[])
{
  funPmain();
  return 0;
}