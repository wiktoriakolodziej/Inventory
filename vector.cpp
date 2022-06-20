#include "vector.h"
#include "functions.h"

#include <fstream> //ofstream -> obs³uga plików
#include <conio.h> //_getch()
#include <cstdlib> //system("cls")
#include <string> //getline()

namespace Inventory {
	void  my_vector::create_new() {
		std::cout << "podaj nazwe obiektu: ";
		std::string name;

		std::getline(std::cin >> std::ws, name);
		system("cls");

		double price = set_price();

		int quantity = set_amount();
		std::string date = set_date();
		if (quantity != 0) {
			if (!date.empty()) {
				while (1) {
					try {
						complex_object p(name, price, date, quantity);
						inventory.push_back(new complex_object(p));

						save_in_file(&p);
						
						return;
					}
					catch (InvalidData) {
						std::cout << "podales zle parametry daty, sprobuj jeszcze raz: ";
						std::getline(std::cin >> std::ws, date);
						system("cls");
					}
				}
				
			}
			object p(name, price, quantity);
			inventory.push_back(new object(p));

			save_in_file(&p);
			return;
		}
		if (!date.empty()) {
			while (1) {
				try {

					complex_object p(name, price, date);
					inventory.push_back(new complex_object(p));

					save_in_file(&p);
					
					return;
				}
				catch (InvalidData) {
					std::cout << "podales zle parametry daty, sprobuj jeszcze raz: ";
					std::cin >> date;
					system("cls");
				}
			}
		}
		object p(name, price);
		inventory.push_back(new object(p));
		save_in_file(&p);
		return;
	}
	void my_vector::iterate_and_find() {
		std::string to_find;
		bool x = true;

		while (x) {
			std::string to_find;

			std::cout << "podaj co chcesz znalezc, lub wcisnij enter jezeli chcesz wyswietlic wszystko" << std::endl;
			char sign = _getch();
			while (sign != 13) {
				std::cout << sign;
				to_find.push_back(sign);
				sign = _getch();
			}
			std::cout << std::endl;

			if (to_find.empty()) {
				
				for (int i = 0; i < inventory.size(); i++) {
					inventory[i]->print();
					std::cout << std::endl;
				}
			}
			else{
		
				my_vector::show_objects(to_find);
			}
			std::cout << std::endl << "nacisnij escape aby wyjsc, lub dowolny inny przycisk by szukac dalej" << std::endl;
			if (_getch() == 27) {

				system("cls");
				x = false;
			}

		}

		return;
	}
	void my_vector::change_params() {
		bool x = true;
		std::string to_find;
		std::vector <int> contener;

		while (x) {

			
			std::cout << "podaj co chcesz znalezc: ";
			std::getline(std::cin >> std::ws, to_find);
			std::vector <int> contener = my_vector::show_objects(to_find);
			if(!contener.empty()) {
				int to_save_number = 0;
				if (contener.size() > 1) {
					std::cout << std::endl << "podaj kod lub pelna nazwe elementu ktory chcesz zmienic: ";
					std::string code;
					std::cin >> code;
					for (int i = 0; i < contener.size(); i++) {
						if (inventory[contener[i]]->find(code)) {
							to_save_number = i;
							break;
						}
					}
					system("cls");
					inventory[contener[to_save_number]]->print();
					std::cout << std::endl;
				}
				bool y = true;
				while (y) {


					std::cout << "podaj jaki parametr chcesz zmienic: 1 - nazwe, 2 - cene, 3 - ilosc";
					int choice;
					std::cin >> choice;
					switch (choice) {
					case 1: {
						system("cls");
						std::cout << "podaj nowa nazwe: ";
						std::string name;
						std::cin >> name;
						inventory[contener[to_save_number]]->change_name(name);
						break;
					}
					case 2: {
						system("cls");
						double price = set_price();
						inventory[contener[to_save_number]]->change_price(price);
						break;
					}
					case 3: {
						system("cls");
						int quantity = set_amount();
						inventory[contener[to_save_number]]->change_quantity(quantity);
						break;
					}
					default:
						system("cls");
						std::cout << "podales zly parametr, sprobuj jeszcze raz";
						continue;
					}
					std::cout << "jezeli chcesz zmienic wiecej elementow nacisnij enter, jezeli chcesz juz skonczyc nacisnij jakis inny przycisk";
					if (_getch() != 13)
						y = false;
					system("cls");
				}
			}




			std::cout << std::endl << "nacisnij escape aby wyjsc, lub dowolny inny przycisk by zmieniac inne elementy" << std::endl;
			if (_getch() == 27)
				x = false;
			system("cls");
		}
		return;
	}
	void my_vector::exportt() {
		
		bool x = true;


		while (x) {
			std::string to_find;
			std::cout << "podaj jaki element chcesz zapisac, lub wcisnij enter jezeli chcesz zapisac wszystko:  " << std::endl;
			char character = _getch();
			while (character != 13) {
				std::cout << character;
				to_find += character;
				character = _getch();
			}
			system("cls");
			std::vector <int> contener;
			
			

			if (!to_find.empty()) {
				contener = my_vector::show_objects(to_find);
				while (contener.empty()) {
					std::cout << std::endl << "podaj jaki element chcesz zapisac: ";
					std::cin >> to_find;
					system("cls");
					contener = my_vector::show_objects(to_find);
				}
					
			}


			
			std::string code;
			int to_save_number = 0;
			if (!contener.empty()) {
				
				


				if (contener.size() > 1) {
					std::cout << "wpisz kod przedmiotu ktory chcesz zapisac, lub wisnij enter zeby zapisac wszystkie przedmioty z listy" << std::endl;


					character = _getch();
					while (character != 13) {
						std::cout << character;
						code += character;
						character = _getch();
					}
					if (!code.empty()) {
						for (int i = 0; i < contener.size(); i++) {
							if (inventory[contener[i]]->find(code)) {
								to_save_number = i;
								break;
							}
						}
					}
					system("cls");
				}
			}
		
				
				std::cout << "podaj nazwe pliku do jakiego chcesz zapisac obiekt" << std::endl;
				std::string file_name;
				std::cin >> file_name;
				std::ofstream file;
				file.open(file_name, std::ios_base::app);
				if (file)
				{
					if (to_find.empty()) {
						std::cout << "wszystko zostalo pomyslnie zapisane" << std::endl;
						for (int i = 0; i < inventory.size(); i++)
							file << *inventory[i] << std::endl;
					}
					else if (contener.size() > 1) {
						for (int i = 0; i < contener.size(); i++)
							file << *inventory[contener[i]] << std::endl;
					}
					else
					{
						std::cout << "element " << inventory[contener[to_save_number]]->print_name() << " zostal zapisany" << std::endl;
						file << *inventory[contener[to_save_number]] << std::endl;
					}
					file.close();
				}
			
			
			std::cout << std::endl << "nacisnij escape aby wyjsc, lub dowolny inny przycisk by zapisac wiecej" << std::endl;
			if (_getch() == 27) {
				system("cls");
				x = false;
			}

		}
		return;
	}
	void my_vector::alerts() {
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory[i]->compare() != -1)
				std::cout << "do nastepnego serwisu " << inventory[i]->print_name() << " pozostalo: " << inventory[i]->compare() / 86400 << " dni " << std::endl;
		}
		std::cout << "nacisnij esc aby wyjsc";
		char esc = _getch();
		while (esc != 27)
			esc = _getch();
		system("cls");
		return;

	}
	std::vector <int>  my_vector::show_objects(std::string to_find) {
	

			std::vector <int> contener;
			
			
			int j = 0;
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i]->find(to_find) && j != 10) {

					inventory[i]->print();
					std::cout << std::endl;
					contener.push_back(i);
					j++;
				}
				else if (j == 10) {
					std::cout << std::endl << "nacisnij dowolny przycisk aby wyswietlic wiecej lub esc jezeli tego nie potrzebujesz";
					if (_getch() == 27)
						return contener;
					inventory[i]->print();
					std::cout << std::endl;
					contener.push_back(i);
					j = 1;

				}
			}
			if (j == 0) 
				std::cout << "niestety nie udalo sie znalezc takiego obiektu, upwenij sie ze na pewno go dodales";
			
			return contener;
	}
	void my_vector::delete_object() {
		std::cout << "podaj nazwe obiektu, ktory chcesz usunac: ";
		std::string to_find;
		std::getline(std::cin >> std::ws, to_find);
		std::vector <int> contener = my_vector::show_objects(to_find);
		if (contener.empty()) {
			system("cls");
			return;
		}
		if (contener.size() > 1) {
			std::string code;
			std::cout << "wybierz ktory element chcesz usunac, badz wcisnij enter aby usunac wszystkie: ";
			char character = _getch();
			while (character != 13) {
				std::cout << character;
				code += character;
				character = _getch();
			}
			if (!code.empty()) {
				for (int i = 0; i < contener.size(); i++) {
					if (inventory[contener[i]]->find(code)) {

						delete (inventory[contener[i]]);
						inventory.erase(inventory.begin() + contener[i]);
						break;
					}
				}
			}
			else {
				for (int i = 0; i < contener.size(); i++) {
					std::cout << "wszystko zostalo pomyslnie usuniete";
					delete (inventory[contener[i]]);
					inventory.erase(inventory.begin() + contener[i]);
				}
			}
		}
		else {
			std::cout << "element " << inventory[contener[0]]->print_name() << " zostal usuniety";
			delete (inventory[contener[0]]);
			inventory.erase(inventory.begin() + contener[0]);
		}
		std::cout << std::endl <<  "nacisniej esc zeby wyjsc";
		int sign = _getch();
		while (sign != 27)
			sign = _getch();
		system("cls");

			
		return;
	}
}
