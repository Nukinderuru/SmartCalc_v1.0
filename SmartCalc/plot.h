#ifndef PLOT_H
#define PLOT_H

#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

extern "C" {
#include "smart_calc.h"
}

class Plot : public QWidget {
  Q_OBJECT

 public:
  Plot();

  double xBegin, xEnd;
  QVector<double> xG, yG;
  void print_graphic(char *input);

 private:
  QGridLayout *mainLayout;
  QCustomPlot *plot;
};

#endif  // PLOT_H
