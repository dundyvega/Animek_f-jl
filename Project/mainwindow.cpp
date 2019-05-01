#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "myactions.h"
#include <QLineEdit>
#include <QWidgetAction>
#include <QImage>
#include "hummelobject.h"
#include "contentdialog.h"
#include <QFileDialog>
#include "aboutdialog.h"
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


     operatorF->configureCreated();



    QFile file("config.fil");


    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    /* Menüpontok hozzáadása
     *
     */
    int i = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        ui->comboBox->addItem(line);
        MyActions *acter = new MyActions(this, line, i);

        ui->menuFind_by_Categories->addAction(acter);

        connect(acter, SIGNAL(triggered(bool)), acter, SLOT(clicked(bool)));
        connect(acter, SIGNAL(menuChanged(int)), this, SLOT(menuAction(int)));
        //connect(acter, SIGNAL(getCatNumber(int)), SLOT(menuAction(int)));
        ++i;
    }

    /*
     *  Keresőmezők hozzáadása
     *
     * 1. Add mező hozzáadás
     */

    addEdit = new QLineEdit(this);
    QWidgetAction *widgetActionAdd = new QWidgetAction(this);
    widgetActionAdd->setDefaultWidget(addEdit);
    ui->menu_Add->addAction(widgetActionAdd);
    //connect(addEdit, SIGNAL(textChanged(QString)), this, SLOT(nameChanged(QString)));
    connect(addEdit, SIGNAL(returnPressed()), this, SLOT(nameChanged()));

    /*
     *
     * 2. A név mező hozzáadása
     *
     */

    nameEdit = new QLineEdit(this);
    QWidgetAction *widgetActionName = new QWidgetAction(this);
    widgetActionName->setDefaultWidget(nameEdit);
    ui->menu_Find_by_Name->addAction(widgetActionName);
    connect(nameEdit, SIGNAL(returnPressed()), this, SLOT(getByName()));

    /*
     *
     * 2. A tartalom mező hozzáadása
     *
     */

    contentEdit = new QLineEdit(this);
    QWidgetAction *widgetActionContent = new QWidgetAction(this);
    widgetActionContent->setDefaultWidget(contentEdit);
    ui->menuFind_on_Content->addAction(widgetActionContent);
    connect(contentEdit, SIGNAL(returnPressed()), this, SLOT(getByContent()));



    /*kép hozzáadása

    ui->label->setPixmap(QPixmap::fromImage(image));
    */

   QImage image("Kinga.png");
    ui->label_4->setPixmap(QPixmap::fromImage(image));

    /*list modem beállítás*/

   // model = new QStandardItemModel(0, 4, this);
    //ui->tableView->setModel(model);



    /*
     *
     *
     * ListView-hez tartózó model becsatolása + a billentyűzet kezelés hozzáadása a listához
     *
     *
     */

    createModel();
    ui->listView->installEventFilter(this);



    /*proba*/



    ui->listView->setModel(model);



    if (!operatorF->isEmpty()) {
        menuAction(1);
    }

    createHashMap();


   this->setWindowIcon(QIcon("favicon.ico"));


}


MainWindow::~MainWindow()
{
    delete dialog;
    delete about;
    delete operatorF;
    delete ui;

    QList<QMovie*>listMovies = urls->keys();
    for (QMovie *o : listMovies) {

        delete o;
    }

    urls->clear();

    delete urls;
    delete smiles;

}

void MainWindow::on_pushButton_clicked()
{
    try {
        //qDebug() << "gombnyomás";
        //HummelObject* obj = ui->listView->model()->a
        // HummelObject* item = model->getElement(index.row());

        if (ui->lineComment1->text() == "" || ui->lineComment2->text() == "" || ui->lineName->text() == "")
        {
             throw "Nem lehet nulla";
        }

        HummelObject *obj = model->getElement(ui->listView->currentIndex().row());

        obj->setName(ui->lineName->text());
        obj->setComment1(ui->lineComment1->text());
        obj->setComment2(ui->lineComment2->text());
        obj->setCondition(ui->comboBox->currentIndex());
        //qDebug() << ui->lineComment1->text() << "txt - átadva";
        operatorF->modositAnimeXML(obj->getId(), obj->getName(), obj->getComment2(), ui->lineComment1->text(), obj->getCondition());
        QMessageBox::information(0, "Módosítva", "A módosításokat elmentettem");

    } catch (...) {}
}

void MainWindow::menuAction(int b)
{
    //qDebug() << "Hello" << b;

    try {
    QList<HummelObject*> obj = operatorF->animekXML(b);

    try {

    if (obj.empty()) {
        throw "üres";
    }


    this->model->clear();
     createModel();



    for (int i = 0; i < obj.length(); ++i)
    {
        this->model->addElement(obj.at(i));
    }



    ui->listView->setModel(model);
    //ui->listView->setC

    ui->listView->setFocus();
    ui->listView->selectionModel()->select( ui->listView->model()->index(0, 0), QItemSelectionModel::Select);
    on_listView_clicked(ui->listView->model()->index(0, 0));
    } catch (...) {}
    } catch (QString b) {}


}

void MainWindow:: nameChanged()
{
    try {
        //qDebug() << this->addEdit->text();
        if (this->addEdit->text() == "")
        {
            throw "tévedés";
        }
        operatorF->ujAnimeXML(this->addEdit->text());
        this->nameEdit->setText(addEdit->text());
        getByName();
        this->addEdit->setText("");
        this->nameEdit->setText("");
    } catch (...) {}
}


void MainWindow:: getByName()
{
    try {
        //qDebug() << this->nameEdit->text();
            QList<HummelObject*> obj = operatorF->keresAnimekXML(this->nameEdit->text());
            if (!obj.isEmpty()) {
            this->model->clear();
             createModel();

            for (int i = 0; i < obj.length(); ++i)
            {
                this->model->addElement(obj.at(i));
            }


            ui->listView->setModel(model);

            this->nameEdit->setText("");

            ui->listView->setFocus();
            ui->listView->selectionModel()->select( ui->listView->model()->index(0, 0), QItemSelectionModel::Select);
            on_listView_clicked(ui->listView->model()->index(0, 0));
        }
    } catch (...) {}
    //ide
}

void MainWindow:: getByContent()
{
    try {
       // qDebug() << this->contentEdit->text();
         QList<HummelObject*> obj = operatorF->keresAnimekTartalomXML(this->contentEdit->text());
         if (!obj.isEmpty()) {
            this->model->clear();
             createModel();

            for (int i = 0; i < obj.length(); ++i)
            {
                this->model->addElement(obj.at(i));
            }


            ui->listView->setModel(model);
            this->contentEdit->setText("");

            ui->listView->setFocus();
            ui->listView->selectionModel()->select( ui->listView->model()->index(0, 0), QItemSelectionModel::Select);
            on_listView_clicked(ui->listView->model()->index(0, 0));
         }
    } catch (...) {}
}



void MainWindow::emptyModel()
{
    model->clear();

}

void MainWindow::createModel()
{
    model = new HashModel(this);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    try {
        HummelObject* item = model->getElement(index.row());
        ui->lineName->setText(item->getName());
        ui->lineComment1->setText(item->getComment1());
        ui->lineComment2->setText(item->getComment2());

        ui->comboBox->setCurrentIndex(item->getCondition());
    } catch (...) {}
}



void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
   //qDebug() << "kaszt";


     dialog = new ContentDialog(model->getElement(index.row()), operatorF, smiles, urls, this);
     dialog->show();


     /*mindent off-ol*/

    // allEnabled(false);

     //connect(dialog, SIGNAL(contentSaved(bool)), this, SLOT(allEnabled(bool)));

    connect (dialog, SIGNAL(contentAded(int, QString, ContentDialog*)), this, SLOT(contentAded(int, QString, ContentDialog*)));






}


void MainWindow::contentAded(int id, QString cont, ContentDialog *dl) {


    if (dl->Accepted) {

    }
    if (id != -1) {
        int indexEr = -1;
        indexEr = model->hasElement(id);
        if (indexEr != -1) {
            model->getElement(indexEr)->setContent(cont);
            operatorF->setTartalom(id, cont);
            //ui->listView->setModel(modelel


        }
    }

    delete dl;

}



void MainWindow::allEnabled(bool activate) {
    ui->menuBar->setEnabled(activate);
    ui->listView->setEnabled(activate);
    ui->lineName->setEnabled(activate);
    ui->lineComment1->setEnabled(activate);
    ui->lineComment2->setEnabled(activate);
    ui->comboBox->setEnabled(activate);
    ui->pushButton->setEnabled(activate);

}



bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{


    if (watched == ui->listView && event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if (ke->key() ==  Qt::Key_Up || ke->key() == Qt::Key_Down)
        {


            /* ha fel-le mozog, akkor töltse be azt, ami rákattra bejönne*/


            on_listView_clicked( ui->listView->currentIndex());
        } else
        {

            if (ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return)
            {
                on_listView_doubleClicked( ui->listView->currentIndex());
            }

        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    try {

        QString fileName = "";
        fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open Anime List"), "",
                                                        tr("Anime List (*.xml);;All Files(*))"));


        if (fileName != "")
        {

                operatorF->setFileName(fileName);

                QList<HummelObject*> obj = operatorF->animekXML(1);
                this->model->clear();
                 createModel();

                for (int i = 0; i < obj.length(); ++i)
                {
                    this->model->addElement(obj.at(i));
                }

               // qDebug() << fileName;

                ui->listView->setModel(model);



                ui->listView->setFocus();
                ui->listView->selectionModel()->select( ui->listView->model()->index(0, 0), QItemSelectionModel::Select);
                on_listView_clicked(ui->listView->model()->index(0, 0));


                // HummelObject *hummel = model->getElement(ui->listView->currentIndex().row());

               // ui->lineName->setText(hummel->getName());
                //ui->lineComment1->setText(hummel->getComment1());
                //ui->lineComment2->setText(hummel->getComment2());

                //ui->comboBox->setCurrentIndex(hummel->getCondition());

        } else
        {
          //  qDebug() << "nem volt kiválasztva semmi";
        }
    } catch (...) {}

}

void MainWindow::on_actionDelete_triggered()
{
    // ui->listView->currentIndex() -t kell törölni
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Törlés", "Biztosan törli?");
    if (reply == QMessageBox::Yes) {
        //qDebug() << "yes";


    try {


         HummelObject *obj = model->getElement(ui->listView->currentIndex().row());

         if (obj == NULL) {
             throw "nincs kiválasztva";
         }

        if (model->length() <= 1) {
            throw "nincs elég elem a törléshez";
        }

         operatorF->torolAnimeXML(obj->getId());
         model->deleteHummel(obj);
         ui->listView->setModel(model);
    } catch (...) {}


}

}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionNew_triggered()
{

    QString fileName = "";
    fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Open Anime List"), "",
                                                    tr("Anime List (*.xml);;All Files(*))"));

    if (fileName != "") {
        operatorF->newFile(fileName);


    }
}

void MainWindow::on_actionAbout_triggered()
{

    delete about;

    about = new AboutDialog(this);

    about->show();
}


void MainWindow::on_actionSave_2_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionContent_triggered()
{
    this->on_listView_doubleClicked(ui->listView->currentIndex());
}





void MainWindow::createHashMap()
{
    QString data;
    QString fileName = "smiles.dat";
    QFile file(fileName);

    urls = new QHash<QMovie*, QUrl>();
    smiles = new QHash<QString, DoubleString>();


    if(!file.open(QIODevice::ReadOnly)) {
    //    qDebug()<<"filenot opened"<<endl;
        QMessageBox::information(0,"error",file.errorString());
    }
    else
    {

        QString line = file.readLine();

        while (!file.atEnd())
        {
            QStringList fields = line.split("#");
            DoubleString obj(fields.at(1), fields.at(2));
            smiles->insert("smiles/"+ fields.at(0), obj);
            //qDebug() << fields.at(1);
            line = file.readLine();

            QMovie *movie = new QMovie(this);
            movie->setFileName("smiles/" + fields.at(0));
            movie->setCacheMode(QMovie::CacheAll);
            urls->insert(movie, "smiles/" + fields.at(0));
            movie->start();

        }


    }

    file.close();

   // qDebug() << data;
}
