#include "withdrawals.h"

Withdrawals::Withdrawals() {
  mainLayout = new QGridLayout();

  m_withdrawalDate = new QLabel();
  m_withdrawalDate->setText("Date:");
  m_withdrawalAmount = new QLabel;
  m_withdrawalAmount->setText("Amount:");

  addWithdrawalButton = createButton("Add +", SLOT(addButtonClicked()));
  okButton = createButton("OK", SLOT(okButtonClicked()));

  m_withdrawalDates[withdrawal] = new QLineEdit();
  m_withdrawalAmounts[withdrawal] = new QLineEdit();

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);

  QFont font = m_withdrawalDate->font();
  font.setPointSize(font.pointSize() + 5);
  m_withdrawalDate->setFont(font);
  m_withdrawalAmount->setFont(font);
  m_withdrawalDates[withdrawal]->setFont(font);
  m_withdrawalAmounts[withdrawal]->setFont(font);

  m_withdrawalDate->setStyleSheet("QLabel {color: #ACFF83;}");
  m_withdrawalAmount->setStyleSheet("QLabel {color: #ACFF83;}");
  addWithdrawalButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  okButton->setStyleSheet("QToolButton {color: #FF8800; background: #232522;}");
  m_withdrawalDates[withdrawal]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_withdrawalAmounts[withdrawal]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");

  mainLayout->addWidget(m_withdrawalDate, 0, 0, 1, 5);
  mainLayout->addWidget(m_withdrawalAmount, 0, 6, 1, 5);
  mainLayout->addWidget(m_withdrawalDates[withdrawal], 1, 0, 1, 5);
  mainLayout->addWidget(m_withdrawalAmounts[withdrawal], 1, 6, 1, 5);
  mainLayout->addWidget(addWithdrawalButton, 2, 0, 1, 5);
  mainLayout->addWidget(okButton, 2, 5, 1, 5);

  setLayout(mainLayout);
  setWindowTitle("Withdrawals");
}

void Withdrawals::addButtonClicked() {
  withdrawalsLine++;
  withdrawal++;
  m_withdrawalDates[withdrawal] = new QLineEdit();
  m_withdrawalAmounts[withdrawal] = new QLineEdit();
  m_withdrawalDates[withdrawal]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_withdrawalAmounts[withdrawal]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  QFont font = m_withdrawalDate->font();
  m_withdrawalDates[withdrawal]->setFont(font);
  m_withdrawalAmounts[withdrawal]->setFont(font);
  mainLayout->addWidget(m_withdrawalDates[withdrawal], withdrawalsLine, 0, 1,
                        5);
  mainLayout->addWidget(m_withdrawalAmounts[withdrawal], withdrawalsLine, 6, 1,
                        5);
  mainLayout->addWidget(addWithdrawalButton, withdrawalsLine + 1, 0, 1, 5);
  mainLayout->addWidget(okButton, withdrawalsLine + 1, 5, 1, 5);
}

void Withdrawals::okButtonClicked() {
  for (int i = 0; i <= withdrawal; i++) {
    inputWithdrawalDates[i] =
        QDate::fromString(m_withdrawalDates[i]->text(), "dd.MM.yyyy");
  }
  for (int i = 0; i <= withdrawal; i++) {
    inputWithdrawalAmounts[i] = m_withdrawalAmounts[i]->text().toDouble();
  }
}

Button *Withdrawals::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}
