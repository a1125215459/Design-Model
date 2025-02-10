#include <iostream>
#include <cstdio>

class Operation
{
    public:
    int m_nFirst;
    int m_nSecond;

    Operation() {};
    ~Operation() {};

    virtual double GetResult()
    {
        double dResult = 0;
        return dResult;    
    }
};

class AddOperation : public Operation
{
    public:
    AddOperation() {};
    ~AddOperation() {};

    double GetResult()
    {
        printf("+++++");
        printf("m_nFirst is %d\n", m_nFirst);
        printf("m_nSecond is %d\n", m_nSecond);
        return m_nFirst + m_nSecond;
    }
};

class SubOperation : public Operation
{
    public:
    SubOperation() {};
    ~SubOperation() {};

    double GetResult()
    {
        printf("-----");
        printf("m_nFirst is %d\n", m_nFirst);
        printf("m_nSecond is %d\n", m_nSecond);
        return m_nFirst - m_nSecond;    
    }
};

class Context : public Operation
{
    public:
    Operation* m_pOper;

    Context(Operation* pOper)
    {
        m_pOper = pOper;    
    }

    double GetResult()
    {
        return m_pOper->GetResult();    
    }
};

int main(void)
{
    int nFirst = 10;
    int nSecond = 5;
    char c = '+';
    double result;
    switch(c)
    {
        case '+':
        {
            Context* pContext = new Context(new AddOperation());
            pContext->m_pOper->m_nFirst = nFirst;            
            pContext->m_pOper->m_nSecond = nSecond;
            result = pContext->GetResult();
            break;
        }
        case '-':
        {
            Context* pContext = new Context(new SubOperation());
            pContext->m_pOper->m_nFirst = nFirst;
            pContext->m_pOper->m_nSecond = nSecond;
            result = pContext->GetResult();
            break;
        }
        default:
        {
            break;
        }
    }
    printf("result is %f\n", result);
    return 0;
}