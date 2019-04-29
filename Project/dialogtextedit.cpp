#include "dialogtextedit.h"
#include "ui_dialogtextedit.h"
#include <QDebug>
#include <QMessageBox>


DialogTextEdit::DialogTextEdit(QString htmlString, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTextEdit)
{
    ui->setupUi(this);

   ui->plainTextEdit->setPlainText(htmlString);
   setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
  // createHashMap();


    this->setWindowIcon(QIcon("favicon.ico"));

}

DialogTextEdit::~DialogTextEdit()
{
    delete ui;

}



void DialogTextEdit::on_plainTextEdit_textChanged()
{

   // ui->label->setText(fromReadableText(ui->plainTextEdit->toPlainText()));
    emit(textEditing(fromReadableText(ui->plainTextEdit->toPlainText())));
}

QString DialogTextEdit::fromReadableText(QString s)
{

    QString htmlTest = "";

/*
    for (int i = 0; i < s.length(); ++i)
    {
        if (s.at(i) == '\n')
        {
            htmlTest += "<br>";
        } else
        {
            htmlTest += s.at(i);
        }

    }

 */

    htmlTest = s;
    //cserék:
    htmlTest = this->emotionText(htmlTest);
    htmlTest.replace('\n', "<br>");
    htmlTest.replace("[b]", "<b>");
    htmlTest.replace("[/b]", "</b>");
    htmlTest.replace("[i]", "<i>");
    htmlTest.replace("[/i]", "</i>");



    /*
     *
     * [c=rgb(77,51,153)]szöveg[/c]   ->   <font style = "color: rgb(77, 51, 153)"> szöveg </font>
        [s=16]Szöveg[/s]              ->   <font size="16">szöveg</font>
        [h=URL]szöveg[/h]             ->   <a href="url">link text</a>

         [s=100]                        <p style="font-size:100px">

         <body style="background-color: rgb(32, 100, 110)">  {c=rgb(32, 100, 110)}
         htmlTest.replace("{c=rgb(", <body style=\"background-color: rgb(>");

    */

    htmlTest.replace("[c=rgb(", "<font style = \"color: rgb(");            htmlTest.replace("{c=rgb(", "<body style=\"background-color: rgb(");
    htmlTest.replace("[/c]", "</font>");


    htmlTest.replace("0}", "0px}");
    htmlTest.replace("1}", "1px}");
    htmlTest.replace("2}", "2px}");
    htmlTest.replace("3}", "3px}");
    htmlTest.replace("4}", "4px}");
    htmlTest.replace("5}", "5px}");
    htmlTest.replace("6}", "6px}");
    htmlTest.replace("7}", "7px}");
    htmlTest.replace("8}", "8px}");
    htmlTest.replace("9}", "9px}");


    htmlTest.replace("[s=", "<font size = \"");          htmlTest.replace("{s=", "<p style=\"font-size:");
    htmlTest.replace("[/s]", "</font>");                 htmlTest.replace("{/s}", "</p>"); htmlTest.replace("}", "\">");



    htmlTest.replace("[h=", "<a href = \"");
    htmlTest.replace("[/h]", "</a>");
    htmlTest.replace("[/a]", "</a>");
     htmlTest.replace("]", "\">");

     //htmlTest.replace("px\"></a>", "\"></a>");




 //iconok betöltése









    return htmlTest;

}

void DialogTextEdit::createHashMap(QHash<QString, DoubleString> & hashMap)
{
    QString data;
    QString fileName = "smiles.dat";
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened"<<endl;
        QMessageBox::information(0,"error",file.errorString());
    }
    else
    {
        qDebug()<<"file opened"<<endl;

        QString line = file.readLine();

        while (!file.atEnd())
        {
            QStringList fields = line.split("#");
            DoubleString obj(fields.at(1), fields.at(2));
            hashMap.insert("smiles/"+ fields.at(0), obj);
            //qDebug() << fields.at(1);
            line = file.readLine();

        }


    }

    file.close();

    qDebug() << data;
}


QString DialogTextEdit::emotionText(QString text)
{

    QHash<QString, DoubleString> hashMap;
    createHashMap(hashMap);
    bool is = false;
    if (text != "" && text != NULL)
    {
        for (QString o: hashMap.keys())
        {
            if (text.contains(hashMap.value(o).getWriter()))
            {
                is = true;
                text = text.replace(hashMap.value(o).getWriter(), "<img src=\"" + o + "\">");
                //<img src="../smiles/cry.gif">


            }
        }

    }

    return text;

}

QString DialogTextEdit::getText()
{

    return ui->plainTextEdit->toPlainText();

}








/*<b>Ez egy vastag szöveg?</b>
<br>
<i>italic</i>
<br>
<body style="background-color:powderblue;">
 <img src="../Kacsa.png" alt="Girl in a jacket" width="300" height="300">

<br>
<font style ="color:rgb(175,168,21)"><b><i><font size="57">egy speckó szín</font></i></b></font>
 <font color="red">This is some text!</font> */


void DialogTextEdit::on_pushButton_clicked()
{

 /*   QTextCursor curs(ui->plainTextEdit->textCursor());
    int pos = curs.position();
    ui->plainTextEdit->setTextCursor(curs);

    QString text = ui->plainTextEdit->toPlainText();
    if (text.length() > 0) {

        QString text1 = text.mid(0, pos - 1);
        QString text2 = text.mid(pos, text.length());

        text = text1 + "[b][/b]" + text2;

        ui->plainTextEdit->setPlainText(text);
        ui->plainTextEdit->setFocus();

    }*/




}
