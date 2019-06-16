#ifndef NEWRELEASEPRICECODE_H
#define NEWRELEASEPRICECODE_H

#include "PriceCode.h"

#define NEW_RELEASE_PRICE 3

class NewReleasePriceCode : public PriceCode {
public:

    static NewReleasePriceCode& getInstance() {
        static NewReleasePriceCode instance;

        return instance;
    }

    double computePrice(int daysRented) const override {
        return daysRented * price;
    }

    int getBonusPoints() const override {
        return 1;
    }

private:
    explicit NewReleasePriceCode() : PriceCode(NEW_RELEASE_PRICE) {}

public:
    NewReleasePriceCode(NewReleasePriceCode const&) = delete;
    void operator=(NewReleasePriceCode const&) = delete;
};

#endif //NEWRELEASEPRICECODE_H
