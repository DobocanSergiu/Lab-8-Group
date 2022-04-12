#pragma once
#include <string>

using namespace std;
typedef	enum
{
	CIRCUIT,
	CITYBREAK,
	CRUISE,
	ALLINCLUSIVE,
}OfferType;

class Offer
{
public:
	Offer();
	Offer(string ID, unsigned int PRICE, string DEPARTURE, string DESTINATION, string START, string END, OfferType TYPE);
	Offer(const Offer& other);
	Offer& operator=(const Offer& other);

	string getId();
	unsigned int getPrice();
	string getDeparture();
	string getDestination();
	string getDataStart();
	string getDataEnd();
	OfferType getType();

	void setId(string other);
	void setPrice(unsigned int other);
	void setDeparture(string other);
	void setDestination(string other);
	void setDataStart(string other);
	void setDataEnd(string other);
	void setType(OfferType other);
	friend bool operator==(const Offer& A, const Offer& B);
	friend std::ostream& operator<<(std::ostream& stream, Offer O);
private:
	string id;
	unsigned int price;
	string departure;
	string destination;
	string data_start;
	string data_end;
	OfferType type;
};

