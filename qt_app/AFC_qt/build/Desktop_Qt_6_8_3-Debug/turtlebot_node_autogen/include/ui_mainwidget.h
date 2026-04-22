/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *pTab1;
    QWidget *pTab2;
    QWidget *pTab3;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(600, 500);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("/* ============================================================\n"
"   1. \354\240\204\354\227\255 \354\212\244\355\203\200\354\235\274 \353\260\217 \353\260\260\352\262\275 \354\204\244\354\240\225\n"
"   ============================================================ */\n"
"QWidget {\n"
"    background-color: #1b1e23;\n"
"    color: #d1d5db;\n"
"    font-family: \"Segoe UI\", \"Malgun Gothic\", sans-serif;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* ============================================================\n"
"   2. \354\273\250\355\205\214\354\235\264\353\204\210 (GroupBox & QFrame \354\271\264\353\223\234 \353\224\224\354\236\220\354\235\270)\n"
"   ============================================================ */\n"
"QGroupBox {\n"
"    background-color: #242930;\n"
"    border: 1px solid #323842;\n"
"    border-radius: 10px;\n"
"    margin-top: 25px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    left: 10px;\n"
""
                        "    padding: 0 10px;\n"
"    color: #00f2ff;\n"
"}\n"
"\n"
"QFrame {\n"
"    background-color: #2c313a;\n"
"    border: 1px solid #3e4451;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QFrame:hover {\n"
"    border: 1px solid #26c6da;\n"
"    background-color: #353b45;\n"
"}\n"
"\n"
"/* ============================================================\n"
"   3. \354\235\274\353\260\230 \353\262\204\355\212\274 \353\224\224\354\236\220\354\235\270\n"
"   ============================================================ */\n"
"QPushButton {\n"
"    background-color: #313742;\n"
"    border: 1px solid #3e4551;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-weight: 600;\n"
"    color: #eceff1;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3a4250;\n"
"    border: 1px solid #00f2ff;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #00f2ff;\n"
"    color: #1b1e23;\n"
"}\n"
"\n"
"/* \353\260\251\355\226\245\355\202\244 \354\240\204\354\232"
                        "\251 (Object Name\354\235\264 pPB\353\241\234 \354\213\234\354\236\221) */\n"
"QPushButton[objectName^=\"pPB\"] {\n"
"    background-color: #2c323d;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* ============================================================\n"
"   4. \355\212\271\354\210\230 \353\262\204\355\212\274 (START & STOP)\n"
"   ============================================================ */\n"
"#btnStartNavi {\n"
"    background-color: #26c6da !important;\n"
"    color: #1b1e23 !important;\n"
"    border: 2px solid #00f2ff !important;\n"
"    font-size: 14px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#btnStartNavi:hover {\n"
"    background-color: #33e0f5 !important;\n"
"    border: 2px solid #ffffff !important;\n"
"}\n"
"\n"
"#pPBStop {\n"
"    background-color: #3d2b2e;\n"
"    border: 1px solid #ff4d4d;\n"
"    color: #ff4d4d;\n"
"}\n"
"\n"
"/* ============================================================\n"
"   5. \353\235\274\353\262\250 \354\212\244\355\203\200\354\235\274 (\354\235\274\353\260\230 \353"
                        "\260\217 \353\215\260\354\235\264\355\204\260 \354\210\230\354\271\230)\n"
"   ============================================================ */\n"
"/* [\354\266\224\352\260\200] \354\235\274\353\260\230 \353\235\274\353\262\250: \354\240\234\353\252\251\354\232\251 (\353\241\234\353\264\207, \353\252\251\354\240\201\354\247\200, \354\266\251\354\240\204\354\206\214 \353\223\261) */\n"
"QLabel {\n"
"    qproperty-alignment: 'AlignCenter'; \n"
"    font-weight: bold;\n"
"    color: #90a4ae; \n"
"    margin-bottom: 5px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* [\354\234\240\354\247\200] \353\215\260\354\235\264\355\204\260 \354\210\230\354\271\230 \353\235\274\353\262\250 \352\260\225\354\241\260 (\354\240\204\354\225\225, \353\260\260\355\204\260\353\246\254 \354\210\230\354\271\230 \353\223\261) */\n"
"QLabel[objectName$=\"Value\"] {\n"
"    color: #00f2ff;\n"
"    font-family: \"Consolas\", monospace;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* ========================="
                        "===================================\n"
"   6. \352\270\260\355\203\200 \354\236\205\353\240\245 \354\234\204\354\240\257\n"
"   ============================================================ */\n"
"QComboBox {\n"
"    background-color: #1b1e23;\n"
"    border: 1px solid #3e4551;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"    color: #d1d5db;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    background-color: #121417;\n"
"    border: 1px solid #323842;\n"
"    border-radius: 4px;\n"
"    text-align: center;\n"
"    color: white;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, \n"
"                      stop:0 #00c6ff, stop:1 #00f2ff);\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border-radius: 4px;\n"
"    border: 1px solid #3e4551;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #00f2ff;\n"
"    border: 1px"
                        " solid #00f2ff;\n"
"}"));
        pTab1 = new QWidget();
        pTab1->setObjectName("pTab1");
        tabWidget->addTab(pTab1, QString());
        pTab2 = new QWidget();
        pTab2->setObjectName("pTab2");
        tabWidget->addTab(pTab2, QString());
        pTab3 = new QWidget();
        pTab3->setObjectName("pTab3");
        tabWidget->addTab(pTab3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab1), QCoreApplication::translate("MainWidget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab2), QCoreApplication::translate("MainWidget", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab3), QCoreApplication::translate("MainWidget", "Tab 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
