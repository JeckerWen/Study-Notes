#ifndef CP5_EX15_03_QUOTE_H_
#define CP5_EX15_03_QUOTE_H_

#include<iostream>
#include<string>


class Quote {
public:
    Quote() = default;
    Quote(std::string const& b, double p): bookNo(b), price(p) {}

    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n*price; }

    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;    
};

double print_total(std::ostream& os, Quote const& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " <<  item.isbn() << " # sold: " << n << " total due: "
       << ret << std::endl;
    return ret; 
}

class Bulk_quote: public Quote {
public:
        Bulk_quote() = default;
        Bulk_quote(std::string const& b, double p, size_t m, double d):
            Quote(b, p), min_qty(m), discount(d) { }
        double net_price(size_t n) const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;    
};

double Bulk_quote::net_price(size_t n) const
{
    if (n >= min_qty)
        return  price * n * (1 - discount);
    else
        return price * n;
}
/*
double print_total(std::ostream& os, Bulk_quote const& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
       << ret << std::endl;
    return ret;
}
*/
#endif 
