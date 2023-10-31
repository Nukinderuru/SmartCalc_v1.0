#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "button.h"
#include "credit.h"
#include "deposit.h"
#include "graphics.h"
#include "interface.h"

extern "C" {
#include "smart_calc.h"
}

#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void calcClicked();
  void creditClicked();
  void depositClicked();

 private:
  Ui::MainWindow *ui;

  Button *createButton(const QString &text, const char *member);

  Interface *i;
  Graphics *g;
  Credit *c;
  Deposit *d;
};

#endif  // MAINWINDOW_H
