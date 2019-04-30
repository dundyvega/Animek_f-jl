#include "textnode.h"

TextNode::TextNode(QString family, QString color, QString size)
{

    this->family = family;
    this->color = color;
    this->size = size;


}

TextNode::TextNode(QString family, QString color, QString size, bool bold, bool italic, TextNode *parent)
{

    this->family = family;
    this->color = color;
    this->size = size;
    this->bold = bold;
    this->italic = italic;
    this->parent = parent;


}


TextNode:: ~TextNode()
{

    for (int i = 0; i < this->children.length(); ++i)
    {
        delete children.at(i);
    }

}

void TextNode::setText(QString text)
{
    this->text = text;
}


QString TextNode::getText()
{
   return text;

}


void TextNode::setSize(QString size)
{

    this->size = size;

}

QString TextNode::getSize()
{
    return size;

}

bool TextNode::isBold()
{
    return bold;
}

void TextNode::setBold(bool bold)
{
    this->bold = bold;
}

bool TextNode::isItalic()
{
    return italic;
}

void TextNode::setItalic(bool italic)
{
    this->italic = italic;
}

QString TextNode::getColor()
{
    return color;
}

void TextNode::setColor(QString s)
{
    this->color = color;
}

QString TextNode::getFamily()
{
    return family;
}

void TextNode::setFamily(QString family)
{
    this->family = family;
}

QList<TextNode *> TextNode::getNode()
{
    return children;
}

void TextNode::setAsChildren(TextNode *node)
{
    children.append(node);
}

int TextNode::getId()
{
    return id;
}

void TextNode::setId(int id)
{
    this->id = id;
}

TextNode *TextNode::getParent()
{
    return parent;
}

void TextNode::setParent(TextNode *parent)
{
    this->parent = parent;
}

void TextNode::setLink(bool link)
{
    this->link = link;
}

bool TextNode::isLink()
{
    return link;
}

bool TextNode::isIcon()
{
    return icon;
}

void TextNode::setIcon(bool icon)
{
   this->icon = icon;
}

QString TextNode::getIconText()
{
    return iconText;
}

void TextNode::setIconText(QString s)
{
    this->iconText = s;
}

QString TextNode::getHyperLink()
{
    return hyperlink;
}

void TextNode::setHyperLink(QString hyperlink)
{
    this->hyperlink = hyperlink;
}

