#include <iostream>

using namespace std;

class SingleObject
{ //������� : Ŭ������ �����Ǳ����� ���ٰ����� ����, ��� ��ü���� �����ϴ� ����
    static SingleObject* m_pInstance;
    SingleObject(){}

    public:

    //��������Լ����� ������ ����Ϸ����ϸ�, ��ü������ �Ϲݸ�������� ����Ҽ� ����
    //�׷��Ƿ� Ŭ������ �����Ǳ������� �����ϴ� ������������� ������ ����ؾ���
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
//Ŭ�������� ������ ������ ��ü�� �����Ƿ�, cpp������ �� �޸𸮸� ����ϱ� ����
//���� ����ó�� ���� ���־����
SingleObject* SingleObject::m_pInstance = NULL;

void main()
{
    SingleObject* pA = SingleObject::getInstance();
    pA->ShowMessage();
    pA->Release();
}