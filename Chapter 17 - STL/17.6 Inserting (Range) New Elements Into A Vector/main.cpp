#include <iostream>
#include <vector>

using namespace std;

int main (int argc, const char **argv)
{
    //Define two vectors.
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {100, 200, 300, 400, 500};

    //Define iterators
    auto it1 = v1.begin() + 1;                      //Points at 2 in v1
    auto it2 = v2.begin();                          //Points at 100 in v2
    auto it3 = v2.begin() + 3;                      //Points at 400 in v2

    //Insert a range of element into v1.
    v1.insert(it1, it2, it3);

    //Display the vector elements.
    for (auto element : v1)
        cout << element << " ";
    cout << endl;

    return 0;
}