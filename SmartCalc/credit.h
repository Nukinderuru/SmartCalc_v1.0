#ifndef CREDIT_H
#define CREDIT_H

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QToolButton>
#include <QWidget>
#include <QtMath>

#include "button.h"

class Credit : public QWidget {
  Q_OBJECT

 public:
  Credit();

 private slots:
  void buttonClicked();
  void annCreditClicked();
  void diffCreditClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  QLineEdit *m_displaySum;
  QLineEdit *m_displayTerm;
  QLineEdit *m_displayInterest;

  QLabel *m_sum;
  QLabel *m_term;
  QLabel *m_interest;

  QLabel *m_calculate;

  QLabel *m_monthlyPayment;
  QLabel *m_overpayment;
  QLabel *m_totalPayment;

  QLabel *m_monthlyPaymentResponse;
  QLabel *m_overpaymentResponse;
  QLabel *m_totalPaymentResponse;

  QRadioButton *m_ann;
  QRadioButton *m_diff;

  double sum, overpayment, total, lastSum;
  int type = 1;

  void calculate(int credit, int months, int interest);
};

#endif  // CREDIT_H
