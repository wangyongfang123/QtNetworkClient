#include "userregister.h"
#include"image.h"
#include"command.h"
#include<QImageReader>
#include<QFile>
UserRegister::UserRegister(QWidget *parent)
	: QDialog(parent),cmd(0)
{
	ui.setupUi(this);
	//ui.m_lbImage->setImage(":/menu/Resources/default_user_image.jpg");
	QImageReader ir(":/menu/Resources/default_user_image.jpg");
	QPixmap image = QPixmap::fromImageReader(&ir);
	ui.m_lbImage-> setPixmap(image.scaled(ui.m_lbImage->size()));
	QObject::connect(ui.pbRegister, SIGNAL(clicked()), this, SLOT(OnRegister()));
}

UserRegister::~UserRegister()
{
	if (cmd != 0)
	{
		delete cmd;
	}
}
CommandRegister* UserRegister::message()
{
	if (cmd)
	{
		delete cmd;
	}
	cmd = new CommandRegister;
	cmd->name = ui.leName->text().toStdString();
	cmd->password = ui.lePassword1->text().toStdString();
	cmd->information = ui.leInformation->toPlainText().toStdString();
	const QString& fileName = ui.m_lbImage->getImage();
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
	{
		QByteArray bytes = file.readAll();
		cmd->img = bytes.toStdString();
		
	}
	else
	{
		delete cmd;
		cmd = 0;
	}
	return cmd;
}
void UserRegister::OnRegister()
{
	emit userRegister();
}
