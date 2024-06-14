#include <iostream>
#include <string>

using namespace std;

// Node class representing a single element in the linked list
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val) : data(val), next(nullptr) {}
};

// LinkedList class template
template <typename T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end of the list
    void attachEnd(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete a node from the middle of the list by value
    void detachMiddle(T val)
    {
        if (!head)
            return;

        if (head->data == val)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *temp = head;
        while (temp->next && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next)
        {
            Node<T> *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Function to display the linked list
    void display() const
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Product class to hold product information
class Product
{
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}

    // Overloading << operator for easy display
    friend ostream &operator<<(ostream &os, const Product &product)
    {
        os << product.name << ": $" << product.price;
        return os;
    }
};

// ProductBill class derived from LinkedList
class ProductBill : public LinkedList<Product>
{
public:
    void addProduct(const Product &product)
    {
        attachEnd(product);
    }

    void deleteProduct(const Product &product)
    {
        detachMiddle(product);
    }

    void displayBill() const
    {
        cout << "Bill:" << endl;
        display();
    }
};

int main()
{
    // Create a ProductBill object
    ProductBill bill;

    // Add products to the bill
    bill.addProduct(Product("Apple", 0.99));
    bill.addProduct(Product("Banana", 1.20));
    bill.addProduct(Product("Milk", 2.50));

    // Display the bill
    bill.displayBill();

    // Delete a product from the bill
    bill.deleteProduct(Product("Banana", 1.20));

    // Display the bill again
    bill.displayBill();

    return 0;
}
