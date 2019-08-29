#ifndef PLAYAREA_H_
#define PLAYAREA_H_

#include "LibCard/CardCollection.h"
#include "LibCard/Deck.h"
#include "Constants.h"

namespace FREECELL
{
class PlayArea : public LIBCARD::CardCollection<PLAY_AREA_SIZE>
{
    public:
        PlayArea();
        ~PlayArea();
        void Add(LIBCARD::Deck& _deck);

    private:
};
}

#endif // ifndef PLAYAREA_H_
