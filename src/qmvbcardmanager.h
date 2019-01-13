#ifndef QMVBCARDMANAGER_H
#define QMVBCARDMANAGER_H

#include <QObject>
#include <QMap>
#include "qmvbcard.h"

class QAbstractMvbProtocol;
class QAbstractMvbDriver;

/*
 * The class is multifunction vehicle bus card manager which is singleton mode,
 * it is used to manage mvb card, like crate cards, remove cards or get cards.
 */
class QMvbCardManager : public QObject
{
public:
    ~QMvbCardManager();

    /*
     * Brief    Get the manager
     * Param    void
     * Return   The pointer of manager
     */
    static QMvbCardManager *getManager();

    /*
     * Brief    Add a mvb card to the manager.
     * Param    "name" is the unique card name
     *          "protocol" is the protocol that is used to parse data,
     *                     default protocol would be applied if it is nullptr.
     * Return  Return the pointer of the mvb card.
     */
    QMvbCard *addMvbCard(const QString name, QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol = nullptr);

    /*
     * Brief    Remove the mvb card from the manager including all information on it
     * Param    "name" is the unique card name
     * Return   Return true if remove successfully, or return false.
     */
    bool removeMvbCard(const QString name);

    /*
     * Brief    Add a mvb card to the manager
     * Param    "name" is the card name
     * Return   Return the pointer of the mvb card, if the name you specify doesn't exist, return nullptr.
     */
    QMvbCard *getMvbCard(const QString name) const;

    QList<QMvbCard *> getAllCard() const;
    QList<QString> getAllCardName() const;
    qint16 getCardSum() const;

private:
    /*
     * Brief    The constructor of the class, it is private for singleton mode.
     * Param    void
     * Return   void
     */
    QMvbCardManager();

private:
    static QMvbCardManager *manager;
    QMap<QString, QMvbCard *> cardMap;
};

#endif // QMVBCARDMANAGER_H
