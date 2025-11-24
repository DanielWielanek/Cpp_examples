#ifndef CPP_EXAMPLES_7_WEKTOR_H_
#define CPP_EXAMPLES_7_WEKTOR_H_

#include <iostream>
class wektor {
  int rozmiar;
  double* dane;

public:
  wektor(int rozmiar = 1);
  wektor(const wektor& inny);
  void Drukuj() const;
  void Ustaw(int indeks, double wartosc);
  double Zwroc(int pos) const;
  wektor& operator=(const wektor& b);
  virtual ~wektor();
  friend wektor operator+(const wektor& a, const wektor& b);
};


#endif /* 2025_P_CPP_EXAMPLES_7_WEKTOREK_H_ */
