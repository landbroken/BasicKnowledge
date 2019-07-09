# 一、内存分配

## malloc与new的区别

id|malloc|new
-|-|-
1 | malloc是函数，要#include头文件 | new是c++的关键字，不要#include
2 | malloc返回的是void*，需要强制转换为所需类型 | new返回的是所需类型
3 | malloc用free释放 | new用delete释放

# 二、内存操作
## memset
在头文件<string.h>中定义
- void * memset（void * _Dst，int _Val，size_t _Size）;
- errno_t memset_s（void * dest，rsize_t destsz，int ch，rsize_t count）

用途：将某一段内存设置为指定值
