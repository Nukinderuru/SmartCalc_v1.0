#include "mainwindow.h"

#include <QGridLayout>
#include <QToolButton>
#include <QtMath>

#include "ui_mainwindow.h"

extern "C" {
#include "smart_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  resize(200, 200);

  QWidget *widget = new QWidget(this);
  QGridLayout *mainLayout = new QGridLayout();
  widget->setLayout(mainLayout);
  setCentralWidget(widget);

  Button *calcButton = createButton("Calculator", SLOT(calcClicked()));
  Button *creditButton = createButton("Credit", SLOT(creditClicked()));
  Button *depositButton = createButton("Deposit", SLOT(depositClicked()));

  mainLayout->addWidget(calcButton, 0, 3, 1, 5);
  mainLayout->addWidget(creditButton, 2, 3, 1, 5);
  mainLayout->addWidget(depositButton, 3, 3, 1, 5);

  calcButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  creditButton->setStyleSheet(
      "QToolButton {color: #ACFF83; background: #232522;}");
  depositButton->setStyleSheet(
      "QToolButton {color: #ACFF83; background: #232522;}");

  setWindowTitle("Calculator");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::calcClicked() {
  i = new Interface();
  i->setStyleSheet("background-color:black;");
  i->show();
}

void MainWindow::creditClicked() {
  c = new Credit();
  c->setStyleSheet("background-color:black;");
  c->show();
}

void MainWindow::depositClicked() {
  d = new Deposit();
  d->setStyleSheet("background-color:black;");
  d->show();
}

Button *MainWindow::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}
