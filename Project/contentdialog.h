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
    QHash<QMovie*, QUrl> urls;


public:
    explicit ContentDialog(HummelObject *humel, FileOperator *operatorF, QWidget *parent = 0);
    ~ContentDialog();
    QString getHTMLFromContentDialog();

    void addAnimation(const QUrl& url, const QString filename);

    void adAll(QString datFile);


private slots:
    void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

    void on_ContentDialog_finished(int result);

    void animate();

private:
    Ui::ContentDialog *ui;
};

#endif // CONTENTDIALOG_H
