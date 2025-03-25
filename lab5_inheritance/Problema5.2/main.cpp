#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Department shoesDept, toysDept;

    shoesDept.addProduct(new Shoes("Nike Air", 120.99));
    shoesDept.addProduct(new Shoes("Adidas UltraBoost", 180.00));
    toysDept.addProduct(new Toys("Lego Set", 59.99));
    toysDept.addProduct(new Toys("Barbie Doll", 24.99));

    cout << "Shoes Department (sorted by name):" << endl;
    shoesDept.displayAll(true);

    cout << "\nToys Department (sorted by price):" << endl;
    toysDept.displayAll(false);

    string searchName = "Lego Set";
    Product *foundProduct = toysDept.findProduct(searchName);
    if (foundProduct)
    {
        cout << "\nFound product: ";
        foundProduct->display();
    }
    else
    {
        cout << "\nProduct " << searchName << " not found!" << endl;
    }

    cout << "\nRemoving 'Barbie Doll' from Toys Department." << endl;
    toysDept.removeProduct("Barbie Doll");
    toysDept.displayAll();

    Order order1;
    order1.addProduct(new Shoes("Nike Air", 120.99));
    order1.addProduct(new Toys("Lego Set", 59.99));

    cout << "\nOrder 1 details:" << endl;
    order1.displayOrder();

    cout << "\nTotal Order Value: $" << order1.computeTotalValue() << endl;

    return 0;
}