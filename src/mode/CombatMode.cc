#include "mode/CombatMode.h"

using namespace Pathos;

CombatMode::CombatMode(Pathos::PathosInstance *inst, Pathos::Hostile *hostile) : Mode(inst), hostile{hostile}, handler{
    std::make_unique<CombatModeHandler>(hostile, inst)} {}

ModeHandler *CombatMode::getHandler() const { return handler.get(); }