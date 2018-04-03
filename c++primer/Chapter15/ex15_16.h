#include"Disc_quote.h"

class Limit_quote: public Disc_quote{
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double p, size_t min, double disc, size_t max): Disc_quote(book, p, min, disc),
    max_qty(max) { }

    double net_price(size_t n) const override final {
        if (n > max_qty) return max_qty * (1 - discount) * price + (n - max_qty) * price;
        else if (n >= quantity) return n * (1- discount) * price;
        else return n * price;    
    }


private:
    size_t max_qty = 0;    
    
};

