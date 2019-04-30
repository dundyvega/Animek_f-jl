#include "contentdialog.h"
#include "ui_contentdialog.h"
#include "dialogtextedit.h"
#include <QMenu>
#include <QLabel>
#include <QMovie>

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
    ui->textBrowser->setVisible(true);

    this->adAll("smiles.dat");


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
    editing->close();

    QList<QMovie*>listMovies = urls.keys();
    for (QMovie *o : listMovies) {

        delete o;
    }

    urls.clear();
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

void ContentDialog::addAnimation(const QUrl &url, const QString filename)
{
    QList<QUrl> listUrls = urls.values();

    if (!listUrls.contains(url)) {
        QMovie *movie = new QMovie(this);
        movie->setFileName(filename);
        movie->setCacheMode(QMovie::CacheAll);
        urls.insert(movie, url);
        connect (movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
        movie->start();

    }
}

void ContentDialog::adAll(QString datFile)
{
    QString data;
    QFile file(datFile);

    if(!file.open(QIODevice::ReadOnly)) {
       // qDebug()<<"filenot opened"<<endl;
        //QMessageBox::information(0,"error",file.errorString());
    }
    else
    {
        //qDebug()<<"file opened"<<endl;

        QString line = file.readLine();

        while (!file.atEnd())
        {
            QStringList fields = line.split("#");
            DoubleString obj(fields.at(1), fields.at(2));
            addAnimation("smiles/" + fields.at(0), "smiles/" + fields.at(0));
            //qDebug() << fields.at(1);
            line = file.readLine();

        }


    }

    file.close();


}

void ContentDialog::on_ContentDialog_finished(int result)
{
    if (editing != NULL) {
        editing->close();
    }
    //this->close();
}

void ContentDialog::animate()
{
    //qDebug() << "harom";
    if (QMovie* movie = qobject_cast<QMovie*>(sender())) {

        ui->textBrowser->document()->addResource(QTextDocument::ImageResource, urls.value(movie), movie->currentPixmap());

        ui->textBrowser->setLineWrapColumnOrWidth(ui->textBrowser->lineWrapColumnOrWidth());
    }
}
