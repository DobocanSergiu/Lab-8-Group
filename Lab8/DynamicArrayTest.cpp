#include "DynamicArrayTest.h"
#include "DynamicArray.h"
#include "Offer.h"
#include <iostream>
#include <cassert>
void DynamicArrayTest::runAllTests()
{
	std::cout << "Starting create test\n";
	createTest();
	std::cout << "Ending create test\n";
	std::cout << "Starting append test\n";
	appendTest();
	std::cout << "Ending append test\n";
	std::cout << "Starting popBack test\n";
	popBackTest();
	std::cout << "Ending popBack test\n";
	std::cout << "Starting remove test\n";
	removeTest();
	std::cout << "Ending remove test\n";
	std::cout << "Starting get test\n";
	getTest();
	std::cout << "Ending get test\n";

}

void DynamicArrayTest::createTest()
{
	DynamicArray testarray;
	assert(testarray.getCapacity() == 100);
	assert(testarray.getLength() == 0);
}
void DynamicArrayTest::appendTest()
{
	DynamicArray testarray;
	Offer testoffer, testoffer2, testoffer3;
	testarray.append(testoffer);
	assert(testarray.getLength() == 1);
	testarray.append(testoffer2);
	assert(testarray.getLength() == 2);
	testarray.append(testoffer3);
	assert(testarray.getLength() == 3);



}

void DynamicArrayTest::popBackTest()
{
	DynamicArray testarray;
	Offer testoffer, testoffer2, returnedoffer;
	testarray.append(testoffer);
	testarray.append(testoffer2);
	assert(testarray.getLength() == 2);
	returnedoffer = testarray.popBack();
	assert(returnedoffer == testoffer2);
	returnedoffer = testarray.popBack();
	assert(returnedoffer == testoffer);


}
void DynamicArrayTest::removeTest()
{
	DynamicArray testarray;
	Offer testoffer, testoffer2, testoffer3, returnedoffer;
	testarray.append(testoffer);
	testarray.append(testoffer2);
	testarray.append(testoffer3);
	assert(testarray.getLength() == 3);
	returnedoffer = testarray.remove(0);
	assert(testarray.getLength() == 2);
	returnedoffer = testarray.remove(0);
	assert(testarray.getLength() == 1);
}
void DynamicArrayTest::getTest()
{
	DynamicArray testarray;
	Offer testoffer, testoffer2, testoffer3, returnedoffer;
	testarray.append(testoffer);
	testarray.append(testoffer2);
	testarray.append(testoffer3);
	returnedoffer = testarray.get(0);
	assert(returnedoffer == testoffer);
	returnedoffer = testarray.get(1);
	assert(returnedoffer == testoffer2);
	returnedoffer = testarray.get(2);
	assert(returnedoffer == testoffer3);



}

