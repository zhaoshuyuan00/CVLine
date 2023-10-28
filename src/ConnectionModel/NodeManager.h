#ifndef NODEMANAGER_H
#define NODEMANAGER_H
#include "src/ConnectionModel/Relations/PortInfo.h"
#include "src/ConnectionModel/Relations/LineInfo.h"

#include <QGraphicsView>

class NodeManager
{

public:
    NodeManager( QGraphicsView *view);

    //通过点拿到端口信息     即这个点是不是在端口上
    PortInfo GetPortByPos( QPoint pos);
    //通过点拿到节点     即这个点是不是在节点上
    Node* GetNodeByPos(QPoint pos);

    //通过端口拿到与该端口连接的所有端口信息信息
    QList<PortInfo> GetNodeAndPortListByPort(Port* port);


    //获取连接到节点上输入端口上的所有端口信息
    QList<PortInfo> GetConnectedInPortInfo(Port* port);


    //通过端口拿到与该端口连接的节点和端口信息列表  (只会拿到一个，比如输入口只能有一个输入节点)
    PortInfo GetNodeAndPortByPort(Port* port);


    //拿到节点程序控制输出端口节点信息表  控制输出端口连接的所有的节点
    QList<PortInfo> GetOutStreamPortInfoByNode(Node*node);

    //拿到与该节点控制输入端口节点信息  因为输入只能有一个，所以只会存在一个节点与输入端口连接
    PortInfo GetInStreamPortInfoByNode(Node*node);

    //端口是否可以连接检测
    bool EnableConnectCheck(PortInfo info1,PortInfo info2);


    //检测回环
    //从一个端口出发看看能不能到达这个端口，如果可以到达那么就是回环，如果最后是空的端口那么就不是回环
    bool CycleCheck();



    //更新线的位置
    void UpdateLine(QPoint pos);

    //添加一条连线关系
    void AddRelation(LineInfo info);

    //执行
    void Run();

    //节点执行 递归
    void NodeRun(QList<PortInfo> portnodeinfolist);
    //节点执行完成以后刷新
    void NodeReflush();


    //添加节点
    void AddNode(Node*node);
    //连接两个节点
    void NodeConnect(Node*node1,Node*node2);

public:
    //端口连线信息列表
    QList<LineInfo> PortLineInfoList;

    //节点表
    QList<Node*>NodeList;

    //场景
    QGraphicsView *view;


};

#endif // NODEMANAGER_H
