#include <QTcpServer>
#include <QTcpSocket>
#include <QtSql>
#include <QUuid>
#include <QTabwidget>
#include <QGridLayout>

#include "qtnetworkserver.h"
#include "command.h"
using namespace std;
QtNetworkServer::QtNetworkServer(QWidget *parent)
	: QMainWindow(parent), m_tcpServer(0), database(0)
{
	ui.setupUi(this);
	ui.m_btSend->setDisabled(true);
	QObject::connect(ui.m_btStart, SIGNAL(clicked()), this, SLOT(OnStartClick()));
	QObject::connect(ui.m_btSend, SIGNAL(clicked()), this, SLOT(OnSendClick()));

	QWidget *center = new QWidget(this);
	this->setCentralWidget(center);
	QGridLayout * grid = new QGridLayout;
	grid->setColumnStretch(1, 2);
	center->setLayout(grid);


	grid->addWidget(ui.lwUsers, 0, 0, 1, 1);
	grid->addWidget(ui.lineEdit, 1, 0, 1, 2);
	grid->addWidget(ui.m_btSend, 1, 2, 1, 1);
	grid->addWidget(ui.m_btStart, 1, 3, 1, 1);
	QTabWidget* tab = new QTabWidget;
	grid->addWidget(tab, 0, 1, 1, 3);


	database -> QSqlDatabase::addDatabase("QMYSQL");
	database->setHostName("127.0.0.1");
	database->setDatabaseName("infor");
	database->setUserName("root");
	database->setPassword("123");
	if (!database->open())
	{
		return;
	}

	QSqlQuery query;
	query.prepare("select * from users;");
	if (query.exec())
	{
		while (query.exec())
		{
			while (query.next())
			{
				QString name = query.value("name").toString();
				QListWidgetItem* item = new QListWidgetItem(ui.lwUsers);
				item->setText(name);
				QPixmap pix;
				QByteArray bytes = query.value("img").toByteArray();

#ifdef _DEBUG
				QFile file("d:\\tupian\\1.jpg");
				file.open(QFile::WriteOnly);
				file.write(bytes);
				file.close();
#endif
				if (pix.loadFromData(bytes))
				{
					QIcon icon(pix);
					item->setIcon(icon);
				}

			}
		}
	}

}
void QtNetworkServer::OnStartClick()
{
	QTcpSocket* client = m_tcpServer->nextPendingConnection();

	if (m_tcpServer == 0)
	{
		m_tcpServer = new QTcpServer(this);
		QObject::connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));

	}

	if (!m_tcpServer->listen(QHostAddress::Any, 8001))
	{
		return;
	}
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(OnClientReadyRead()));
	ui.m_btStart->setText("started");
	ui.m_btStart->setDisabled(true);
}

void QtNetworkServer::OnNewConnection()
{
	QTcpSocket* client = m_tcpServer->nextPendingConnection();

	if (client == 0)
	{
		return;
	}
	ui.m_btSend->setEnabled(true);

	m_clients.push_back(client);
	m_clientBuffs.insert(std::pair<QTcpSocket*, std::string*>(client, new string));

}

void QtNetworkServer::OnSendClick()
{
	for (std::list<QTcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); it++)
	{
		QTcpSocket* socket = *it;
		if (socket->state() == QAbstractSocket::UnconnectedState)
		{
			it = m_clients.erase(it);
			string* value = m_clientBuffs[*it];
			m_clientBuffs.erase(*it);
			delete value;
			delete socket;
			continue;
		}

		socket->write(QByteArray::fromStdString(ui.lineEdit->text().toStdString()));
	}
}
void QtNetworkServer::OnClientReadyRead()
{
	for (std::list<QTcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); it++)
	{
		QTcpSocket* socket = *it;
		if (!socket->isReadable())
		{
			continue;
		}
		QByteArray bytes = socket->readAll();
		string* buff = m_clientBuffs[socket];
		buff->append(bytes.toStdString());
		Package*  package;
		package->from_data(*buff);
		CommandRegister* cmd = ( CommandRegister*)(package->getCmd());
		if (cmd == 0)
		{
			continue;
		}

#ifdef _DEBUG
		QFile file("d:\\tupian\\1.jpg");
		file.open(QFile::WriteOnly);
		file.write(cmd->img.data(), cmd->img.length());
		file.close();
#endif
		if (!database->isOpen() && !database->open())
		{
			continue;
		}
		QSqlQuery query;
		query.prepare("insert into user(id,name,password,img) values(:id,:name,:password,:img);");
		query.bindValue(":id", QUuid().toString());
		query.bindValue(":name", cmd->name.c_str());
		query.bindValue(":password", cmd->password.c_str());
		query.bindValue(":img", QByteArray::fromStdString(cmd->img));

		if (!query.exec())
		{
			qDebug() << query.lastError();
		}
	
	}
}

