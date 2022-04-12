#pragma once
class FilteringTest
{
public:
	static void runAllTests();
private:
	static void testPriceFiltering();
	static void testTypeFiltering();
	static void testPriceAndTypeFiltering();
};

