#ifndef PRICECODE_H
#define PRICECODE_H

class PriceCode {
public:

    explicit PriceCode(double price) : price(price) {}

    virtual double computePrice(int daysRented) const = 0;

    virtual int getBonusPoints() const {
        return 0;
    }

    virtual ~PriceCode() = default;

protected:
    const double price;
};

#endif //PRICECODE_H
