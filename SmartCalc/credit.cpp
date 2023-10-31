#include "credit.h"

Credit::Credit() {
  QGridLayout *mainLayout = new QGridLayout();

  m_sum = new QLabel();
  m_sum->setText("The whole sum:");
  m_term = new QLabel();
  m_term->setText("Amount of months:");
  m_interest = new QLabel();
  m_interest->setText("Interest rate (%):");

  m_displaySum = new QLineEdit();
  m_displayTerm = new QLineEdit();
  m_displayInterest = new QLineEdit();

  m_monthlyPayment = new QLabel();
  m_monthlyPayment->setText("Monthly payment:");
  m_overpayment = new QLabel();
  m_overpayment->setText("Overpayment:");
  m_totalPayment = new QLabel();
  m_totalPayment->setText("Total payment:");

  m_monthlyPaymentResponse = new QLabel();
  m_overpaymentResponse = new QLabel();
  m_totalPaymentResponse = new QLabel();

  m_ann = new QRadioButton("Annuity");
  connect(m_ann, &QRadioButton::clicked, [=]() { this->annCreditClicked(); });
  m_diff = new QRadioButton("Differentiated");
  connect(m_diff, &QRadioButton::clicked, [=]() { this->diffCreditClicked(); });

  m_calculate = new QLabel();

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);

  m_displaySum->setAlignment(Qt::AlignRight);
  m_displayTerm->setAlignment(Qt::AlignRight);
  m_displayInterest->setAlignment(Qt::AlignRight);

  m_monthlyPaymentResponse->setAlignment(Qt::AlignRight);
  m_totalPaymentResponse->setAlignment(Qt::AlignRight);
  m_overpaymentResponse->setAlignment(Qt::AlignRight);

  QFont font = m_displaySum->font();
  font.setPointSize(font.pointSize() + 5);
  m_displaySum->setFont(font);
  m_displayTerm->setFont(font);
  m_displayInterest->setFont(font);
  m_sum->setFont(font);
  m_term->setFont(font);
  m_interest->setFont(font);
  m_monthlyPayment->setFont(font);
  m_monthlyPaymentResponse->setFont(font);
  m_overpayment->setFont(font);
  m_overpaymentResponse->setFont(font);
  m_totalPayment->setFont(font);
  m_totalPaymentResponse->setFont(font);
  m_ann->setFont(font);
  m_diff->setFont(font);

  m_displaySum->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayTerm->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayInterest->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");

  m_sum->setStyleSheet("QLabel {color: #ACFF83;}");
  m_term->setStyleSheet("QLabel {color: #ACFF83;}");
  m_interest->setStyleSheet("QLabel {color: #ACFF83;}");
  m_monthlyPayment->setStyleSheet("QLabel {color: #ACFF83;}");
  m_overpayment->setStyleSheet("QLabel {color: #ACFF83;}");
  m_totalPayment->setStyleSheet("QLabel {color: #ACFF83;}");
  m_monthlyPaymentResponse->setStyleSheet("QLabel {color: #ACFF83;}");
  m_overpaymentResponse->setStyleSheet("QLabel {color: #ACFF83;}");
  m_totalPaymentResponse->setStyleSheet("QLabel {color: #ACFF83;}");

  m_ann->setStyleSheet("QRadioButton {color: #ACFF83;}");
  m_ann->setChecked(true);
  m_diff->setStyleSheet("QRadioButton {color: #ACFF83;}");

  Button *calcButton = createButton("Calculate!", SLOT(buttonClicked()));
  calcButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");

  mainLayout->addWidget(m_sum, 0, 0, 1, 4);
  mainLayout->addWidget(m_displaySum, 0, 5, 1, 5);
  mainLayout->addWidget(m_term, 1, 0, 1, 4);
  mainLayout->addWidget(m_displayTerm, 1, 5, 1, 5);
  mainLayout->addWidget(m_interest, 2, 0, 1, 4);
  mainLayout->addWidget(m_displayInterest, 2, 5, 1, 5);

  mainLayout->addWidget(m_ann, 3, 0, 1, 2);
  mainLayout->addWidget(m_diff, 3, 5, 1, 2);

  mainLayout->addWidget(calcButton, 4, 0, 1, 10);

  mainLayout->addWidget(m_monthlyPayment, 5, 0, 1, 4);
  mainLayout->addWidget(m_monthlyPaymentResponse, 5, 5, 1, 5);
  mainLayout->addWidget(m_overpayment, 6, 0, 1, 4);
  mainLayout->addWidget(m_overpaymentResponse, 6, 5, 1, 5);
  mainLayout->addWidget(m_totalPayment, 7, 0, 1, 4);
  mainLayout->addWidget(m_totalPaymentResponse, 7, 5, 1, 5);

  setLayout(mainLayout);
  setWindowTitle("Credit");
}

void Credit::buttonClicked() {
  int credit = m_displaySum->text().toInt();
  int months = m_displayTerm->text().toInt();
  int interest = m_displayInterest->text().toInt();
  if (credit && months && interest) {
    calculate(credit, months, interest);
  }

  if (type == 1)
    m_monthlyPaymentResponse->setText(QString::number(sum, 'f', 2));
  else if (type == 2)
    m_monthlyPaymentResponse->setText(QString::number(sum, 'f', 2) + " ... " +
                                      QString::number(lastSum, 'f', 2));
  m_totalPaymentResponse->setText(QString::number(total, 'f', 2));
  m_overpaymentResponse->setText(QString::number(overpayment, 'f', 2));
}

void Credit::annCreditClicked() { type = 1; }

void Credit::diffCreditClicked() { type = 2; }

Button *Credit::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}

void Credit::calculate(int credit, int months, int interest) {
  double hundredthInterest = 0.0;
  hundredthInterest = ((double)interest / 12.0) / 100.0;
  if (type == 1) {
    sum = (double)credit *
          (hundredthInterest +
           (hundredthInterest / (pow((1 + hundredthInterest), months) - 1)));
    total = sum * (double)months;
    overpayment = total - (double)credit;
  } else if (type == 2) {
    overpayment = 0.0;
    double fixed = credit / (double)months;
    double remain = (double)credit, monthInterest = 0.0;
    for (int i = 0; i < months; i++) {
      monthInterest = remain * hundredthInterest;
      overpayment += monthInterest;
      remain -= fixed;
      if (i == 0) sum = fixed + monthInterest;
      if (i == months - 1) lastSum = fixed + monthInterest;
    }
    total = credit + overpayment;
  }
}
