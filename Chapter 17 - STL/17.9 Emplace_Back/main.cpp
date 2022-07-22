#include <iostream>
#include "Product.h"
#include <vector>

using namespace std;

int main (int argc, const char **argv)
{
    //Create a vector to hold the Products.
    vector<Product> products;

    //Add the products to the vector.
    products.emplace_back ("T-Shirt", 20);
    products.emplace_back ("Calender", 25);
    products.emplace_back ("Coffee Mug", 30);

    //use an iterator to display the vector contents.
    for (auto it = products.begin();    it != products.end();   it++){
        cout << "Product: " << it->getName() << endl;
        cout << "Units: " << it->getUnits() << endl;
    }
    return 0;
}