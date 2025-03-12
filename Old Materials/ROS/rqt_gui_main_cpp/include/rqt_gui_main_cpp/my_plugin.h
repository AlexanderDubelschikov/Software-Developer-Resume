#ifndef RQT_GUI_MAIN_CPP_MY_PLUGIN_H
#define RQT_GUI_MAIN_CPP_MY_PLUGIN_H

#include <rqt_gui_cpp/plugin.h>
#include <rqt_gui_main_cpp/ui_my_plugin.h>
#include <image_transport/image_transport.h>
#include <ros/package.h>
#include <ros/macros.h>
#include <ros/master.h>
#include <sensor_msgs/Image.h>
#include <geometry_msgs/Point.h>
#include <opencv2/core/core.hpp>
#include <QImage>
#include <QList>
#include <QString>
#include <QSet>
#include <QSize>
#include <QWidget>
#include <vector>
#include <QVideoWidget>
#include <QMediaPlayer>

namespace rqt_gui_main_cpp


{

class MyPlugin
  : public rqt_gui_cpp::Plugin
{
  Q_OBJECT
public:
  MyPlugin();
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings,
      qt_gui_cpp::Settings& instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
      const qt_gui_cpp::Settings& instance_settings);
      void tcpDataReceive();
      void on_pushButton_clicked();
      void closeEvent(QCloseEvent* event);
      

protected slots:
  virtual void updateTopicList();

protected:
  virtual QSet<QString> getTopics(const QSet<QString>& message_types, /*const QSet<QString>& message_sub_types,*/ const QList<QString>& transports);
  virtual void selectTopic1(const QString& topic);
  virtual void selectTopic2(const QString& topic);
  virtual void selectTopic3(const QString& topic);
  virtual void selectTopic4(const QString& topic);
  virtual void selectTopic5(const QString& topic);
  virtual void selectTopic6(const QString& topic);
  
protected slots:
  virtual void onTopicChanged1(int index);
  virtual void onTopicChanged2(int index);
  virtual void onTopicChanged3(int index);
  virtual void onTopicChanged4(int index);
  virtual void onTopicChanged5(int index);
  virtual void onTopicChanged6(int index);
  void on_startBtn_pressed();
  //virtual void saveImage();
  virtual void onLand();
  virtual void onTakeoff();
  virtual void onUp();
  virtual void onDown();
  virtual void onYawL();
  virtual void onYawR();
  virtual void onFrw();
  virtual void onBack();
  virtual void onRollL();
  virtual void onRollR();
  void slotEnter();       // Слот для обработки нажатия клавиши Enter
  void slotLinkClicked(QUrl url); // Слот для клика по ссылке на странице

protected:
  virtual void callbackImage1(const sensor_msgs::Image::ConstPtr& msg);
  virtual void callbackImage2(const sensor_msgs::Image::ConstPtr& msg);
  virtual void callbackImage3(const sensor_msgs::Image::ConstPtr& msg);
  virtual void callbackImage4(const sensor_msgs::Image::ConstPtr& msg);
  virtual void callbackImage5(const sensor_msgs::Image::ConstPtr& msg);
  virtual void callbackImage6(const sensor_msgs::Image::ConstPtr& msg);
  virtual void invertPixels1(int x, int y);
  virtual void invertPixels2(int x, int y);
  virtual void invertPixels3(int x, int y);
  virtual void invertPixels4(int x, int y);
  virtual void invertPixels5(int x, int y);
  virtual void invertPixels6(int x, int y);
  
private:
  Ui::MainWindow ui_;
  QWidget* widget_;
  image_transport::Subscriber subscriber1_, subscriber2_, subscriber3_, subscriber4_, subscriber5_, subscriber6_;
  cv::Mat conversion_mat1_, conversion_mat2_, conversion_mat3_, conversion_mat4_, conversion_mat5_, conversion_mat6_;
  ros::NodeHandle nh;
  ros::Publisher pub;
};
}  // namespace
#endif
