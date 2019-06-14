#ifndef REGULARPRICECODE_H
#define REGULARPRICECODE_H

#include "PriceCode.h"

#define REGULAR_PRICE 2

class RegularPriceCode : public PriceCode {
public:

    static RegularPriceCode& getInstance() {
        static RegularPriceCode instance;

        return instance;
    }

    double computePrice(double daysRented) override {
        return price + ((daysRented > 2) ? (daysRented - 2) * 1.5 : 0);
    }

private:
    explicit RegularPriceCode() : PriceCode(REGULAR_PRICE) {}

public:
    RegularPriceCode(RegularPriceCode const&) = delete;
    void operator=(RegularPriceCode const&) = delete;


};

#endif //REGULARPRICECODE_H
