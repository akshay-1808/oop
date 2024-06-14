#include <iostream>
#include <string>
using namespace std;
template <typename T>
class arraylist
{
protected:
    T *arr;
    int size;
    int capacity;

public:
    arraylist(int capacity = 10)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        size = 0;
    }
    ~arraylist()
    {
        delete[] arr;
    }

    void add(const T &p)
    {
        if (size == capacity)
        {
            cout << "capacity is full" << endl;
            return;
        }
        arr[size] = p;
        size++;
    }
    void del(const T &p)
    {
        if (size > 0)
        {
            int index = -1;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == p)
                {
                    index = i;
                    break;
                }
            }
            if (index != -1)
            {
                for (int i = index; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
            }
            size--;
        }
    }
    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " " << endl;
        }
    }
};

class product
{
    string name;
    int price;

public:
    product()
    {
    }
    product(const string &name, int price)
    {
        this->name = name;
        this->price = price;
    }
    friend ostream &operator<<(ostream &os, const product &p)
    {
        os << "Product name:" << p.name << ",price" << p.price;
        return os;
    }
    bool operator==(const product &p) const
    {
        return name == p.name && price == p.price;
    }
};

class productlist : public arraylist<product>
{
public:
    void addproduct(const product &p)
    {
        add(p);
    }
    void deleteproduct(const product &p)
    {
        del(p);
    }
};

int main()
{
    productlist Productlist;

    product p1("mobile", 10000);
    product p2("laptop", 80000);
    product p3("TV", 15000);

    Productlist.add(p1);
    Productlist.add(p2);
    Productlist.add(p3);
    Productlist.display();

    cout << "after delete 2nd product list:" << endl;
    Productlist.del(p2);
    Productlist.display();
}