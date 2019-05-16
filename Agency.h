#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "aux_funcs.h"
#include "Address.h"
#include "Client.h"
#include "Pack.h"

using namespace std;

typedef std::pair<string, int> spe_pair;

class Agency {
private:
	string name; 
	string nif; 
	Address address; 
	string URL; 
	vector<Client> clients;
	vector<Pack> packs;
	string clients_filename;
	string packs_filename;
	vector<spe_pair> get_most_visited_places();

public:
	Agency(string fileName);

	// methods GET
	string getName() const;
	string getNif() const;
	Address getAddress() const;
	string getURL() const;
	vector<Client> getClients() const;
	vector<Pack> getPackets() const;


	// methods SET
	void setName(string name);
	void setNif(string nif);
	void setAddress(Address address);
	void setURL(string url);
	void setClients(vector<Client>& clients);
	void setPackets(vector<Pack>& packets);

	// other methods
	friend ostream& operator<<(ostream& out, const Agency& agency);
	
	bool update_clients_file() const;
	bool update_packs_file() const;
	void create_client();
	void remove_client();
	void change_client();
	void create_pack();
	void change_pack();
	void show_specific_client() const;
	void show_all_clients() const;
	void show_all_packs() const;
	void show_all_packs_related_to_place() const;
	void show_packs_between_dates() const;
	void show_packs_between_dates_and_related_to_place() const;
	void show_packs_sold_to_client() const;
	void show_packs_sold_to_all_clients() const;
	void buy_pack();
	void show_sold_packs_info() const;
	void show_most_visited_places();
	void show_recommended_packs();
};