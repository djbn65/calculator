#pragma once
#include <QMainWindow>
#include <QTextEdit>
#include <QApplication>
#include <QtWidgets>
#include "buttons.h"

class Calculator : public QMainWindow
{
  Q_OBJECT

  public:
    Calculator();

  private slots:
    void showCalc(QString* update);
    void back();
    void clear();
    void equals();
    void quit();

  private:
    QVBoxLayout* layout;
    Buttons* buttons;
    QTextEdit* display;
    QAction* quitAction;
    QMenuBar* fileMenu;
};