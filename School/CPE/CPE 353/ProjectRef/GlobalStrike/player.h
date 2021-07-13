#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class Player
{
public:
	Player(unsigned int uuid, QString name, QString country);
	void setUUID(unsigned int param);
	void setName(QString param);
	void setCountry(QString param);
	void setScore(int param);

	unsigned int UUID;
	QString name;
	QString country;
	int score = 0; // Needs to be cleared or set to 0 if a new game is made
};

#endif // PLAYER_H
