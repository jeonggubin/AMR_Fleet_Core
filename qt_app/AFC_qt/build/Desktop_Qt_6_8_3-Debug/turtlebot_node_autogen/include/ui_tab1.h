/********************************************************************************
** Form generated from reading UI file 'tab1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1_H
#define UI_TAB1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
public:
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *cbRobot;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_3;
    QComboBox *cbDest;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QComboBox *cbItem;
    QComboBox *cbCount;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_11;
    QPushButton *btnStart;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBattery_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pPBRight;
    QPushButton *pPBBackward;
    QPushButton *pPBForward;
    QPushButton *pPBStop;
    QPushButton *pPBLeft;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pPBServo0;
    QPushButton *pPBServo30;
    QGroupBox *groupBattery;
    QVBoxLayout *verticalLayout_4;
    QProgressBar *barBattery;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblVoltageValue;

    void setupUi(QWidget *Tab1)
    {
        if (Tab1->objectName().isEmpty())
            Tab1->setObjectName("Tab1");
        Tab1->resize(640, 747);
        verticalLayoutWidget_4 = new QWidget(Tab1);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(20, 10, 561, 661));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget_4);
        groupBox->setObjectName("groupBox");
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(frame_2);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        cbRobot = new QComboBox(frame_2);
        cbRobot->addItem(QString());
        cbRobot->addItem(QString());
        cbRobot->setObjectName("cbRobot");

        verticalLayout_2->addWidget(cbRobot);


        horizontalLayout_4->addWidget(frame_2);

        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName("frame_3");
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");

        verticalLayout_9->addWidget(label_3);

        cbDest = new QComboBox(frame_3);
        cbDest->addItem(QString());
        cbDest->addItem(QString());
        cbDest->addItem(QString());
        cbDest->addItem(QString());
        cbDest->addItem(QString());
        cbDest->addItem(QString());
        cbDest->setObjectName("cbDest");

        verticalLayout_9->addWidget(cbDest);


        horizontalLayout_4->addWidget(frame_3);

        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName("frame_4");
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_4);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");

        verticalLayout_10->addWidget(label_4);

        cbItem = new QComboBox(frame_4);
        cbItem->addItem(QString());
        cbItem->addItem(QString());
        cbItem->addItem(QString());
        cbItem->setObjectName("cbItem");

        verticalLayout_10->addWidget(cbItem);

        cbCount = new QComboBox(frame_4);
        cbCount->addItem(QString());
        cbCount->addItem(QString());
        cbCount->addItem(QString());
        cbCount->addItem(QString());
        cbCount->addItem(QString());
        cbCount->setObjectName("cbCount");

        verticalLayout_10->addWidget(cbCount);


        horizontalLayout_4->addWidget(frame_4);

        frame_5 = new QFrame(groupBox);
        frame_5->setObjectName("frame_5");
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        btnStart = new QPushButton(frame_5);
        btnStart->setObjectName("btnStart");

        verticalLayout_11->addWidget(btnStart);


        horizontalLayout_4->addWidget(frame_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addWidget(groupBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBattery_2 = new QGroupBox(verticalLayoutWidget_4);
        groupBattery_2->setObjectName("groupBattery_2");
        verticalLayout_5 = new QVBoxLayout(groupBattery_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pPBRight = new QPushButton(groupBattery_2);
        pPBRight->setObjectName("pPBRight");

        gridLayout->addWidget(pPBRight, 1, 2, 1, 1);

        pPBBackward = new QPushButton(groupBattery_2);
        pPBBackward->setObjectName("pPBBackward");

        gridLayout->addWidget(pPBBackward, 2, 1, 1, 1);

        pPBForward = new QPushButton(groupBattery_2);
        pPBForward->setObjectName("pPBForward");

        gridLayout->addWidget(pPBForward, 0, 1, 1, 1);

        pPBStop = new QPushButton(groupBattery_2);
        pPBStop->setObjectName("pPBStop");

        gridLayout->addWidget(pPBStop, 1, 1, 1, 1);

        pPBLeft = new QPushButton(groupBattery_2);
        pPBLeft->setObjectName("pPBLeft");

        gridLayout->addWidget(pPBLeft, 1, 0, 1, 1);

        checkBox = new QCheckBox(groupBattery_2);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pPBServo0 = new QPushButton(groupBattery_2);
        pPBServo0->setObjectName("pPBServo0");

        horizontalLayout_2->addWidget(pPBServo0);

        pPBServo30 = new QPushButton(groupBattery_2);
        pPBServo30->setObjectName("pPBServo30");

        horizontalLayout_2->addWidget(pPBServo30);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBattery_2);

        groupBattery = new QGroupBox(verticalLayoutWidget_4);
        groupBattery->setObjectName("groupBattery");
        verticalLayout_4 = new QVBoxLayout(groupBattery);
        verticalLayout_4->setObjectName("verticalLayout_4");
        barBattery = new QProgressBar(groupBattery);
        barBattery->setObjectName("barBattery");
        barBattery->setValue(24);

        verticalLayout_4->addWidget(barBattery);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lblVoltageValue = new QLabel(groupBattery);
        lblVoltageValue->setObjectName("lblVoltageValue");

        horizontalLayout_3->addWidget(lblVoltageValue);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBattery);


        verticalLayout_7->addLayout(verticalLayout_3);


        retranslateUi(Tab1);

        QMetaObject::connectSlotsByName(Tab1);
    } // setupUi

    void retranslateUi(QWidget *Tab1)
    {
        Tab1->setWindowTitle(QCoreApplication::translate("Tab1", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Tab1", "\354\236\220\354\234\250\354\243\274\355\226\211 \353\252\250\353\223\234", nullptr));
        label->setText(QCoreApplication::translate("Tab1", " \353\241\234\353\264\207", nullptr));
        cbRobot->setItemText(0, QCoreApplication::translate("Tab1", "\355\204\260\355\213\200\353\264\207A", nullptr));
        cbRobot->setItemText(1, QCoreApplication::translate("Tab1", "\355\204\260\355\213\200\353\264\207B", nullptr));

        label_3->setText(QCoreApplication::translate("Tab1", "\353\252\251\354\240\201\354\247\200", nullptr));
        cbDest->setItemText(0, QCoreApplication::translate("Tab1", "\355\225\230\354\227\255\354\236\245X", nullptr));
        cbDest->setItemText(1, QCoreApplication::translate("Tab1", "\355\225\230\354\227\255\354\236\245Y", nullptr));
        cbDest->setItemText(2, QCoreApplication::translate("Tab1", "\355\225\230\354\227\255\354\236\245Z", nullptr));
        cbDest->setItemText(3, QCoreApplication::translate("Tab1", "\354\203\201\354\260\250\354\236\245", nullptr));
        cbDest->setItemText(4, QCoreApplication::translate("Tab1", "\354\266\251\354\240\204\354\206\214A", nullptr));
        cbDest->setItemText(5, QCoreApplication::translate("Tab1", "\354\266\251\354\240\204\354\206\214B", nullptr));

        label_4->setText(QCoreApplication::translate("Tab1", "\353\254\274\355\222\210/\352\260\234\354\210\230", nullptr));
        cbItem->setItemText(0, QCoreApplication::translate("Tab1", "\354\225\204\354\235\264\355\205\234A", nullptr));
        cbItem->setItemText(1, QCoreApplication::translate("Tab1", "\354\225\204\354\235\264\355\205\234B", nullptr));
        cbItem->setItemText(2, QCoreApplication::translate("Tab1", "\354\225\204\354\235\264\355\205\234C", nullptr));

        cbCount->setItemText(0, QCoreApplication::translate("Tab1", "1", nullptr));
        cbCount->setItemText(1, QCoreApplication::translate("Tab1", "2", nullptr));
        cbCount->setItemText(2, QCoreApplication::translate("Tab1", "3", nullptr));
        cbCount->setItemText(3, QCoreApplication::translate("Tab1", "4", nullptr));
        cbCount->setItemText(4, QCoreApplication::translate("Tab1", "5", nullptr));

        btnStart->setText(QCoreApplication::translate("Tab1", "START", nullptr));
        groupBattery_2->setTitle(QCoreApplication::translate("Tab1", "\354\210\230\353\217\231 \353\252\250\353\223\234", nullptr));
        pPBRight->setText(QCoreApplication::translate("Tab1", "\342\226\266", nullptr));
        pPBBackward->setText(QCoreApplication::translate("Tab1", "\342\226\274", nullptr));
        pPBForward->setText(QCoreApplication::translate("Tab1", "\342\226\262", nullptr));
        pPBStop->setText(QCoreApplication::translate("Tab1", "\342\226\240", nullptr));
        pPBLeft->setText(QCoreApplication::translate("Tab1", "\342\227\200", nullptr));
        checkBox->setText(QCoreApplication::translate("Tab1", "\354\210\230\353\217\231 \354\241\260\354\236\221", nullptr));
        pPBServo0->setText(QCoreApplication::translate("Tab1", "\354\204\234\353\263\264\353\252\250\355\204\260 0'", nullptr));
        pPBServo30->setText(QCoreApplication::translate("Tab1", "\354\204\234\353\263\264\353\252\250\355\204\260 30'", nullptr));
        groupBattery->setTitle(QCoreApplication::translate("Tab1", "\353\260\260\355\204\260\353\246\254 \354\203\201\355\203\234", nullptr));
        lblVoltageValue->setText(QCoreApplication::translate("Tab1", "VOLTAGE:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1: public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1_H
