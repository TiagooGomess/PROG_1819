
#include "Client.h"
#include "Address.h"
#include "aux_funcs.h"
#include <string>
#include <vector>


Client::Client(string name, string nif, unsigned short family_size, Address address) {
	this->name = name;
	this->nif = nif;
	this->family_size = family_size;
	this->address = address;
}

Client::Client(string name, string nif, unsigned short family_size, Address address, vector<int>bought_packets, unsigned total_buys) {
	this->name = name;
	this->nif = nif;
	this->family_size = family_size;
	this->address = address;
	this->bought_packs = bought_packets;
	this->total_buys = total_buys;
}

// Getters
string Client::getName() const {
	return this->name;
}

string Client::getNif() const {
	return this->nif;
}

unsigned short Client::getFamily_size() const {
	return this->family_size;
}

Address Client::getAddress() const {
	return this->address;
}

vector<int> Client::getBought_packets() const {
	return this->bought_packs;
}

unsigned Client::getTotal_buys() const {
	return this->total_buys;
}

// Setters
void Client::setName(string name) {
	this->name = name;
}

void Client::setNif(string nif) {
	this->nif = nif;
}

void Client::setFamily_size(unsigned short family_size) {
	this->family_size = family_size;
}
void Client::setAddress(Address address) {
	this->address = address;
}
void Client::setBought_packets(vector<int>& bought_packets) {
	this->bought_packs = bought_packets;
}
unsigned Client::setTotal_buys(unsigned total_buys) {
	this->total_buys = total_buys;
}


ostream& operator<<(ostream& out, const Client& client) {
	out << client.name << "  |  " << client.nif << "  |  " << client.family_size << "  |  " << client.address << "  |  ";
	string pack_ids = "";
	for (size_t i = 0; i < client.bought_packs.size(); i++){
		pack_ids += to_string(client.bought_packs.at(i)) + "; ";
	}
	pack_ids = pack_ids.substr(0, pack_ids.size() - 2);
	out << pack_ids << "  |  " << client.total_buys << "  ";
}