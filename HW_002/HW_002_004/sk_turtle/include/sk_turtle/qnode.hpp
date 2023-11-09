/**
 * @file /include/sk_turtle/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sk_turtle_QNODE_HPP_
#define sk_turtle_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include "geometry_msgs/Twist.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sk_turtle
{
  /*****************************************************************************
  ** Class
  *****************************************************************************/

  class QNode : public QThread
  {
    Q_OBJECT
  public:
    QNode(int argc, char** argv);
    virtual ~QNode();
    bool init();
    void run();

    void go();
    void back();
    void left();
    void right();
    void stop();

  Q_SIGNALS:
    void rosShutdown();

  private:
    int init_argc;
    char** init_argv;
  };

}  // namespace s

#endif /* sk_turtle_QNODE_HPP_ */
