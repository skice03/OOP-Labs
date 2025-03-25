#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class ListManager
{
private:
    vector<T> elements;

public:
    void addElement(const T &element)
    {
        elements.push_back(element);
    }

    int findElementIndexByKey(const string &key) const
    {
        for (size_t i = 0; i < elements.size(); i++)
        {
            if (elements[i].key == key)
                return i;
        }
        return -1;
    }

    void removeElementByIndex(int index)
    {
        if (index >= 0 && index < elements.size())
            elements.erase(elements.begin() + index);
    }

    void display() const
    {
        for (const auto &element : elements)
            cout << element.key << endl;
    }

    void sortList(bool ascending = true)
    {
        if (ascending)
        {
            sort(elements.begin(), elements.end(), [](const T &a, const T &b)
                 { return a.key < b.key; });
        }
        else
        {
            sort(elements.begin(), elements.end(), [](const T &a, const T &b)
                 { return a.key > b.key; });
        }
    }
};

class Item
{
public:
    string key;
    Item(string k) : key(k) {}
};

int main()
{
    ListManager<Item> manager;

    manager.addElement(Item("Key3"));
    manager.addElement(Item("Key1"));
    manager.addElement(Item("Key2"));

    cout << "List after adding elements:" << endl;
    manager.display();

    cout << "Index of Key2: " << manager.findElementIndexByKey("Key2") << endl;

    manager.sortList(true);
    cout << "List after sorting (ascending):" << endl;
    manager.display();

    manager.removeElementByIndex(1);
    cout << "List after removing element at index 1:" << endl;
    manager.display();

    return 0;
}