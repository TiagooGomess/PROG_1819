#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "aux_funcs.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Construtor
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
		this->last_pack_id = stoi(last_id);
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

// Metodo para atualizar o ficheiro de clientes
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

// Metodo para atualizar o ficheiro de packs
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

// Metodo para criar um cliente
void Agency::create_client(){
	string name, nif, address;
	unsigned short int family_size;
	bool valid = false;
	cout << "Qual o nome do cliente? ";
	getline(cin, name);
	do{
		cout << "Qual o NIF do cliente? ";
		getline(cin, nif);
	} while(!is_valid(nif));
	do {
		cout << "Quantas pessoas estão no agregado familiar? ";
		cin >> family_size;
		if(cin.fail()){
			cout << "Invalido. Introduza de novo." << endl;
			valid = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			valid = true;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while(!valid);
	Address add;
	do {
		cout << "Qual a morada? ";
		getline(cin, address);
		add = Address(address);
	} while(!add.isValid());
	Client client(name, nif, family_size, add);
	this->clients.push_back(client);
}


// Metodo para remover um cliente
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

// Metodo para alterar a informaçao de um cliente
void Agency::change_client(){
	string nif;
	bool valid = false;
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
		unsigned int choice = 0;
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
			Address add;
			unsigned short int family_size;
			switch(choice){
				case 1:
					cout << "Qual o novo nome? ";
					getline(cin, option);
					this->clients.at(idx).setName(option);
					break;
				case 2:
					do{
						cout << "Qual o novo NIF do cliente? ";
						getline(cin, nif);
					} while(!is_valid(nif));
					this->clients.at(idx).setNif(option);
					break;
				case 3:
						do {
							cout << "Quantas pessoas estão no agregado familiar? ";
							cin >> family_size;
							if(cin.fail()){
								cout << "Invalido. Introduza de novo." << endl;
								valid = false;
								cin.clear();
								cin.ignore(1000, '\n');
							}
							else {
								valid = true;
								cin.clear();
								cin.ignore(1000, '\n');
							}
						} while(!valid);
					this->clients.at(idx).setFamily_size(family_size);
					break;
				case 4:
					do {
						cout << "Qual a morada? ";
						getline(cin, option);
						add = Address(option);
					} while(!add.isValid());
					this->clients.at(idx).setAddress(add);
					break;
				default:
					cout << "Opcao inexistente. Introduza de novo." << endl;
			}
		} while(running);
	}

}

// Metodo para criar um pacote
void Agency::create_pack(){
	int id = this->last_pack_id + 1;;
	unsigned int num_spots;
	double price_p_person;
	string places, date;
	cout << "Quais os lugares a visitar? (separados por virgulas)";
	getline(cin, places);
	vector<string> places_vector = separate_string(places, ',');
	Date beg_date;
	do {
		cout << "Qual a data de inicio? ";
		getline(cin, date);
		beg_date = Date(date);
	} while(!beg_date.isValid());
	Date end_date;
	do {
		cout << "Qual a data de fim? ";
		getline(cin, date);
		end_date = Date(date);
	} while(!end_date.isValid());
	bool valid = false;
	do {
		cout << "Qual o preço por pessoa? ";
		cin >> price_p_person;
		if(cin.fail()){
			cout << "Invalido. Introduza de novo." << endl;
			valid = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			valid = true;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while(!valid);
	valid = false;
	do {
		cout << "Quantas sao as vagas totais? ";
		cin >> num_spots;
		if(cin.fail()){
			cout << "Invalido. Introduza de novo." << endl;
			valid = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			valid = true;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while(!valid);
	Pack pack(id, places_vector, beg_date, end_date, price_p_person, num_spots, 0);
	this->packs.push_back(pack);
}

// Metodo para alterar a informaçao de um pacote
void Agency::change_pack(){
	int id, idx = -1;
	cout << "Qual o id do pack que pretende alterar? ";
	cin >> id;
	cin.clear();
	cin.ignore(1000, '\n');

	for (size_t i = 0; i < this->packs.size(); i++){
		if (this->packs.at(i).getId() == id)
			idx = i;
	}

	if (idx == -1){
		cout << "Pack nao encontrado." << endl;
	} else {
		bool running = true;
		unsigned int choice = 0;
		do {
			cout << "Que parametro do pack deseja alterar? " << endl;
			cout << " [1] Locais a visitar\n [2] Data de inicio\n [3] Data de fim\n [4] Preco por pessoa\n [5] Número total de vagas\n [0] Voltar\n";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
			if(choice == 0){
				break;
			}
			int new_id, num_spots;
			double price;
			bool valid = false;
			string option = "", date = "";
			Date end_date, beg_date;
			switch(choice){
				case 1:
					cout << "Quais os novos locais a visitar (separados por virgulas) ? ";
					getline(cin, option);
					this->packs.at(idx).setPlaces(separate_string(option, ','));
					break;
				case 2:
					do {
						cout << "Qual a nova data de inicio? ";
						getline(cin, date);
						beg_date = Date(date);
					} while(!beg_date.isValid());
					break;
				case 3:
					do {
						cout << "Qual a nova data de fim? ";
						getline(cin, date);
						end_date = Date(date);
					} while(!end_date.isValid());
					this->packs.at(idx).setEndDate(end_date);
					break;
				case 4:
					do {
						cout << "Qual o novo preço por pessoa? ";
						cin >> price;
						if(cin.fail()){
							cout << "Invalido. Introduza de novo." << endl;
							valid = false;
							cin.clear();
							cin.ignore(1000, '\n');
						}
						else {
							valid = true;
							cin.clear();
							cin.ignore(1000, '\n');
						}
					} while(!valid);
					this->packs.at(idx).setPricePerPerson(price);
					valid = false;
					break;
				case 5:
					do {
						cout << "Qual é o novo total de vagas? ";
						cin >> num_spots;
						if(cin.fail()){
							cout << "Invalido. Introduza de novo." << endl;
							valid = false;
							cin.clear();
							cin.ignore(1000, '\n');
						}
						else {
							valid = true;
							cin.clear();
							cin.ignore(1000, '\n');
						}
					} while(!valid);
					this->packs.at(idx).setMaxNumPeople(num_spots);
					break;
				default:
					cout << "Opcao inexistente. Introduza de novo." << endl;
			}
		} while(running);
	}
}

// Metodo para remover/tornar indisponivel um pacote
void Agency::remove_pack(){
	int id, idx = -1;
	cout << "Qual o id do pack que pretende remover? ";
	cin >> id;
	cin.clear();
	cin.ignore(1000, '\n');

	for (size_t i = 0; i < this->packs.size(); i++){
		if (this->packs.at(i).getId() == id)
			idx = i;
	}

	if (idx == -1){
		cout << "Pack nao encontrado." << endl;
	} else {
		this->packs.at(idx).setId(-this->packs.at(idx).getId());
	}

}

// Metodo para mostrar informaçao sobre um cliente especifico
void Agency::show_specific_client() const{
	string nif = "";
	int idx = -1;
	cout << "Qual o NIF do cliente? ";
	getline(cin, nif);
	for (size_t i = 0; i < this->clients.size(); i++){
		if (this->clients.at(i).getNif() == nif)
			idx = i;	
	}
	if (idx == -1)
		cout << "Cliente nao encontrado" << endl;
	else {
		cout << "[Name]: " << this->clients.at(idx).getName() << endl;
		cout << "[NIF]: " << this->clients.at(idx).getNif() << endl;
		cout << "[Number of people on the household]: " << this->clients.at(idx).getFamily_size() << endl;
		cout << "[Address]: " << this->clients.at(idx).getAddress() << endl;
		cout << "[List of purchased packages]: ";
		for (int j = 0; j < this->clients.at(idx).getBought_packets().size() - 1; j++) {
			cout << this->clients.at(idx).getBought_packets().at(j) << " ; ";
		}
		// Adds the last element of the vector list_of_purchased_packages; I did this to avoid the ';' in the end of the identifiers pack's list
		cout << this->clients.at(idx).getBought_packets().at(this->clients.at(idx).getBought_packets().size() - 1);
	}
}

// Metodo para mostrar informaçao de todos os clientes
void  Agency::show_all_clients() const {
	for (size_t i = 0; i < this->clients.size(); i++) {
		cout << "[Nome]: " << this->clients.at(i).getName() << endl;
		cout << "[NIF]: " << this->clients.at(i).getNif() << endl;
		cout << "[Numero de pessoas no agregado familiar]: " << this->clients.at(i).getFamily_size() << endl;
		cout << "[Morada]: " << this->clients.at(i).getAddress() << endl;
		cout << "[Lista de pacotes comprados]: ";
		for (int j = 0; j < this->clients.at(i).getBought_packets().size() - 1; j++) {
			cout << this->clients.at(i).getBought_packets().at(j) << " ; ";
		}
		// Adds the last element of the vector list_of_purchased_packages; I did this to avoid the ';' in the end of the identifiers pack's list
		cout << this->clients.at(i).getBought_packets().at(this->clients.at(i).getBought_packets().size() - 1);
		cout << "\n\n";
	}
}

// Metodo para mostrar informaçao de todos os packs
void Agency::show_all_packs() const{
	for (size_t i = 0; i < this->packs.size(); i++)
		cout << this->packs.at(i) << endl;
}

// Metodo para mostrar informaçao sobre packs relativos a um dado lugar
void Agency::show_all_packs_related_to_place() const{
	string place = "";
	vector<Pack> target_packs;
	cout << "Qual o local? ";
	getline(cin, place);
	for (size_t i = 0; i < this->packs.size(); i++){
		for (size_t j = 0; j < this->packs.at(i).getPlaces().size(); j++){
			if (this->packs.at(i).getPlaces().at(j) == place)
				target_packs.push_back(this->packs.at(i));
		}
	}
	if (target_packs.size() == 0)
		cout << "Nao ha nenhum pack relativo a esse destino." << endl;
	else{
		for (size_t i = 0; i < target_packs.size(); i++){
			cout << target_packs.at(i) << endl;
		}
	}
}

// Metodo para mostrar informaçao relativa a packs entre duas datas
void Agency::show_packs_between_dates() const{
	Date beg_date, end_date;
	vector<Pack> target_packs;
	string date = "";
	cout << "Qual a primeira data? ";
	getline(cin, date);
	beg_date = Date(date);
	cout << "Qual a segunda data? ";
	getline(cin, date);
	end_date = Date(date);
	for (size_t i = 0; i < this->packs.size(); i++){
		if (beg_date < this->packs.at(i).getBeginningDate() && this->packs.at(i).getEndDate() < end_date)
			target_packs.push_back(this->packs.at(i));
	}
	if (target_packs.size() == 0)
		cout << "Nenhum pack foi encontrado" << endl;
	else
		for (size_t i = 0; i < target_packs.size(); i++)
			cout << target_packs.at(i) << endl;
}

// Metodo para mostrar informaçao sobre packs reltivos a um certo lugar, entre duas datas
void Agency::show_packs_between_dates_and_related_to_place() const{
	Date beg_date, end_date;
	string date = "", place = "";
	vector<Pack> target_packs, intermediate;
	cout << "Qual o local? ";
	getline(cin, place);
	cout << "Qual a primeira data? ";
	getline(cin, date);
	beg_date = Date(date);
	cout << "Qual a segunda data? ";
	getline(cin, date);
	end_date = Date(date);
	for (size_t i = 0; i < this->packs.size(); i++){
		for (size_t j = 0; j < this->packs.at(i).getPlaces().size(); j++){
			if (this->packs.at(i).getPlaces().at(j) == place)
				intermediate.push_back(this->packs.at(i));
		}
	}
	for (size_t i = 0; i < intermediate.size(); i++){
		if (beg_date < intermediate.at(i).getBeginningDate() && intermediate.at(i).getEndDate() < end_date)
			target_packs.push_back(intermediate.at(i));
	}
	if (target_packs.size() == 0)
		cout << "Nenhum pack foi encontrado" << endl;
	else
	{
		for (size_t i = 0; i < target_packs.size(); i++)
			cout << target_packs.at(i) << endl;
	}
}

// Metodo para mostrar informaçao relativa a packs vendidos a um cliente especifico
void Agency::show_packs_sold_to_client() const{
	string nif = "";
	int idx = -1;
	vector<Pack> target_packs;
	cout << "Qual o nif do cliente? ";
	getline(cin, nif);
	for (size_t i = 0; i < this->clients.size(); i++){
		if (this->clients.at(i).getNif() == nif){
			idx = i;
		}
	}
	if (idx == -1)
		cout << "Cliente nao encontrado" << endl;
	else {
		for (size_t i = 0; i < this->clients.at(idx).getBought_packets().size(); i++){
			for (size_t j = 0; j < this->packs.size(); j++){
				if (this->packs.at(j).getId() == this->clients.at(idx).getBought_packets().at(i))
					target_packs.push_back(this->packs.at(j));
			}
		}
		if (target_packs.size() == 0)
			cout << "Nenhum pack foi encontrado" << endl;
		else {
			for (size_t i = 0; i < target_packs.size(); i++)
				cout << target_packs.at(i) << endl;
		}
	}
}

// Metodo para mostrar informaçao sobre todos os packs vendidos
void Agency::show_packs_sold_to_all_clients() const{
	vector<int> all_ids;
	vector<Pack> target_packs;

	for(size_t i = 0; i < this->clients.size(); i++){
		for (size_t j = 0; j < this->clients.at(i).getBought_packets().size(); j++){
			if (!is_in(this->clients.at(i).getBought_packets().at(j), all_ids))
				all_ids.push_back(this->clients.at(i).getBought_packets().at(j));
		}
	}

	for (size_t i = 0; i < all_ids.size(); i++){
		for (size_t j = 0; j < this->packs.size(); j++){
			if (this->packs.at(j).getId() == all_ids.at(i))
				target_packs.push_back(this->packs.at(j));
		}
	}
	if (target_packs.size() == 0)
		cout << "Nenhum pack foi encontrado" << endl;
	else
		for (size_t i = 0; i < target_packs.size(); i++)
			cout << target_packs.at(i) << endl;
}

// Metodo para comprar um pack por um cliente
void Agency::buy_pack(){
	string nif = "";
	int idx = -1, id, id_idx = -1;
	cout << "Qual o NIF do cliente? ";
	getline(cin, nif);
	for (size_t i = 0; i < this->clients.size(); i++){
		if (this->clients.at(i).getNif() == nif)
			idx = i;
	}
	if (idx == -1)
		cout << "Cliente nao encontrado" << endl;
	else {
		cout << "Qual o id do pack? ";
		cin >> id;
		cin.clear();
		cin.ignore(1000, '\n');
		for (size_t i = 0; i < this->packs.size(); i++){
			if (this->packs.at(i).getId() == id)
				id_idx = i;
		}
		if (id_idx == -1)
			cout << "Pack nao encontrado" << endl;
		else {
			if (this->packs.at(idx).getId() < 0)
				cout << "Pack Indisponivel." << endl;
			else{
				if (this->packs.at(id_idx).getMaxNumPeople() - this->packs.at(id_idx).getAlreadySold() - this->clients.at(idx).getFamily_size() >= 0){
					// Atualiza lista de pacotes comprados pelo cliente
					vector<int> ids = this->clients.at(idx).getBought_packets();
					ids.push_back(this->packs.at(id_idx).getId());
					this->clients.at(idx).setBought_packets(ids);

					// Atualiza total de compras do cliente
					this->clients.at(idx).setTotal_buys(this->clients.at(idx).getTotal_buys() + this->clients.at(idx).getFamily_size() * this->packs.at(id_idx).getPricePerPerson());

					// Atualiza vagas do pack
					this->packs.at(id_idx).setAlreadySold(this->packs.at(id_idx).getAlreadySold() + this->clients.at(idx).getFamily_size());
					if (this->packs.at(id_idx).getMaxNumPeople() - this->packs.at(id_idx).getAlreadySold() == 0)
						this->packs.at(id_idx).setId(-this->packs.at(idx).getId());
				}
				else
					cout << "Nao ha vagas disponiveis" << endl;
			}
		}
	}
}

// Metodo para mostrar informaçao sobre o total de packs vendidos e o valor destes
void Agency::show_sold_packs_info() const{
	unsigned int sum = 0, total_money = 0;
	for (size_t i = 0; i < this->packs.size(); i++){
		sum += this->packs.at(i).getAlreadySold();
		total_money += this->packs.at(i).getAlreadySold() * this->packs.at(i).getPricePerPerson();
	}
	cout << "Total de packs vendidos: " << sum << endl << "Valor total dos pacotes vendidos: " << total_money << endl;
}

// Metodo para obter os N locais mais visitados
vector<spe_pair> Agency::get_most_visited_places(){
	map<string, int> places_map;
	vector<spe_pair> v;
	unsigned int n = 0;
	vector<spe_pair> vec;
	for (size_t i = 0; i < this->packs.size(); i++){
		for (size_t j = 0; j < this->packs.at(i).getPlaces().size(); j++){
			if (places_map.count(this->packs.at(i).getPlaces().at(j)) > 0)
				places_map[this->packs.at(i).getPlaces().at(j)] += 1;
			else
				places_map[this->packs.at(i).getPlaces().at(j)] = 1;
		}
	}
	copy(places_map.begin(), places_map.end(), back_inserter<vector<spe_pair>>(v));
	sort(v.begin(), v.end(), [](const spe_pair &pair1, const spe_pair &pair2){
		if (pair1.second != pair2.second)
			return pair1.second > pair2.second;
		return pair1.first < pair2.first;
	});
	cout << "Quantos locais pretende visualizar? ";
	cin >> n;
	cin.clear();
	cin.ignore(1000, '\n');
	if (n > v.size())
		cout << "Numero invalido" << endl;
	else {
		copy(v.begin(), v.begin() + n, back_inserter(vec));
	}
	return vec;
}

// Metodo para mostrar os locais mais visitados
void Agency::show_most_visited_places(){
	vector<spe_pair> v = get_most_visited_places();
	for (size_t i = 0; i < v.size(); i++)
		cout << "#" << i + 1 << ": " << v.at(i).first << endl;
}

// Metodo para mostrar os packs recomendados a cada cliente
void Agency::show_recommended_packs(){
	string place = "";
	int id = 0, idx = -1;
	bool found = false;
	vector<spe_pair> most_visited_places = get_most_visited_places();
	vector<string> client_places;
	for (Client client: this->clients){

		for (size_t i = 0; i < client.getBought_packets().size(); i++){
			for (size_t j = 0; j < this->packs.size(); j++){
				if (this->packs.at(j).getId() == client.getBought_packets().at(i))
					for (string place: this->packs.at(j).getPlaces())
						client_places.push_back(place);
			}
		}
		place = get_first_not_in(client_places, most_visited_places);
		cout << place << endl;
		if (place == "None")
			cout << client.getName() << ": Nenhuma recomendaçao disponivel" << endl;
		else {
			for (size_t i = 0; i < this->packs.size(); i++){
				for (size_t j = 0; j < this->packs.at(i).getPlaces().size(); j++){
					if (this->packs.at(i).getPlaces().at(j) == place){
						id = this->packs.at(i).getId();
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
			cout << client.getName() <<  ": Pack " << id << endl;
		}
		client_places.clear();
	}
}