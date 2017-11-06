 // version��Ŀ
      # include <windows.h>
      # include <iostream>
 
      // ���ý��̺Ͳ���ϵͳ�İ汾��Ϣ�ļ�ʾ��
      void main()
      {
          // ��ȡ������̵�ID��
          DWORD dwIdThis = :: GetCurrentProcessId() ;
 
          // �����һ���̺ͱ�������İ汾��Ҳ���Է���0�Ա�ָ����һ����
          DWORD dwVerReq = :: GetProcessVersion(dwIdThis) ;
          WORD wMajorReq = (WORD) (dwVerReq > 16) ;
          WORD wMinorReq = (WORD) (dwVerReq & 0xffff) ;
          std :: cout << "Process ID: "<< dwIdThis
              << ", requires OS: " << wMajorReq << wMinorReq << std :: endl ;
 
          // ���ð汾��Ϣ�����ݽṹ���Ա㱣�����ϵͳ�İ汾��Ϣ
          OSVERSIONINFOEX osvix;
          :: ZeroMemory(&osvix, sizeof(osvix) ) ;
          osvix.dwOSVersionInfoSize = sizeof(osvix) ;
 
          // ��ȡ�汾��Ϣ�ͱ���
          :: GetVersionEx(reinterpret_cast < LPOSVERSIONINFO > (&osvix) ) ;
          std :: cout << "Running on OS: " << osvix.dwMajorVersion << "."
              << osvix.dwMinorVersion << std :: endl;
 
          // �����NTS (Windows  Server 2003) ϵͳ�������������Ȩ
          if (osvix.dwPlatformId == VER_PLATFORM_WIN32_NT &&
              osvix.dwMajorVersion >= 5)
          {
              // �ı����ȼ�
              :: SetPriorityClass(
                  :: GetCurrentProcess( ) ,					// ������һ����
                  HIGH_PRIORITY_CLASS) ;			// �ı�Ϊhigh
 
              // ������û�
              std :: cout << "Task Manager should now indicate this "
                  "process is high priority��" << std :: endl;
          }
      }
