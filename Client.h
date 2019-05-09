
#pragma once

#include "Address.h"
#include "Pack.h"
#include <string>
#include <vector>


using namespace std;

class Client{
    public:
		Client(string name, string nif, unsigned short family_size, Address address);  // for a new client
		Client(string name, string nif, unsigned short family_size, Address address, vector<int> bought_packets, unsigned total_buys);  // client read from file

		// GET methods

		string getName() const;
		string getNif() const;
		unsigned short getFamily_size() const;
		Address getAddress() const;
		vector<int> getBought_packets() const;
		unsigned getTotal_buys() const;

		// SET methods

		void setName(string name);
		void setNif(string VATnumber);	// NEED TO CHANGE THIS
		void setFamily_size(unsigned short familySize);
		void setAddress(Address address);
		void setBought_packets(vector<int>& packets);
		unsigned setTotal_buys(unsigned totalPurchased);

		// other methods

		friend ostream& operator<<(ostream& out, const Client& client);

    private:
        string name;
        string nif;
        unsigned short family_size;
        Address address;
        vector<int> bought_packs;
        unsigned total_buys;
};