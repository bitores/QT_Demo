#ifndef INI_PARAM_STATIC_APP_VER_H
#define INI_PARAM_STATIC_APP_VER_H

#include <QObject>

class CIPStaticAppVer : public QObject
{
    Q_OBJECT
public:
    explicit CIPStaticAppVer(QObject *parent = 0);
    ~CIPStaticAppVer();

    //拷贝构造函数
    CIPStaticAppVer(const CIPStaticAppVer& src);
    //拷贝赋值函数
    CIPStaticAppVer& operator=(const CIPStaticAppVer& src);

public:
    qint32 GetCurNum() const;
    void SetCurNum(qint32 i32CurNum);

    QString GetFortuna() const;
    void SetFortuna(const QString& strFortuna);

    QString GetNotein() const;
    void SetNotein(const QString& strNotein);

    QString GetNoteout() const;
    void SetNoteout(const QString& strNoteout);

    QString GetCoinin() const;
    void SetCoinin(const QString& strCoinin);

    QString GetCoinout() const;
    void SetCoinout(const QString& strCoinout);

    QString GetStamping() const;
    void SetStamping(const QString& strStamping);

    QString GetScanner() const;
    void SetScanner(const QString& strScanner);

    QString GetUps() const;
    void SetUps(const QString& strUps);

    QString GetLotbox() const;
    void SetLotbox(const QString& strLotbox);

    QString GetCamera() const;
    void SetCamera(const QString& strCamera);

    void Clear();
    
signals:
    
public slots:

public:
    qint32              m_i32CurNum;            //当前数量

    QString             m_strFortuna;           //终端主程序版本
    QString             m_strNotein;            //纸币进币器驱动版本
    QString             m_strNoteout;           //纸币出币器驱动版本
    QString             m_strCoinin;            //硬币进币器驱动版本
    QString             m_strCoinout;           //硬币出币器驱动版本
    QString             m_strStamping;          //兑奖模块驱动版本
    QString             m_strScanner;           //扫描仪驱动版本
    QString             m_strUps;               //ups驱动版本
    QString             m_strLotbox;            //出票模块驱动版本
    QString             m_strCamera;            //摄像头驱动版本
    
};

#endif // INI_PARAM_STATIC_APP_VER_H
