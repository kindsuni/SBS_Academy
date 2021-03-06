#include <iostream>
#include <Windows.h>
#include <process.h>
#include <string>

using namespace std;

unsigned int WINAPI InputProcess(void *arg)//arg를 통해 외부의 데이터값을 받을 수 있음.
{
    int* pData = (int*)arg;

    while(true)
    {
        scanf("%d", pData);
    }
};

int main()
{
    enum WM_MSG{CREATE, COMMOND, PAINT, DESTROY, MAX};
    string strMSG[MAX] = { "CREATE", "COMMOND", "PAINT", "DESTROY" };

    HANDLE hThread = NULL;
    DWORD dwThreadID = NULL;

    int nMsg = CREATE;

    //스레드: 프로세스 내부에 처리를 하는 흐름단위(반복문을 동시에 처리가능함)
    //프로세스 : 프로그램의 기본적인 처리담당하는 흐름단위(메인루프)
    //스레드는 프로그램 내부에서 처리하는 내용을 변경할수 있어야 하므로 그 프로그램 내의 함수를
    //호출 하여 사용함
    //콜백 함수 : 프로세스 내에서 호출하지않고 외부에서 호출하도록 함(함수의 주소값을 넘김)
    hThread = (HANDLE)_beginthreadex(NULL, 0,
        InputProcess, //콜백함수 등록하기
        (void*)&nMsg, //받아올 메세지의 주소를 넘김
        0, (unsigned*)&dwThreadID);

    //메세지루프
    while(true)
    {
        switch(nMsg)
        {
            case CREATE:
                cout << "초기화" << endl;
                nMsg = COMMOND;
                break;
            case COMMOND:
                cout << "명령을 입력하세요." << endl;
                for(int i = 1; i < MAX; i++)
                    cout << i << ":" << strMSG[i] << ",";
                cout << endl;
                break;
            case PAINT:
                cout << "화면에 그립니다." << endl;
                nMsg = COMMOND;
                break;
            case DESTROY:
                cout << "프로그램을 종료합니다." << endl;
                exit(0);
                break;
            default:

                break;
        }
        Sleep(1000);
    }

    return 0;
}
