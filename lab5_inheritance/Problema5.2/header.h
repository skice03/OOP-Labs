#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// base class produs
class Product
{
protected:
    string name;
    double price;

public:
    Product(string name, double price) : name(name), price(price) {}
    virtual ~Product() {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void display() const = 0; // virtual function
};

// clasele shoes / toys care mostenesc din product
class Shoes : public Product
{
public:
    Shoes(string name, double price) : Product(name, price) {}
    void display() const override
    {
        cout << "Shoe - Name: " << name << ", Price: $" << price << endl;
    }
};

class Toys : public Product
{
public:
    Toys(string name, double price) : Product(name, price) {}
    void display() const override
    {
        cout << "Toy - Name: " << name << ", Price: $" << price << endl;
    }
};

class Department
{
private:
    vector<Product *> products;

public:
    ~Department()
    {
        for (auto product : products)
        {
            delete product;
        }
    }

    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    void addProducts(const vector<Product *> &newProducts)
    {
        products.insert(products.end(), newProducts.begin(), newProducts.end());
    }

    Product *findProduct(const string &name) const
    {
        for (auto product : products)
        {
            if (product->getName() == name)
            {
                return product;
            }
        }
        return nullptr;
    }

    void removeProduct(const string &name)
    {
        products.erase(remove_if(products.begin(), products.end(),
                                 [&](Product *product)
                                 {
                                     if (product->getName() == name)
                                     {
                                         delete product;
                                         return true;
                                     }
                                     return false;
                                 }),
                       products.end());
    }

    void displayAll(bool sortByName = true) const
    {
        vector<Product *> sortedProducts = products;

        if (sortByName)
        {
            sort(sortedProducts.begin(), sortedProducts.end(),
                 [](Product *a, Product *b)
                 {
                     return a->getName() < b->getName();
                 });
        }
        else
        {
            sort(sortedProducts.begin(), sortedProducts.end(),
                 [](Product *a, Product *b)
                 {
                     return a->getPrice() < b->getPrice();
                 });
        }

        for (auto product : sortedProducts)
        {
            product->display();
        }
    }
};

class Order
{
private:
    vector<Product *> items;

public:
    ~Order()
    {
        for (auto item : items)
        {
            delete item;
        }
    }

    void addProduct(Product *product)
    {
        items.push_back(product);
    }

    void addProducts(const vector<Product *> &products)
    {
        items.insert(items.end(), products.begin(), products.end());
    }

    vector<Product *> searchProduct(const string &name) const
    {
        vector<Product *> foundProducts;
        for (auto item : items)
        {
            if (item->getName() == name)
            {
                foundProducts.push_back(item);
            }
        }
        return foundProducts;
    }

    double computeTotalValue() const
    {
        double total = 0.0;
        for (auto item : items)
        {
            total += item->getPrice();
        }
        return total;
    }

    void displayOrder() const
    {
        for (auto item : items)
        {
            item->display();
        }
    }
};

#endif
