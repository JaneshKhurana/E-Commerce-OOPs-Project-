#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Product class to represent each product in the store
//changes are made by bhumit gupta here
//Janesh is a sexy boy
class Product {
private:
    int productID;
    string name;
    double price;
    int quantity;

public:
    Product(int id, string name, double price, int qty) : productID(id), name(name), price(price), quantity(qty) {}

    int getProductID() const { return productID; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void displayProduct() const {
        cout << "ID: " << productID << ", Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

// CartItem class to represent a product added to the cart with a specified quantity
class CartItem {
private:
    Product product;
    int quantity;

public:
    CartItem(Product prod, int qty) : product(prod), quantity(qty) {}

    Product getProduct() const { return product; }
    int getQuantity() const { return quantity; }

    double getItemTotal() const {
        return product.getPrice() * quantity;
    }

    void displayCartItem() const {
        cout << product.getName() << " - " << quantity << " pcs - $" << getItemTotal() << endl;
    }
};

// Cart class to manage a list of products added to the cart
class Cart {
private:
    vector<CartItem> items;

public:
    void addItem(const Product& product, int quantity) {
        items.push_back(CartItem(product, quantity));
    }

    void displayCart() const {
        cout << "Cart Contents:" << endl;
        for (const auto& item : items) {
            item.displayCartItem();
        }
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getItemTotal();
        }
        return total;
    }
};

// Store class to manage available products
class Store {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayProducts() const {
        cout << "Available Products:" << endl;
        for (const auto& product : products) {
            product.displayProduct();
        }
    }

    Product* getProductByID(int id) {
        for (auto& product : products) {
            if (product.getProductID() == id) {
                return &product;
            }
        }
        return nullptr;
    }
};

// Main function
int main() {
    Store store;
    Cart cart;

    // Add products to the store
    store.addProduct(Product(1, "Laptop", 999.99, 10));
    store.addProduct(Product(2, "Smartphone", 499.99, 15));
    store.addProduct(Product(3, "Headphones", 49.99, 30));

    int choice, productID, quantity;

    while (true) {
        cout << "\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            store.displayProducts();
        }
        else if (choice == 2) {
            cout << "Enter Product ID to add to cart: ";
            cin >> productID;
            Product* product = store.getProductByID(productID);

            if (product) {
                cout << "Enter quantity: ";
                cin >> quantity;

                if (quantity > 0 && quantity <= product->getQuantity()) {
                    cart.addItem(*product, quantity);
                    cout << "Added to cart!" << endl;
                } else {
                    cout << "Invalid quantity!" << endl;
                }
            } else {
                cout << "Product not found!" << endl;
            }
        }
        else if (choice == 3) {
            cart.displayCart();
        }
        else if (choice == 4) {
            cart.displayCart();
            cout << "Total Amount: $" << cart.calculateTotal() << endl;
            cout << "Thank you for shopping!" << endl;
            break;
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
