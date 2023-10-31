#include "deposit.h"

Deposit::Deposit() {
  mainLayout = new QGridLayout();

  m_sum = new QLabel();
  m_sum->setText("The whole sum:");
  m_startDate = new QLabel();
  m_startDate->setText("The starting date:");
  m_term = new QLabel();
  m_term->setText("Term:");
  m_interest = new QLabel();
  m_interest->setText("Interest rate (%):");
  m_taxRate = new QLabel();
  m_taxRate->setText("Tax rate:");
  m_periodicity = new QLabel();
  m_periodicity->setText("Periodicity:");
  m_capitalization = new QLabel();
  m_capitalization->setText("Capitalization:");

  m_displaySum = new QLineEdit();
  m_displayDate = new QLineEdit();
  m_displayTerm = new QLineEdit();
  m_displayTermIn = new QComboBox();
  m_displayTermIn->addItem("days");
  m_displayTermIn->addItem("months");
  m_displayTermIn->addItem("years");
  m_displayInterest = new QLineEdit();
  m_displayTaxRate = new QLineEdit();
  m_displayPeriodicity = new QComboBox();
  m_displayPeriodicity->addItem("Every day");
  m_displayPeriodicity->addItem("Every week");
  m_displayPeriodicity->addItem("Every month");
  m_displayPeriodicity->addItem("Every quarter");
  m_displayPeriodicity->addItem("Twice a year");
  m_displayPeriodicity->addItem("Once a year");
  m_displayPeriodicity->addItem("At the end of the term");

  m_replenishments = new QLabel();
  m_replenishments->setText("Replenishments:");
  addReplenishmentButton =
      createButton("Add +", SLOT(addReplenishmantClicked()));
  m_withdrawals = new QLabel();
  m_withdrawals->setText("Withdrawals:");
  addWithdrawalButton = createButton("Add +", SLOT(addWithdrawalClicked()));

  m_accruedInterest = new QLabel();
  m_accruedInterest->setText("Accrued interest:");
  m_taxAmount = new QLabel();
  m_taxAmount->setText("Tax amount:");
  m_totalPayment = new QLabel();
  m_totalPayment->setText("Total payment:");

  m_accruedInterestResponse = new QLabel();
  m_taxAmountResponse = new QLabel();
  m_totalPaymentResponse = new QLabel();

  m_capitalizationYes = new QRadioButton("Yes");
  connect(m_capitalizationYes, &QRadioButton::clicked,
          [=]() { this->capitalizationYesClicked(); });
  m_capitalizationNo = new QRadioButton("No");
  connect(m_capitalizationNo, &QRadioButton::clicked,
          [=]() { this->capitalizationNoClicked(); });

  m_calculate = new QLabel();

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);

  m_displaySum->setAlignment(Qt::AlignRight);
  m_displayDate->setAlignment(Qt::AlignRight);
  m_displayTerm->setAlignment(Qt::AlignRight);
  m_displayInterest->setAlignment(Qt::AlignRight);
  m_displayTaxRate->setAlignment(Qt::AlignRight);

  m_accruedInterestResponse->setAlignment(Qt::AlignRight);
  m_totalPaymentResponse->setAlignment(Qt::AlignRight);
  m_taxAmountResponse->setAlignment(Qt::AlignRight);

  QFont font = m_displaySum->font();
  font.setPointSize(font.pointSize() + 5);
  m_displaySum->setFont(font);
  m_displayDate->setFont(font);
  m_displayTerm->setFont(font);
  m_displayTermIn->setFont(font);
  m_displayInterest->setFont(font);
  m_displayTaxRate->setFont(font);
  m_displayPeriodicity->setFont(font);
  m_sum->setFont(font);
  m_startDate->setFont(font);
  m_term->setFont(font);
  m_interest->setFont(font);
  m_taxRate->setFont(font);
  m_periodicity->setFont(font);
  m_capitalization->setFont(font);
  m_replenishments->setFont(font);
  m_withdrawals->setFont(font);
  m_accruedInterest->setFont(font);
  m_accruedInterestResponse->setFont(font);
  m_taxAmount->setFont(font);
  m_taxAmountResponse->setFont(font);
  m_totalPayment->setFont(font);
  m_totalPaymentResponse->setFont(font);
  m_capitalizationYes->setFont(font);
  m_capitalizationNo->setFont(font);

  m_displaySum->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayDate->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayTerm->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayTermIn->setStyleSheet(
      "QComboBox {color: #ACFF83; background: #232522;}");
  m_displayInterest->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayTaxRate->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_displayPeriodicity->setStyleSheet(
      "QComboBox {color: #ACFF83; background: #232522;}");

  m_sum->setStyleSheet("QLabel {color: #ACFF83;}");
  m_startDate->setStyleSheet("QLabel {color: #ACFF83;}");
  m_term->setStyleSheet("QLabel {color: #ACFF83;}");
  m_interest->setStyleSheet("QLabel {color: #ACFF83;}");
  m_taxRate->setStyleSheet("QLabel {color: #ACFF83;}");
  m_periodicity->setStyleSheet("QLabel {color: #ACFF83;}");
  m_capitalization->setStyleSheet("QLabel {color: #ACFF83;}");
  m_replenishments->setStyleSheet("QLabel {color: #ACFF83;}");
  m_withdrawals->setStyleSheet("QLabel {color: #ACFF83;}");
  m_replenishments->setStyleSheet("QLabel {color: #ACFF83;}");
  m_withdrawals->setStyleSheet("QLabel {color: #ACFF83;}");
  addReplenishmentButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  addWithdrawalButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  m_accruedInterest->setStyleSheet("QLabel {color: #ACFF83;}");
  m_taxAmount->setStyleSheet("QLabel {color: #ACFF83;}");
  m_totalPayment->setStyleSheet("QLabel {color: #ACFF83;}");
  m_capitalizationYes->setStyleSheet("QLabel {color: #ACFF83;}");
  m_capitalizationNo->setStyleSheet("QLabel {color: #ACFF83;}");
  m_accruedInterestResponse->setStyleSheet("QLabel {color: #ACFF83;}");
  m_taxAmountResponse->setStyleSheet("QLabel {color: #ACFF83;}");
  m_totalPaymentResponse->setStyleSheet("QLabel {color: #ACFF83;}");

  m_capitalizationYes->setStyleSheet("QRadioButton {color: #ACFF83;}");
  m_capitalizationYes->setChecked(true);
  m_capitalizationNo->setStyleSheet("QRadioButton {color: #ACFF83;}");

  calcButton = createButton("Calculate!", SLOT(buttonClicked()));
  calcButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");

  mainLayout->addWidget(m_sum, 0, 0, 1, 5);
  mainLayout->addWidget(m_displaySum, 0, 10, 1, 5);
  mainLayout->addWidget(m_startDate, 1, 0, 1, 5);
  mainLayout->addWidget(m_displayDate, 1, 10, 1, 5);
  mainLayout->addWidget(m_term, 2, 0, 1, 5);
  mainLayout->addWidget(m_displayTerm, 2, 5, 1, 5);
  mainLayout->addWidget(m_displayTermIn, 2, 10, 1, 5);
  mainLayout->addWidget(m_interest, 3, 0, 1, 5);
  mainLayout->addWidget(m_displayInterest, 3, 10, 1, 5);
  mainLayout->addWidget(m_taxRate, 4, 0, 1, 5);
  mainLayout->addWidget(m_displayTaxRate, 4, 10, 1, 5);
  mainLayout->addWidget(m_periodicity, 5, 0, 1, 5);
  mainLayout->addWidget(m_displayPeriodicity, 5, 10, 1, 5);
  mainLayout->addWidget(m_capitalization, 6, 0, 1, 5);
  mainLayout->addWidget(m_capitalizationYes, 6, 5, 1, 2);
  mainLayout->addWidget(m_capitalizationNo, 6, 10, 1, 2);
  mainLayout->addWidget(m_replenishments, 7, 0, 1, 6);
  mainLayout->addWidget(addReplenishmentButton, 7, 10, 1, 5);
  mainLayout->addWidget(m_withdrawals, 8, 0, 1, 5);
  mainLayout->addWidget(addWithdrawalButton, 8, 10, 1, 5);

  mainLayout->addWidget(calcButton, 9, 3, 1, 10);

  mainLayout->addWidget(m_accruedInterest, 10, 0, 1, 4);
  mainLayout->addWidget(m_accruedInterestResponse, 10, 10, 1, 5);
  mainLayout->addWidget(m_taxAmount, 11, 0, 1, 4);
  mainLayout->addWidget(m_taxAmountResponse, 11, 10, 1, 5);
  mainLayout->addWidget(m_totalPayment, 12, 0, 1, 4);
  mainLayout->addWidget(m_totalPaymentResponse, 12, 10, 1, 5);

  setLayout(mainLayout);
  setWindowTitle("Deposit");
}

void Deposit::buttonClicked() {
  calculate();
  m_accruedInterestResponse->setText(QString::number(accruedInterest, 'f', 2));
  m_totalPaymentResponse->setText(QString::number(totalSum, 'f', 2));
  m_taxAmountResponse->setText(QString::number(taxAmount, 'f', 2));
}

void Deposit::capitalizationYesClicked() { capitalization = 1; }

void Deposit::capitalizationNoClicked() {
  capitalization = 0;
  m_displayPeriodicity->setCurrentIndex(6);
}

void Deposit::addReplenishmantClicked() {
  r = new Replenishments();
  r->setStyleSheet("background-color:black;");
  r->show();
  replenishments = 1;
}

void Deposit::addWithdrawalClicked() {
  w = new Withdrawals();
  w->setStyleSheet("background-color:black;");
  w->show();
  withdrawals = 1;
}

Button *Deposit::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}

void Deposit::calculate() {
  accruedInterest = 0.0;
  totalSum = 0.0;
  taxAmount = 0.0;
  long double sum = (long double)m_displaySum->text().toDouble();
  long double interest =
      (long double)m_displayInterest->text().toDouble() / 100;
  QDate dateStart = QDate::fromString(m_displayDate->text(), "dd.MM.yyyy");
  int term = m_displayTerm->text().toInt();
  QDate dateEnd;
  if (m_displayTermIn->currentIndex() == 0)
    dateEnd = dateStart.addDays(term);
  else if (m_displayTermIn->currentIndex() == 1)
    dateEnd = dateStart.addMonths(term);
  else if (m_displayTermIn->currentIndex() == 2)
    dateEnd = dateStart.addYears(term);

  int periodicity = m_displayPeriodicity->currentIndex();
  int days = 0;
  if (periodicity == 6)
    days = dateStart.daysTo(dateEnd);
  else
    days = count_days(dateStart, periodicity);

  QDate paymentDay = dateStart;
  if (periodicity > 0) paymentDay = paymentDay.addDays(days);

  calc(paymentDay, days, periodicity, dateStart, dateEnd, sum, interest);
}

int Deposit::count_days(QDate currentDate, int periodicity) {
  int days = 0;
  QDate nextTerm;
  nextTerm.setDate(currentDate.year(), currentDate.month(), currentDate.day());
  switch (periodicity) {
    case 0:
      days = 1;
      break;
    case 1:
      days = 7;
      break;
    case 2:
      days = currentDate.daysInMonth();
      break;
    case 3:
      nextTerm = nextTerm.addMonths(3);
      days = currentDate.daysTo(nextTerm);
      break;
    case 4:
      nextTerm = nextTerm.addMonths(6);
      days = currentDate.daysTo(nextTerm);
      break;
    case 5:
      nextTerm = nextTerm.addYears(1);
      days = currentDate.daysTo(nextTerm);
      break;
  }
  return days;
}

long double Deposit::calc_taxes(long double yearlyIncome) {
  double notObliged = 1000000 * (m_displayTaxRate->text().toDouble() / 100.0);
  long double tax = 0.0;
  if (yearlyIncome > notObliged) {
    tax = (yearlyIncome - notObliged) * 0.13;
  }
  return tax;
}

void Deposit::calc(QDate paymentDay, int days, int periodicity, QDate dateStart,
                   QDate dateEnd, long double sum, long double interest) {
  long double ai = 0.0;
  long double wholeIncome = 0.0;
  long double yearlyIncome = 0.0;
  long double yearlyAI = 0.0;
  long double subtractAI = 0.0;
  long double taxesSum = 0.0;
  long double index =
      (QDate::isLeapYear(dateStart.year())) ? 1 / 366.0 : 1 / 365.0;
  for (QDate curr = dateStart; curr < dateEnd; curr = curr.addDays(1)) {
    if (replenishments) {
      for (int i = 0; i <= r->replenishment; i++) {
        if (r->inputReplenishmentDates[i] == curr) {
          sum += r->inputReplenishmentAmounts[i];
        }
      }
    }
    if (withdrawals) {
      for (int i = 0; i <= w->withdrawal; i++) {
        if (w->inputWithdrawalDates[i] == curr) {
          sum -= w->inputWithdrawalAmounts[i];
        }
      }
    }
    if (curr.day() == 1 && curr.month() == 1) {
      index = (QDate::isLeapYear(curr.year())) ? 1 / 366.0 : 1 / 365.0;
      yearlyAI = 0.0;
    }
    if (periodicity == 0) ai += sum * interest * index;
    if (curr == paymentDay) {
      sum += ai;
      accruedInterest += ai;
      yearlyAI += ai;
      if (periodicity > 1 && periodicity < 6)
        days = count_days(curr, periodicity);
      paymentDay = paymentDay.addDays(days);
      ai = 0.0;
    }
    if (periodicity > 0) ai += sum * interest * index;

    if (curr.addDays(1) == dateEnd) {
      sum += ai;
      accruedInterest += ai;
      yearlyAI += ai;
      ai = 0.0;
    }

    if ((curr.day() == 31 && curr.month() == 12) ||
        curr.addDays(1) == dateEnd) {
      yearlyIncome = yearlyAI + ai - subtractAI;
      subtractAI = ai;
      long double tax = calc_taxes(yearlyIncome);
      taxesSum += tax;
      wholeIncome += yearlyIncome;
    }
  }
  taxAmount = taxesSum;
  totalSum = sum;
}
