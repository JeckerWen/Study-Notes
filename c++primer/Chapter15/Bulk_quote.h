#include"Disc_quote.h"

class Bulk_quote: public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& b, double p, size_t q, double disc):
              Disc_quote(b, p, q, disc) { }
    double net_price(size_t) const override;
};
