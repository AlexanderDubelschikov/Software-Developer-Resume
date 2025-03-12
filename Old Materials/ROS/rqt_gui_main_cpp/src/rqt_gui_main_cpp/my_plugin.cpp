#include "rqt_gui_main_cpp/my_plugin.h"
#include <pluginlib/class_list_macros.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Char.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMessageBox>
#include <QPainter>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QApplication>
#include <ros/ros.h>
#include <QNetworkAccessManager>
#include <QTcpSocket>
#include <iostream>
#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <visualization_msgs/Marker.h>
#include <QWidget>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include<rviz/tool.h>

namespace rqt_gui_main_cpp
{
QGraphicsPixmapItem pixmap;
cv::VideoCapture video;

QByteArray data;

MyPlugin::MyPlugin()
  : rqt_gui_cpp::Plugin()
  , widget_(0)
{
  setObjectName("Main Window");
}

void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
  widget_ = new QWidget();
  ui_.setupUi(widget_);
  context.addWidget(widget_);

  pub = nh.advertise<std_msgs::Char>("gui_topic", 10);
  

  updateTopicList();
  ui_.leaderBox->setCurrentIndex(ui_.leaderBox->findText(""));
  connect(ui_.leaderBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged1(int)));
  ui_.observerBox->setCurrentIndex(ui_.observerBox->findText(""));
  connect(ui_.observerBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged2(int)));
  ui_.leaderBox_2->setCurrentIndex(ui_.leaderBox_2->findText(""));
  connect(ui_.leaderBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged3(int)));
  ui_.leaderBox_3->setCurrentIndex(ui_.leaderBox_3->findText(""));
  connect(ui_.leaderBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged4(int)));
  ui_.leaderBox_4->setCurrentIndex(ui_.leaderBox_4->findText(""));
  connect(ui_.leaderBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged5(int)));
  ui_.leaderBox_5->setCurrentIndex(ui_.leaderBox_5->findText(""));
  connect(ui_.leaderBox_5, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged6(int)));
  ui_.leaderBox_5->setHidden(true);
  ui_.imageFrameLA->setHidden(true);

  connect(ui_.takeoffButt, SIGNAL(pressed()), this, SLOT(onTakeoff()));
  connect(ui_.landButt, SIGNAL(pressed()), this, SLOT(onLand()));
  connect(ui_.upButt, SIGNAL(pressed()), this, SLOT(onUp()));
  connect(ui_.downButt, SIGNAL(pressed()), this, SLOT(onDown()));
  connect(ui_.yawLButt, SIGNAL(pressed()), this, SLOT(onYawL()));
  connect(ui_.yawRButt, SIGNAL(pressed()), this, SLOT(onYawR()));
  connect(ui_.frwButt, SIGNAL(pressed()), this, SLOT(onFrw()));
  connect(ui_.backButt, SIGNAL(pressed()), this, SLOT(onBack()));
  connect(ui_.rollRButt, SIGNAL(pressed()), this, SLOT(onRollR()));
  connect(ui_.rollLButt, SIGNAL(pressed()), this, SLOT(onRollL()));
  
  ui_.imageFrameLF->setOuterLayout(ui_.imageLayoutLF);
  ui_.imageFrameOF->setOuterLayout(ui_.imageLayoutOF);
  ui_.imageFrameLL->setOuterLayout(ui_.imageLayoutLL);
  ui_.imageFrameNB->setOuterLayout(ui_.imageLayoutNB);
  ui_.imageFrameIC->setOuterLayout(ui_.imageLayoutIC);
  ui_.imageFrameLA->setOuterLayout(ui_.imageLayoutLA);


  ui_.graphicsView->setScene(new QGraphicsScene(this));
  ui_.graphicsView->scene()->addItem(&pixmap);
  connect(ui_.startBtn, SIGNAL(pressed()), this, SLOT(on_startBtn_pressed()));
  rviz::RenderPanel *render_panel_= new rviz::RenderPanel;

          // Установить макет

     ui_.mainLayout->addWidget(render_panel_);
          // Инициализировать объект управления RVIZ
     rviz::VisualizationManager* manager_ = new rviz::VisualizationManager(render_panel_);
          // Инициализировать камеру эту строку кода для достижения масштабирования, сокращения, перевода и других операций
     render_panel_->initialize(manager_->getSceneManager(),manager_);

     //показывать
manager_->initialize();
manager_->removeAllDisplays();
manager_->startUpdate();

     // Установите настройки параметра левого теста RVIZ
manager_->setFixedFrame("/map");

     // Создать слой rviz/pointcloud2, который используется для получения данных облака точек в качестве points_map. Это слой моей конечной базовой карты
rviz::Display *map_=manager_->createDisplay("rviz/Pose","Pose",true);

map_->subProp("Topic")->setValue("/mavros/local_position/pose");
map_->subProp("Unreliable")->setValue("false");
map_->subProp("Queue Size")->setValue("10");
map_->subProp("Alpha")->setValue("1");

rviz::Display *ma_=manager_->createDisplay("rviz/Map","Map",true);

    ma_->subProp("Topic")->setValue("/map");

  QRegExp rx("([a-zA-Z/][a-zA-Z0-9_/]*)?");
}

void MyPlugin::on_startBtn_pressed()
{
    using namespace cv;

    if(video.isOpened())
    {
        ui_.startBtn->setText("Start");
        video.release();
        return;
    }

    bool isCamera;
    int cameraIndex = ui_.videoEdit->text().toInt(&isCamera);
    if(isCamera)
    {
        if(!video.open(cameraIndex))
        {

            return;
        }
    }
    else
    {
        if(!video.open(ui_.videoEdit->text().trimmed().toStdString()))
        {

            return;
        }
    }

    ui_.startBtn->setText("Stop");

    Mat frame;
    while(video.isOpened())
    {
        video >> frame;
        if(!frame.empty())
        {
            /*copyMakeBorder(frame,
                           frame,
                           frame.rows/16,
                           frame.rows/16,
                           frame.cols/16,
                           frame.cols/16,
                           BORDER_REFLECT);*/

            QImage qimg(frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_RGB888);
            pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
            ui_.graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }

    ui_.startBtn->setText("Start");
}

void MyPlugin::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        event->ignore();
    }
    else
    {
        event->accept();
    }
}



void MyPlugin::shutdownPlugin() {
  subscriber1_.shutdown();
  subscriber2_.shutdown();
  subscriber3_.shutdown();
  subscriber4_.shutdown();
  subscriber5_.shutdown();
  subscriber6_.shutdown();

  pub.shutdown();
}

void MyPlugin::onLand() {
  std_msgs::Char msg;
  //msg.data = 'h'; //k
  msg.data = 'g';
  pub.publish(msg);
}

void MyPlugin::onTakeoff() {
  std_msgs::Char msg;
  msg.data = 't';
  pub.publish(msg);
}

void MyPlugin::onUp() {
  std_msgs::Char msg;
  msg.data = 'q';
  pub.publish(msg);
}

void MyPlugin::onDown() {
  std_msgs::Char msg;
  msg.data = 'z';
  pub.publish(msg);
}

void MyPlugin::onYawL() {
  std_msgs::Char msg;
  msg.data = 'j';
  pub.publish(msg);
}

void MyPlugin::onYawR() {
  std_msgs::Char msg;
  msg.data = 'l';
  pub.publish(msg);
}

void MyPlugin::onFrw() {
  std_msgs::Char msg;
  msg.data = 'i';
  pub.publish(msg);
}

void MyPlugin::onBack() {
  std_msgs::Char msg;
  msg.data = ',';
  pub.publish(msg);
}

void MyPlugin::onRollL() {
  std_msgs::Char msg;
  msg.data = 'o';
  pub.publish(msg);
}

void MyPlugin::onRollR() {
  std_msgs::Char msg;
  msg.data = 'u';
  pub.publish(msg);
}

void MyPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings,
    qt_gui_cpp::Settings& instance_settings) const
{
  QString topic1 = ui_.leaderBox->currentText();
  instance_settings.setValue("topic1", topic1);
  QString topic2 = ui_.observerBox->currentText();
  instance_settings.setValue("topic2", topic2);
  QString topic3 = ui_.leaderBox_2->currentText();
  instance_settings.setValue("topic3", topic3);
  QString topic4 = ui_.leaderBox_3->currentText();
  instance_settings.setValue("topic4", topic4);
  QString topic5 = ui_.leaderBox_4->currentText();
  instance_settings.setValue("topic5", topic5);
  QString topic6 = ui_.leaderBox_5->currentText();
  instance_settings.setValue("topic6", topic6);
}

void MyPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
    const qt_gui_cpp::Settings& instance_settings)
{
  QString topic1 = instance_settings.value("topic1", "").toString();
  selectTopic1(topic1);
  QString topic2 = instance_settings.value("topic2", "").toString();
  selectTopic2(topic2);
  QString topic3 = instance_settings.value("topic3", "").toString();
  selectTopic3(topic3);
  QString topic4 = instance_settings.value("topic4", "").toString();
  selectTopic4(topic4);
  QString topic5 = instance_settings.value("topic5", "").toString();
  selectTopic5(topic5);
  QString topic6 = instance_settings.value("topic6", "").toString();
  selectTopic6(topic6);
}

void MyPlugin::updateTopicList()
{
  QSet<QString> message_types;
  message_types.insert("sensor_msgs/Image");
  //QSet<QString> message_sub_types;
  //message_sub_types.insert("sensor_msgs/CompressedImage");

  // get declared transports
  QList<QString> transports;
  image_transport::ImageTransport it(getNodeHandle());
  std::vector<std::string> declared = it.getDeclaredTransports();
  for (std::vector<std::string>::const_iterator it = declared.begin(); it != declared.end(); it++)
  {
    QString transport = it->c_str();

    // strip prefix from transport name
    QString prefix = "image_transport/";
    if (transport.startsWith(prefix))
    {
      transport = transport.mid(prefix.length());
    }
    transports.append(transport);
  }

  QString selected1 = ui_.leaderBox->currentText();
  QString selected2 = ui_.observerBox->currentText();
  QString selected3 = ui_.leaderBox_2->currentText();
  QString selected4 = ui_.leaderBox_3->currentText();
  QString selected5 = ui_.leaderBox_4->currentText();
  QString selected6 = ui_.leaderBox_5->currentText();

  // fill combo box
  QList<QString> topics = getTopics(message_types, /*message_sub_types,*/ transports).values();
  topics.append("");
  qSort(topics);
  ui_.leaderBox->clear();
  ui_.observerBox->clear();
  ui_.leaderBox_2->clear();
  ui_.leaderBox_3->clear();
  ui_.leaderBox_4->clear();
  ui_.leaderBox_5->clear();
  for (QList<QString>::const_iterator it = topics.begin(); it != topics.end(); it++)
  {
    QString label(*it);
    label.replace(" ", "/");
    ui_.leaderBox->addItem(label, QVariant(*it));
    ui_.observerBox->addItem(label, QVariant(*it));
    ui_.leaderBox_2->addItem(label, QVariant(*it));
    ui_.leaderBox_3->addItem(label, QVariant(*it));
    ui_.leaderBox_4->addItem(label, QVariant(*it));
    ui_.leaderBox_5->addItem(label, QVariant(*it));
  }

  // restore previous selection
  selectTopic1(selected1);
  selectTopic2(selected2);
  selectTopic3(selected3);
  selectTopic4(selected4);
  selectTopic5(selected5);
  selectTopic6(selected6);
}

QSet<QString> MyPlugin::getTopics(const QSet<QString>& message_types, /*const QSet<QString>& message_sub_types,*/ const QList<QString>& transports)
{
  ros::master::V_TopicInfo topic_info;
  ros::master::getTopics(topic_info);

  QSet<QString> all_topics;
  for (ros::master::V_TopicInfo::const_iterator it = topic_info.begin(); it != topic_info.end(); it++)
  {
    all_topics.insert(it->name.c_str());
  }

  QSet<QString> topics;
  for (ros::master::V_TopicInfo::const_iterator it = topic_info.begin(); it != topic_info.end(); it++)
  {
    if (message_types.contains(it->datatype.c_str()))
    {
      QString topic = it->name.c_str();

      // add raw topic
      topics.insert(topic);

      // add transport specific sub-topics
      /*for (QList<QString>::const_iterator jt = transports.begin(); jt != transports.end(); jt++)
      {
        if (all_topics.contains(topic + "/" + *jt))
        {
          QString sub = topic + " " + *jt;
          topics.insert(sub);
        }
      }*/
    }
    /*if (message_sub_types.contains(it->datatype.c_str()))
    {
      QString topic = it->name.c_str();
      int index = topic.lastIndexOf("/");
      if (index != -1)
      {
        topic.replace(index, 1, " ");
        topics.insert(topic);
      }
    }*/
  }
  return topics;
}

void MyPlugin::selectTopic1(const QString& topic)
{
  int index = ui_.leaderBox->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.leaderBox->addItem(label, QVariant(topic));
    index = ui_.leaderBox->findText(topic);
  }
  ui_.leaderBox->setCurrentIndex(index);
}

void MyPlugin::selectTopic2(const QString& topic)
{
  int index = ui_.observerBox->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.observerBox->addItem(label, QVariant(topic));
    index = ui_.observerBox->findText(topic);
  }
  ui_.observerBox->setCurrentIndex(index);
}

void MyPlugin::selectTopic3(const QString& topic)
{
  int index = ui_.leaderBox_2->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.leaderBox_2->addItem(label, QVariant(topic));
    index = ui_.leaderBox_2->findText(topic);
  }
  ui_.leaderBox_2->setCurrentIndex(index);
}

void MyPlugin::selectTopic4(const QString& topic)
{
  int index = ui_.leaderBox_3->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.leaderBox_3->addItem(label, QVariant(topic));
    index = ui_.leaderBox_3->findText(topic);
  }
  ui_.leaderBox_3->setCurrentIndex(index);
}

void MyPlugin::selectTopic5(const QString& topic)
{
  int index = ui_.leaderBox_4->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.leaderBox_4->addItem(label, QVariant(topic));
    index = ui_.leaderBox_4->findText(topic);
  }
  ui_.leaderBox_4->setCurrentIndex(index);
}

void MyPlugin::selectTopic6(const QString& topic)
{
  int index = ui_.leaderBox_5->findText(topic);
  if (index == -1)
  {
    // add topic name to list if not yet in
    QString label(topic);
    label.replace(" ", "/");
    ui_.leaderBox_5->addItem(label, QVariant(topic));
    index = ui_.leaderBox_5->findText(topic);
  }
  ui_.leaderBox_5->setCurrentIndex(index);
}

void MyPlugin::onTopicChanged1(int index)
{
  conversion_mat1_.release();

  subscriber1_.shutdown();

  // reset image on topic change
  ui_.imageFrameLF->setImage(QImage());

  QStringList parts = ui_.leaderBox->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber1_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage1, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}

void MyPlugin::onTopicChanged2(int index)
{
  conversion_mat2_.release();

  subscriber2_.shutdown();

  // reset image on topic change
  ui_.imageFrameOF->setImage(QImage());

  QStringList parts = ui_.observerBox->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber2_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage2, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}

void MyPlugin::onTopicChanged3(int index)
{
  conversion_mat3_.release();

  subscriber3_.shutdown();

  // reset image on topic change
  ui_.imageFrameLL->setImage(QImage());

  QStringList parts = ui_.leaderBox_2->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber3_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage3, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}

void MyPlugin::onTopicChanged4(int index)
{
  conversion_mat4_.release();

  subscriber4_.shutdown();

  // reset image on topic change
  ui_.imageFrameNB->setImage(QImage());

  QStringList parts = ui_.leaderBox_3->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber4_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage4, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}

void MyPlugin::onTopicChanged5(int index)
{
  conversion_mat5_.release();

  subscriber5_.shutdown();

  // reset image on topic change
  ui_.imageFrameIC->setImage(QImage());

  QStringList parts = ui_.leaderBox_4->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber5_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage5, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}

void MyPlugin::onTopicChanged6(int index)
{
  conversion_mat6_.release();

  subscriber6_.shutdown();

  // reset image on topic change
  ui_.imageFrameLA->setImage(QImage());

  QStringList parts = ui_.leaderBox_5->itemData(index).toString().split(" ");
  QString topic = parts.first();
  QString transport = parts.length() == 2 ? parts.last() : "raw";

  if (!topic.isEmpty())
  {
    image_transport::ImageTransport it(getNodeHandle());
    image_transport::TransportHints hints(transport.toStdString());
    try {
      subscriber6_ = it.subscribe(topic.toStdString(), 1, &MyPlugin::callbackImage6, this, hints);
    } catch (image_transport::TransportLoadException& e) {
      QMessageBox::warning(widget_, tr("Loading image transport plugin failed"), e.what());
    }
  }
}
/*void MyPlugin::saveImage()
{
  // take a snapshot before asking for the filename
  QImage img = ui_.imageFrameLF->getImageCopy();

  QString file_name = QFileDialog::getSaveFileName(widget_, tr("Save as image"), "image.png", tr("Image (*.bmp *.jpg *.png *.tiff)"));
  if (file_name.isEmpty()) return;
  img.save(file_name);
}*/

void MyPlugin::invertPixels1(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat1_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::invertPixels2(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat2_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::invertPixels3(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat3_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::invertPixels4(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat4_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::invertPixels5(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat5_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::invertPixels6(int x, int y)
{
  cv::Vec3b & pixel = conversion_mat6_.at<cv::Vec3b>(cv::Point(x, y));
  if (pixel[0] + pixel[1] + pixel[2] > 3 * 127)
    pixel = cv::Vec3b(0,0,0);
  else
    pixel = cv::Vec3b(255,255,255);
}

void MyPlugin::callbackImage1(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat1_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat1_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat1_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image1() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameLF->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image1() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameLF->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat1_.data, conversion_mat1_.cols, conversion_mat1_.rows, conversion_mat1_.step[0], QImage::Format_RGB888);
  ui_.imageFrameLF->setImage(image);
}

void MyPlugin::callbackImage2(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat2_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat2_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat2_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image2() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameOF->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image2() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameOF->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat2_.data, conversion_mat2_.cols, conversion_mat2_.rows, conversion_mat2_.step[0], QImage::Format_RGB888);
  ui_.imageFrameOF->setImage(image);
}

void MyPlugin::callbackImage3(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat3_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat3_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat3_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image1() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameLL->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image1() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameLL->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat3_.data, conversion_mat3_.cols, conversion_mat3_.rows, conversion_mat3_.step[0], QImage::Format_RGB888);
  ui_.imageFrameLL->setImage(image);
}

void MyPlugin::callbackImage4(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat4_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat4_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat4_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image1() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameNB->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image1() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameNB->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat4_.data, conversion_mat4_.cols, conversion_mat4_.rows, conversion_mat4_.step[0], QImage::Format_RGB888);
  ui_.imageFrameNB->setImage(image);
}

void MyPlugin::callbackImage5(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat5_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat5_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat5_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image1() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameIC->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image1() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameIC->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat5_.data, conversion_mat5_.cols, conversion_mat5_.rows, conversion_mat5_.step[0], QImage::Format_RGB888);
  ui_.imageFrameIC->setImage(image);
}

void MyPlugin::callbackImage6(const sensor_msgs::Image::ConstPtr& msg)
{
  try
  {
    // First let cv_bridge do its magic
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
    conversion_mat6_ = cv_ptr->image;
  }
  catch (cv_bridge::Exception& e)
  {
    try
    {
      // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
      cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
      if (msg->encoding == "CV_8UC3")
      {
        // assuming it is rgb
        conversion_mat6_ = cv_ptr->image;
      } else if (msg->encoding == "8UC1") {
        // convert gray to rgb
        cv::cvtColor(cv_ptr->image, conversion_mat6_, CV_GRAY2RGB);
      } else {
        qWarning("MyPlugin.callback_image1() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
        ui_.imageFrameLA->setImage(QImage());
        return;
      }
    }
    catch (cv_bridge::Exception& e)
    {
      qWarning("MyPlugin.callback_image1() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
      ui_.imageFrameLA->setImage(QImage());
      return;
    }
  }
  // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
  QImage image(conversion_mat6_.data, conversion_mat6_.cols, conversion_mat6_.rows, conversion_mat6_.step[0], QImage::Format_RGB888);
  ui_.imageFrameLA->setImage(image);
}

}  // namespace
PLUGINLIB_EXPORT_CLASS(rqt_gui_main_cpp::MyPlugin, rqt_gui_cpp::Plugin)
