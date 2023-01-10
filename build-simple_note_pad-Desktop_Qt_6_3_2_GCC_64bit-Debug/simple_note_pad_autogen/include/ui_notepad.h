/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAdd_source;
    QAction *actionCompile;
    QAction *actionRun;
    QAction *actionStop;
    QAction *actionMemory;
    QAction *actionvirt;
    QAction *actionversatilepb;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *textEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listOpenedFile;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *rmOpenedFileButton;
    QTextBrowser *debugText;
    QPlainTextEdit *testText;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCompile;
    QMenu *menuSetting;
    QMenu *menuMachine_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QString::fromUtf8("Notepad"));
        Notepad->resize(800, 600);
        actionNew = new QAction(Notepad);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/imgs/New.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(Notepad);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/imgs/Open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_As = new QAction(Notepad);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/imgs/Save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionExit = new QAction(Notepad);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCopy = new QAction(Notepad);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(Notepad);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(Notepad);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionUndo = new QAction(Notepad);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(Notepad);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionAdd_source = new QAction(Notepad);
        actionAdd_source->setObjectName(QString::fromUtf8("actionAdd_source"));
        actionCompile = new QAction(Notepad);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        actionRun = new QAction(Notepad);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionStop = new QAction(Notepad);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionMemory = new QAction(Notepad);
        actionMemory->setObjectName(QString::fromUtf8("actionMemory"));
        actionvirt = new QAction(Notepad);
        actionvirt->setObjectName(QString::fromUtf8("actionvirt"));
        actionvirt->setCheckable(true);
        actionversatilepb = new QAction(Notepad);
        actionversatilepb->setObjectName(QString::fromUtf8("actionversatilepb"));
        actionversatilepb->setCheckable(true);
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 60, 571, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QPlainTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 60, 161, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listOpenedFile = new QListWidget(verticalLayoutWidget_2);
        listOpenedFile->setObjectName(QString::fromUtf8("listOpenedFile"));

        verticalLayout_2->addWidget(listOpenedFile);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 161, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        rmOpenedFileButton = new QPushButton(horizontalLayoutWidget);
        rmOpenedFileButton->setObjectName(QString::fromUtf8("rmOpenedFileButton"));
        QIcon icon3;
        QString iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        rmOpenedFileButton->setIcon(icon3);

        horizontalLayout->addWidget(rmOpenedFileButton);

        debugText = new QTextBrowser(centralwidget);
        debugText->setObjectName(QString::fromUtf8("debugText"));
        debugText->setGeometry(QRect(15, 371, 751, 141));
        testText = new QPlainTextEdit(centralwidget);
        testText->setObjectName(QString::fromUtf8("testText"));
        testText->setGeometry(QRect(220, 10, 321, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 10, 89, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 350, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 40, 131, 21));
        Notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuCompile = new QMenu(menubar);
        menuCompile->setObjectName(QString::fromUtf8("menuCompile"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuMachine_2 = new QMenu(menuSetting);
        menuMachine_2->setObjectName(QString::fromUtf8("menuMachine_2"));
        Notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(Notepad);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Notepad->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuCompile->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuCompile->addAction(actionAdd_source);
        menuCompile->addAction(actionCompile);
        menuCompile->addAction(actionRun);
        menuCompile->addAction(actionStop);
        menuSetting->addSeparator();
        menuSetting->addAction(actionMemory);
        menuSetting->addAction(menuMachine_2->menuAction());
        menuMachine_2->addAction(actionvirt);
        menuMachine_2->addAction(actionversatilepb);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave_As);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "IDE for bare-metal ARM ISA", nullptr));
        actionNew->setText(QCoreApplication::translate("Notepad", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("Notepad", "Open", nullptr));
        actionSave_As->setText(QCoreApplication::translate("Notepad", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("Notepad", "Exit", nullptr));
        actionCopy->setText(QCoreApplication::translate("Notepad", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("Notepad", "Paste", nullptr));
        actionCut->setText(QCoreApplication::translate("Notepad", "Cut", nullptr));
        actionUndo->setText(QCoreApplication::translate("Notepad", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("Notepad", "Redo", nullptr));
        actionAdd_source->setText(QCoreApplication::translate("Notepad", "Add Source", nullptr));
        actionCompile->setText(QCoreApplication::translate("Notepad", "Compile", nullptr));
        actionRun->setText(QCoreApplication::translate("Notepad", "Compile and Run", nullptr));
        actionStop->setText(QCoreApplication::translate("Notepad", "Stop", nullptr));
        actionMemory->setText(QCoreApplication::translate("Notepad", "Memory", nullptr));
        actionvirt->setText(QCoreApplication::translate("Notepad", "virt", nullptr));
        actionversatilepb->setText(QCoreApplication::translate("Notepad", "versatilepb", nullptr));
        label->setText(QCoreApplication::translate("Notepad", "Source Files List", nullptr));
        rmOpenedFileButton->setText(QString());
        pushButton->setText(QCoreApplication::translate("Notepad", "test", nullptr));
        label_2->setText(QCoreApplication::translate("Notepad", "Log", nullptr));
        label_3->setText(QCoreApplication::translate("Notepad", "File Content ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Notepad", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("Notepad", "Edit", nullptr));
        menuCompile->setTitle(QCoreApplication::translate("Notepad", "Compile", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("Notepad", "Setting", nullptr));
        menuMachine_2->setTitle(QCoreApplication::translate("Notepad", "Machine", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Notepad", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
