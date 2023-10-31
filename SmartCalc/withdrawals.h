#ifndef WITHDRAWALS_H
#define WITHDRAWALS_H

#include <QDate>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>

#include "button.h"

class Withdrawals : public QWidget {
  Q_OBJECT
 public:
  Withdrawals();

 private slots:
  void addButtonClicked();
  void okButtonClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  QGridLayout *mainLayout;

  QLabel *m_withdrawalDate;
  QLabel *m_withdrawalAmount;
  Button *addWithdrawalButton;
  Button *okButton;

  QLineEdit *m_withdrawalDates[100];
  QLineEdit *m_withdrawalAmounts[100];

  int withdrawalsLine = 1;

 public:
  int withdrawal = 0;
  QDate inputWithdrawalDates[100];
  long double inputWithdrawalAmounts[100];
};

#endif  // WITHDRAWALS_H
