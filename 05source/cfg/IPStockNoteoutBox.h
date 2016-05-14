#ifndef INI_PARAM_STOCK_NOTEOUT_BOX_H
#define INI_PARAM_STOCK_NOTEOUT_BOX_H

#include <QObject>

class CIPStockNoteoutBox : public QObject
{
    Q_OBJECT
public:
    explicit CIPStockNoteoutBox(QObject *parent = 0);
    ~CIPStockNoteoutBox();

    //拷贝构造函数
    CIPStockNoteoutBox(const CIPStockNoteoutBox& src);
    //拷贝赋值函数
    CIPStockNoteoutBox& operator=(const CIPStockNoteoutBox& src);

public:
    qint32 GetFace() const;
    void SetFace(qint32 i32Face);

    qint32 GetTotalNoteNum() const;
    void SetTotalNoteNum(qint32 i32TotalNoteNum);

    qint32 GetBoxNoteNum() const;
    void SetBoxNoteNum(qint32 i32BoxNoteNum);

    qint32 GetRejectNoteNum() const;
    void SetRejectNoteNum(qint32 i32RejectNoteNum);

    qint32 GetRejectCount() const;
    void SetRejectCount(qint32 i32RejectCount);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32Face;              //出钞箱面值
    qint32              m_i32TotalNoteNum;      //总张数(钱箱总张数=拒付箱张数+钞箱内张数)
    qint32              m_i32BoxNoteNum;        //出钞箱当前数量,钞箱内当前剩余张数(不含拒付箱内张数)
    qint32              m_i32RejectNoteNum;     //出钞箱拒付数量,拒付箱内当前剩余张数
    qint32              m_i32RejectCount;       //拒付次数,当前拒付次数
    
};

#endif // INI_PARAM_STOCK_NOTEOUT_BOX_H
