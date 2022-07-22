#include <iostream>
#include <vector>

using namespace std;

int main (int argc, const char **argv)
{
    vector<double> doubleVec;               // vector of doubles
    vector<string> names;                   // vector of strings

    doubleVec.push_back(2.5);               // infinitely expandable
    cout << doubleVec.size() << endl;       // knows its own size
    cout << doubleVec[0] << endl;           // use array notation
    doubleVec.pop_back();                   // remove last element

    return 0;
}