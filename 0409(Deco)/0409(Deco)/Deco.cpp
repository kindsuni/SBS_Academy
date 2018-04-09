//데코레이션 디자인 패턴
//클래스의 선언
class Context;
class StateOne;
class StateTow;
class StateThree;


//클래스의 정의
class State
{
    public:
    //멤버함수의 정의
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

//멤버함수의 선언
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