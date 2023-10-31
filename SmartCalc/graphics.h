#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QLabel>
#include <QLineEdit>

#include "button.h"
#include "plot.h"

extern "C" {
#include "smart_calc.h"
}

class Graphics : public QWidget {
  Q_OBJECT

 public:
  Graphics();
  QString expression;

 private slots:
  void printClicked();
  void fromClicked();
  void toClicked();

 private:
  Button *createButton(const QString &text, const char *member);

  QLineEdit *m_display_expression;
  QLineEdit *m_display_from;
  QLineEdit *m_display_to;
  QLabel *m_info;
  QLabel *m_from;
  QLabel *m_to;

  Plot *p;
};

#endif  // GRAPHICS_H
