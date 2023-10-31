#include "replenishments.h"

Replenishments::Replenishments() {
  mainLayout = new QGridLayout();

  m_replenishmentDate = new QLabel();
  m_replenishmentDate->setText("Date:");
  m_replenishmentAmount = new QLabel;
  m_replenishmentAmount->setText("Amount:");

  addReplenishmentButton = createButton("Add +", SLOT(addButtonClicked()));
  okButton = createButton("OK", SLOT(okButtonClicked()));

  m_replenishmentDates[replenishment] = new QLineEdit();
  m_replenishmentAmounts[replenishment] = new QLineEdit();

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);

  QFont font = m_replenishmentDate->font();
  font.setPointSize(font.pointSize() + 5);
  m_replenishmentDate->setFont(font);
  m_replenishmentAmount->setFont(font);
  m_replenishmentDates[replenishment]->setFont(font);
  m_replenishmentAmounts[replenishment]->setFont(font);

  m_replenishmentDate->setStyleSheet("QLabel {color: #ACFF83;}");
  m_replenishmentAmount->setStyleSheet("QLabel {color: #ACFF83;}");
  addReplenishmentButton->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");
  m_replenishmentDates[replenishment]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_replenishmentAmounts[replenishment]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");

  mainLayout->addWidget(m_replenishmentDate, 0, 0, 1, 5);
  mainLayout->addWidget(m_replenishmentAmount, 0, 6, 1, 5);
  mainLayout->addWidget(m_replenishmentDates[replenishment], 1, 0, 1, 5);
  mainLayout->addWidget(m_replenishmentAmounts[replenishment], 1, 6, 1, 5);
  mainLayout->addWidget(addReplenishmentButton, 2, 0, 1, 5);
  mainLayout->addWidget(okButton, 2, 5, 1, 5);

  setLayout(mainLayout);
  setWindowTitle("Replenishments");
}

void Replenishments::addButtonClicked() {
  replenishmentsLine++;
  replenishment++;
  m_replenishmentDates[replenishment] = new QLineEdit();
  m_replenishmentAmounts[replenishment] = new QLineEdit();
  m_replenishmentDates[replenishment]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_replenishmentAmounts[replenishment]->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  QFont font = m_replenishmentDate->font();
  m_replenishmentDates[replenishment]->setFont(font);
  m_replenishmentAmounts[replenishment]->setFont(font);
  mainLayout->addWidget(m_replenishmentDates[replenishment], replenishmentsLine,
                        0, 1, 5);
  mainLayout->addWidget(m_replenishmentAmounts[replenishment],
                        replenishmentsLine, 6, 1, 5);
  mainLayout->addWidget(addReplenishmentButton, replenishmentsLine + 1, 0, 1,
                        5);
  mainLayout->addWidget(okButton, replenishmentsLine + 1, 5, 1, 5);
}

void Replenishments::okButtonClicked() {
  for (int i = 0; i <= replenishment; i++) {
    inputReplenishmentDates[i] =
        QDate::fromString(m_replenishmentDates[i]->text(), "dd.MM.yyyy");
  }
  for (int i = 0; i <= replenishment; i++) {
    inputReplenishmentAmounts[i] = m_replenishmentAmounts[i]->text().toDouble();
  }
}

Button *Replenishments::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}
