# include <windows.h>
# include <iostream>

void GetMemSta(void);
using namespace std;

int main(int argc, char* argv[] )
{
	LPVOID BaseAddr; //LPVOID,是一个没有类型的指针，也就是说你可以将任意类型的指针赋值给LPVOID类型的变量(一般作为参数传递)，然后在使用的时候再转换回来。
	char *str;

	GetMemSta();
	printf("Now Allocate 32M Virsual Memory and 2M Physical Memory\n\n");
	BaseAddr=::VirtualAlloc(NULL,1024*1024*32,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);//分配虚拟内存
	if (BaseAddr==NULL) printf("Virsual Allocate Fail.\n");
	str=(char *)malloc(1024*1024*2);                         //分配内存
	GetMemSta();
	printf("Now Release 32M Virsual Memory and 2M Physical Memory\n\n");
	if (::VirtualFree(BaseAddr,0,MEM_RELEASE)==0)           //释放虚拟内存
		printf("Release Allocate Fail.\n");
	free(str);                                             //释放内存
	/*free函数是由C语言继承而来的，是和malloc配对的，而不能和new配对。
free释放内存的和delete可以说是两套代码，它们的逻辑不同，不能混用。用new申请的就要用delete翻译，用malloc申请的就要用free释放。
顺便说一下它们还有一个区别， free 只是告诉操作系统回收内存，而delete会先调用类的析构函数，然后才告诉操作系统回收内存。*/
	GetMemSta();
	return 0;
}

void GetMemSta(void)
{
	MEMORYSTATUS MemInfo;
	GlobalMemoryStatus(&MemInfo);

	printf("Current Memory Status is :\n");
	printf("\t Total Physical Memory is %d MB\n",MemInfo.dwTotalPhys/(1024*1024));
	printf("\t Available Physical Memory is %d MB\n",MemInfo.dwAvailPhys/(1024*1024));
	printf("\t Total Page File is %d MB\n",MemInfo.dwTotalPageFile/(1024*1024));
	printf("\t Available Page File is %d MB\n",MemInfo.dwAvailPageFile/(1024*1024));
	printf("\t Total Virtual Memory is %d MB\n",MemInfo.dwTotalVirtual/(1024*1024));
	printf("\t Available Virsual memory is %d MB\n",MemInfo.dwAvailVirtual/(1024*1024));
	printf("\t Memory Load is %d %%\n\n",MemInfo.dwMemoryLoad);
	
}
