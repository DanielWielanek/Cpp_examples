/*
 * test.C
 *
 *  Created on: 7 sty 2026
 *      Author: daniel
 */

#include <Rtypes.h>
#include <RtypesCore.h>
#include <TAttLine.h>
#include <TAttMarker.h>
#include <TAxis.h>
#include <TH1.h>
#include <TMath.h>
#include <iostream>
#include <vector>

const Int_t N = 10;

void setup(TH1D* h, Color_t c, Bool_t open) {
  if (open)
    h->SetMarkerStyle(kOpenCircle);
  else
    h->SetMarkerStyle(kFullCircle);
  h->SetLineColor(c);
  h->SetMarkerColor(c);
}
void test() {
  int n;
  std::vector<int> nterms;
  std::vector<double> cosines;
  std::vector<double> sines;
  std::ifstream file("data.txt");
  double a, b;
  while (file >> n >> a >> b) {
    nterms.push_back(n);
    sines.push_back(a);
    cosines.push_back(b);
  }
  n = nterms.size();

  TH1D* sineTerms   = new TH1D("sines", "sines", n, -0.5, double(n) - 0.5);
  TH1D* cosineTerms = new TH1D("sines", "sines", n, -0.5, double(n) - 0.5);
  setup(sineTerms, kGreen, false);
  setup(cosineTerms, kRed, false);


  TH1D** h = new TH1D*[n * 2 + 1];
  int bins = 500;
  for (int i = 0; i < n; i++) {
    h[i * 2]     = new TH1D("sine", "sine", bins, 0, 1);
    h[i * 2 + 1] = new TH1D("cosine", "cosine", bins, 0, 1);
    setup(h[i * 2], kGreen, false);
    setup(h[i * 2 + 1], kRed, false);
    sineTerms->SetBinContent(i + 1, sines[i]);
    cosineTerms->SetBinContent(i + 1, cosines[i]);
  }
  h[n * 2] = new TH1D("total", "total", bins, 0, 1);
  setup(h[n * 2], kBlue, false);
  for (int i = 0; i <= bins; i++) {
    double x   = h[n * 2]->GetXaxis()->GetBinCenter(i);
    double sum = 0;
    for (int j = 0; j < n; j++) {
      h[j * 2]->SetBinContent(i, sines[j] * TMath::Sin(2.0 * TMath::Pi() * x * j));
      h[j * 2 + 1]->SetBinContent(i, cosines[j] * TMath::Cos(2.0 * TMath::Pi() * x * j));
      sum += h[j * 2]->GetBinContent(i) + h[j * 2 + 1]->GetBinContent(i);
    }
    h[n * 2]->SetBinContent(i, sum);
  }
  h[n * 2]->SetMinimum(-1.1);
  h[n * 2]->SetMaximum(1.1);
  TCanvas* c = new TCanvas();
  c->Divide(2, 1);
  c->cd(1);
  h[n * 2]->Draw();
  for (int j = 0; j < n; j++) {
    h[j * 2]->Draw("same");
    h[j * 2 + 1]->Draw("SAME");
  }
  c->cd(2);
  sineTerms->SetMinimum(-1);
  sineTerms->SetMaximum(1);
  sineTerms->Draw();
  cosineTerms->Draw("SAME");
}
