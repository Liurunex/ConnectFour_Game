#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "new_window.h"    //包含头文件
  namespace Ui
 {
  class Widget;
 }

  class Widget : public QWidget
{
  Q_OBJECT

  public:
  Widget(QWidget *parent = 0);
  ~Widget();

  private:
  Ui::Widget *ui;
  xyDlg xy2;       //对my2进行定义
  private slots:
  void on_pushButton_clicked();
  };

 #endif // WIDGET_H
