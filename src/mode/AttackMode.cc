#include "AttackMode.h"

using namespace Pathos;

AttackMode::AttackMode(Pathos::PathosInstance *inst, Pathos::Hostile *hostile) : Mode(inst), hostile{hostile}, handler{
    std::make_unique<AttackModeHandler>(
        hostile)} {}

ModeHandler *AttackMode::getHandler() const { return handler.get(); }