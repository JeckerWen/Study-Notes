#include"Quote.h"


class Disc_quote: public Quote{
public:
   Disc_quote() = default;
   Disc_quote(const string& b, double p, size_t q, double disc):
              Quote(b, p), quantity(q), discount(disc) { } 
   double net_price(size_t) const = 0;

protected:
    size_t quantity = 0;
    double discount = 0.0;

};
