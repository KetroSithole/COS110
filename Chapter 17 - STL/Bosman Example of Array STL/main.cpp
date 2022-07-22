#include <iostream>
#include <array>

using namespace std;

int main (int argc, const char **argv)
{
    array<double,5>doubleArr;               //array of doubles, size 5
    array<string,3> stringArr;              //array of strings, size 3

    doubleArr[0] = 2.5;                     //Overloads the [] operator
    cout << doubleArr.size() << endl;       //knows its own size
    cout << doubleArr[0] << endl;           //Use array notation

    return 0;
}