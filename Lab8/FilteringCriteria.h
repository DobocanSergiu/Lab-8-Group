#pragma once
#include "DynamicArray.h"
#include "Offer.h"
#include<iostream>
#include <string>
using namespace std;
// you can add all your filtering classes in this module
template <typename T>
class FilteringCriteria
{
public:
	virtual DynamicArray<T> filter(DynamicArray<T>& arr) = 0;
	
	
};	


template<class T,class c1,class c2,class d1,class d2>
class FilteringCriteriaAnd :public FilteringCriteria<T> {
public:
	FilteringCriteriaAnd(d1 t,d2 s)
	{
		this->criteria1 = c1(t);
		this->criteria2 = c2(s);
	}
	DynamicArray<T> filter(DynamicArray<T>& arr) override
	{
		DynamicArray<T> rez;
		rez = criteria1.filter(arr);
		rez = criteria2.filter(rez);
		return rez;
	}
private:
	c1 criteria1;
	c2 criteria2;
};

template<typename T>
class FilterPrice :public FilteringCriteria<T> {
	float price;

public:
	FilterPrice()
	{
		this->price = 0;

	}
	FilterPrice(float other_price)
	{
		this->price = other_price;
	}
	DynamicArray<T> filter(DynamicArray<T>& arr) override
	{
		DynamicArray<T> rez;
		for (int i = 0; i < arr.getLength(); i++) {
			T a;
			a = arr.get(i);
			if (a.getPrice() <= price) {
				rez.append(a);
			}
		}
		return rez;

	}
};
template<typename T>
class FilterDestination :public FilteringCriteria<T> {
	string destination;

public:
	FilterDestination()
	{
		this->destination ="Default Destination";
		 
	}
	FilterDestination(string other_destination)
	{
		this->destination = other_destination;
	}
	DynamicArray<T> filter(DynamicArray<T>& arr) override
	{
		DynamicArray<T> rez;
		for (int i = 0; i < arr.getLength(); i++)
		{
			T a;
			a = arr.get(i);
			if (a.getDestination() <= destination) {
				rez.append(a);
			}
		}
		return rez;
	}


};


template<typename T>
class FilterDeparture :public FilteringCriteria<T> {
	string departure;

public:

	FilterDeparture()
	{
		this->departure = "Default Location";

	}
	FilterDeparture(string other_destination)
	{
		this->departure = other_destination;
	}
	DynamicArray<T> filter(DynamicArray<T>& arr) override
	{
		DynamicArray<T> rez;
		for (int i = 0; i < arr.getLength(); i++)
		{
			Offer a;
			a = arr.get(i);
			if (a.getDeparture() <= departure) {
				rez.append(a);
			}
		}
		return rez;
	}


};

template<typename T>
class FilterOfferType :public FilteringCriteria<T> {
	OfferType offertype;

public:

	FilterOfferType()
	{
		this->offertype =ALLINCLUSIVE;

	}
	FilterOfferType(OfferType other_offertype)
	{
		if(other_offertype>=0&& other_offertype <=3){
			this->offertype = other_offertype;
		}
	}
	DynamicArray<T> filter(DynamicArray<T>& arr) override
	{
		DynamicArray<T> rez;
		for (int i = 0; i < arr.getLength(); i++)
		{
			Offer a;
			a = arr.get(i);
			if (a.getType() == offertype) {
				rez.append(a);
			}
		}
		return rez;
	}


};



