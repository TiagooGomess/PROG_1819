#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "aux_funcs.h"
#include "Address.h"
#include "Client.h"
#include "Pack.h"

using namespace std;

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
	void show_specific_client();
	void show_all_clients();
	void show_all_packs();
	void show_all_packs_related_to_place();
};