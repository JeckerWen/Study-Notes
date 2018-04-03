#include"ex15_3_5_6.h"

int main()
{
   Bulk_quote q1("sss-00xx-001", 19.9, 20, 0.2);
   Bulk_quote q2("sss-00xx-002", 19.9, 10, 0.1);
   print_total(std::cout, q1, 10);     
   print_total(std::cout, q2, 10);     
}
