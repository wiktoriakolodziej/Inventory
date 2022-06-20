#include "functions.h"
#include "complex_object.h"
#include "date.h"

#include <iostream>
#include <conio.h> //_getch()
#include <math.h> //pow()
#include <cstdlib> //system("cls")
#include <fstream> //ofstream -> obs³uga plików



using namespace Inventory;
void info() {
	std::cout << "1 - dodaj nowy element" << std::endl << "2 - eksportuj" << std::endl << "3 - zmien parametry" << std::endl;
	std::cout << "4 - wyszukaj obiekt " << std::endl << "5 - pokaz liste alertow" << std::endl << "6 - usun" << std::endl;
	std::cout  << "q - zakoncz program" << std::endl;
}
double set_price() {
	std::cout << "podaj cene za 1 sztuke: ";
	std::vector<char> contener;
	char sign = _getch();
	while (sign != 13) {
		std::cout << sign;
		if (sign > 57 || sign < 48) {
			system("cls");
			std::cout << "podales bledna wartosc ceny, sprobuj jeszcze raz" << std::endl;

			std::cout << "podaj cene za 1 sztuke: ";
			contener.clear();
			sign = _getch();
			system("cls");
			continue;
		}

		contener.push_back(sign);
		if (contener[0] == '0') {
			system("cls");
			std::cout << "podales bledna wartosc ceny, sprobuj jeszcze raz" << std::endl;
			contener.clear();
		}
		sign = _getch();
	}

	double price = 0;
	for (int i = contener.size() - 1; i >= 0; i--) {
		price += pow(10, contener.size() - 1 - i) * (contener[i] - 48);
	}
	system("cls");
	return price;
}
int set_amount() {
	std::cout << "podaj ilosc(wcisnij enter zeby pominac): ";
	std::vector<char> contener;
	char sign = _getch();
	while (sign != 13) {
		std::cout << sign;
		if (sign > 57 || sign < 48) {
			system("cls");
			std::cout << "podales bledna wartosc ilosci, sprobuj jeszcze raz" << std::endl;

			std::cout << "podaj ilosc(wcisnij enter zeby pominac): ";
			contener.clear();
			sign = _getch();
			system("cls");
			continue;
		}

		contener.push_back(sign);
		sign = _getch();
	}
	int quantity = 0;
	for (int i = contener.size() - 1; i >= 0; i--) {
		quantity += pow(10, contener.size() - 1 - i) * (contener[i] - 48);
	}
	system("cls");
	return quantity;
}
std::string set_date() {
	std::cout << "jezeli chcesz podac date wpisz ja oddzielajac pozycje spacja albo kropka, jezeli nie chcesz dodawac daty wcisnij enter " << std::endl;
	std::string date;
	char character = _getch();
	while (character != 13) {
		std::cout << character;
		date.push_back(character);
		character = _getch();
	}
	system("cls");
	return date;
}
void save_in_file(object* p) {
	std::ofstream file;
	file.open("inventory", std::ios_base::app);
	if (file) {
		file << *p << std::endl;
		file.close();
	}
}

