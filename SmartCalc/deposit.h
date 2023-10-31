#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QComboBox>
#include <QDate>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QToolButton>
#include <QWidget>
#include <QtMath>

#include "button.h"
#include "replenishments.h"
#include "withdrawals.h"

class Deposit : public QWidget {
  Q_OBJECT

 public:
  Deposit();

 private slots:
  void buttonClicked();
  void capitalizationYesClicked();
  void capitalizationNoClicked();
  void addReplenishmantClicked();
  void addWithdrawalClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  QGridLayout *mainLayout;

  QLineEdit *m_displaySum;
  QLineEdit *m_displayDate;
  QLineEdit *m_displayTerm;
  QComboBox *m_displayTermIn;
  QLineEdit *m_displayInterest;
  QLineEdit *m_displayTaxRate;
  QComboBox *m_displayPeriodicity;

  QLabel *m_sum;
  QLabel *m_startDate;
  QLabel *m_term;
  QLabel *m_interest;
  QLabel *m_taxRate;
  QLabel *m_periodicity;
  QLabel *m_capitalization;

  QLabel *m_replenishments;
  QLabel *m_replenishmentDate;
  QLabel *m_replenishmentAmount;
  Button *addReplenishmentButton;
  QLabel *m_withdrawals;
  QLabel *m_withdrawalDate;
  QLabel *m_withdrawalAmount;
  Button *addWithdrawalButton;

  QLabel *m_calculate;
  Button *calcButton;

  QLabel *m_accruedInterest;
  QLabel *m_taxAmount;
  QLabel *m_totalPayment;

  QLabel *m_accruedInterestResponse;
  QLabel *m_taxAmountResponse;
  QLabel *m_totalPaymentResponse;

  QRadioButton *m_capitalizationYes;
  QRadioButton *m_capitalizationNo;

  QLineEdit *m_withdrawalDates[100];
  QLineEdit *m_withdrawalAmounts[100];

  long double accruedInterest, taxAmount, totalSum;
  bool capitalization = 1;
  bool replenishments;
  bool withdrawals;

  void calculate(int credit, int months, int interest);
  void calculate();
  int count_days(QDate currentDate, int periodicity);
  long double calc_taxes(long double yearlyIncome);
  void calc(QDate paymentDay, int days, int periodicity, QDate dateStart,
            QDate dateEnd, long double sum, long double interest);

  Replenishments *r;
  QDate inputReplenishmentDates[100];
  long double inputReplenishmentAmounts[100];

  Withdrawals *w;
  QDate inputWithdrawalDates[100];
  long double inputWithdrawalAmounts[100];
};

#endif  // DEPOSIT_H
