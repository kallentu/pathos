#include "request/TalkRequest.h"
#include "view/View.h"
#include <string>

using namespace Pathos;

TalkRequest::TalkRequest(std::string dialogue) : npcDialogue{dialogue} {}

void TalkRequest::beDrawnBy(View &view) const { view.draw(*this); }
