#include "userlogin.h"
#include"image.h"
#include<QImageReader>
UserLogin::UserLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QImageReader ir(":/menu/Resources/default_user_image.jpg");
	QPixmap image = QPixmap::fromImageReader(&ir);
	ui.m_Image->setPixmap(image.scaled(ui.m_Image->size()));
}

UserLogin::~UserLogin()
{
}
