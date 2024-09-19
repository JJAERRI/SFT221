#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string city;
    std::string province;
    std::string postalCode;

    static Customer getCustomerInfo();
    static bool isValidPostalCode(const std::string& postalCode, std::string& formattedPostalCode);
};

#endif
