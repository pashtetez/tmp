#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QImage>

#include "lcd.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    LCD lcd;
    QImage image;
    void setPixel (int x, int y, bool i);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
