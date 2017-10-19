/********************************************************************************
** Form generated from reading UI file 'qtnetworkclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTNETWORKCLIENT_H
#define UI_QTNETWORKCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtNetworkClientClass
{
public:
    QAction *m_acRegisterUser;
    QAction *m_acLoginUser;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QPushButton *m_btConnect;
    QListWidget *m_lwMessages;
    QMenuBar *menuBar;
    QMenu *m_menuser;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtNetworkClientClass)
    {
        if (QtNetworkClientClass->objectName().isEmpty())
            QtNetworkClientClass->setObjectName(QStringLiteral("QtNetworkClientClass"));
        QtNetworkClientClass->resize(600, 400);
        m_acRegisterUser = new QAction(QtNetworkClientClass);
        m_acRegisterUser->setObjectName(QStringLiteral("m_acRegisterUser"));
        m_acLoginUser = new QAction(QtNetworkClientClass);
        m_acLoginUser->setObjectName(QStringLiteral("m_acLoginUser"));
        centralWidget = new QWidget(QtNetworkClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 120, 113, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(80, 120, 46, 22));
        m_btConnect = new QPushButton(centralWidget);
        m_btConnect->setObjectName(QStringLiteral("m_btConnect"));
        m_btConnect->setGeometry(QRect(390, 120, 93, 28));
        m_lwMessages = new QListWidget(centralWidget);
        m_lwMessages->setObjectName(QStringLiteral("m_lwMessages"));
        m_lwMessages->setGeometry(QRect(110, 180, 256, 192));
        QtNetworkClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtNetworkClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        m_menuser = new QMenu(menuBar);
        m_menuser->setObjectName(QStringLiteral("m_menuser"));
        QtNetworkClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtNetworkClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtNetworkClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtNetworkClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtNetworkClientClass->setStatusBar(statusBar);

        menuBar->addAction(m_menuser->menuAction());
        m_menuser->addAction(m_acRegisterUser);
        m_menuser->addAction(m_acLoginUser);

        retranslateUi(QtNetworkClientClass);

        QMetaObject::connectSlotsByName(QtNetworkClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtNetworkClientClass)
    {
        QtNetworkClientClass->setWindowTitle(QApplication::translate("QtNetworkClientClass", "QtNetworkClient", Q_NULLPTR));
        m_acRegisterUser->setText(QApplication::translate("QtNetworkClientClass", "Register", Q_NULLPTR));
        m_acLoginUser->setText(QApplication::translate("QtNetworkClientClass", "Login", Q_NULLPTR));
        m_btConnect->setText(QApplication::translate("QtNetworkClientClass", "connect", Q_NULLPTR));
        m_menuser->setTitle(QApplication::translate("QtNetworkClientClass", "user", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtNetworkClientClass: public Ui_QtNetworkClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTNETWORKCLIENT_H
