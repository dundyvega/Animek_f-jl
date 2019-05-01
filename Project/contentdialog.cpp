#include "contentdialog.h"
#include "ui_contentdialog.h"
#include "dialogtextedit.h"
#include <QMenu>
#include <QLabel>
#include <QMovie>
#include <QDebug>


ContentDialog::ContentDialog(HummelObject *humel, FileOperator *operatorF, QHash<QString, DoubleString> *smiles, QHash<QMovie*, QUrl> *urls, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentDialog)
{
    mn = parent;
    ui->setupUi(this);

    this->humel = new HummelObject(humel->getId(), humel->getComment1(), humel->getCondition(), humel->getName(), humel->getComment2(), humel->getContent(), this);
    this->humel1 = humel;
    this->operatorF = operatorF;
    text = this->humel->getContent();


   ui->textBrowser->setOpenLinks(true);
    //ui->textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    ui->textBrowser->setOpenExternalLinks(true);

    this->smiles = smiles;
    this->urls = urls;

    ui->textBrowser->setText(editing->fromReadableText(text, smiles));
    ui->textBrowser->setVisible(true);



    this->adAll();


/*    animatedBrowser = new TextBrowserAnimated2(this);
    animatedBrowser->setOpenExternalLinks(true);
    animatedBrowser->setOpenExternalLinks(true);
    animatedBrowser->setText(editing->fromReadableText(text));

    //animatedBrowser->addAnimation(QUrl("smiles/smile.gif"), "smiles/smile.gif");
    animatedBrowser->adAll("smiles.dat");
  // animatedBrowser->animate();

    ui->verticalLayout->addWidget(animatedBrowser);
*/




    //ui->textEdit->setText(s);

    this->setWindowIcon(QIcon("favicon.ico"));







}

ContentDialog::~ContentDialog()
{
    //editing->close();



//    urls.clear();
    delete humel;

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


        humel1->setContent(text);


        emit(contentSaved(true));


    } catch (...) {}
}

void ContentDialog::on_checkBox_clicked(bool checked)
{
    if (checked)
    {

        editing = new DialogTextEdit(getHTMLFromContentDialog(), smiles, mn);
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



void ContentDialog::adAll()
{ //ezt még lehet, hogy átírom úgy, hogy csak azokat a smile-kat animálja, amelyek szerepelnek a szövegben

    QList<QMovie*> listUrls = urls->keys();

    for (QMovie* movie: listUrls) {



        connect (movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
        //movie->start();


    }



}

void ContentDialog::on_ContentDialog_finished(int result)
{

     emit(contentSaved(true));
    if (editing != NULL) {
        editing->close();


    }
    //this->close();
}

void ContentDialog::animate()
{
    //qDebug() << humel->getName();
    if (QMovie* movie = qobject_cast<QMovie*>(sender())) {

        ui->textBrowser->document()->addResource(QTextDocument::ImageResource, urls->value(movie), movie->currentPixmap());

        ui->textBrowser->setLineWrapColumnOrWidth(ui->textBrowser->lineWrapColumnOrWidth());
    }
}
