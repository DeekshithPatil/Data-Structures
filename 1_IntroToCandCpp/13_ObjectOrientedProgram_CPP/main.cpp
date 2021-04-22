#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;

    public:
        void initialise(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return(length * breadth);
        }

        int perimeter()
        {
            return(2*(length + breadth));
        }
};

int main()
{
    Rectangle r;

    r.initialise(12,10);

    cout << r.area()<<" "<<r.perimeter() << endl;
    return 0;
}
