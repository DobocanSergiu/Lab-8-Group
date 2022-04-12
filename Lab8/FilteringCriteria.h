#pragma once
#include <string>
#include "DynamicArray.h"
// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
	DynamicArray filter(DynamicArray& arr)
	{
		return arr;
	}

};

class FilterPrice :public FilteringCriteria {
	float price;

public:
	FilterPrice();
	FilterPrice(float other_price);
	DynamicArray filter(DynamicArray& arr);




};

class FilterType : public FilteringCriteria {
	OfferType type;

public:
	FilterType();
	FilterType(OfferType other_offertype);
	DynamicArray filter(DynamicArray& arr);


};


class FilterTypeAndPrice : public FilteringCriteria {

	FilterType ft;
	FilterPrice fp;
public:
	FilterTypeAndPrice();
	FilterTypeAndPrice(float price, OfferType type);
	DynamicArray filter(DynamicArray& arr);

};


