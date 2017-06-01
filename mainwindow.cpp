#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MULT 10
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //intelasation LCD
    image = QImage (128*MULT,64*MULT, QImage::Format_RGB32);

    std::vector <pins> array;
    array.resize(1);
    for (int i=0; i<array.size(); i++){
        lcd.handle(array[i],std::bind(&MainWindow::setPixel,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPixel (int x, int y, bool i){
    if (i){
        for(int x1=x*MULT;x1<(x+1)*MULT;x1++)
            for(int y1=y*MULT;y1<(y+1)*MULT;y1++)
                image.setPixel(x1,y1,qRgb(255, 255, 255));
    }else{
        for(int x1=x*MULT;x1<(x+1)*MULT;x1++)
            for(int y1=y*MULT;y1<(y+1)*MULT;y1++)
                image.setPixel(x1,y1,qRgb(0, 0, 0));
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

