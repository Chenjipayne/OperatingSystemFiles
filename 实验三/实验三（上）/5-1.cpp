// ����vmeminfo
#include <windows.h>
#include <iostream>
#include <shlwapi.h>
#include <iomanip>
#pragma comment(lib, "shlwapi.lib")

int main( )
{
	// ���ȣ������ǻ��ϵͳ��Ϣ
	SYSTEM_INFO si;
	:: ZeroMemory(&si, sizeof(si) ) ;//ָ��һ��׼����0�������ڴ�����Ŀ�ʼ��ַ��
	:: GetSystemInfo(&si) ;//���ع��ڵ�ǰϵͳ����Ϣ��

	// ʹ����Ǹ��������һЩ�ߴ���и�ʽ��
	TCHAR szPageSize[MAX_PATH];
	::StrFormatByteSize(si.dwPageSize, szPageSize, MAX_PATH) ;//DWORD-->TCHAR

	TCHAR dwAllocationGranularity[MAX_PATH];
	::StrFormatByteSize(si.dwAllocationGranularity, dwAllocationGranularity, MAX_PATH) ;

	DWORD dwMemSize = (DWORD)si.lpMaximumApplicationAddress -
		(DWORD) si.lpMinimumApplicationAddress+1;
	TCHAR szMemSize [MAX_PATH] ;
	:: StrFormatByteSize(dwMemSize, szMemSize, MAX_PATH) ;

	// ���ڴ���Ϣ��ʾ����
	std :: cout << "Virtual memory page size: " << szPageSize << std :: endl;
	std :: cout << "�����ڴ�����: " << dwAllocationGranularity << std :: endl;

	std :: cout.fill ('0') ;//cout.fill �����λ����0���
	std :: cout << "Minimum application address: 0x"
		<< std :: hex << std :: setw(8)  //std :: hex ���ʮ������FF ;std::setw ��Ҫ�����ٸ��ַ�,Ĭ�������ַ�Ϊ' '�ո�
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
