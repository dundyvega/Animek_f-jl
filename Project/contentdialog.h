#ifndef CONTENTDIALOG_H
#define CONTENTDIALOG_H

#include <QDialog>
#include <QString>
#include "dialogtextedit.h"
#include "hummelobject.h"
#include "fileoperator.h"
#include <QWidget>

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


public:
    explicit ContentDialog(HummelObject *humel, FileOperator *operatorF, QWidget *parent = 0);
    ~ContentDialog();
    QString getHTMLFromContentDialog();


private slots:
    void on_buttonBox_accepted();

    void on_checkBox_clicked(bool checked);

    void on_ContentDialog_finished(int result);

private:
    Ui::ContentDialog *ui;
};

#endif // CONTENTDIALOG_H
