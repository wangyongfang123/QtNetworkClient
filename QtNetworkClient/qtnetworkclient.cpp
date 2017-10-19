#include "qtnetworkclient.h"
#include"userregister.h"
#include"userlogin.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <string>
using namespace std;
QtNetworkClient::QtNetworkClient(QWidget *parent)
	: QMainWindow(parent), m_socket(0),m_userRegister(0),m_userLogin(0)
{
	ui.setupUi(this);
	QObject::connect(ui.m_btConnect, SIGNAL(clicked()), this, SLOT(OnConnectClick()));
	m_userRegister = new UserRegister(this);
	connect(ui.m_acRegisterUser, &QAction::triggered, m_userRegister, &UserRegister::exec);
	ui.m_acRegisterUser->setIcon(QIcon(":/menu/Resources/Register.jpg"));
	m_userLogin = new UserLogin(this);
	//QAction *action = ui.m_menuser->addAction("Login");
	ui.m_acLoginUser->setIcon(QIcon(":/menu/Resources/Login.jpg"));
	connect(ui.m_acLoginUser, &QAction::triggered, m_userLogin, &UserLogin::exec);

}
void QtNetworkClient::OnConnectClick()
{
	if (m_socket == 0)
	{
		m_socket = new QTcpSocket;
		QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(OnConnected()));
		QObject::connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnSocketError(QAbstractSocket::SocketError)));
		QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(OnDataReadyRead()));
	}

	m_socket->connectToHost("127.0.0.1", 8001);

	ui.m_btConnect->setDisabled(true);
	ui.m_btConnect->setText("connectiong...");

}

void QtNetworkClient::OnConnected()
{
	ui.m_btConnect->setText("connected");
}

void QtNetworkClient::OnSocketError(QAbstractSocket::SocketError error)
{
	ui.m_btConnect->setEnabled(true);
	ui.m_btConnect->setText("connect");
}

void QtNetworkClient::OnDataReadyRead()
{
	QByteArray data = m_socket->readAll();
	ui.m_lwMessages->addItem(data);
}
