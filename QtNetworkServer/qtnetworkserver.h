#pragma once
#include <list>
#include <map>
#include <string>
#include <QtWidgets/QMainWindow>
#include "ui_qtnetworkserver.h"

class QTcpServer;
class QTcpSocket;

class QtNetworkServer : public QMainWindow
{
	Q_OBJECT

public:
	QtNetworkServer(QWidget *parent = Q_NULLPTR);
private slots:
	void OnStartClick();
	void OnNewConnection();
	void OnSendClick();
	void OnClientReadyRead();
private:
	Ui::QtNetworkServerClass ui;
	QTcpServer* m_tcpServer;
	std::list<QTcpSocket*> m_clients;
	std::map<QTcpSocket*, std::string*> m_clientBuffs;
};
