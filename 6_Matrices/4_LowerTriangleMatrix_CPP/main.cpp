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
        this->A = new int[n * (n+1)/2];
    }
    ~Matrix()
    {
        delete []A;
    }

    void Set(int i, int j, int x)
    {
        if(i>=j)
        {
            A[i * (i-1)/2 + j - 1] = x;
        }
    }

    int Get(int i,int j)
    {
        if(i>=j)
        {
            return A[i * (i-1)/2 + j - 1];
        }
        return 0;
    }

    void Display()
    {
        cout<<"The elements of Matrix are: "<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if (i>=j)
                {
                    cout<<A[i * (i-1)/2 + j - 1]<<" ";
                }
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int d=4;
    Matrix m(d);
    int x;

    printf("Enter the elements of a %dx%d Matrix: \n",d,d);

    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            m.Set(i,j,x);
        }
    }

    m.Display();


    return 0;
}
