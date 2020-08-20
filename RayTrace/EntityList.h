#pragma once
#include <memory>
#include <vector>
#include "Entity.h"
using std::shared_ptr;
using std::make_shared;

class EntityList : public Entity {
public:
    EntityList() {}
    EntityList(shared_ptr<Entity> object) { add(object); }

    void clear() { ents.clear(); }
    void add(shared_ptr<Entity> object) { ents.push_back(object); }

    hitInfo getHitInfo(const Ray& r, const hitInfo& info, double t_min, double t_max) const;

private:
    std::vector<shared_ptr<Entity>> ents;
};

hitInfo EntityList::getHitInfo(const Ray& r, const hitInfo& info, double t_min, double t_max) const
{
    hitInfo hit, returnedInfo;
    hit.hitEntity = false;
    returnedInfo = info;
    double closest = t_max;

    for (const shared_ptr<Entity>& e : ents) 
    {
        hitInfo hitLocal = e->getHitInfo(r, hit, t_min, closest);
        if (hitLocal.hitEntity) 
        {
            hit.hitEntity = true;
            closest = hit.t;
            returnedInfo = hit;
        }
    }

    return returnedInfo;
}