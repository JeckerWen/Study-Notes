#include<iostream>
#include<string>


using std::string;


class Quote{
public:
    Quote() = default;
    Quote(const string& b, double p): bookNo(b), price(p) { }

    const string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const {
        std::cout << "data members: \n" << "\tbookNo: "
                  << bookNo << "\tprice: " << price << std::endl;    
    }

    virtual ~Quote() = default;
private:
    string  bookNo;
protected:
    double price; 
};

double print_total(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold:  " << n
       << " total due:  " << ret << std::endl;
    return ret;    
}

