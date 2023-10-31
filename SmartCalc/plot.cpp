#include "plot.h"

Plot::Plot() {
  resize(500, 500);
  mainLayout = new QGridLayout();
  plot = new QCustomPlot();
  mainLayout->addWidget(plot, 0, 0, 5, 1);
  setLayout(mainLayout);
  setWindowTitle("Plot");
}

void Plot::print_graphic(char *input) {
  stack_t *parced_input = parce_input(input);
  stack_t *output = make_reverse_polish_notation(&parced_input);
  double xVal, yMin = 0.0, yMax = 0.0;
  long double yVal = 0.0;
  for (xVal = xBegin; xVal < xEnd; xVal += 0.01) {
    int status = calculate(&output, xVal, &yVal);
    if (!status && !std::isnan(yVal)) {
      if (yVal < yMin) yMin = yVal;
      if (yVal > yMax) yMax = yVal;
      xG.push_back(xVal);
      yG.push_back((double)yVal);
    }
  }
  plot->xAxis->setRange(xBegin, xEnd);
  plot->yAxis->setRange(yMin, yMax);
  plot->addGraph();
  plot->graph(0)->addData(xG, yG);
  plot->replot();
}
