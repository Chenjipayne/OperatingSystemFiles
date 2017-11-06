# include <windows.h>
# include <iostream>

void GetMemSta(void);
using namespace std;

int main(int argc, char* argv[] )
{
	LPVOID BaseAddr; //LPVOID,��һ��û�����͵�ָ�룬Ҳ����˵����Խ��������͵�ָ�븳ֵ��LPVOID���͵ı���(һ����Ϊ��������)��Ȼ����ʹ�õ�ʱ����ת��������
	char *str;

	GetMemSta();
	printf("Now Allocate 32M Virsual Memory and 2M Physical Memory\n\n");
	BaseAddr=::VirtualAlloc(NULL,1024*1024*32,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);//���������ڴ�
	if (BaseAddr==NULL) printf("Virsual Allocate Fail.\n");
	str=(char *)malloc(1024*1024*2);                         //�����ڴ�
	GetMemSta();
	printf("Now Release 32M Virsual Memory and 2M Physical Memory\n\n");
	if (::VirtualFree(BaseAddr,0,MEM_RELEASE)==0)           //�ͷ������ڴ�
		printf("Release Allocate Fail.\n");
	free(str);                                             //�ͷ��ڴ�
	/*free��������C���Լ̳ж����ģ��Ǻ�malloc��Եģ������ܺ�new��ԡ�
free�ͷ��ڴ�ĺ�delete����˵�����״��룬���ǵ��߼���ͬ�����ܻ��á���new����ľ�Ҫ��delete���룬��malloc����ľ�Ҫ��free�ͷš�
˳��˵һ�����ǻ���һ������ free ֻ�Ǹ��߲���ϵͳ�����ڴ棬��delete���ȵ����������������Ȼ��Ÿ��߲���ϵͳ�����ڴ档*/
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
