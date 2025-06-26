#include "Silencer.h"
#include "Mission.h"

Silencer::Silencer() : Item("Tłumik") {}

void Silencer::applyEffect(Mission &mission)
{
    mission.setHasSilencer(true);
}
