//
// Created by benderm on 3/26/2025.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
private:
    int lives;
    int gold;
    int torches;
    int torchDuration;
    int rations;
    int arrows;
    int keys;
public:
    Player();
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
};



#endif //PLAYER_H
