#pragma once

#include <QLabel>

class Image : public QLabel
{
	Q_OBJECT

public:
	Image(QWidget *parent);
	~Image();
	void setImage(const QString& file);
protected:
	void mousePressEvent(QMouseEvent *event);
};
