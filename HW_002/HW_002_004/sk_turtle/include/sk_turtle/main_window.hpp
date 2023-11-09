/**
 * @file /include/sk_turtle/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef sk_turtle_MAIN_WINDOW_H
#define sk_turtle_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "geometry_msgs/Twist.h"
#include "QKeyEvent"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace sk_turtle
{
  /*****************************************************************************
  ** Interface [MainWindow]
  *****************************************************************************/
  /**
   * @brief Qt central, all operations relating to the view part here.
   */
  class MainWindow : public QMainWindow
  {
    Q_OBJECT

  public:
    MainWindow(int argc, char** argv, QWidget* parent = 0);
    ~MainWindow();


   public Q_SLOTS: 
     void keyPressEvent(QKeyEvent *event);

     void on_go_clicked();
    
    void on_stop_clicked();
        
    void on_back_clicked();
    
    void on_right_clicked();
    
    void on_left_clicked();

  private:
    Ui::MainWindowDesign ui;
    QNode qnode;
  };

}  // namespace s

#endif  // sk_turtle_MAIN_WINDOW_H
