#ifndef PORT_H
#define PORT_H

#include<QMap>
#include <QPainter>
#include <QGraphicsItem>

class Port
{
public:
    //端口类型
    enum PortType { None,InStream,OutStream, Input, Output };
    //端口数据类型
    enum PortDataType {Stream,Int,Bool,String,Double,Bit,Vector2,Vector3,Color};


    bool IsValid()
    {
        return portType!=None;
    }
    Port():portType(None)
    {

    }
    Port(uint id,QString Name="Port",PortType type=Input,PortDataType portDataType=Int,QVariant Data=0)
        :portType(type),
        ID(id),
        Name(Name),
        Data(Data),
        portDataType(portDataType),
        portColor(PortColorMap[portDataType])
    {

            //设置端口颜色范围和端口文字范围和文字框对齐方向
            portRect=(portType==Input||portType==InStream)?QRectF(5,50+ID*30,20,20):QRectF(135,50+ID*30,20,20);
            portTextRect=(portType==Input||portType==InStream)?QRectF(28,50+ID*28,50,28):QRectF(83,50+ID*28,50,28);
            TextAlign=(portType==Input||portType==InStream)?Qt::AlignLeft:Qt::AlignRight;




    }





    //端口数据类型检测


    // 端口类型检测
    bool PortTypeCheck(PortType traporttype)
    {
        if(traporttype==InStream)
            return portType==OutStream;
        if(traporttype==OutStream)
            return portType==InStream;
        if(traporttype==Input)
            return portType==Output;
        if(traporttype==Output)
            return portType==Input;

        return portType==OutStream;
    }

    //端口存放的数据
    QVariant Data{0};
    //端口类型
    PortType portType;
    //端口数据类型
    PortDataType portDataType;
    //端口ID
    uint ID=0 ;
    //端口名称
    QString Name{"Port"};
    //端口范围
    QRectF portRect;
    //端口文字范围
    QRectF portTextRect;
    //端口文字对齐
    Qt::AlignmentFlag TextAlign;

    //端口颜色
    QColor portColor;

    //是否连接
    bool IsConnected=false;

    //更新端口信息
    void update()
    {
        if(portType==Input||portType==Output)
        {
            //设置端口颜色范围和端口文字范围和文字对齐方向
            portRect=(portType==Input)?QRectF(3,45+ID*30,20,20):QRectF(127,45+ID*30,20,20);
            portTextRect=(portType==Input)?QRectF(25,45+ID*28,50,28):QRectF(75,45+ID*28,50,28);
            TextAlign=(portType==Input)?Qt::AlignLeft:Qt::AlignRight;
        }
        else if(portType==InStream||portType==OutStream)
        {
            //设置端口颜色范围和端口文字范围和文字对齐方向
            portRect=(portType==InStream)?QRectF(8,10,20,20):QRectF(125,10,20,20);
        }
         portColor=PortColorMap[portDataType];
    }

    //端口数据类型颜色表
    inline static QMap<PortDataType,QColor> PortColorMap
    {
      {Stream,QColor(240,240,240)},
      {Int,QColor(106,34,136)},
      {Bool,QColor(200,50,170)},
      {String,QColor(56,136,34)},
      {Bit,QColor(160,160,100)},
      {Double, QColor(34, 136, 204)},
      {Vector2, QColor(136, 84, 68)},
      {Vector3, QColor(136, 34, 68)},
      {Color, QColor(85, 34, 136)}
    };

    //端口数据类型名字表
    inline static QMap<PortDataType,QString> PortDataTypeNameMap
        {
            {Stream,"程序控制流"},
            {Int,"整数"},
            {Bool,"布尔值"},
            {String,"字符串"},
            {Double,"小数"},
            {Bit, "比特"},
            {Vector2,"2维向量"},
            {Vector3,"3维向量"},
            {Color, "颜色"}
        };

};







#endif // PORT_H
