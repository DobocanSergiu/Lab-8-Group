#include "FilteringCriteria.h"
#include "DynamicArray.h"
#include<iostream>
using namespace std;
FilterPrice::FilterPrice()
{
	this->price = 0;
}

FilterPrice::FilterPrice(float other_price)
{
	this->price = other_price;
}

DynamicArray FilterPrice::filter(DynamicArray& arr)
{
	DynamicArray rez;
	for (int i = 0; i < arr.getLength(); i++) {
		Offer a;
		a = arr.get(i);
		if (a.getPrice() <= price) {
			rez.append(a);
		}
	}
	return rez;
}


FilterType::FilterType()
{
	this->type = ALLINCLUSIVE;
}

FilterType::FilterType(OfferType other_type)
{
	this->type = other_type;

}
DynamicArray FilterType::filter(DynamicArray& arr)
{
	DynamicArray rez;
	for (int i = 0; i < arr.getLength(); i++)
	{
		Offer a;
		a = arr.get(i);
		if (a.getType() == this->type)
		{
			rez.append(a);

		}

	}
	return rez;
}

FilterTypeAndPrice::FilterTypeAndPrice()
{
	this->ft = FilterType(ALLINCLUSIVE);
	this->fp = FilterPrice(0);
}
FilterTypeAndPrice::FilterTypeAndPrice(float price, OfferType type)
{
	this->fp = FilterPrice(price);
	this->ft = FilterType(type);
}

DynamicArray FilterTypeAndPrice::filter(DynamicArray& arr)
{
	DynamicArray rez = fp.filter(arr);
	rez = ft.filter(rez);
	return rez;
}

