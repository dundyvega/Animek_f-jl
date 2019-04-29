#include "contentdialog.h"
#include "ui_contentdialog.h"
#include <QDebug>
#include "dialogtextedit.h"
#include <QMenu>

ContentDialog::ContentDialog(HummelObject *humel, FileOperator *operatorF, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentDialog)
{
    mn = parent;
    ui->setupUi(this);

    this->humel = humel;
    this->operatorF = operatorF;
    text = this->humel->getContent();

   ui->textBrowser->setOpenLinks(true);
    //ui->textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    ui->textBrowser->setOpenExternalLinks(true);

    ui->textBrowser->setText(editing->fromReadableText(text));

    //ui->textEdit->setText(s);

    this->setWindowIcon(QIcon("favicon.ico"));







}

ContentDialog::~ContentDialog()
{
    editing->close();
}

void ContentDialog::on_buttonBox_accepted()
{
    try
    {
        if (text == "")
        {
            throw "nem lehet üres";
        }

        humel->setContent(text);
        operatorF->setTartalom(humel->getId(), humel->getContent());
    } catch (...) {}
}

void ContentDialog::on_checkBox_clicked(bool checked)
{
    if (checked)
    {

        editing = new DialogTextEdit(getHTMLFromContentDialog(), mn);
        //editing->setWindowFlag(Qt::Dialog);
        editing->move(ui->checkBox->x() + 100, ui->textBrowser->y() + 20);
        editing->show();
        connect(editing, SIGNAL(textEditing(QString)), ui->textBrowser, SLOT(setHtml(QString)));

        ui->buttonBox->buttons().at(0)->setEnabled(false);
    } else
    {
        text = editing->getText();
        editing->close();
        ui->buttonBox->buttons().at(0)->setEnabled(true);

    }
}

QString ContentDialog::getHTMLFromContentDialog()
{

    return text;

}

void ContentDialog::on_ContentDialog_finished(int result)
{
    if (editing != NULL) {
        editing->close();
    }
    //this->close();
}
