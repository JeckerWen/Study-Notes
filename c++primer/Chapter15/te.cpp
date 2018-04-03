#ifdef CP5_EX15_26_DISC_QUOTE_H_
#define CP5_EX15_26_DISC_QUOTE_H_

#include "ex15_26_Quote.h"

class Bulk_quote() {
public:
    Bulk_quote() {
        cout << "Bulk_quote Constructor." << endl;
    }

    Bulk_quote(string &b, double p, size_t m, double d): Quote(b, p), min_qty(m), discount(d) {
        cout << "Bulk_quote Constructor taking four paramters."    
    }

    Bulk_quote& (const Bulk_quote &rhs): Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {
        cout << "Bulk_quote copy Constructor." << endl;     
    }

    Bulk_quote& operator=(const Bulk_quote &rhs) {
        cout << "Bulk_quote copy assignment operator." << endl;    
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        return *this;
    }

    Bulk_quote(Bulk_quote &&rhs) noexcept: Quote(rhs), min_qty(std::move(rhs.minqty)),
                                           discount(std::move(rhs.discount)) {
        cout << "Bulk_quote move Constructor." << endl;                                 
    }

    Bulk_quote& operator=(const Bulk_quote&& rhs) noexcept { 
        cout << "Bulk_quote move assignment operator." << endl;
        Quote::operator=(rhs);
        min_qty = std::move(rhs.min_qty);
        discount = std::move(rhs.discount);
        return *this;    
    }

    virtual ~Bulk_quote() {
        cout << "Bulk_quote destructor." << endl;    
    }

    virtual double net_price(size_t cnt) const override {
        if (cnt >= min_qty) return cnt * (1 - discount) * price;    
        else return cnt * price;
    }

protected:
    size_t min_qty = 0;
    double discount = 0.0;    
};

#endif

