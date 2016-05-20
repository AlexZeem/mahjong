#pragma once
#include <QObject>
#include "../persistence/Participant.h"

namespace cabinet {
class GameInfoMediator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int ParticipatedIn READ ParticipatedIn NOTIFY ParticipatedInChanged)

 public:
    GameInfoMediator(QObject *parent = 0);
    int ParticipatedIn () const;

 signals:
    void participationChanged();
    void ParticipatedInChanged();

 public slots:
    void setParticipation(QString login);

 private:
    QVector <persistence::Participant> participated;

}; // gameInfoMediator
} // cabinet
