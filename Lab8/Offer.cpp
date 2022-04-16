#include "Offer.h"
#include <string>
#include <iostream>

Offer::Offer()
{
	this->id = "0";
	this->data_start = "01.01.1970";
	this->data_end = "01.01.1970";
	this->price = 0;
	this->departure = "Bucharest";
	this->destination = "Bucharest";
	this->type = CIRCUIT;
}

Offer::Offer(string ID, unsigned int PRICE, string DEPARTURE, string DESTINATION, string START, string END, OfferType TYPE)
{
	this->id = ID;
	this->data_start = START;
	this->data_end = END;
	this->price = PRICE;
	this->departure = DEPARTURE;
	this->destination = DESTINATION;
	this->type = TYPE;

}
Offer::Offer(const Offer& other)
{
	this->id = other.id;
	this->data_start = other.data_start;
	this->data_end = other.data_end;
	this->price = other.price;
	this->departure = other.departure;
	this->destination = other.destination;
	this->type = other.type;
}



Offer& Offer::operator=(const Offer& other)
{
	this->id = other.id;
	this->data_start = other.data_start;
	this->data_end = other.data_end;
	this->price = other.price;
	this->departure = other.departure;
	this->destination = other.destination;
	this->type = other.type;
	return *this;

}
string Offer::getId()
{
	string rez;
	rez = this->id;
	return rez;
}
unsigned int Offer::getPrice()
{
	unsigned int rez;
	rez = this->price;
	return rez;
}
string Offer::getDeparture()
{
	string rez;
	rez = this->departure;
	return rez;
}
string Offer::getDestination()
{
	string rez;
	rez = this->destination;
	return rez;
}
string Offer::getDataStart()
{
	string rez;
	rez = this->data_start;
	return rez;
}
string Offer::getDataEnd()
{
	string rez;
	rez = this->data_end;
	return rez;
}
OfferType Offer::getType()
{
	OfferType rez;
	rez = this->type;
	return rez;
}
void Offer::setId(string other)
{
	this->id = other;
}
void Offer::setPrice(unsigned int other)
{
	this->price = other;
}
void Offer::setDeparture(string other)
{
	this->departure = other;

}
void Offer::setDestination(string other)
{
	this->destination = other;
}
void Offer::setDataStart(string other)
{
	this->data_start = other;
}
void Offer::setDataEnd(string other)
{
	this->data_end = other;
}
void Offer::setType(OfferType other)
{
	this->type = other;
}

bool operator==(const Offer& A, const Offer& B)
{
	if (A.id == B.id && A.data_end == B.data_end && A.data_start == A.data_start && A.departure == B.departure && A.destination == B.destination && A.id == B.id && A.price == B.price && A.type == B.type)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& stream, Offer O)
{
	stream << "ID:" << O.getId() << ", Price: " << O.getPrice() << ", Departure: " << O.getDeparture() << ", Destination: " << O.getDestination() << ", Starts: " << O.getDataStart() << ", Ends: " << O.getDataEnd() << ", Type: " << O.getType() << " || \n";
	return stream;
}
