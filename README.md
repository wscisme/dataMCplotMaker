dataMCplotMaker
===============

Function to quickly make nice data/MC plots.  In addition to formatting, it automatically makes an overflow bin for your data, automatically puts the smallest backgrounds on the bottom, and automatically chooses a reasonable maximum and minimum.  

To run:
  1.  Put both .cc and .h files in the same directory
  2.  "Include" the .h file (#include "path/dataMCplotMaker") in your file
  3.  In root, compile the .cc file (.L path/dataMCplotMaker.cc+) before loading and compiling your file.

To call the function:
  - dataMCplotMaker(TH1F* data, std::vector < TH1F* > Backgrounds, std::vector < char* > Titles*, char* title, char* Title2, std::string Options, std::vector < Color_t > colors)

Mandatory arguments:
  - data: a histogram of the data
  - backgrounds: a vector of histograms, each representing a background
  - titles: the name of each background, in the same order as the backgrounds vector
  - title: the title of the distribution
  - title2: the subtitle of the distribution

Optional arguments:
  - options: a string with any optional flags you want (see supported options below)
  - colors: a vector of kColors that you want to use instead of the defaults [ex: vector.push_back(kRed)]

Supported flags for "options" string:
  - --isLinear: to use linear instead of log on y-axis
  - --preserveBackgroundOrder: to keep the backgrounds in the order you specified, rather than putting the smallest backgrounds on the bottom
  - --noDivisionLabel: to remove the divisions label on the y-axis (ex: "Entries/30 GeV" becomes "Entries")
  - --noOverflow: do not make the last bin an overflow bin (important if your last bin is already an overflow bin)
  - --energy X: change the energy from its default of 8 TeV
  - --lumi X: change the lumi from its default of 19.5 fb-1.
  - --yAxisLabel X: change the y-axis label from its default of "Entries"
  - --yAxisUnit X: change the y-axis unit from its default of ""
  - --yAxisOverride X: replace the entire y-axis label with the X
  - --xAxisLabel X: change the x-axis label from its default of "Entries"
  - --noXaxisUnit: do not display a unit for the x-axis
  - --xAxisUnit X: change the x-axis unit from its default of ""
  - --xAxisOverride X: override the entire x-axis label to the user-defined value
  - --dataName X: replace the name for "data" in the legend with the user-defined value
  - --topYaxisTitle X: change the y-axis label in the top histogram from its default of "data/SM"
  - --type X: change the top-left label from its default of "CMS Preliminary"
  - --overrideHeader X: override the entire top line to the user-defined value
  - --outputName X: change the name of the pdf file produced from its default of "data_MC_plot"
  - --vLine X: insert a vectical line where the x-axis = X
  - --setMaximum X: change the y-axis maximum from its default value (originally chosen such that the top of the top-most error bar appears at 3/4 of the histogram's height)
  - --setMinimum X: change the y-axis minimum from its default value (originally chosen to be 90% of the smallest bin's height on the bottom background)
  - --legendUp X: move the legend up by X (number from 0 to 1; you probably want around 0.05), negative numbers to move it down
  - --legendRight X: move the legend to the right by X (number from 0 to 1; you probably want around 0.05), negative numbers to move it to the left
  - --legendTextSize X: change the legend text size from its default value of 0.04
  - --divHalf: reduce the number of x-axis divisions by half
  - --nDivisions X: change the number of x-axis divisions to X, where X = number of primary divisions + 100*number of secondary divisions + 10000*number of tertiary divisions; positive to allow it to optimize (strongly recommended), negative to require it to use your values

Example:
  - std::vector < TH1F* > myVector;
  - myVector.push_back(CR1_ttsl);
  - myVector.push_back(CR1_ttdl);
  - std::vector < char* > myTitles;
  - myTitles.push_back("ttsl");
  - myTitles.push_back("ttdl");
  - dataMCplotMaker(CR1_data, myVector, myTitles, "#tilde{t} #rightarrow t#tilde{#chi} _ {1}^{0} ISR", "CR-0b", "--vLine 120 --outputName test _ plot");

E-mail Alex with bug reports or feature requests, george AT physics DOT ucsb
