#include <memory>
#include <iostream>
#include "./p15_3Quote.h"
#include "./p15_5Bulkquote.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);

	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);

	return 0;
}