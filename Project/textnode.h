#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <QString>
#include <QList>

class TextNode
{


private:

    QString text;
    bool italic;
    bool icon;
    bool bold;
    QString iconText;
    QString size;
    QString color;
    QString family;
    bool link;
    QString hyperlink;
    QList<TextNode*> children;
    TextNode *parent;
    int id;


public:

    TextNode(QString family, QString color, QString size);

    TextNode(QString family, QString color, QString size, bool bold, bool italic, TextNode *parent);

    ~TextNode();

    void setText(QString text);

    QString getText();

   void setSize(QString size);

   QString getSize();

   bool isBold();

   void setBold(bool bold);

   bool isItalic();

  void setItalic(bool italic);

  QString getColor();

  void setColor(QString s);


  QString getFamily();

  void setFamily(QString family);

  QList<TextNode*> getNode();

  void setAsChildren(TextNode* node);

  int getId();

  void setId(int id);

  TextNode* getParent();

  void setParent(TextNode *parent);

  void setLink(bool link);

  bool isLink();

  bool isIcon();

  void setIcon(bool icon);

  QString getIconText();

  void setIconText(QString s);

  QString getHyperLink();

  void setHyperLink(QString hyperlink);




};

#endif // TEXTNODE_H
