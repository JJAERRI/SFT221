#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <cassert>
#include <iostream>

void test_isValidPostalCode() {
    std::string formattedPostalCode;

    // Valid postal codes
    assert(Customer::isValidPostalCode("M2E 4X4", formattedPostalCode) == true);
    assert(formattedPostalCode == "M2E 4X4");

    assert(Customer::isValidPostalCode("m2e 4x4", formattedPostalCode) == true);
    assert(formattedPostalCode == "M2E 4X4");

    // Invalid postal codes
    assert(Customer::isValidPostalCode("M2E4X4", formattedPostalCode) == false); // No space
    assert(Customer::isValidPostalCode("M2E4X", formattedPostalCode) == false);
    assert(Customer::isValidPostalCode("M2E 4X444", formattedPostalCode) == false);
    assert(Customer::isValidPostalCode("M2E4 X4", formattedPostalCode) == false); // Space at wrong position
    assert(Customer::isValidPostalCode("M2E  4X4", formattedPostalCode) == false); // Extra spaces
    assert(Customer::isValidPostalCode("M2E 4X#", formattedPostalCode) == false);
    assert(Customer::isValidPostalCode("", formattedPostalCode) == false);
}

void test_getCustomerInfo() {

}

int main() {
    test_isValidPostalCode();
    test_getCustomerInfo();

    std::cout << "All tests passed.\n";
    return 0;
}
