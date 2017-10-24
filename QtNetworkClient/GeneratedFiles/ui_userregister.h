/********************************************************************************
** Form generated from reading UI file 'userregister.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTER_H
#define UI_USERREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <image.h>

QT_BEGIN_NAMESPACE

class Ui_UserRegister
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_6;
    QLineEdit *leName;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_8;
    QLineEdit *lePassword1;
    QPushButton *pushButton_7;
    QLineEdit *lePassword2;
    Image *m_lbImage;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QTextEdit *leInformation;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbRegister;
    QPushButton *pushButton;

    void setupUi(QDialog *UserRegister)
    {
        if (UserRegister->objectName().isEmpty())
            UserRegister->setObjectName(QStringLiteral("UserRegister"));
        UserRegister->resize(824, 570);
        verticalLayout_6 = new QVBoxLayout(UserRegister);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_6 = new QPushButton(UserRegister);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_4->addWidget(pushButton_6);

        leName = new QLineEdit(UserRegister);
        leName->setObjectName(QStringLiteral("leName"));

        horizontalLayout_4->addWidget(leName);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_8 = new QPushButton(UserRegister);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_5->addWidget(pushButton_8);

        lePassword1 = new QLineEdit(UserRegister);
        lePassword1->setObjectName(QStringLiteral("lePassword1"));

        horizontalLayout_5->addWidget(lePassword1);

        pushButton_7 = new QPushButton(UserRegister);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_5->addWidget(pushButton_7);

        lePassword2 = new QLineEdit(UserRegister);
        lePassword2->setObjectName(QStringLiteral("lePassword2"));

        horizontalLayout_5->addWidget(lePassword2);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout_4);

        m_lbImage = new Image(UserRegister);
        m_lbImage->setObjectName(QStringLiteral("m_lbImage"));
        m_lbImage->setMinimumSize(QSize(96, 128));

        horizontalLayout_3->addWidget(m_lbImage);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(UserRegister);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        verticalLayout_5->addWidget(groupBox);

        leInformation = new QTextEdit(UserRegister);
        leInformation->setObjectName(QStringLiteral("leInformation"));

        verticalLayout_5->addWidget(leInformation);


        verticalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pbRegister = new QPushButton(UserRegister);
        pbRegister->setObjectName(QStringLiteral("pbRegister"));

        horizontalLayout_2->addWidget(pbRegister);

        pushButton = new QPushButton(UserRegister);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_3);


        retranslateUi(UserRegister);

        QMetaObject::connectSlotsByName(UserRegister);
    } // setupUi

    void retranslateUi(QDialog *UserRegister)
    {
        UserRegister->setWindowTitle(QApplication::translate("UserRegister", "UserRegister", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("UserRegister", "Name:", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("UserRegister", "password", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("UserRegister", "repeat password", Q_NULLPTR));
        m_lbImage->setText(QApplication::translate("UserRegister", "TextLabel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserRegister", "Person Information", Q_NULLPTR));
        pbRegister->setText(QApplication::translate("UserRegister", "Register", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UserRegister", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserRegister: public Ui_UserRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTER_H
