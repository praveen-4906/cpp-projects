#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Maximum number of products
const int MAX_PRODUCTS = 25;

// Product details
char   productName[MAX_PRODUCTS][15];
double price[MAX_PRODUCTS];
int    quantity[MAX_PRODUCTS];
double amount[MAX_PRODUCTS];
double totalAmount = 0.0;
int    productCount = 0;

// Constants
const double TAX_RATE = 0.05;     // 5% tax
const double DISCOUNT_RATE = 0.10; // 10% discount for totals over 1000

void displayMenu();
void addProduct();
void displayBill();

void displayMenu() {
    char choice;
    cout << "\nDo you want to add a product? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        addProduct();
    } else {
        displayBill();
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Product limit reached!\n";
        displayBill();
        return;
    }

    cout << "\nEnter name of product " << productCount + 1 << "     : ";
    cin >> productName[productCount];
    cout << "Enter price of product " << productCount + 1 << "    : ";
    cin >> price[productCount];
    cout << "Enter quantity of product " << productCount + 1 << " : ";
    cin >> quantity[productCount];

    amount[productCount] = price[productCount] * quantity[productCount];
    totalAmount += amount[productCount];
    productCount++;

    displayMenu();
}

void displayBill() {
    double discount = 0.0;
    double tax = 0.0;
    double finalTotal = 0.0;

    cout << "\n===========================================\n";
    cout << "             Supermarket Bill               \n";
    cout << "===========================================\n";
    cout << setw(5) << "S.No"
         << setw(15) << "Product"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(12) << "Amount" << endl;
    cout << "-------------------------------------------\n";

    for (int i = 0; i < productCount; i++) {
        cout << setw(5) << i + 1
             << setw(15) << productName[i]
             << setw(10) << fixed << setprecision(2) << price[i]
             << setw(8) << quantity[i]
             << setw(12) << amount[i] << endl;
    }

    cout << "-------------------------------------------\n";
    cout << setw(38) << "Subtotal: " << setw(8) << totalAmount << endl;

    // Apply discount if applicable
    if (totalAmount > 1000) {
        discount = totalAmount * DISCOUNT_RATE;
        cout << setw(38) << "Discount (10%): -" << setw(8) << discount << endl;
    }

    // Tax
    tax = (totalAmount - discount) * TAX_RATE;
    cout << setw(38) << "GST (5%): +" << setw(8) << tax << endl;

    // Final total
    finalTotal = totalAmount - discount + tax;
    cout << "===========================================\n";
    cout << setw(38) << "TOTAL PAYABLE: " << setw(8) << finalTotal << endl;
    cout << "===========================================\n";
}

int main() {
    cout << "===========================================\n";
    cout << "        Supermarket Billing Software        \n";
    cout << "===========================================\n";

    displayMenu();
    return 0;
}
