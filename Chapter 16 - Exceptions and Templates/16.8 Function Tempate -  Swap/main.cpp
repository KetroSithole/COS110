//This program demonstrates the swapVars function template 
#include <iostream>

using namespace std;

template <class T>
void swapVars (T &var1, T &var2){
    swap(var1, var2);
}

int main(int argc, const char **argv)
{
    char firstChar, secondChar;             //Two chars
    int firstInt, secondInt;                //Two ints
    double firstDouble, secondDouble;       //Two doubles

    //Get and swapVars two chars.
    cout << "Enter two characters: ";
    cin >> firstChar >> secondChar;
    swapVars (firstChar, secondChar);
    cout << firstChar << " and " << secondChar << endl;

    //Get and swapVars two ints.
    cout << "\nEnter two integers: ";
    cin >> firstInt >> secondInt;
    swapVars (firstInt, secondInt);
    cout << firstInt << " and " << secondInt << endl;

    //Get and swapvars two doubles.
    cout << "\nEnter two floating-point numbers: ";
    cin >> firstDouble >> secondDouble;
    swapVars (firstDouble, secondDouble);
    cout << firstDouble << " and " << secondDouble << endl;
    
    return 0;
}
