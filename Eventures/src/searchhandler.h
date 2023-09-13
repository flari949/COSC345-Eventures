#ifndef SEARCHHANDLER_H
#define SEARCHHANDLER_H

#include <QObject>

class SearchHandler : public QObject
{
    Q_OBJECT
public:
    explicit SearchHandler(QObject *parent = nullptr);

signals:

public slots:
    void parse(const QString &text);

};

#endif // SEARCHHANDLER_H
