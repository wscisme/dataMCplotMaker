#ifndef MAKEPLOT_H
#define MAKEPLOT_H

#include "TROOT.h"
#include <string>

struct PlotInfo {
  TH1F* Plot;
  char* Title;
};

TStyle *tdrStyle = NULL;

void makePlot(TH1F* Data, std::vector <TH1F*> Backgrounds, std::vector <char*> Titles, char* title = "", char* title2 = "", std::string options_string = "", std::vector <Color_t> color_input = std::vector<Color_t>());



#endif