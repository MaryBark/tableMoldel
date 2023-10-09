#include "stateVectorModel.h"

#include <QDateTime>
#include <QFont>
#include <QColor>
#include <QPainter>
#include <QDebug>

class stateVectorModelPrivate
{
public:
    QDateTime m_dt; // время КА
    QList <double > m_q; // вектор координат и скоростей КА
};

stateVectorModel::stateVectorModel(QObject *parent) :
    m_dataModelptr(new stateVectorModelPrivate()), QAbstractTableModel()
{

}

stateVectorModel::stateVectorModel(const QList<double> dataModel, const QObject *parent):
    m_dataModelptr(new stateVectorModelPrivate()), QAbstractTableModel()
{

    m_dataModelptr->m_q = dataModel;
}

int stateVectorModel::rowCount(const QModelIndex &parent) const
{
    return 10; // количество эфемерид (скольки их будет - это надо из бекенда дергать, а его пока не прикрутила)
}

int stateVectorModel::columnCount(const QModelIndex &parent) const
{
    return 7; // координаты, скорости и дата
}

QVariant stateVectorModel::data(const QModelIndex &index, int role) const
{

    switch(role)
    {
    case Qt::DisplayRole:
    {
//        m_dataModelptr->m_q[0] = 10;
//        m_dataModelptr->m_q[1] = 10;
//        m_dataModelptr->m_q[3] = 10;
//        int d =  m_dataModelptr->m_q[0];

        QVariant value;

        m_dataModelptr->m_q = QList<double>();


        if (!index.isValid())
                return QVariant();


        return QIcon("free-icon-whatsapp-3670051.png");



//        switch (index.column()) {
//        case 0: {
//            value = m_dataModelptr->m_q.at(0/*index.row()*/);
//            break;
//        }
//        case 1: {
//            value = m_dataModelptr->m_q.at(156);
//            break;
//        }
//        case 2: {
//            value = m_dataModelptr->m_q.at(34546/*index.row()*/);
//            break;
//        }
//        }
        return /*m_dataModelptr->m_q*/value;

    }
     break;
    case Qt::BackgroundRole:
    {
        return QColor(155, 0, 0, 40);
    }
      break;
     case Qt::FontRole:
    {
        return QFont("Times", 10, QFont::Bold);
    }
      break;


//    case Qt::Pa
//   {
//    }
//    break;

    }

    return QVariant();
}









TableItemDelegate::TableItemDelegate()
{

}

QSize TableItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItem myOption = option;

    if (index.column()==2)
    {
        QString data = index.model()->data(index, Qt::DisplayRole).toString();

        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;

        QString icon = ":/img/" + index.model()->data(index, Qt::DisplayRole).toString();

        QPixmap pixmap2(icon);

        painter->drawPixmap(myOption.rect.x()+30,myOption.rect.y(),32,32, pixmap2);
    }
    else
    {
        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());

    }
    drawFocus(painter, myOption, myOption.rect);
}
