#include "graphics.h"

#include "interface.h"
#include "qcustomplot.h"
//#include "ui_graphics.h"
#include <QDebug>

#include "button.h"

extern "C" {
#include "smart_calc.h"
}

Graphics::Graphics() {
  QGridLayout *mainLayout = new QGridLayout();

  m_info = new QLabel();
  m_from = new QLabel();
  m_display_from = new QLineEdit();
  m_to = new QLabel();
  m_display_to = new QLineEdit();

  m_from->setText("From:");
  m_to->setText("To:");

  mainLayout->setSizeConstraint(QLayout::SetFixedSize);

  m_display_from->setAlignment(Qt::AlignRight);
  m_display_to->setAlignment(Qt::AlignRight);

  m_display_from->setMaxLength(10);
  m_display_to->setMaxLength(10);

  QFont font = m_display_from->font();
  font.setPointSize(font.pointSize() + 5);
  m_display_from->setFont(font);
  m_display_to->setFont(font);
  m_from->setFont(font);
  m_to->setFont(font);

  m_display_from->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_display_to->setStyleSheet(
      "QLineEdit {color: #ACFF83; background: #232522;}");
  m_info->setStyleSheet("QLabel {color: #ACFF83;}");
  m_from->setStyleSheet("QLabel {color: #ACFF83;}");
  m_to->setStyleSheet("QLabel {color: #ACFF83;}");

  Button *printGraphic = createButton("Draw a graphic!", SLOT(printClicked()));
  printGraphic->setStyleSheet(
      "QToolButton {color: #FF8800; background: #232522;}");

  mainLayout->addWidget(m_from, 0, 0, 1, 1);
  mainLayout->addWidget(m_display_from, 0, 3, 1, 3);
  mainLayout->addWidget(m_to, 1, 0, 1, 1);
  mainLayout->addWidget(m_display_to, 1, 3, 1, 3);

  mainLayout->addWidget(printGraphic, 2, 2, 1, 3);

  setLayout(mainLayout);

  setWindowTitle("Graphics");
}

void Graphics::printClicked() {
  if (!isnanf(m_display_from->text().toDouble()) &&
      !isnanf(m_display_to->text().toDouble())) {
    p = new Plot();
    p->xBegin = m_display_from->text().toDouble();
    p->xEnd = m_display_to->text().toDouble();

    QByteArray arr = expression.toLocal8Bit();
    char *str = arr.data();

    p->print_graphic(str);
    p->setWindowTitle(str);
  }
  p->show();
}

void Graphics::fromClicked() { m_display_from->clear(); }

void Graphics::toClicked() { m_display_to->clear(); }

Button *Graphics::createButton(const QString &text, const char *member) {
  Button *btn = new Button(text);
  connect(btn, SIGNAL(clicked()), this, member);
  return btn;
}
