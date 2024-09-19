#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <cassert>
#include <iostream>

int main() {
    Customer customer = Customer::getCustomerInfo();
    std::cout << "\nYou entered:\n";
    std::cout << customer.firstName << " " << customer.lastName << "\n";
    std::cout << customer.streetAddress << "\n";
    std::cout << customer.city << ", " << customer.province << ",\n";
    std::cout << customer.postalCode << "\n";


    return 0;
}