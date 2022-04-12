#include "FilteringTest.h"
#include "DynamicArray.h"
#include "Offer.h"
#include <iostream>
#include <cassert>
#include "FilteringCriteria.h"
using namespace std;
void FilteringTest::runAllTests()
{
	std::cout << "StartingFilterPriceTest\n";
	testPriceFiltering();
	std::cout << "EndingFilterPirceTest\n";


	std::cout << "StartingFilterTypeTest\n";
	testTypeFiltering();
	std::cout << "EndingFilterTypeTest\n";

	std::cout << "StartingFilterTypeAndPriceTest\n";
	testPriceAndTypeFiltering();
	std::cout << "EndingFilterTypeAndPriceTest\n";

}
void FilteringTest::testPriceFiltering()
{
	DynamicArray arr, rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", ALLINCLUSIVE);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilterPrice t(11111);
	rez = t.filter(arr);
	assert(rez.getLength() == 3);

	FilterPrice tt(100);
	rez = tt.filter(arr);
	assert(rez.getLength() == 0);

	FilterPrice ttt(2500);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 2);


}


void FilteringTest::testTypeFiltering()
{
	DynamicArray arr, rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", CIRCUIT);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilterType t(CIRCUIT);
	rez = t.filter(arr);
	assert(rez.getLength() == 1);

	FilterType tt(ALLINCLUSIVE);
	rez = tt.filter(arr);
	assert(rez.getLength() == 2);

	FilterType ttt(CRUISE);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 0);

}

void FilteringTest::testPriceAndTypeFiltering()
{
	DynamicArray arr, rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", CIRCUIT);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilterTypeAndPrice t(4000, CIRCUIT);
	rez = t.filter(arr);
	assert(rez.getLength() == 1);

	FilterTypeAndPrice tt(2500, ALLINCLUSIVE);
	rez = tt.filter(arr);
	assert(rez.getLength() == 1);

	FilterTypeAndPrice ttt(4000, ALLINCLUSIVE);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 2);

}






