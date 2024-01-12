#include <iostream>
#include <string>

// Singleton - Clasa `Database`
class Database {
private:
    static Database* instance;
    Database() {}

public:
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database();
        }
        return instance;
    }

    void query(const std::string& sql) {
        std::cout << "Executing SQL query: " << sql << std::endl;
    }

    Database(Database const&) = delete;
    void operator=(Database const&) = delete;
};

Database* Database::instance = nullptr;

// Factory Method - Clase `Product` și `ProductFactory`
class Product {
public:
    virtual void describe() const = 0;
    virtual ~Product() {}
};

class Book : public Product {
public:
    void describe() const override {
        std::cout << "This is a book." << std::endl;
    }
};

class Electronics : public Product {
public:
    void describe() const override {
        std::cout << "This is an electronic item." << std::endl;
    }
};

class ProductFactory {
public:
    static Product* createProduct(const std::string& type) {
        if (type == "book") {
            return new Book();
        } else if (type == "electronics") {
            return new Electronics();
        }
        return nullptr;
    }
};

// Clasă Șablon (Template)
template <typename T>
class ShoppingCart {
public:
    void addItem(const T& item) {
        std::cout << "Item added to cart." << std::endl;
    }

    void checkout() {
        std::cout << "Checkout completed." << std::endl;
    }
};

// Funcție Șablon (Template)
template <typename T>
void printDetails(const T& item) {
    item.describe();
}

int main() {
    // Singleton
    Database* db = Database::getInstance();
    db->query("SELECT * FROM products");

    // Factory Method
    Product* book = ProductFactory::createProduct("book");
    Product* electronic = ProductFactory::createProduct("electronics");

    if (book) book->describe();
    if (electronic) electronic->describe();

    // Clasă Șablon
    ShoppingCart<Book> bookCart;
    ShoppingCart<Electronics> electronicsCart;

    // Funcție Șablon
    if (book) printDetails(*book);
    if (electronic) printDetails(*electronic);

    // Eliberarea memoriei
    delete book;
    delete electronic;

    return 0;
}
