#pragma once
#include "Character.h"
class Enemy :
    public Character
{
public:
    Enemy() = default;
    virtual ~Enemy() = default;

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

};

