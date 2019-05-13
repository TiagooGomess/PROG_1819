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
	this->clients_filename = clients_filename;
	this->packs_filename = packs_filename;
	f.close();
	string name, nif, address_str, pack_ids_str, family_size, total_buys, not_used;
	vector<Client> clients_vector;
	vector<int> ids;
	f.open(clients_filename);
	if (f.is_open()) {
		do {
			getline(f, name);
			getline(f, nif);
			getline(f, family_size);
			getline(f, address_str);
			getline(f, pack_ids_str);
			getline(f, total_buys);
			getline(f, not_used);
			Address address(address_str);
			ids = separate_string_int(pack_ids_str);
			Client client(name, nif, stoi(family_size), address, ids, stoi(total_buys));
			clients_vector.push_back(client);
		} while(not_used == "::::::::::");
		f.close();
	}
	else {
		cerr << "Error: Could not open the clients file." << endl;
	}
	f.open(packs_filename);
	unsigned int num_spots, already_sold;
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
			f >> already_sold;
			f.clear();
			f.ignore(1000, '\n');
			getline(f, not_used);
			Pack pack(id, places_vector, beginning_date, end_date, price_per_person, num_spots, already_sold);
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

bool Agency::update_clients_file() const{
	ofstream f;
	string ids = "";
	f.open(this->clients_filename, ios::out);
	if (f.is_open()){
		for (size_t i = 0; i < this->clients.size(); i++){
			f << this->clients.at(i).getName() << "\n" << this->clients.at(i).getNif() << "\n" << this->clients.at(i).getFamily_size() << "\n" << this->clients.at(i).getAddress() << "\n";
			for (size_t j = 0; j < this->clients.at(i).getBought_packets().size(); j++){
				ids += to_string(this->clients.at(i).getBought_packets().at(j)) + "; ";
			}
			ids = ids.substr(0, ids.size() - 2);
			f << ids << "\n" << this->clients.at(i).getTotal_buys() << "\n";
			if (i != this->clients.size() - 1)
				f << "::::::::::" << "\n";
			ids = "";
		}
		f.close();
		return true;
	}
	return false;
}

bool Agency::update_packs_file() const{
	ofstream f;
	string places_str = "";
	f.open(this->packs_filename, ios::out);
	if (f.is_open()){
		f << this->packs.at(this->packs.size() - 1).getId() << "\n";
		for (size_t i = 0; i < this->packs.size(); i++){
			f << this->packs.at(i).getId() << "\n";
			for (size_t j = 0; j < this->packs.at(i).getPlaces().size(); j++){
				places_str += this->packs.at(i).getPlaces().at(j);
				if (j == 0)
					places_str += " - ";
				else
					places_str += ", ";
			}
			places_str = places_str.substr(0, places_str.size() - 2);
			f << places_str << "\n" << this->packs.at(i).getBeginningDate() << "\n" << this->packs.at(i).getEndDate() << "\n" << this->packs.at(i).getPricePerPerson() << "\n" << this->packs.at(i).getMaxNumPeople() << "\n" << this->packs.at(i).getAlreadySold() << "\n";
			if (i != this->packs.size() - 1)
				f << "::::::::::" << "\n";
			places_str = "";
		}
		f.close();
		return true;
	}
	return false;
}


// Not Tested
void Agency::create_client(){
	string name, nif, address;
	unsigned short int family_size;
	cout << "Qual o nome do cliente? ";
	getline(cin, name);
	cout << "Qual o NIF do cliente? ";
	getline(cin, nif);
	cout << "Quantas pessoas estão no agregado familiar? ";
	cin >> family_size;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Qual a morada? ";
	getline(cin, address);
	Address add(address);
	Client client(name, nif, family_size, add);
	this->clients.push_back(client);
}

// Not Tested
void Agency::remove_client(){
	string nif;
	int idx = -1;
	cout << "Qual o NIF do cliente que deseja apagar? ";
	getline(cin, nif);
	for (size_t i = 0; i < this->clients.size(); i++){
		if (this->clients.at(i).getNif() == nif)
			idx = i;
	}
	if (idx == -1){
		cout << "Cliente nao encontrado." << endl;
	} else{
		this->clients.erase(this->clients.begin() + idx);
	}
}

// Not Tested
void Agency::change_client(){
	string nif;
	int idx = -1;
	cout << "Qual o NIF do cliente que pretende alterar? ";
	getline(cin, nif);
	for (size_t i = 0; i < this->clients.size(); i++){
		if (this->clients.at(i).getNif() == nif)
			idx = i;
	}
	if (idx == -1)
		cout << "Cliente nao encontrado." << endl;
	else {
		bool running = true;
		int choice = 0;
		do {
			cout << "Que parametro deseja alterar? " << endl;
			cout << " [1] Nome\n [2] NIF\n [3] Numero de pessoas no agregado familiar\n [4] Morada\n [0] Voltar\n";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
			if(choice == 0){
				break;
			}
			string option = "";
			unsigned short int family_size;
			switch(choice){
				case 1:
					cout << "Qual o novo nome? ";
					getline(cin, option);
					this->clients.at(idx).setName(option);
					break;
				case 2:
					cout << "Qual o novo NIF? ";
					getline(cin, option);
					this->clients.at(idx).setNif(option);
					break;
				case 3:
					cout << "Quantas pessoas tem o cliente no seu agregado familiar? ";
					cin >> family_size;
					cin.clear();
					cin.ignore(1000, '\n');
					this->clients.at(idx).setFamily_size(family_size);
					break;
				case 4:
					cout << "Qual a nova morada? ";
					getline(cin, option);
					Address address(option);
					this->clients.at(idx).setAddress(address);
					break;
			}
		} while(running);
	}

}

// Not Tested
// TODO: Verificar se o id ja existe ou nao
void Agency::create_pack(){
	int id;
	unsigned int num_spots;
	double price_p_person;
	string places, date;
	cout << "Qual o id do pack? ";
	cin >> id;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Quais os lugares a visitar? (separados por virgulas)";
	getline(cin, places);
	vector<string> places_vector = separate_string(places, ',');
	cout << "Qual a data de inicio? ";
	getline(cin, date);
	Date beg_date(date);
	cout << "Qual a data de fim? ";
	getline(cin, date);
	Date end_date(date);
	cout << "Qual o preço por pessoa? ";
	cin >> price_p_person;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Quantas sao as vagas totais? ";
	cin >> num_spots;
	cin.clear();
	cin.ignore(1000, '\n');
	Pack pack(id, places_vector, beg_date, end_date, price_p_person, num_spots, 0);
	this->packs.push_back(pack);
}