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
    HummelObject* humel1;
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
    void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

    void on_ContentDialog_finished(int result);

    void animate();

private:
    Ui::ContentDialog *ui;

signals:
    void contentSaved(bool activate);
};

#endif // CONTENTDIALOG_H
