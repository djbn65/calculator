#pragma once
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QString>
using namespace std;

class Buttons : public QFrame
{
  Q_OBJECT

  public:
    Buttons();
    void setOperatorPressed(bool val) { operatorPressed = val; }
    void setNumberPressed(bool val) { numberPressed = val; }
    bool getAnswerShown() { return answerShown; }
    void setAnswerShown(bool val) { answerShown = val; }

  signals:
    void updateScreen(QString* update);
    void showAnswer();
    void clearScreen();
    void backSpace();

  private slots:
    void additionPress();
    void subtractionPress();
    void divisionPress();
    void multiplicationPress();
    void onePress();
    void twoPress();
    void threePress();
    void fourPress();
    void fivePress();
    void sixPress();
    void sevenPress();
    void eightPress();
    void ninePress();
    void zeroPress();
    void decimalPress();
    void equalPress();
    void clearPress();
    void backPress();

  private:
    QGridLayout* numberGrid;
    QVBoxLayout* opsStack;
    QHBoxLayout* main;
    QPushButton* one;
    QPushButton* two;
    QPushButton* three;
    QPushButton* four;
    QPushButton* five;
    QPushButton* six;
    QPushButton* seven;
    QPushButton* eight;
    QPushButton* nine;
    QPushButton* zero;
    QPushButton* decimal;
    QPushButton* plus;
    QPushButton* minus;
    QPushButton* division;
    QPushButton* multiplication;
    QPushButton* equal;
    QPushButton* clear;
    QPushButton* back;
    bool operatorPressed = true;
    bool numberPressed = false;
    bool answerShown = false;
};