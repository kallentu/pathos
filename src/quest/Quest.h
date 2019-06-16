#ifndef PATHOS_QUEST
#define PATHOS_QUEST

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/quest/QuestRecipient.h"
#include <map>
#include <string>

namespace Pathos {

// TODO: Have function to check progress of the quest.
class Quest {
public:
  enum Status { NotStarted, InProgress, Completed };

  // QuestGivers are always mandatory for the player to return to, while
  // QuestRecipients are an intermediate step in the quest that may not be
  // needed.
  Quest(QuestGiver *questGiver)
      : status{NotStarted}, questGiver{questGiver}, questRecipient{nullptr} {}
  virtual ~Quest() {}

  void setStatus(Status s) { status = s; }
  Status getStatus() const { return status; }

  void setQuestGiver(QuestGiver *qg) { questGiver = qg; }
  QuestGiver *getQuestGiver() const { return questGiver; }

  void setQuestRecipient(QuestRecipient *qp) { questRecipient = qp; }
  QuestRecipient *getQuestRecipient() const { return questRecipient; }

  void addDialogue(Status status, std::string newDiag) {
    dialogue[status] = newDiag;
  }
  std::string getDialogue(Status status) { return dialogue[status]; }

  // Updates Status if conditions changed the status of the quest.
  Quest::Status updateQuestStatus(PathosInstance *inst) {
    Status newStatus = checkConditions(inst);
    if (status != newStatus) {
      setStatus(newStatus);
    }
    return newStatus;
  }

private:
  Status status;

  // Will always report back to QuestGiver if completed/failed.
  QuestGiver *questGiver;

  // Nullable, doesn't need a recipient.
  QuestRecipient *questRecipient;

  // Dialogue based on the status of the quest and spoken by the QuestGiver.
  // Loophole is to make players send an additional letter to QuestRecipients if
  // needed.
  std::map<Status, std::string> dialogue;

  // Runs condition checker of quest (eg. update in certain mob kill count since
  // last)
  virtual Status checkConditions(PathosInstance *inst) = 0;
};

} // namespace Pathos

#endif // PATHOS_QUEST
