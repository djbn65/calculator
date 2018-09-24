#include <QApplication>
#include "calculator.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Calculator calc;
  calc.setFixedSize(350,430);
  calc.setWindowTitle("Ultimate Calculator Extreme!");
  calc.show();

  return app.exec();
}