#ifndef NODE_H
#define NODE_H


#include<QList>
#include <QRect>
#include<QObject>
#include <QPointF>
#include <QVariant>
#include <QPainter>
#include <QGraphicsItem>
#include<QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "src/NodeGraphics/Port/Port.h"
#include "src/LineGraphics/beziercurveitem.h"
#include "src/ConnectionModel/Relations/StreamPortinfo.h"

typedef BezierCurveItem Line;

class Node: public QGraphicsItem
{

public:

    //节点类型
    enum NodeType {BaseNode,StartNode, FunctionNode, DataNode};

    Node(NodeType nodetype=Node::BaseNode, QPointF pos=QPointF(0,0));

    QRectF boundingRect() const ;



    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;

    void setHighlighted(bool highlight);


    void AddPort(Port *port);
    void SetPortValue(uint portID,QVariant data,Port::PortType type);
    Port *GetPort(uint portID,Port::PortType type);

    void SetInStreamPort();
    void SetOutStreamPort();





   StreamPortinfo GetStreamInfo();//拿到程序控制端口信息

    bool CheckPortByPos(QPointF pos);//检测点是否在端口上
    Port*GetPortByPos(QPointF pos);//获取点上的端口



    uint GetInputCount()const ; //获取输入端口数量
    uint GetOutCount()const ;   //获取输出端口数量


    QList<Port*> GetInport();//获取输入端口
    QList<Port*> GetConnectedInport();//获取已经连接的输入端口
    QList<Port*> GetOutport();//获取输入端口
    QList<Port*> GetConnectedOutport();//获取已经连接的输入端口

    QString NodeName{"Node"};   //节点名字

    NodeType nodeType{BaseNode};//节点类型

    QColor TitleColor;

    bool IsExecuted=false;


    virtual void execute();//节点执行逻辑
private:

    bool isHighlighted;

    QList<Port*> portList;//端口列表

    //节点类型标题颜色表  各种颜色都是经过哥哥我精心挑选的
    inline static QMap<NodeType,QColor> TitleColorMap
        {
            {BaseNode,QColor(100,100,100)},
            {StartNode,QColor(100,0,0)},
            {FunctionNode,QColor(20,80,150)},
            {DataNode,QColor(220, 200, 20)},

        };




};

#endif // NODE_H
