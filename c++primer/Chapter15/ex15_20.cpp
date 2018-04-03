
class Base{
protected:
    int prot_mem;
private:
    char priv_mem;    
};

class Pub_Dery: public Base {
    void memfcn(Base &b) { b = *this; }    
    int f() { return prot_mem; }
};

class Priv_Dery: private Base {
    void memfcn(Base &b) { b = *this; }    
    int f1() const { return prot_mem; }
};

class Prot_Dery: protected Base {
    void memfcn(Base &b) { b = *this; }    
    int f2() { return prot_mem; }
};

class Derived_from_Public: public Pub_Dery {
    void memfcn(Base &b) { b = *this; }    
    int use_base() { return prot_mem; }
};

class Derivec_from_Private: public Priv_Dery {
    //int use_base() { return prot_mem; }    
};

class Derivec_from_Protected: public Prot_Dery {
    void memfcn(Base &b) { b= *this; }
};

int main () {}
