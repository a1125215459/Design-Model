#include <stdio.h>

class COperation
{
    public:
        int m_nFirst;
        int m_nSecond;

        COperation() {}
        ~COperation() {}

        virtual double GetResult()
        {
            double dResult = 0;
            return dResult;
        }
};

class AddOperation : public COperation
{
    public:
        AddOperation() {}
        ~AddOperation() {}

        double GetResult()
        {
            return m_nFirst + m_nSecond;
        }
};

class SubOperation : public COperation
{
    public:
        SubOperation() {}
        ~SubOperation() {}

        double GetResult()
        {
            return m_nFirst - m_nSecond;
        }
};

class CCalculatorFactory
{
    public:
        CCalculatorFactory() {}
        ~CCalculatorFactory() {}

        COperation* CreateOperation(char cOper)
        {
            COperation* pOper = NULL;
            switch (cOper)
            {
                case '+':
                    pOper = new AddOperation();
                    break;
                case '-':
                    pOper = new SubOperation();
                    break;
                default:
                    break;
            }
            return pOper;
        }
};

int main(void)
{
    CCalculatorFactory factory;
    COperation* pOper = factory.CreateOperation('+');
    if (pOper)
    {
        pOper->m_nFirst = 10;
        pOper->m_nSecond = 20;
        printf("Result is %f\n", pOper->GetResult());
        delete pOper;
    }

    return 0;    
}