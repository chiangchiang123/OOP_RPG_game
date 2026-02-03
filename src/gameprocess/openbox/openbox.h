#ifndef OPENBOX_H
#define OPENBOX_H

#include "../gameprocess.h"

class OpenBox: public GameProcessBase {
private:
    
public:
    OpenBox();
    ~OpenBox();

    ProcessInfo run(InputState action);

    void render();
};

#endif