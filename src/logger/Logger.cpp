#include <QMutex>
#include <QDateTime>
#include <QMouseEvent>

#include "Logger.h"

SingletonLogger::SingletonLogger(QWidget *parent)
    : QWidget(parent)
{
}

SingletonLogger::~SingletonLogger()
{
}

SingletonLogger &SingletonLogger::instance()
{
    static SingletonLogger logger;
    logger.setMouseTracking(true);
    return logger;
}

void redirectMessageHandle(QtMsgType type, const QMessageLogContext &context, const QString &str)
{
    SingletonLogger &logger = SingletonLogger::instance();
    QString message = QString("%1 %2:%3 %4")
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
                          .arg(context.file)
                          .arg(context.line)
                          .arg(str);

    emit logger.log(message);
}
