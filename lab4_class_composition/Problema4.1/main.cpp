#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"

using namespace std;

int main()
{
    // creare si adaugare produse / categorii + afisare la final
    Product product1("Laptop", 1200.00, true, "Electronics");
    Product product2("Smartphone", 800.00, false, "Electronics");
    Product product3("Shirt", 30.00, true, "Clothing");
    Product product4("Jeans", 50.00, false, "Clothing");

    Category electronics("Electronics");
    Category clothing("Clothing");

    electronics.addProduct(product1);
    electronics.addProduct(product2);
    clothing.addProduct(product3);
    clothing.addProduct(product4);

    OnlineShop shop;

    shop.addCategory(electronics);
    shop.addCategory(clothing);

    shop.addProductToShop(product1);
    shop.addProductToShop(product2);
    shop.addProductToShop(product3);
    shop.addProductToShop(product4);

    shop.displayAllProducts();

    shop.displayPromotionProducts();

    shop.searchProducts("Shirt");

    shop.searchProducts("", 30.00, 100.00);

    shop.searchProducts("", -1, -1, "Electronics");

    shop.removeProductFromShop("Jeans");
    cout << "\nAfter removing 'Jeans':\n";
    shop.displayAllProducts();

    return 0;
}