#include "userregister.h"
#include"image.h"
#include<QImageReader>
UserRegister::UserRegister(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//ui.m_lbImage->setImage(":/menu/Resources/default_user_image.jpg");
	QImageReader ir(":/menu/Resources/default_user_image.jpg");
	QPixmap image = QPixmap::fromImageReader(&ir);
	ui.m_lbImage-> setPixmap(image.scaled(ui.m_lbImage->size()));
}

UserRegister::~UserRegister()
{
}
