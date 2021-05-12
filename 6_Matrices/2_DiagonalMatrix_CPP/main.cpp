#include <iostream>

using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
        this->A = new int[n];
    }

    void Set(int i,int j,int x)
    {
        if(i==j)
        {
            this->A[i-1] = x;
        }
    }

    int Get(int i,int j)
    {
        if(i==j)
            return this->A[i-1];
        else
            return 0;
    }

    void Display()
    {

        for(int i=0;i<this->n;i++)
        {
            for(int j=0;j<this->n;j++)
            {
                if(i==j)
                    cout<<A[i]<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }

    }

    ~Matrix()
    {
        delete []A;
    }

};

int main()
{
    Matrix d(4);

    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);

    d.Display();
    return 0;
}
