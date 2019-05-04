#include "Agency.h"



Agency::Agency(string fileName) {

	//  IMPLEMENTATION REQUIRED 
}

// metodos GET -------------------------------------------------------------------------------------------------------------------------------
string Agency::getName() const {
	return this->name;
}

unsigned Agency::getNif() const {
	return this->nif;
}

Address Agency::getAddress() const {
	return this->address;
}

string Agency::getURL() const {
	return this->URL;
}

vector<Client> Agency::getClients() const {
	return this->clients;
}

vector<Packet> Agency::getPackets() const {
	return this->packets;
}


// SET Methods -------------------------------------------------------------------------------------------------------------------------------

void Agency::setName(string name) {
	this->name = name;
}

void Agency::setNif(unsigned nif) {
	this->nif = nif;
}

void Agency::setAddress(Address address) {
	this->address = address;
}

void Agency::setURL(string url) {
	this->URL = URL;
}

void Agency::setClients(vector<Client>& clients) {
	this->clients = clients;
}

void Agency::setPackets(vector<Pack>& packets) {
	this->packets = packets;
}

/*********************************
 * Mostrar Loja
 ********************************/

 // mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency& agency) {

	// A IMPLEMENTATION REQUIRED 
}
