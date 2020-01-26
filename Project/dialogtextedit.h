#ifndef DIALOGTEXTEDIT_H
#define DIALOGTEXTEDIT_H

#include <QDialog>
#include "textnode.h"
#include<QHash>
#include "doublestring.h"

namespace Ui {
class DialogTextEdit;
}

class DialogTextEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTextEdit(QString htmlString, QHash<QString, DoubleString> *smiles, QWidget *parent = 0);
    ~DialogTextEdit();
    QString fromReadableText(QString s, QHash<QString, DoubleString> *sm);
    QString getText();


    void createHashMap(QHash<QString, DoubleString> & hashMap);
    QString emotionText(QString text, QHash<QString, DoubleString> *sm);
signals:
    void textEditing(QString s);

private slots:

    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::DialogTextEdit *ui;
    QHash<QString, DoubleString> *smiles;

};

#endif // DIALOGTEXTEDIT_H
