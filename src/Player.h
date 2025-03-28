//
// Created by benderm on 3/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
class Map;
class Player {
private:
    int lives;
    int gold;
    int torches;
    int torchDuration;
    int rations;
    int arrows;
    int keys;
    double goldMultiplier;
    Map* map;
public:
    Player();
    Map* getMap();
    void changeMap(Map* map);
    int getLives() const;
    void changeLives(int dLives);
    int getGold() const;
    void changeGold(int dGold);
    int getTorches() const;
    void changeTorches(int dTorches);
    int getTorchDuration() const;
    void setTorchDuration(int newTorchDuration);
    void decrementTorchDuration();
    int getRations() const;
    void changeRations(int dRations);
    int getArrows() const;
    void changeArrows(int dArrows);
    int getKeys() const;
    void changeKeys(int dKeys);
    double getGoldMultiplier() const;
    void multiplyGoldMultiplier(double multiplier);
};

#endif //PLAYER_H
