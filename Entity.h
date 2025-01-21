#ifndef ENTITY_H
#define ENTITY_H

using namespace std;
#include <iostream>
#include <string>
#include <cmath>

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
    virtual Entity& operator-=(const Entity& other)=0; //reduce the currentAmountOfLife according to the received character's attackValue
    virtual Entity& operator-=(int num); //reduce the attckValue according the received number

    virtual Entity& attack(Entity& other)=0;

    int getCurrentAmountOfLife() const;
    int getAttackValue() const;
    virtual string getType() const;

    bool operator==(const Entity& other) const; //This operator will compare characters by their damage multiplied by the current amount of life they have
    bool operator>(const Entity& other) const;
    bool operator<(const Entity &other) const;

    friend ostream& operator<<(ostream& os, const Entity& other);//print
};

#endif