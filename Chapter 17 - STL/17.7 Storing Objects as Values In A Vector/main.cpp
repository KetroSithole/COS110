#include <iostream>
#include "Product.h"
#include <vector>

using namespace std;

int main (int argc, const char **argv)
{
    //Create a vector of Product objects.
    vector<Product> products = 
    {
        Product ("T-Shirt", 20),
        Product ("Calender", 25),
        Product ("Coffee Mug", 30)
    };

    //Display the vector elements.
    for (auto element : products){
        cout << "Product: " << element.getName() << endl;
        cout << "Units: " << element.getUnits() << endl;
    }
    return 0;
}