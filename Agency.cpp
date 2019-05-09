#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "aux_funcs.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Agency::Agency(string filename) {
	ifstream f;
	string field = "", clients_filename = "", packs_filename = "";
	f.open(filename);
	getline(f, this->name);
	getline(f, this->nif);
	getline(f, this->URL);
	getline(f, field);
	this->address = Address(field);
	getline(f, clients_filename);
	getline(f, packs_filename);
	f.close();
	string name, nif, packs, address_str, not_used;
	unsigned int total_buys, num_people;
	vector<Client> clients_vector;
	f.open(filename);
	if (f.is_open()) {
		while (!f.eof()) {
			getline(f, name);
			getline(f, nif);
			f >> num_people;
			f.clear();
			f.ignore(1000, '\n');
			getline(f, address_str);
			getline(f, packs);
			f >> total_buys;
			f.clear();
			f.ignore(1000, '\n');
			getline(f, not_used);
			Address address(address_str);
			packs += ";";
			stringstream s(packs);
			int id;
			vector<int> pack_ids;
			while(s >> id){
				pack_ids.push_back(id);
				s.clear();
				s.ignore(1000, ' ');
			}
			Client client(name, nif, num_people, address, pack_ids, total_buys);
			clients_vector.push_back(client);
		}
		f.close();
	}
	else {
		cerr << "Error: Could not open the clients file." << endl;
	}

	f.open(packs_filename);
	unsigned int num_spots;
	vector<Pack> packs_vector;
	vector <string> places_vector;
	double price_per_person;
	int id;
	string places, beg_date, e_date, last_id;
	if (f.is_open()) {
		getline(f, last_id);
		while (!f.eof()) {
			f >> id;
			f.clear();
			f.ignore(1000, '\n');
			getline(f, places);
			places_vector = parse_places(places);
			getline(f, beg_date);
			Date beginning_date(beg_date);
			getline(f, e_date);
			Date end_date(e_date);
			f >> price_per_person;
			f.clear();
			f.ignore(1000, '\n');
			f >> num_spots;
			f.clear();
			f.ignore(1000, '\n');
			getline(f, not_used);
			Pack pack(id, places_vector, beginning_date, end_date, price_per_person, num_spots);
			packs_vector.push_back(pack);
		}
		f.close();
	}
	else {
		cerr << "Error: Could not open the packs file." << endl;
	}
	this->packs = packs_vector;
	this->clients = clients_vector;
}

// Getters
string Agency::getName() const {
	return this->name;
}

string Agency::getNif() const {
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

vector<Pack> Agency::getPackets() const {
	return this->packs;
}


// Setters
void Agency::setName(string name) {
	this->name = name;
}

void Agency::setNif(string nif) {
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

void Agency::setPackets(vector<Pack>& packs) {
	this->packs = packs;
}

ostream& operator<<(ostream& out, const Agency& agency) {
	out << agency.name << "  |  " << agency.nif << "  |  " << agency.URL << "  |  " << agency.address << "  ";
}
