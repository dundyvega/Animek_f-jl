/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//#include <QtGui/QAction>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_AS;
    QAction *actionClose;
    QAction *actionSave_2;
    QAction *actionDelete;
    QAction *actionContent;
    QAction *actionStatistic;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineComment1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineName;
    QLineEdit *lineComment2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QListView *listView;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menu_Add;
    QMenu *menuHelp;
    QMenu *menuFind_by_Categories;
    QMenu *menu_Find_by_Name;
    QMenu *menuFind_on_Content;
    QMenu *menuHelp_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(947, 524);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("alien.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/smiles/rar.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_AS = new QAction(MainWindow);
        actionSave_AS->setObjectName(QString::fromUtf8("actionSave_AS"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/smiles/flower.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/smiles/gif.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_2->setIcon(icon3);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionContent = new QAction(MainWindow);
        actionContent->setObjectName(QString::fromUtf8("actionContent"));
        actionStatistic = new QAction(MainWindow);
        actionStatistic->setObjectName(QString::fromUtf8("actionStatistic"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineComment1 = new QLineEdit(gridLayoutWidget);
        lineComment1->setObjectName(QString::fromUtf8("lineComment1"));

        gridLayout->addWidget(lineComment1, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineName = new QLineEdit(gridLayoutWidget);
        lineName->setObjectName(QString::fromUtf8("lineName"));

        gridLayout->addWidget(lineName, 1, 2, 1, 1);

        lineComment2 = new QLineEdit(gridLayoutWidget);
        lineComment2->setObjectName(QString::fromUtf8("lineComment2"));

        gridLayout->addWidget(lineComment2, 3, 2, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 4, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 2, 1, 1);

        splitter->addWidget(gridLayoutWidget);

        gridLayout_3->addWidget(splitter, 0, 2, 1, 1);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setAcceptDrops(false);

        gridLayout_3->addWidget(listView, 0, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 947, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu_Add = new QMenu(menuEdit);
        menu_Add->setObjectName(QString::fromUtf8("menu_Add"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFind_by_Categories = new QMenu(menuHelp);
        menuFind_by_Categories->setObjectName(QString::fromUtf8("menuFind_by_Categories"));
        menu_Find_by_Name = new QMenu(menuHelp);
        menu_Find_by_Name->setObjectName(QString::fromUtf8("menu_Find_by_Name"));
        menuFind_on_Content = new QMenu(menuHelp);
        menuFind_on_Content->setObjectName(QString::fromUtf8("menuFind_on_Content"));
        menuHelp_2 = new QMenu(menuBar);
        menuHelp_2->setObjectName(QString::fromUtf8("menuHelp_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(listView, lineName);
        QWidget::setTabOrder(lineName, lineComment1);
        QWidget::setTabOrder(lineComment1, lineComment2);
        QWidget::setTabOrder(lineComment2, comboBox);
        QWidget::setTabOrder(comboBox, pushButton);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuEdit->addAction(menu_Add->menuAction());
        menuEdit->addAction(actionSave_2);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionContent);
        menu_Add->addSeparator();
        menuHelp->addAction(menu_Find_by_Name->menuAction());
        menuHelp->addAction(menuFind_by_Categories->menuAction());
        menuHelp->addAction(menuFind_on_Content->menuAction());
        menuFind_by_Categories->addSeparator();
        menu_Find_by_Name->addSeparator();
        menuFind_on_Content->addSeparator();
        menuHelp_2->addAction(actionStatistic);
        menuHelp_2->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Denera Hummel", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_AS->setText(QCoreApplication::translate("MainWindow", "Save AS...", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "&Close", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "&Delete", nullptr));
        actionContent->setText(QCoreApplication::translate("MainWindow", "&Content", nullptr));
        actionStatistic->setText(QCoreApplication::translate("MainWindow", "&Statistic", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "comment1: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "comment2: ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name: ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_4->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Fi&le", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menu_Add->setTitle(QCoreApplication::translate("MainWindow", "&Add", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Fi&nd", nullptr));
        menuFind_by_Categories->setTitle(QCoreApplication::translate("MainWindow", "Find &by Categories", nullptr));
        menu_Find_by_Name->setTitle(QCoreApplication::translate("MainWindow", "&Find by Name", nullptr));
        menuFind_on_Content->setTitle(QCoreApplication::translate("MainWindow", "Find &on Content", nullptr));
        menuHelp_2->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
