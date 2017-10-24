#pragma once

#include <QDialog>
#include "ui_userregister.h"
#include "command.h"
class CommandRegister;
class  UserRegister : public QDialog
{
	Q_OBJECT

public:
	UserRegister(QWidget *parent = Q_NULLPTR);
	~UserRegister();
	CommandRegister* message();
private slots:
	void OnRegister();
Q_SIGNALS:
	void userRegister();

private:
	Ui::UserRegister ui;
	CommandRegister*  cmd;
};
