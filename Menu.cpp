#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "aux_funcs.h"
#include "Menu.h"

using namespace std;

void main_menu(Agency agency);


// Menu de gestão de clientes
void client_management(Agency agency) {
	int option, var;
	while(true){
		cout << "\n\n[1]: Adicionar cliente\n";
		cout << "[2]: Modificar cliente\n";
		cout << "[3]: Remover cliente\n\n";
		cout << "[0]: Menu principal\n\n";
		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Insira um numero [0-3] para escolher uma opcao: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (cin.fail() || option < 0 || option > 3);

		cout << "\n\n";
		cout << "-----------------------------------------------------\n";
		if (option == 0) {
			break;
		}
		else if (option == 1) {
			agency.create_client();
			agency.update_clients_file();
			cout << "Pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 2) {
			agency.change_client();
			agency.update_clients_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 3) {
			agency.remove_client();
			agency.update_clients_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "\n\n";
	}
}

// Menu de gestao de packs
void packs_management(Agency agency) {
	int option, var;
	while(true){
		cout << "\n\n[1]: Adicionar pacote\n";
		cout << "[2]: Modificar pacote\n";
		cout << "[3]: Remover pacote\n";
		cout << "[4]: Comprar pacote para um cliente\n\n";
		cout << "[0]: Menu principal\n\n";
		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Insira um numero [0-4] para escolher uma opcao: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (cin.fail() || option < 0 || option > 4);

		cout << "\n\n";
		cout << "-----------------------------------------------------\n";
		if (option == 0) {
			break;
		}
		else if (option == 1) {
			agency.create_pack();
			agency.update_packs_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 2) {
			agency.change_pack();
			agency.update_packs_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 3) {
			agency.remove_pack();
			agency.update_packs_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 4) {
			agency.buy_pack();
			agency.update_packs_file();
			agency.update_clients_file();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "\n\n";
	}
}

// Menu de visualizaçao de informaçao
void information_visualization(Agency agency) {
	int option, var;
	while(true){
		cout << "\n\n[1]: Mostrar um cliente\n";
		cout << "[2]: Mostrar todos os clientes\n\n";
		cout << "[3]: Mostrar todos os pacotes\n";
		cout << "[4]: Mostrar todos os pacotes entre duas datas especificas\n";
		cout << "[5]: Mostrar todos os pacotes relativos a um destino especifico\n";
		cout << "[6]: Mostrar todos os pacotes entre duas datas especificas e relativos a um destino especifico\n\n";
		cout << "[7]: Mostrar todos os pacotes vendidos a todos os clientes\n";
		cout << "[8]: Mostrar o numero e o valor total dos pacotes vendidos\n\n";

		cout << "[0]: Menu principal\n\n";
		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Insira um numero [0-8] para escolher uma opcao: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (cin.fail() || option < 0 || option > 8);

		cout << "\n\n";
		cout << "-----------------------------------------------------\n";
		if (option == 0) {
			break;
		}
		else if (option == 1) {
			agency.show_specific_client();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 2) {
			agency.show_all_clients();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 3) {
			agency.show_all_packs();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 4) {
			agency.show_packs_between_dates();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 5) {
			agency.show_all_packs_related_to_place();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 6) {
			agency.show_packs_between_dates_and_related_to_place();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 7) {
			agency.show_packs_sold_to_all_clients();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 8) {
			agency.show_sold_packs_info();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "\n\n";
		cout << "-----------------------------------------------------\n";
	}
}

// Menu de dados estatisticos
void estatisticas(Agency agency) {
	int option, var;
	while(true){
		cout << "\n\n[1]: Obter o nome dos N locais mais visitados\n";
		cout << "[2]: Mostrar pack recomendado para cada cliente\n";
		cout << "[0]: Menu principal\n\n";
		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Insira um numero [0-2] para escolher uma opcao: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (cin.fail() || option < 0 || option > 4);

		cout << "\n\n";
		cout << "-----------------------------------------------------\n";
		if (option == 0) {
			break;
		}
		else if (option == 1) {
			agency.show_most_visited_places();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (option == 2) {
			agency.show_recommended_packs();
			cout << "pressione ctrl-Z para voltar ao menu" << endl;
			cin >> var;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "\n\n";
	}
}

// Menu Principal
void main_menu(Agency agency) {
	int option;
	while(true){
		cout << "NiceHolidays\n\n";
		cout << "---------------MENU PRINCIPAL---------------\n\n";
		cout << "[1]: Gestao de clientes\n";
		cout << "[2]: Gestao de pacotes\n";
		cout << "[3]: Visualizacao de informacao\n";
		cout << "[4]: Dados estatisticos\n\n";
		cout << "[0]: Sair\n\n";

		do {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Insira um numero [0-4] para escolher uma opcao: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (cin.fail() || option < 0 || option > 4);

		cout << "-----------------------------------------------------\n";

		if (option == 0) {
			cout << "\n\n\n";
			break;
		}
		if (option == 1) {
			client_management(agency);
		}
		else if (option == 2) {
			packs_management(agency);
		}
		else if (option == 3) {
			information_visualization(agency);
		}
		else if (option == 4) {
			estatisticas(agency);
		}
	}
}