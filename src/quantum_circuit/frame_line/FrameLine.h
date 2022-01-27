#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>

#include "../quantum_gates/GateRectF.h"
// #include

class FrameLine : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit FrameLine(const QString &label, const QPointF &pos, QObject *parent = nullptr);
    virtual ~FrameLine();

signals:
   void inValidPos(bool, QPointF);

public slots:
    void showValidPos(QRectF rect);
    void hideValidPos();
    void checkValidPos(QRectF rect);

private:
    QGraphicsTextItem *m_line_label;
    QGraphicsLineItem *m_frame_line;
    QGraphicsRectItem *m_virtual_gate;
    QPointF m_valid_pos;
};
