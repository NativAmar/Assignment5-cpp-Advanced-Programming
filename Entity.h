#ifndef ENTITY_H
#define ENTITY_H


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Monster;
class Player;

class Entity {

protected:
    string name;
    int maxAmountOfLife;
    int currentAmountOfLife; //should be bigger than 0 and lower/equal than maximum
    int attackValue;

public:
    //constructors
    Entity() : maxAmountOfLife(0), currentAmountOfLife(0), attackValue(0) {};
    Entity(string name,int maxAmountOfLife, int damageValue) : name(move(name)),maxAmountOfLife(maxAmountOfLife),
                                                                    currentAmountOfLife(maxAmountOfLife), attackValue(damageValue) {};
    //copy constructor
    Entity(const Entity& Esource) {
        name = Esource.name;
        maxAmountOfLife = Esource.maxAmountOfLife;
        currentAmountOfLife = Esource.currentAmountOfLife;
        attackValue =  Esource.attackValue;
    };
    //Assignment operator
    Entity& operator=(const Entity& Esource);

    //destructor
    virtual ~Entity();

    Entity& operator+=(int num); //increase the currentAmountOfLife by the num which received
    Entity& operator-=(const Entity& other); //reduce the currentAmountOfLife according to the received character's attackValue
    virtual Entity& operator-=(int num); //reduce the attckValue according the received number

    virtual Monster& MonsterAttackPlayer(Player& player);

    virtual Player& PlayerAttackMonster(Monster& monster);

    int getCurrentAmountOfLife() const;
    int getAttackValue() const;
    virtual string getType() const=0;

    bool operator==(const Entity& other) const; //This operator will compare characters by their damage multiplied by the current amount of life they have
    virtual bool operator>(const Entity& other) const;
    virtual bool operator<(const  Entity&other) const;

    friend ostream& operator<<(ostream& os, const Entity& other);//print
};

#endif