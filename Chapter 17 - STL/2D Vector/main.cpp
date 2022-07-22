#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char **argv)
{
    vector < vector<int> > vect(4, vector<int>(4,9));

    for (int xIndex=0;  xIndex<4;   xIndex++)
    {
        for (int yIndex=0;  yIndex<4;   yIndex++)
        {
            cout << vect[xIndex][yIndex] << " ";
        }
        cout << endl;
    }
    return 0;
}