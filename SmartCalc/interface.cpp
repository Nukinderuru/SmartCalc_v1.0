#include "interface.h"

#include <QGridLayout>
#include <QToolButton>
#include <QtMath>

#include "graphics.h"
#include "qcustomplot.h"

extern "C" {
#include "smart_calc.h"
}

Interface::Interface() {
  m_display_up = new QLineEdit();
  m_display_down = new QLineEdit();
  m_sign = new QLabel();
  QGridLayout *mainLayout = new QGridLayout();

  m_display_down->setText("0");
  m_sign->setAlignment(Qt::AlignRight);

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);
  m_display_up->setReadOnly(true);
  m_display_down->setReadOnly(true);

  m_display_up->setAlignment(Qt::AlignRight);
  m_display_down->setAlignment(Qt::AlignRight);

  m_display_up->setMaxLength(255);
  m_display_down->setMaxLength(255);

  QFont font = m_display_up->font();
  font.setPointSize(font.pointSize() + 5);
  m_display_up->setFont(font);
  m_display_down->setFont(font);
  m_sign->setFont(font);

  m_display_up->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_display_down->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_sign->setStyleSheet("QLabel {color: #ACFF83;}");

  for (int i = 0; i < NumButtons; ++i)
    m_numberButtons[i] =
        createButton(QString::number(i), SLOT(numberClicked()));

  Button *printGraphic = createButton("Print", SLOT(printClicked()));

  Button *clearButton = createButton("Clear", SLOT(clearClicked()));
  Button *clearAllButton = createButton("AC", SLOT(clearAllClicked()));

  Button *pointButton = createButton(".", SLOT(pointClicked()));
  Button *backspaceButton =
      createButton(m_backspace_sign, SLOT(backspaceClicked()));
  Button *equalButton = createButton("=", SLOT(equalClicked()));
  Button *openingBracketButton = createButton("(", SLOT(operandClicked()));
  Button *closingBracketButton = createButton(")", SLOT(operandClicked()));

  Button *plusButton = createButton(m_plus_sign, SLOT(operandClicked()));
  Button *minusButton = createButton(m_minus_sign, SLOT(operandClicked()));
  Button *timesButton = createButton(m_times_sign, SLOT(operandClicked()));
  Button *divisionButton =
      createButton(m_division_sign, SLOT(operandClicked()));
  Button *modButton = createButton("%", SLOT(operandClicked()));

  Button *squareRootButton =
      createButton(m_squareRoot_sign, SLOT(operandClicked()));
  Button *powerButton = createButton(m_power_sign, SLOT(operandClicked()));

  plusButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  minusButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  timesButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  divisionButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  modButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  squareRootButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  powerButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  equalButton->setStyleSheet(
      "QToolButton {color: #FFFFFF; background: #CD730D; border-radius: "
      "28px;}");

  Button *logButton = createButton("log", SLOT(functionClicked()));
  Button *lnButton = createButton("ln", SLOT(functionClicked()));
  Button *cosButton = createButton("cos", SLOT(functionClicked()));
  Button *acosButton = createButton("acos", SLOT(functionClicked()));
  Button *sinButton = createButton("sin", SLOT(functionClicked()));
  Button *asinButton = createButton("asin", SLOT(functionClicked()));
  Button *tanButton = createButton("tan", SLOT(functionClicked()));
  Button *atanButton = createButton("atan", SLOT(functionClicked()));

  Button *xButton = createButton("x", SLOT(xClicked()));

  mainLayout->addWidget(m_display_up, 0, 0, 1, 6);
  mainLayout->addWidget(m_sign, 1, 5, 1, 1);
  mainLayout->addWidget(m_display_down, 2, 0, 1, 6);

  mainLayout->addWidget(printGraphic, 3, 0, 1, 1);
  mainLayout->addWidget(backspaceButton, 3, 3, 1, 1);
  mainLayout->addWidget(clearButton, 3, 4, 1, 1);
  mainLayout->addWidget(clearAllButton, 3, 5, 1, 1);

  mainLayout->addWidget(sinButton, 4, 0);
  mainLayout->addWidget(asinButton, 4, 1);
  mainLayout->addWidget(squareRootButton, 4, 2);
  mainLayout->addWidget(powerButton, 4, 3);
  mainLayout->addWidget(modButton, 4, 4);
  mainLayout->addWidget(divisionButton, 4, 5);

  mainLayout->addWidget(cosButton, 5, 0, 1, 1);
  mainLayout->addWidget(acosButton, 5, 1, 1, 1);
  mainLayout->addWidget(m_numberButtons[1], 5, 2, 1, 1);
  mainLayout->addWidget(m_numberButtons[2], 5, 3, 1, 1);
  mainLayout->addWidget(m_numberButtons[3], 5, 4, 1, 1);
  mainLayout->addWidget(timesButton, 5, 5, 1, 1);

  mainLayout->addWidget(tanButton, 6, 0, 1, 1);
  mainLayout->addWidget(atanButton, 6, 1, 1, 1);
  mainLayout->addWidget(m_numberButtons[4], 6, 2, 1, 1);
  mainLayout->addWidget(m_numberButtons[5], 6, 3, 1, 1);
  mainLayout->addWidget(m_numberButtons[6], 6, 4, 1, 1);
  mainLayout->addWidget(minusButton, 6, 5, 1, 1);

  mainLayout->addWidget(logButton, 7, 0, 1, 1);
  mainLayout->addWidget(lnButton, 7, 1, 1, 1);
  mainLayout->addWidget(m_numberButtons[7], 7, 2, 1, 1);
  mainLayout->addWidget(m_numberButtons[8], 7, 3, 1, 1);
  mainLayout->addWidget(m_numberButtons[9], 7, 4, 1, 1);
  mainLayout->addWidget(plusButton, 7, 5, 1, 1);

  mainLayout->addWidget(openingBracketButton, 8, 0, 1, 1);
  mainLayout->addWidget(closingBracketButton, 8, 1, 1, 1);
  mainLayout->addWidget(pointButton, 8, 2, 1, 1);
  mainLayout->addWidget(m_numberButtons[0], 8, 3, 1, 1);
  mainLayout->addWidget(xButton, 8, 4, 1, 1);
  mainLayout->addWidget(equalButton, 8, 5, 1, 1);

  setLayout(mainLayout);

  setWindowTitle("Calculator");
}

Button *Interface::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}

void Interface::numberClicked() {
  Button *btn = (Button *)sender();
  int number = btn->text().toInt();

  if (answer_shown) {
    m_display_up->clear();
    m_display_down->clear();
    answer_shown = 0;
  }

  if (xDisplay == 2) {
    m_display_down->clear();
    m_display_down->setText(QString::number(number));
    xDisplay = 3;
  } else if (xDisplay == 3) {
    m_display_down->setText(m_display_down->text() + QString::number(number));
  } else {
    if (m_display_down->text() == "0") {
      m_display_down->clear();
      m_display_up->clear();
    }
    m_display_down->setText(m_display_down->text() + QString::number(number));
  }
}

void Interface::xClicked() {
  xDisplay = 1;
  if (m_display_down->text() == "0") {
    m_display_down->clear();
    m_display_up->clear();
  }
  m_display_down->setText(m_display_down->text() + "x");
}

void Interface::operandClicked() {
  Button *btn = (Button *)sender();
  QString operation = btn->text();

  if (answer_shown) {
    m_display_up->clear();
    m_display_down->clear();
    answer_shown = 0;
  }

  if (operation == m_power_sign) operation = "^";
  if (operation == m_times_sign) operation = "*";
  if (operation == m_division_sign) operation = "/";
  if (operation == m_squareRoot_sign) operation = "sqrt(";
  if (operation == "%") operation = "mod";

  m_sign->setText(operation);

  QString text = m_display_up->text() + m_display_down->text();
  if (m_display_down->text() == "0") {
    text = operation;
  }
  if ((text.endsWith("+") || text.endsWith("-") || text.endsWith("*") ||
       text.endsWith("%") || text.endsWith("/") || text.endsWith("^")) &&
      (operation == "+" || operation == "-" || operation == "*" ||
       operation == "/" || operation == "^" || operation == "%")) {
    text.chop(1);
    m_display_up->setText(text);
  }

  if (m_display_down->text() == "0")
    m_display_up->setText(operation);
  else
    m_display_up->setText(m_display_up->text() + m_display_down->text() +
                          operation);

  if (operation == ')') m_sign->clear();

  m_display_down->clear();
}

void Interface::functionClicked() {
  Button *btn = (Button *)sender();
  QString operation = btn->text() + '(';

  if (answer_shown) {
    m_display_up->clear();
    m_display_down->clear();
    answer_shown = 0;
  }

  QString whole_expression =
      m_display_up->text() + m_display_down->text() + operation;
  if (whole_expression[0] == "0")
    m_display_up->setText(operation);
  else
    m_display_up->setText(m_display_up->text() + m_display_down->text() +
                          operation);
  m_display_down->clear();
}

void Interface::equalClicked() {
  setlocale(LC_NUMERIC, "C");
  QString input = "";
  if (xDisplay == 1) {
    m_display_up->setText(m_display_up->text() + m_display_down->text());
    xDisplay = 2;
    m_sign->clear();
    m_display_down->setText("Now enter the value of x:");
  } else if (xDisplay == 3) {
    xDisplay = 0;
    double temp = m_display_down->text().toDouble();
    x = (long double)temp;
    m_display_down->clear();
    input = m_display_up->text() + m_display_down->text();
    check_and_calculate(input, x);
  } else {
    input = m_display_up->text() + m_display_down->text();
    m_display_up->setText(input);
    m_display_down->clear();
    check_and_calculate(input, 0.0);
  }
  m_sign->setText("=");
}

void Interface::pointClicked() {
  if (!m_display_down->text().contains('.')) {
    m_display_down->setText(m_display_down->text() + '.');
  }
}

void Interface::backspaceClicked() {
  QString text = m_display_down->text();
  text.chop(1);

  if (text.isEmpty()) {
    text = "0";
    m_sign->clear();
  }

  m_display_down->setText(text);
}

void Interface::clearClicked() { m_display_down->setText("0"); }

void Interface::clearAllClicked() {
  m_display_down->setText("0");
  m_display_up->clear();
  m_sign->clear();
}

void Interface::abortOperation() { m_display_down->setText("Wrong input"); }

bool Interface::check_and_calculate(QString input, long double x) {
  QByteArray arr = input.toLocal8Bit();
  char *str = arr.data();
  int check_error = check_input(str);

  if (check_error > 0) m_display_down->setText("Wrong input!");

  stack_t *parced_input = parce_input(str);
  stack_t *output = make_reverse_polish_notation(&parced_input);
  long double result = 0.0;
  int status = calculate(&output, x, &result);

  if (status == 0 && !std::isnan(result)) {
    m_display_down->setText(QString::number(result, 'f', 7));
    answer_shown = 1;
  } else
    abortOperation();

  return true;
}

void Interface::printClicked() {
  xDisplay = 0;
  QString input = "";
  if (answer_shown)
    input = m_display_up->text();
  else
    input = m_display_up->text() + m_display_down->text();
  m_display_up->setText(input);
  m_display_down->clear();

  QByteArray arr = input.toLocal8Bit();
  char *str = arr.data();
  int check_error = check_input(str);

  if (check_error > 0)
    m_display_down->setText("Wrong input!");
  else {
    g = new Graphics();
    g->setStyleSheet("background-color:black;");
    g->expression = input;
  }
  g->show();
  answer_shown = 1;
}
