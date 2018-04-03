#ifndef CP5_EX15_26_QUOTE_H_
#define CP5_EX15_26_QUOTE_H_

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Quote {
public:
    Quote() {
        cout << "Quote Constructori." << endl; 
    }

    Quote(const string &b, double p): bookNo(b), price(p) {
        cout << "Quote Constructor taking two parameters." << endl;    
    }

    Quote(const Quote &rhs): bookNo(rhs.bookNo), price(rhs.price) {
        cout << "Quote copy Constructor." << endl;
    }

    Quote& operator=(const Quote &rhs) {
        cout << "Quote copy aasignment operator." << endl;    
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
    }

    Quote(Quote &&rhs) noexcept: bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))   { 
        cout << "Quote move Constructor." << endl;
    }

    Quote& operator=(Quote &&rhs) noexcept {
        cout << "Quote move assignment operator." << endl;
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
        return *this;     
    }

    virtual ~Quote() {
        cout << "Quote Destructor." << endl;    
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

private:
    string bookNo;
protected:
    double price = 0.0;
};


#endif


