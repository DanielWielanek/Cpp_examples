#ifndef CPP_EXAMPLES_7_WEKTOR_H_
#define CPP_EXAMPLES_7_WEKTOR_H_

class wektor {
  int rozmiar;
  double* dane;

public:
  wektor(int rozmiar = 1);
  wektor(const wektor& inny);
  void Ustaw(int indeks, double wartosc);
  void Dodaj(const wektor& inny);
  void Odejmij(const wektor& inny);
  void Drukuj() const;
  virtual ~wektor();
};

#endif /* 2025_P_CPP_EXAMPLES_7_WEKTOREK_H_ */
