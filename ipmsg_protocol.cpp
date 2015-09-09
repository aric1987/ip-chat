#include "ipmsg_protocol.h"

IpmsgProtocol::IpmsgProtocol(const QString &name, QObject *parent) :
	QObject(parent)
{
	localName = name;
}
