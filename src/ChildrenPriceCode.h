#ifndef CHILDRENPRICECODE_H
#define CHILDRENPRICECODE_H

#include "PriceCode.h"

#define CHILDREN_PRICE 1.5

class ChildrenPriceCode : public PriceCode {
public:

    static ChildrenPriceCode& getInstance() {
        static ChildrenPriceCode instance;

        return instance;
    }

    double computePrice(double daysRented) override {
        return price + ((daysRented > 3) ? (daysRented - 3) * 1.5 : 0);
    }

private:
    explicit ChildrenPriceCode() : PriceCode(CHILDREN_PRICE) {}

public:
    ChildrenPriceCode(ChildrenPriceCode const&) = delete;
    void operator=(ChildrenPriceCode const&) = delete;

};

#endif //CHILDRENPRICECODE_H
