#ifndef IPMSG_PROTOCOL_H
#define IPMSG_PROTOCOL_H

#include <QObject>

class IpmsgProtocol : public QObject
{
	Q_OBJECT
public:
	enum Version
	{
		VERISON_IPMSG=0,
		VERSION_FEIQ
	};
private:
	QString localName;
signals:
	void cmdReady(quint32 type, QByteArray *dataByteArray);
public slots:

public:
	explicit IpmsgProtocol(const QString &name, QObject *parent=0);
	void encode(quint32 type, QByteArray &dataByteArray, QByteArray &cmdByteArray);
	void decode(QByteArray &cmdByteArray);
};

#endif // IPMSG_PROTOCOL_H
