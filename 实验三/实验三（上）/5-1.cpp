// 工程vmeminfo
#include <windows.h>
#include <iostream>
#include <shlwapi.h>
#include <iomanip>
#pragma comment(lib, "shlwapi.lib")

int main( )
{
	// 首先，让我们获得系统信息
	SYSTEM_INFO si;
	:: ZeroMemory(&si, sizeof(si) ) ;//指向一块准备用0来填充的内存区域的开始地址。
	:: GetSystemInfo(&si) ;//返回关于当前系统的信息。

	// 使用外壳辅助程序对一些尺寸进行格式化
	TCHAR szPageSize[MAX_PATH];
	::StrFormatByteSize(si.dwPageSize, szPageSize, MAX_PATH) ;//DWORD-->TCHAR

	TCHAR dwAllocationGranularity[MAX_PATH];
	::StrFormatByteSize(si.dwAllocationGranularity, dwAllocationGranularity, MAX_PATH) ;

	DWORD dwMemSize = (DWORD)si.lpMaximumApplicationAddress -
		(DWORD) si.lpMinimumApplicationAddress+1;
	TCHAR szMemSize [MAX_PATH] ;
	:: StrFormatByteSize(dwMemSize, szMemSize, MAX_PATH) ;

	// 将内存信息显示出来
	std :: cout << "Virtual memory page size: " << szPageSize << std :: endl;
	std :: cout << "虚拟内存粒度: " << dwAllocationGranularity << std :: endl;

	std :: cout.fill ('0') ;//cout.fill 多余的位数用0填充
	std :: cout << "Minimum application address: 0x"
		<< std :: hex << std :: setw(8)  //std :: hex 输出十六进制FF ;std::setw 需要填充多少个字符,默认填充的字符为' '空格
		<< (DWORD) si.lpMinimumApplicationAddress
		<< std :: endl;
	std :: cout << "Maximum application address: 0x"
		<< std :: hex << std :: setw(8)
		<< (DWORD) si.lpMaximumApplicationAddress
		<< std :: endl;

	std :: cout << "Total available virtual memory: "
		<< szMemSize << std :: endl ;
	return 0;
}
