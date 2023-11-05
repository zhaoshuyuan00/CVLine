#include "Add.h"

AddNode::AddNode(QPointF pos,Port::PortDataType datatype):Node(Node::FunctionNode, pos)
{
    NodeName="Add";

    //添加控制端口
    AddPort(new Port(0,"",Port::InStream,Port::Stream));
    AddPort(new Port(0,"",Port::OutStream,Port::Stream));

        QVariant val;
    if(datatype==Port::Int)
            val=0;
    if(datatype==Port::Double)
            val=double(0.0);
    if(datatype==Port::String)
        val=QString("");
    //数据端口
    AddPort(new Port(1,"A",Port::Input,datatype,val));
    AddPort(new Port(2,"B",Port::Input,datatype,val));
    AddPort(new Port(1,"A+B",Port::Output,datatype,val));

}
void AddNode::execute()
{

    QVariant inportDat1,inportDat2;
    inportDat1=GetPort(1,Port::Input)->Data;
    inportDat2=GetPort(2,Port::Input)->Data;
    //设置节点执行完成
    if(inportDat1.type()!=inportDat2.type())
    {
        SetPortValue(0,0,Port::Output);
        return;
    }

     //类型判断设置自己端口的输出值
    if(inportDat1.type()==QVariant::Int)
        SetPortValue(1,inportDat1.toInt()+inportDat2.toInt(),Port::Output);
    if(inportDat1.type()==QVariant::Double)
        SetPortValue(1,inportDat1.toDouble()+inportDat2.toDouble(),Port::Output);
    if(inportDat1.type()==QVariant::String)
        SetPortValue(1,inportDat1.toString()+inportDat2.toString(),Port::Output);

}
