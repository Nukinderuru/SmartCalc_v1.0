#ifndef REPLENISHMENTS_H
#define REPLENISHMENTS_H

#include <QDate>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>

#include "button.h"

class Replenishments : public QWidget {
  Q_OBJECT

 public:
  Replenishments();

 private slots:
  void addButtonClicked();
  void okButtonClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  QGridLayout *mainLayout;

  QLabel *m_replenishmentDate;
  QLabel *m_replenishmentAmount;
  Button *addReplenishmentButton;
  Button *okButton;

  int replenishmentsLine = 1;

  QLineEdit *m_replenishmentDates[100];
  QLineEdit *m_replenishmentAmounts[100];

 public:
  int replenishment = 0;
  QDate inputReplenishmentDates[100];
  long double inputReplenishmentAmounts[100];
};

#endif  // REPLENISHMENTS_H
