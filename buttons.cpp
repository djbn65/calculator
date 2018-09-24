#include "buttons.h"

Buttons::Buttons() {
  numberGrid = new QGridLayout;
  opsStack = new QVBoxLayout;
  main = new QHBoxLayout;

  one = new QPushButton("1");
  two = new QPushButton("2");
  three = new QPushButton("3");
  four = new QPushButton("4");
  five = new QPushButton("5");
  six = new QPushButton("6");
  seven = new QPushButton("7");
  eight = new QPushButton("8");
  nine = new QPushButton("9");
  zero = new QPushButton("0");
  decimal = new QPushButton(".");
  plus = new QPushButton("+");
  minus = new QPushButton("-");
  division = new QPushButton("/");
  multiplication = new QPushButton("*");
  equal = new QPushButton("=");
  clear = new QPushButton("Clear");
  back = new QPushButton("Back");

  QObject::connect(one, SIGNAL(clicked()), this, SLOT(onePress()));
  QObject::connect(two, SIGNAL(clicked()), this, SLOT(twoPress()));
  QObject::connect(three, SIGNAL(clicked()), this, SLOT(threePress()));
  QObject::connect(four, SIGNAL(clicked()), this, SLOT(fourPress()));
  QObject::connect(five, SIGNAL(clicked()), this, SLOT(fivePress()));
  QObject::connect(six, SIGNAL(clicked()), this, SLOT(sixPress()));
  QObject::connect(seven, SIGNAL(clicked()), this, SLOT(sevenPress()));
  QObject::connect(eight, SIGNAL(clicked()), this, SLOT(eightPress()));
  QObject::connect(nine, SIGNAL(clicked()), this, SLOT(ninePress()));
  QObject::connect(zero, SIGNAL(clicked()), this, SLOT(zeroPress()));
  QObject::connect(decimal, SIGNAL(clicked()), this, SLOT(decimalPress()));
  QObject::connect(plus, SIGNAL(clicked()), this, SLOT(additionPress()));
  QObject::connect(minus, SIGNAL(clicked()), this, SLOT(subtractionPress()));
  QObject::connect(division, SIGNAL(clicked()), this, SLOT(divisionPress()));
  QObject::connect(multiplication, SIGNAL(clicked()), this, SLOT(multiplicationPress()));
  QObject::connect(back, SIGNAL(clicked()), this, SLOT(backPress()));
  QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clearPress()));
  QObject::connect(equal, SIGNAL(clicked()), this, SLOT(equalPress()));

  numberGrid->addWidget(clear, 1, 1, 1, 2);
  numberGrid->addWidget(back, 1, 3);
  numberGrid->addWidget(seven, 2, 1);
  numberGrid->addWidget(eight, 2, 2);
  numberGrid->addWidget(nine, 2, 3);
  numberGrid->addWidget(four, 3, 1);
  numberGrid->addWidget(five, 3, 2);
  numberGrid->addWidget(six, 3, 3);
  numberGrid->addWidget(one, 4, 1);
  numberGrid->addWidget(two, 4, 2);
  numberGrid->addWidget(three, 4, 3);
  numberGrid->addWidget(zero, 5, 1, 1, 2);
  numberGrid->addWidget(decimal, 5, 3);

  opsStack->addWidget(plus);
  opsStack->addWidget(minus);
  opsStack->addWidget(division);
  opsStack->addWidget(multiplication);
  opsStack->addWidget(equal);

  main->addLayout(numberGrid);
  main->addLayout(opsStack);

  setLayout(main);
}

void Buttons::additionPress() {
  if (answerShown)
    emit clearScreen();
  if (!operatorPressed)
    emit updateScreen(new QString("+"));
  operatorPressed = true;
}

void Buttons::subtractionPress() {
  if (answerShown)
    emit clearScreen();
  if (!operatorPressed)
    emit updateScreen(new QString("-"));
  operatorPressed = true;
}

void Buttons::divisionPress() {
  if (answerShown)
    emit clearScreen();
  if (!operatorPressed)
    emit updateScreen(new QString("/"));
  operatorPressed = true;
}

void Buttons::multiplicationPress() {
  if (answerShown)
    emit clearScreen();
  if (!operatorPressed)
    emit updateScreen(new QString("*"));
  operatorPressed = true;
}

void Buttons::onePress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("1"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::twoPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("2"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::threePress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("3"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::fourPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("4"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::fivePress() {
  if (answerShown)
    emit updateScreen(new QString("7"));
  emit updateScreen(new QString("5"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::sixPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("6"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::sevenPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("7"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::eightPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("8"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::ninePress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("9"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::zeroPress() {
  if (answerShown)
    emit clearScreen();
  emit updateScreen(new QString("0"));
  operatorPressed = false;
  numberPressed = true;
}

void Buttons::decimalPress() {
  if (answerShown)
    emit clearScreen();
  if (!operatorPressed)
    emit updateScreen(new QString("."));
  operatorPressed = true;
  numberPressed = false;
}

void Buttons::equalPress() {
  emit showAnswer();
}

void Buttons::clearPress() {
  emit clearScreen();
}

void Buttons::backPress() {
  if (answerShown)
    emit clearScreen();
  emit backSpace();
}