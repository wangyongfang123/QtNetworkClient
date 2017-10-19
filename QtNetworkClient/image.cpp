#include "image.h"
#include<QFileDialog>
#include<QImageReader>
#include<QLabel>
Image::Image(QWidget *parent)
	: QLabel(parent)
{
}

Image::~Image()
{
}

void Image::setImage(const QString & file)
{
	QImageReader ir(file);
	QPixmap image = QPixmap::fromImageReader(&ir);
	this->setPixmap(image.scaled(this->size()));

}
void Image::mousePressEvent(QMouseEvent *event)
{
	QLabel::mousePressEvent(event);
	QFileDialog dialog(this);
	dialog.setNameFilter("Images(*.png *.xpm *.jpg)");
	dialog.setViewMode(QFileDialog::Detail);
	if (dialog.exec() == QDialog::Rejected)
	{
		return;
	}
	QStringList files = dialog.selectedFiles();
	/*QImageReader ir(*files.begin());
	QPixmap image = QPixmap::fromImageReader(&r);
	this->setPixmap(image.scaled(this->size()));*/
	setImage(*files.begin());
}