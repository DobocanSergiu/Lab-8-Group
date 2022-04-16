#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArray.h"
#include "DynamicArrayTest.h"
#include "FilteringCriteria.h"
#include "Offer.h"
#include<string>
#include <iostream>
using namespace std;


void displayMenu() {
	cout << "A|a  add an offer" << endl;
	cout << "S|s  show all offers" << endl;
	cout << "P|p  filter offers by price" << endl;
	cout << "T|t  filter offers by type" << endl;
	cout << "B|b  filter offers by type and price" << endl;
	cout << "Q|q  quit" << endl;
}

int main() {

	//OfferTest::runAllTests();
	//FilteringTest::runAllTests();
	//DynamicArrayTest::runAllTests();
	Offer ofer1;
	ofer1.setDeparture("Bucharest");
	ofer1.setDestination("Rome");
	ofer1.setDataStart("01/01/2023");
	ofer1.setDataEnd("18/01/2023");
	ofer1.setPrice(1300);
	ofer1.setId("1");
	ofer1.setType(CITYBREAK);
	Offer ofer2("2", 3000, "Milan", "Galati", "01/01/2002", "02/02/02", ALLINCLUSIVE);
	DynamicArray<Offer> arr;
	DynamicArray<Offer> result;
	//FilterPrice<Offer> t(2000);
    //FilterDeparture<Offer> p("Bucharest");
	FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterDeparture<Offer>, float, string> z(2000.0, "Bucharest");
	arr.append(ofer1);
	arr.append(ofer2);
	result = z.filter(arr);
	cout << result;
	



	}
	/*
	DynamicArray<Offer> arr;
	arr.append(ofer1);
	string choice;
	choice = 'p';
	while (choice != "q" || choice != "Q")
	{
		displayMenu();
		cin >> choice;
		if (choice == "a" || choice == "A") {
			string id, data_start, data_end, destination, departure;
			OfferType type;
			int price, t;
			cout << "ID:" << endl;
			cin >> id;
			cout << "Price:" << endl;
			cin >> price;
			cout << "Departure: " << endl;
			cin >> departure;
			cout << "Destination: " << endl;
			cin >> destination;
			cout << "Start Date: " << endl;
			cin >> data_start;
			cout << "End Date: " << endl;
			cin >> data_end;
			cout << "Type:0-Circuit,1-CityBreak,2-Cruise,3-AllInclusive  ";
			cin >> t;
			type = CITYBREAK;
			if (t == 1)
			{
				type = CITYBREAK;
			}
			else if (t == 2)
			{
				type = CRUISE;
			}
			else if (t == 3)
			{
				type = ALLINCLUSIVE;
			}
			else if (t == 0)
			{
				type = CIRCUIT;
			}
			Offer O(id, price, departure, destination, data_start, data_end, type);
			arr.append(O);
		}
		else if (choice == "s" || choice == "S")
		{
			cout << arr;
			cout << endl;
		}
		else if (choice == "p" || choice == "P")
		{
			DynamicArray<Offer> result;
			cout << "Price: ";
			int price;
			cin >> price;
			FilterPrice p(price);
			result = p.filter(arr);
			cout << result;
		}
		else if (choice == "t" || choice == "T")
		{
			DynamicArray<Offer> result;
			OfferType type;
			cout << "Type:0-Circuit,1-CityBreak,2-Cruise,3-AllInclusive  ";
			int ty;
			cin >> ty;
			if (ty == 1)
			{
				type = CITYBREAK;
			}
			else if (ty == 2)
			{
				type = CRUISE;
			}
			else if (ty == 3)
			{
				type = ALLINCLUSIVE;
			}
			else if (ty == 0)
			{
				type = CIRCUIT;
			}
			FilterType t(type);
			result = t.filter(arr);
			cout << result << endl;
		}
		else if (choice == "b" || choice == "B")
		{
			DynamicArray<Offer> result;
			int ty, price;
			OfferType type;
			cout << "Type:0-Circuit,1-CityBreak,2-Cruise,3-AllInclusive\n";

			cin >> ty;
			if (ty == 1)
			{
				type = CITYBREAK;
			}
			else if (ty == 2)
			{
				type = CRUISE;
			}
			else if (ty == 3)
			{
				type = ALLINCLUSIVE;
			}
			else if (ty == 0)
			{
				type = CIRCUIT;
			}
			cout << "Price";
			cin >> price;
			FilterTypeAndPrice F(price, type);
			result = F.filter(arr);
			cout << result << endl;
		}
		else if (choice == "q" || choice == "Q")
		{
			return 0;
		}
	}
	return 0;


	///arr.append("DynamicArray class");
	//arr.append("NOT");
	///arr.append("tested");

	///cout << arr << endl;

	displayMenu();

	return 0;
}
*/