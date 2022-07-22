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
        Product ("Coffee Mug", 30)
    };

    //Get an iterator to the second element.
    auto it = products.begin() + 1;

    //Insert another Product into the vector.
    products.emplace(it, "Calender", 25);

    //Display the vector contents.
    for (auto element : products){
        cout << "Product: " << element.getName() << endl;
        cout << "Units: " << element.getUnits() << endl;
    }
    return 0;
}