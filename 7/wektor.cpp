/*
 * wektor.cpp
 *
 *  Created on: 18 lis 2025
 *      Author: daniel
 */

#include "wektor.h"

#include <iostream>

wektor::wektor(int rozmiar) : rozmiar(0), dane(nullptr) {
  if (rozmiar > 0) {
    dane          = new double[rozmiar];
    this->rozmiar = rozmiar;
    for (int i = 0; i < rozmiar; i++) {
      dane[i] = 0;
    }
  }
}

wektor::wektor(const wektor& inny) : rozmiar(0), dane(nullptr) {
  if (inny.rozmiar == 0) return;
  rozmiar = inny.rozmiar;
  dane    = new double[rozmiar];
  for (int i = 0; i < rozmiar; i++)
    dane[i] = inny.dane[i];
}

void wektor::Dodaj(const wektor& inny) {
  if (inny.rozmiar != rozmiar) {
    std::cout << "Nie mozna dodac" << std::endl;
    return;
  }
  for (int i = 0; i < rozmiar; i++)
    dane[i] = dane[i] + inny.dane[i];
}

void wektor::Odejmij(const wektor& inny) {
  if (inny.rozmiar != rozmiar) {
    std::cout << "Nie mozna dodac" << std::endl;
    return;
  }
  for (int i = 0; i < rozmiar; i++)
    dane[i] = dane[i] - inny.dane[i];
}

void wektor::Drukuj() const {
  for (int i = 0; i < rozmiar; i++) {
    std::cout << dane[i] << " ";
  }
  std::cout << std::endl;
}

void wektor::Ustaw(int indeks, double wartosc) {
  if (indeks < 0) return;
  if (indeks >= rozmiar) return;
  dane[indeks] = wartosc;
}

wektor::~wektor() {
  if (dane) delete[] dane;
}
