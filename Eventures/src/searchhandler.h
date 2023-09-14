/*!
* @file searchhandler.h
* @brief This file contains the declaration of the SearchHandler class,
* responsible for handling search query on GUI searchbar by user.
* User searches for city they want to look for events in around New Zealand
*/
#ifndef SEARCHHANDLER_H
#define SEARCHHANDLER_H

#include <QObject>

class SearchHandler : public QObject
{
    Q_OBJECT
public:
    /*!
    * @brief Constructor for the SearchHandler class.
    * @param parent The parent QObject (default is nullptr).
    */
    explicit SearchHandler(QObject *parent = nullptr);

signals:

public slots:
    /*!
    * @brief Parses and processes the provided text as a search query.
    * @param text The search query text to be parsed.
    */
    void parse(const QString &text);

};

#endif // SEARCHHANDLER_H
