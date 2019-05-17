#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "aux_funcs.h"
#include "Menu.h"

using namespace std;

void main_menu(Agency agency);

void client_management(Agency agency) {
	int option;
	cout << "\n\n[1]: Adicionar cliente\n";
	cout << "[2]: Modificar cliente\n";
	cout << "[3]: Remover cliente\n\n";
	cout << "[0]: Menu principal\n\n";
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Insira um numero [0-3] para escolher uma op��o: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (cin.fail() || option < 0 || option > 3);

	cout << "\n\n";
	cout << "-----------------------------------------------------\n";
	if (option == 0) {
		main_menu(agency);
	}
	else if (option == 1) {
		agency.create_client();
		agency.update_clients_file();
	}
	else if (option == 2) {
		agency.change_client();
		agency.update_clients_file();
	}
	else if (option == 3) {
		agency.remove_client();
		agency.update_clients_file();
	}
	cout << "\n\n";
	client_management(agency);
}


void packs_management(Agency agency) {
	int option;
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
		cout << "Insira um numero [0-4] para escolher uma op��o: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (cin.fail() || option < 0 || option > 4);

	cout << "\n\n";
	cout << "-----------------------------------------------------\n";
	if (option == 0) {
		main_menu(agency);
	}
	else if (option == 1) {
		agency.create_pack();
		agency.update_packs_file();
	}
	else if (option == 2) {
		agency.change_pack();
		agency.update_packs_file();
	}
	//else if (option == 3) {
		// agency.remove_pack();   We need to implement this method!!
		// agency.update_packs_file();
	//}
	//else if (option == 4) {
		// agency.buy_pack();  We need to implement this method!!
		//agency.update_packs_file();
	//}
	cout << "\n\n";
	packs_management(agency);
}


//void information_visualization() {
//	int option;
//	cout << "\n\n[1]: Mostrar um cliente\n";
//	cout << "[2]: Mostrar todos os clientes\n\n";
//	cout << "[3]: Mostrar um pacote\n";
//	cout << "[4]: Mostrar todos os pacotes\n";
//	cout << "[5]: Mostrar todos os pacotes entre duas datas especificas\n";
//	cout << "[6]: Mostrar todos os pacotes relativos a um destino especifico\n";
//	cout << "[7]: Mostrar todos os pacotes entre duas datas especificas e relativos a um destino especifico\n\n";
//	cout << "[8]: Mostrar todos os pacotes vendidos a todos os clientes\n";
//	cout << "[9]: Mostrar o numero e o valor total dos pacotes vendidos\n\n";
//
//	cout << "[0]: Menu principal\n\n";
//	do {
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(1000, '\n');
//		}
//		cout << "Insira um numero [0-9] para escolher uma op��o: ";
//		cin >> option;
//		cin.clear();
//		cin.ignore(1000, '\n');
//	} while (cin.fail() || option < 0 || option > 9);
//
//	cout << "\n\n";
//	cout << "-----------------------------------------------------\n";
//	if (option == 0) {
//		main_menu();
//	}
//	else if (option == 1) {
//		show_client();
//	}
//	else if (option == 2) {
//		show_all_clients();
//	}
//	else if (option == 3) {
//		show_pack();
//	}
//	else if (option == 4) {
//		show_all_packs();
//	}
//	else if (option == 5) {
//		show_packs_between_2_dates();
//	}
//	else if (option == 6) {
//		show_packs_for_specific_destination();
//	}
//	else if (option == 7) {
//		show_packs_between_2_dates_for_specific_destination();
//	}
//	else if (option == 8) {
//		show_all_sold_packs();
//	}
//	else if (option == 9) {
//		show_number_and_total_value_of_sold_packs();
//	}
//	cout << "\n\n";
//	cout << "-----------------------------------------------------\n";
//	information_visualization();
//}

void estatisticas(Agency agency) {
	int option;
	cout << "\n\n[1]: Obter o nome dos N locais mais visitados\n";
	cout << "[2]: listagem de todos os clientes na qual se indica, para cada cliente, um dos pacotes em que seja visitado um dos N locais mais visitados que ele ainda n�o visitou\n";
	cout << "[0]: Menu principal\n\n";
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Insira um numero [0-2] para escolher uma op��o: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
	} while (cin.fail() || option < 0 || option > 4);

	cout << "\n\n";
	cout << "-----------------------------------------------------\n";
	if (option == 0) {
		main_menu(agency);
	}
	//else if (option == 1) {
	//	// Implementar
	//}
	//else if (option == 2) {
	//	// Implementar
	//}
	cout << "\n\n";
	packs_management(agency);
}


void main_menu(Agency agency) {
	int option;
	cout << "NiceHolidays\n\n";
	cout << "---------------MENU PRINCIPAL---------------\n\n";
	cout << "[1]: Gestao de clientes\n";
	cout << "[2]: Gestao de pacotes\n";
	cout << "[3]: Visualizacao de informacao\n\n";
	cout << "[0]: Sair\n\n";

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Insira um numero [0-3] para escolher uma op��o: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');

	} while (cin.fail() || option < 0 || option > 3);

	cout << "-----------------------------------------------------\n";

	if (option == 0) {
		cout << "\n\n\n";
		system("pause");
	}
	if (option == 1) {
		client_management(agency);
	}
	else if (option == 2) {
		packs_management(agency);
	}
	/*else if (option == 3) {
		information_visualization(agency);
	}*/
}