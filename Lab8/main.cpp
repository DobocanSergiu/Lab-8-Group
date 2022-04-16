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
	cout << "B|b  filter by any 2 criteria" << endl;
	cout << "Q|q  quit" << endl;
}

int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();
	/*Offer ofer1;
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
	*/

	
	DynamicArray<Offer> arr;
	//arr.append(ofer1);
	string choice;
	choice = "p";
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
			float price;
			cin >> price;
			FilterPrice<Offer> p(price);
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
			FilterOfferType<Offer> t(type);
			result = t.filter(arr);
			cout << result << endl;
		}
		else if (choice == "b" || choice == "B")
		{
			DynamicArray<Offer> result;
			cout << "Choose Criteria 1: "<<endl;
			cout << "1-Price; 2-Departure 3-Destination; 4-Type" << endl;
			int choice1, choice2;
			cin >> choice1;
			cout << "Choose Criteria 2: " << endl;
			cout << "1-Price; 2-Departure 3-Destination; 4-Type" << endl;
			cin >> choice2;
			if (choice1 == 1 && choice2 == 1) {
				DynamicArray<Offer> result;
				float price1, price2;
				cout << "Price1:"; cin >> price1;
				cout << "Price2:"; cin >> price2;
				FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterPrice<Offer>, float, float> z(price1, price2);
				result = z.filter(arr);
				cout << result;
			}
			else if((choice1==1&& choice2==2)||(choice1==2&& choice2==1))
			{ 
				DynamicArray<Offer> result;
				float price; string departure;
				cout << "Price:"; cin >> price;
				cout << "Departure:"; cin >> departure;
				FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterDeparture<Offer>, float, string> z(price, departure);
				result = z.filter(arr);
				cout << result;
			}
			else if ((((choice1 == 1 && choice2 == 3) || (choice1 == 3 && choice2 == 1)))) {
				DynamicArray<Offer> result;
				float price; string destination;
				cout << "Price:"; cin >> price;
				cout << "Destination: "; cin >> destination;
				FilteringCriteriaAnd<Offer, FilterPrice<Offer>, FilterDestination<Offer>, float, string> z(price, destination);
				result = z.filter(arr);
				cout << result;
			}
			else if ((((choice1 == 1 && choice2 == 4) || (choice1 == 4 && choice2 == 1)))) {
				DynamicArray<Offer> result;
				float price;
				float ty; OfferType  type;
				cout << "Price:"; cin >> price;
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
				FilteringCriteriaAnd < Offer, FilterPrice<Offer>, FilterOfferType<Offer>, float, OfferType> z(price, type);
				result = z.filter(arr);
				cout << result;
			}
			else if (choice1 == 2 && choice2 == 2) {
				DynamicArray<Offer> result;
				string dep1, dep2;
				cout << "Departure1:"; cin >> dep1;
				cout << "Departure2:"; cin >> dep2;
				FilteringCriteriaAnd<Offer, FilterDeparture<Offer>, FilterDeparture<Offer>, string, string> z(dep1,dep2);
				result = z.filter(arr);
				cout << result;
			}
			else if ((choice1 == 2 && choice2 == 3)|| (choice1 == 3 && choice2 == 2)) {
				DynamicArray<Offer> result;
				string dep1, dep2;
				cout << "Departure:"; cin >> dep1;
				cout << "Destiantion:"; cin >> dep2;
				FilteringCriteriaAnd<Offer, FilterDeparture<Offer>, FilterDestination<Offer>, string, string> z(dep1, dep2);
				result = z.filter(arr);
				cout << result;
			}
			else if ((((choice1 == 2 && choice2 == 4) || (choice1 == 4 && choice2 == 2)))) {
				DynamicArray<Offer> result;
				string departure;
				float ty; OfferType type;
				cout << "Departure:"; cin >> departure;
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
				FilteringCriteriaAnd < Offer, FilterDeparture<Offer>, FilterOfferType<Offer>, string, OfferType> z(departure, type);
				result = z.filter(arr);
				cout << result;
			}
			else if (choice1 == 3 && choice2 == 3)  {
				DynamicArray<Offer> result;
				string dep1, dep2;
				cout << "Destination:"; cin >> dep1;
				cout << "Destiantion:"; cin >> dep2;
				FilteringCriteriaAnd<Offer, FilterDestination<Offer>, FilterDestination<Offer>, string, string> z(dep1, dep2);
				result = z.filter(arr);
				cout << result;
			}
			else if ((((choice1 == 3 && choice2 == 4) || (choice1 == 4 && choice2 ==3 )))) {
			DynamicArray<Offer> result;
			string departure;
			float ty; OfferType type;
			cout << "Departure:"; cin >> departure;
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
			FilteringCriteriaAnd < Offer, FilterDestination<Offer>, FilterOfferType<Offer>, string, OfferType> z(departure, type);
			result = z.filter(arr);
			cout << result;
			}
			else if (choice1 == 4 && choice2 == 4) {
			DynamicArray<Offer> result;
			float ty1,ty2; OfferType type1,type2;
			cout << "Type:0-Circuit,1-CityBreak,2-Cruise,3-AllInclusive\n";
			cout << "Type1:"; cin >> ty1;
			cout << "Type:0-Circuit,1-CityBreak,2-Cruise,3-AllInclusive\n";
			cout << "Type2:"; cin >> ty2;
			if (ty1 == 1)
			{
				type1 = CITYBREAK;
			}
			else if (ty1 == 2)
			{
				type1 = CRUISE;
			}
			else if (ty1 == 3)
			{
				type1 = ALLINCLUSIVE;
			}
			else if (ty1 == 0)
			{
				type1 = CIRCUIT;
			}
			if (ty2 == 1)
			{
				type2 = CITYBREAK;
			}
			else if (ty2 == 2)
			{
				type2 = CRUISE;
			}
			else if (ty2 == 3)
			{
				type2 = ALLINCLUSIVE;
			}
			else if (ty2 == 0)
			{
				type2 = CIRCUIT;
			}
			FilteringCriteriaAnd < Offer, FilterOfferType<Offer>, FilterOfferType<Offer>, OfferType, OfferType> z(type1, type2);
			result = z.filter(arr);
			cout << result;
			}

			//FilterCriteriaAnd<Offer, FilterPrice<Offer>, FilterDeparture<Offer>, float, string> z(2000.0, "Bucharest");
			//result = F.filter(arr);
			//cout << result << endl;
		}
		else if (choice == "q" || choice == "Q")
		{
			return 0;
		}
	}
	return 0;


	displayMenu();

	return 0;
}
