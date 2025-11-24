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

double wektor::Zwroc(int pos) const {
  if (pos >= 0 && pos < rozmiar) return dane[pos];
  return 0;
}

wektor& wektor::operator=(const wektor& b) {
  if (this == &b) return *this;
  if (dane) delete[] dane;
  dane    = nullptr;
  rozmiar = b.rozmiar;
  if (rozmiar > 0) {
    dane = new double[rozmiar];
    for (int i = 0; i < rozmiar; i++)
      dane[i] = b.dane[i];
  }
  return *this;
}


wektor operator+(const wektor& a, const wektor& b) {
  if (a.rozmiar != b.rozmiar) { return a; }
  wektor wynik(a.rozmiar);
  for (int i = 0; i < a.rozmiar; ++i) {
    wynik.Ustaw(i, a.Zwroc(i) + b.Zwroc(i));
  }
  return wynik;
}
