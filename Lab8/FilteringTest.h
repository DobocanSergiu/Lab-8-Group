#pragma once
class FilteringTest
{
public:
	static void runAllTests();
private:
	static int testPriceFiltering();
	static int testTypeFiltering();
	static int testPriceAndTypeFiltering();
};

