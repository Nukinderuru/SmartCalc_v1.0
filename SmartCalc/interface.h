#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>
#include <QWidget>

#include "button.h"
#include "graphics.h"

extern "C" {
#include "smart_calc.h"
}

class Interface : public QWidget {
  Q_OBJECT

 public:
  Interface();

 private slots:
  void numberClicked();
  void xClicked();
  void operandClicked();
  void functionClicked();
  void equalClicked();
  void pointClicked();
  void backspaceClicked();
  void clearClicked();
  void clearAllClicked();
  void printClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  void abortOperation();

  QLineEdit *m_display_up;
  QLineEdit *m_display_down;
  QLabel *m_sign;

  bool check_and_calculate(QString input, long double);

  QString m_squareRoot_sign = QChar(0x221A);
  QString m_power_sign = 'x' + QChar(0x000002b8);

  QString m_backspace_sign = QChar(0x2190);

  QString m_division_sign = QChar(0x000000F7);
  QString m_times_sign = QChar(0x000000D7);
  QString m_plus_sign = "+";
  QString m_minus_sign = "-";

  static const int NumButtons = 10;
  Button *m_numberButtons[10];

  int xDisplay = 0;
  int answer_shown = 0;
  QString input = "";

  long double x;

  Graphics *g;

  double xBegin, xEnd, step, temp;
  int N;
};

#endif  // INTERFACE_H
