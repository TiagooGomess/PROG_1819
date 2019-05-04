
#include "Client.h"
#include "Address.h"
#include "aux_funcs.h"
#include <string>
#include <vector>


Client::Client(string name, unsigned nif, unsigned short family_size, Address address) {
	this->name = name;
	this->nif = nif;
	this->family_size = family_size;
	this->address = address;
}

Client::Client(string name, unsigned nif, unsigned short family_size, Address address, vector<Packet>& bought_packets, unsigned total_buys) {
	this->name = name;
	this->nif = nif;
	this->family_size = family_size;
	this->address = address;
	this->bought_packs = bought_packets;
	this->total_buys = total_buys;
}

// GET METHODS -------------------------------------------------------------------------------------------------------------------------------

string Client::getName() const {
	return this->name;
}

unsigned Client::getNif() const {
	return this->nif;
}

unsigned short Client::getFamily_size() const {
	return this->family_size;
}

Address Client::getAddress() const {
	return this->address;
}

vector<Packet> Client::getBought_packets() const {
	return this->bought_packs;
}

unsigned Client::getTotal_buys() const {
	return this->total_buys;
}

// SET METHODS -------------------------------------------------------------------------------------------------------------------------------

void Client::setName(string name) {
	this->name = name;
}

void Client::setNif(unsigned nif) {
	this->nif = nif;
}

void Client::setFamily_size(unsigned short family_size) {
	this->family_size = family_size;
}
void Client::setAddress(Address address) {
	this->address = address;
}
void Client::setBought_packets(vector<Packet>& bought_packets) {
	this->bought_packets = bought_packets;
}
unsigned Client::setTotal_buys(unsigned total_buys) {
	this->total_buys = total_buys;
}

// OTHER METHODS -------------------------------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& out, const Client& client) {

	// REQUIRES IMPLEMENTATION 

}