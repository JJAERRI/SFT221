#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <iostream>
#include <cctype>
#include <algorithm>

void getInput(const std::string& prompt, std::string& input) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            break;
        }
        std::cout << "Invalid Entry: ";
    }
}

bool Customer::isValidPostalCode(const std::string& postalCode, std::string& formattedPostalCode) {
    std::string temp;
    for (char ch : postalCode) {
        if (isalnum(ch)) {
            temp += toupper(ch);
        }
    }

    if (temp.length() != 6) {
        return false;
    }

    formattedPostalCode = temp.substr(0, 3) + " " + temp.substr(3, 3);

    if (postalCode[3] != ' ') {
        return false;
    }

    return true;
}

Customer Customer::getCustomerInfo() {
    Customer customer;
    std::string postalCode;
    std::string formattedPostalCode;

    getInput("Enter your first name: ", customer.firstName);
    getInput("Enter your last name: ", customer.lastName);
    getInput("Enter your street address: ", customer.streetAddress);
    getInput("Enter your city: ", customer.city);
    getInput("Enter your province: ", customer.province);

    while (true) {
        getInput("Enter your postal code: ", postalCode);
        if (isValidPostalCode(postalCode, formattedPostalCode)) {
            customer.postalCode = formattedPostalCode;
            break;
        }
        else {
            std::cout << "Invalid Entry: ";
        }
    }

    return customer;
}

