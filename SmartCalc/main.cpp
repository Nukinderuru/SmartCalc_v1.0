#include "interface.h"
#include "mainwindow.h"
extern "C" {
#include "smart_calc.h"
}

#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow w;
  w.setStyleSheet("background-color:black;");
  w.show();
  return app.exec();
}
