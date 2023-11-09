/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/sk_turtle/main_window.hpp"
#include "geometry_msgs/Twist.h"
#include "QKeyEvent"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sk_turtle
{
  using namespace Qt;

  /*****************************************************************************
  ** Implementation [MainWindow]
  *****************************************************************************/

  MainWindow::MainWindow(int argc, char** argv, QWidget* parent) : QMainWindow(parent), qnode(argc, argv)
  {
    ui.setupUi(this);  // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    qnode.init();
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
  }



  
  MainWindow::~MainWindow()
  { 
    
  }

 void MainWindow::keyPressEvent(QKeyEvent *event){

 if (event->key()=='A'){qnode.left();} 
 else if(event->key()=='D'){qnode.right();}
 else if(event->key()=='S'){qnode.back();}
 else if(event->key()=='W'){ qnode.go();}
 }


void MainWindow::on_go_clicked(){
    qnode.go();
}

void MainWindow::on_stop_clicked(){
  qnode.stop();
}

void MainWindow::on_back_clicked(){
  qnode.back();

}

void MainWindow::on_right_clicked(){
      qnode.right();

}

void MainWindow::on_left_clicked(){
      qnode.left();
 }
  /*****************************************************************************
  ** Functions
  *****************************************************************************/

}  // namespace s
