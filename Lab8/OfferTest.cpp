#include "OfferTest.h"
#include "DynamicArray.h"
#include "Offer.h"
#include <iostream>
#include <cassert>
void OfferTest::runAllTests()
{
	std::cout << "Starting OfferTest\n";
	CreateOffer();
	std::cout << "Ending OfferTest\n";
}
void OfferTest::CreateOffer()
{
	Offer a;
	assert(a.getId() == "0");
	assert(a.getPrice() == 0);
	assert(a.getDataEnd() == "01.01.1970");
	assert(a.getDataStart() == "01.01.1970");
	assert(a.getDestination() == "Bucharest");
	assert(a.getDeparture() == "Bucharest");
	assert(a.getType() == CIRCUIT);
	Offer b("aa", 100, "Paris", "Cluj", "10/10/2022", "11/11/2022", ALLINCLUSIVE);
	assert(b.getId() == "aa");
	assert(b.getPrice() == 100);
	assert(b.getDataEnd() == "11/11/2022");
	assert(b.getDataStart() == "10/10/2022");
	assert(b.getDestination() == "Cluj");
	assert(b.getDeparture() == "Paris");
	assert(b.getType() == ALLINCLUSIVE);


}