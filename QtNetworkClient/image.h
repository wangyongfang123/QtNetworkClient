#pragma once

#include <QLabel>
#include "command.h"
class Image : public QLabel
{
	Q_OBJECT

public:
	Image(QWidget *parent);
	~Image();
	void setImage(const QString& file);
	const QString& getImage() const;
protected:
	void mousePressEvent(QMouseEvent *event);
private:
	QString m_file;

};
