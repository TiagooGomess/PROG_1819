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

	bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
	bool packetsInfoHasChanged; // flag that is set to "true" if at least one packet has been changed/added/deleted
	unsigned int maxClientsId; // maximum value among all clients identifiers
	unsigned int maxPacketsId; // maximum value among all packets identifiers

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

};