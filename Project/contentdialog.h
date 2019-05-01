#ifndef CONTENTDIALOG_H
#define CONTENTDIALOG_H

#include <QDialog>
#include <QString>
#include "dialogtextedit.h"
#include "hummelobject.h"
#include "fileoperator.h"
#include <QWidget>
#include "animatedtextbrowser.h"
#include "textbrowseranimated2.h"
#include <QHash>
#include <QMovie>
#include "doublestring.h"
#include <QUrl>

namespace Ui {
class ContentDialog;
}

class ContentDialog : public QDialog
{
    Q_OBJECT

private:

    QString text;
    DialogTextEdit *editing = NULL;
    HummelObject* humel;
    FileOperator *operatorF;
    QWidget *mn;
    //TextBrowserAnimated2 *animatedBrowser;
    QHash<QMovie*, QUrl> *urls;
    QHash<QString, DoubleString> *smiles;


public:
    explicit ContentDialog(HummelObject *humel, FileOperator *operatorF, QHash<QString, DoubleString> *smiles, QHash<QMovie*, QUrl> *urls, QWidget *parent = 0);
    ~ContentDialog();
    QString getHTMLFromContentDialog();


    void adAll();


private slots:
    //void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

   // void on_ContentDialog_finished(int result);

    void animate();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ContentDialog *ui;

signals:
    void contentSaved(bool activate);
    void contentAded(int, QString, ContentDialog*);
};

#endif // CONTENTDIALOG_H
