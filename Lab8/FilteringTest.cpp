#include "FilteringTest.h"
#include "DynamicArray.h"
#include "Offer.h"
#include <iostream>
#include <cassert>
#include "FilteringCriteria.h"
using namespace std;
void FilteringTest::runAllTests()
{
	int a;
	std::cout << "StartingFilterPriceTest\n";
	a=testPriceFiltering();
	std::cout << "EndingFilterPirceTest\n";


	std::cout << "StartingFilterTypeTest\n";
	a=testTypeFiltering();
	std::cout << "EndingFilterTypeTest\n";

	std::cout << "StartingFilterTypeAndPriceTest\n";
    testPriceAndTypeFiltering();
	std::cout << "EndingFilterTypeAndPriceTest\n";

}
int FilteringTest::testPriceFiltering()
{
	DynamicArray<Offer> arr,rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", ALLINCLUSIVE);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilterPrice<Offer> t(11111);
	rez = t.filter(arr);
	assert(rez.getLength()==3);

	FilterPrice<Offer> tt(100);
	rez = tt.filter(arr);
	assert(rez.getLength() == 0);

	FilterPrice<Offer> ttt(2500);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 2);
	return 0;

}


int FilteringTest::testTypeFiltering()
{
	DynamicArray<Offer> arr, rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", CIRCUIT);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilterOfferType<Offer> t(CIRCUIT);
	rez = t.filter(arr);
	assert(rez.getLength() == 1);

	FilterOfferType<Offer> tt(ALLINCLUSIVE);
	rez = tt.filter(arr);
	assert(rez.getLength() == 2);

	FilterOfferType<Offer> ttt(CRUISE);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 0);

	return 0;

}


int FilteringTest::testPriceAndTypeFiltering()
{
	DynamicArray<Offer> arr, rez;
	Offer a("1", 1000, "Bucharest", "New york", "01/01/2022", "20/10/2022", CIRCUIT);
	Offer b("2", 2000, "Bucharest", "New Delhi", "15/09/2022", "10/10/2022", ALLINCLUSIVE);
	Offer c("3", 3000, "Bucharest", "Berlin", "03/11/2022", "28/12/2022", ALLINCLUSIVE);
	arr.append(a);
	arr.append(b);
	arr.append(c);
	FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterOfferType<Offer>, float, OfferType> t(4000, CIRCUIT);
	rez = t.filter(arr);
	assert(rez.getLength() == 1);

	FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterOfferType<Offer>, float, OfferType> tt(2500, ALLINCLUSIVE);
	rez = tt.filter(arr);
	assert(rez.getLength() == 1);

	FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterOfferType<Offer>, float, OfferType> ttt(4000, ALLINCLUSIVE);
	rez = ttt.filter(arr);
	assert(rez.getLength() == 2);
	return 0;

}




