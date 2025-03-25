#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Product
{
public:
    string name;
    double price;
    bool onPromotion;
    string category;

    // constructor de initializare
    Product(string name, double price, bool onPromotion, string category)
        : name(name), price(price), onPromotion(onPromotion), category(category) {}

    void displayProduct() const
    {
        cout << "Name: " << name << ", Price: $" << price
             << ", Promotion: " << (onPromotion ? "Yes" : "No")
             << ", Category: " << category << endl;
    }
};

class Category
{
public:
    string name;
    vector<Product> products;

    Category(string name) : name(name) {}

    void addProduct(const Product &product)
    {
        products.push_back(product);
    }

    void removeProduct(const string &productName)
    {
        products.erase(remove_if(products.begin(), products.end(),
                                 [&productName](const Product &p)
                                 { return p.name == productName; }),
                       products.end());
    }

    // afisare produse dintr-o categorie
    void displayCategoryProducts() const
    {
        cout << "Category: " << name << endl;
        for (const auto &product : products)
        {
            product.displayProduct();
        }
    }
};

class OnlineShop
{
private:
    vector<Category> categories;
    vector<Product> allProducts;

public:
    void addCategory(const Category &category)
    {
        categories.push_back(category);
    }

    void removeCategory(const string &categoryName)
    {
        categories.erase(remove_if(categories.begin(), categories.end(),
                                   [&categoryName](const Category &c)
                                   { return c.name == categoryName; }),
                         categories.end());
    }

    void addProductToShop(const Product &product)
    {
        allProducts.push_back(product);
    }

    void removeProductFromShop(const string &productName)
    {
        allProducts.erase(remove_if(allProducts.begin(), allProducts.end(),
                                    [&productName](const Product &p)
                                    { return p.name == productName; }),
                          allProducts.end());
    }

    void displayAllProducts() const
    {
        cout << "\nAll products in the shop:\n";
        for (const auto &product : allProducts)
        {
            product.displayProduct();
        }
    }

    void displayPromotionProducts() const
    {
        cout << "\nProducts on promotion:\n";
        for (const auto &product : allProducts)
        {
            if (product.onPromotion)
            {
                product.displayProduct();
            }
        }
    }

    // cautare produse dupa nume / pret / categorie
    void searchProducts(const string &name = "", double minPrice = -1, double maxPrice = -1, const string &category = "") const
    {
        cout << "\nSearch results:\n";
        for (const auto &product : allProducts)
        {
            bool match = true;

            if (!name.empty() && product.name.find(name) == string::npos)
            {
                match = false;
            }
            if (minPrice != -1 && product.price < minPrice)
            {
                match = false;
            }
            if (maxPrice != -1 && product.price > maxPrice)
            {
                match = false;
            }
            if (!category.empty() && product.category != category)
            {
                match = false;
            }

            if (match)
            {
                product.displayProduct();
            }
        }
    }
};

#endif