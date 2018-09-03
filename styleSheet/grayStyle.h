/*
###############################################################################
#                                                                             #                                                           #                                                                             #
# Copyright (C) 2018 by Ali Ajorian: arastoo.ajorian@gmail.com                #
#                                                                             #
###############################################################################
*/

#ifndef __GRAY_STYLE_AJR_H__
#define __GRAY_STYLE_AJR_H__

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFont>
#include <QFile>

class QGrayStyle : public QProxyStyle
{
  Q_OBJECT

public:
	QGrayStyle():QProxyStyle(styleBase()),m_gradientStart(0,0),m_gradientFinalStop(0,200){ }

	void setGradient(const QPointF & start, const QPointF& stop) { m_gradientStart = start; m_gradientFinalStop = stop; }
	QStyle *baseStyle() const{ return styleBase(); }
	void polish(QPalette &palette) override;
	void polish(QApplication *app) override;

private:
	QPointF m_gradientStart, m_gradientFinalStop;
	QStyle *styleBase(QStyle *style = 0) const{ return (style!=0) ? QStyleFactory::create(QStringLiteral("Windows")) : style; }
};

#endif
