#ifndef STATEVECTORMODEL_H
#define STATEVECTORMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QVector>
#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>

class stateVectorModelPrivate;

class stateVectorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    stateVectorModel(QObject* parent = nullptr);
    stateVectorModel(const QList <double >, const QObject* parent = nullptr);
    ~stateVectorModel(){delete m_dataModelptr;}

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;


private:
    stateVectorModelPrivate *m_dataModelptr;



};





// Для иконок
class TableItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    TableItemDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const override;
};



#endif // STATEVECTORMODEL_H
