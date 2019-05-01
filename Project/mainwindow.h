#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QStandardItemModel>
#include "hashmodel.h"
#include "contentdialog.h"
#include "fileoperator.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    int m_duration;
    QLineEdit *addEdit;
    QLineEdit *nameEdit;
    QLineEdit *contentEdit;
    HashModel *model;
    ContentDialog *dialog = NULL;
    AboutDialog *about = NULL;
    FileOperator *operatorF = new FileOperator();
    QHash<QMovie*, QUrl> *urls;
    QHash<QString, DoubleString> *smiles;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void emptyModel();
    void createModel();

    void createHashMap();
public slots:
    void contentAded(int id, QString cont, ContentDialog *dl);
protected:
    bool eventFilter(QObject *watched, QEvent *event);


private slots:


    //gombnyomás
    void on_pushButton_clicked();
    //a tartalom keresés menűpontjainak a slotja
    void menuAction(int b);
    //hozzáad egy elem
   void nameChanged();
   //kimutat név alapján
   void getByName();
   //kimutat tartalom alapján
   void getByContent();

   void on_listView_clicked(const QModelIndex &index);

   //void on_listView_entered(const QModelIndex &index);

   void on_listView_doubleClicked(const QModelIndex &index);

  // void on_listView_activated(const QModelIndex &index);

   //void on_listView_pressed(const QModelIndex &index);

   //void on_listView_indexesMoved(const QModelIndexList &indexes);

   void on_actionOpen_triggered();

   void on_actionDelete_triggered();

   void on_actionClose_triggered();

   void on_actionNew_triggered();

   void on_actionAbout_triggered();

   void on_actionSave_2_triggered();

   void on_actionContent_triggered();

    void allEnabled(bool activate);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
