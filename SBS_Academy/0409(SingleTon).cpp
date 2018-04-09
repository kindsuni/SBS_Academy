#include <iostream>

using namespace std;

class SingleObject
{ //정적멤버 : 클래스가 생성되기전에 접근가능한 영역, 모든 객체들이 공유하는 영역
    static SingleObject* m_pInstance;
    SingleObject(){}

    public:

    //정적멤버함수에서 변수를 사용하려고하면, 실체가없는 일반멤버변수는 사용할수 없다
    //그러므로 클래스가 생성되기전부터 존재하는 정적멤버변수를 가져와 사용해야함
    static SingleObject* getInstance()
    {
        if(m_pInstance != NULL)
        {
            m_pInstance = new SingleObject();
        }
        return m_pInstance;
    }

    void ShowMessage()
    {
        cout << "SingleObject" << endl;
    }

    void Release()
    {
        delete m_pInstance;
    }
};
//클래스에서 선언은 했지만 실체가 없으므로, cpp에서는 이 메모리를 사용하기 위해
//전역 변수처럼 선언 해주어야함
SingleObject* SingleObject::m_pInstance = NULL;

void main()
{
    SingleObject* pA = SingleObject::getInstance();
    pA->ShowMessage();
    pA->Release();
}