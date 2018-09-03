#include "grayStyle.h"

void QGrayStyle::polish(QPalette &palette)
{
   	QLinearGradient widgetsBckGrnd(m_gradientStart,m_gradientFinalStop);
   	widgetsBckGrnd.setColorAt(0, QColor("#DDDDDD"));
   	widgetsBckGrnd.setColorAt(1, QColor("#F7F7F7"));

   	palette.setBrush(QPalette::Base, widgetsBckGrnd);
   	palette.setBrush(QPalette::Background, widgetsBckGrnd);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::HighlightedText, Qt::black);
   	palette.setColor(QPalette::Highlight, QColor("#CCCCCC"));
}

void QGrayStyle::polish(QApplication *app)
{
  if (!app) return;
  QFile qfDarkstyle(QStringLiteral(":/styleSheet/grayStyle.qss"));
  if (qfDarkstyle.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QString qsStylesheet = QString::fromLatin1(qfDarkstyle.readAll());
    app->setStyleSheet(qsStylesheet);
    qfDarkstyle.close();
  }
}
