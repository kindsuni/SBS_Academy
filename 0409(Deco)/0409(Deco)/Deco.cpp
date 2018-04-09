//���ڷ��̼� ������ ����
//Ŭ������ ����
class Context;
class StateOne;
class StateTow;
class StateThree;


//Ŭ������ ����
class State
{
    public:
    //����Լ��� ����
   virtual void GoNext(Context* context) = 0;
   
};
class Context
{
    State* m_pState;

    public:
    void SetState(State* pState)
    {
        m_pState = pState;
    }

    void GoNext()
    {
        m_pState->GoNext(this);
    }
};




class StateOne : public State
{
    public:

    void GoNext(Context* context);
    
};
class StateTwo : public State
{
    public:

    void GoNext(Context* context);
    
};
class StateThree: public State
{
    public:

    void GoNext(Context* context);
   
};

//����Լ��� ����
void StateOne::GoNext(Context* context)
{
    context->SetState(new StateTwo());
}

void StateTwo::GoNext(Context* context)
{
    context->SetState(new StateTwo());
}

void StateThree::GoNext(Context* context)
{
    context->SetState(new StateTwo());
}

void main()
{
    Context sCon;
}