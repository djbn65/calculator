#include "calculator.h"
#include <QChar>
#include <QMessageBox>
#include "parser.h"

Calculator::Calculator() {
  layout = new QVBoxLayout;
  buttons = new Buttons;
  display = new QTextEdit;
  display->setReadOnly(1);
  display->setFixedHeight(200);
  buttons->setFixedHeight(200);
  layout->addWidget(display);
  layout->addWidget(buttons);
  quitAction = new QAction("&Quit", this);
  QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));

  QWidget* main = new QWidget;
  main->setLayout(layout);
  setCentralWidget(main);

  QObject::connect(buttons, SIGNAL(updateScreen(QString*)), this, SLOT(showCalc(QString*)));
  QObject::connect(buttons, SIGNAL(backSpace()), this, SLOT(back()));
  QObject::connect(buttons, SIGNAL(clearScreen()), this, SLOT(clear()));
  QObject::connect(buttons, SIGNAL(showAnswer()), this, SLOT(equals()));

  fileMenu = menuBar();
  fileMenu->addAction(quitAction);
}

void Calculator::showCalc(QString* update) {
  display->setPlainText(display->toPlainText() + (*update));
}

void Calculator::back() {
  display->setPlainText(display->toPlainText().mid(0,display->toPlainText().length()-1));
  if (display->toPlainText().length() == 0)
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('+'))
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('-'))
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('*'))
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('/'))
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('.'))
    buttons->setOperatorPressed(1);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('1'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('2'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('3'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('4'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('5'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('6'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('7'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('8'))
    buttons->setOperatorPressed(0);
  else if (display->toPlainText().mid(display->toPlainText().length()-1) == QChar('9'))
    buttons->setOperatorPressed(0);
}

void Calculator::clear() {
  if (display->toPlainText().length() != 0)
  {
    if (buttons->getAnswerShown() == 0)
    {
      QMessageBox messageBox;
      messageBox.setWindowTitle("Are you sure?");
      messageBox.setText("Current calculations will be lost if cleared.");
      messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      messageBox.setDefaultButton(QMessageBox::No);
      if (messageBox.exec() == QMessageBox::Yes)
      {
        display->setPlainText(QString(""));
        buttons->setOperatorPressed(1);
        buttons->setNumberPressed(0);
        buttons->setAnswerShown(0);
      }
    }
    else
    {
      display->setPlainText(QString(""));
      buttons->setOperatorPressed(1);
      buttons->setNumberPressed(0);
      buttons->setAnswerShown(0);
    }
  }
}

void Calculator::equals() {
  Parser expression;
  string result=expression.parse(display->toPlainText().toStdString().c_str());
  display->setPlainText(QString(display->toPlainText().toStdString().c_str()) + QString("\n") + QString(result.c_str()));
  buttons->setAnswerShown(1);
}

void Calculator::quit() {
  qApp->quit();
}