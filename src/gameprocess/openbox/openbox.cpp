#include "openbox.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

// add your code to implement the Pause class here

// ACTION_INIT is a state where nothing has been input.

OpenBox::OpenBox(){

}

OpenBox::~OpenBox(){

}

ProcessInfo OpenBox::run(InputState action){
    if(action != ACTION_INIT){
        return OPEN_BOX_FINISH_MOVE;
    }
    return CONTINUE;
}






void OpenBox::render() {
    AnsiPrint("\n\n\n", black, black);
    AnsiPrint("            ██████████████        ", white, black);
    AnsiPrint("    You get a powerful diamond!     \n", cyan, black);
    AnsiPrint("          ████", white, black);
    AnsiPrint("██████████", pink, black);
    AnsiPrint("████    \n", white, black);
    AnsiPrint("        ██", white, black);
    AnsiPrint("████", blue, blue);
    AnsiPrint("██", white, white);
    AnsiPrint("██████", pink, pink);
    AnsiPrint("██", white, white);
    AnsiPrint("████", red, black);
    AnsiPrint("██    ", white, black);
    AnsiPrint("    Additional skills :            \n", cyan, black);
    AnsiPrint("      ██", white, black);
    AnsiPrint("████████", blue, blue);
    AnsiPrint("██", white, white);
    AnsiPrint("██", pink, pink);
    AnsiPrint("██", white, white);
    AnsiPrint("████████", red, red);
    AnsiPrint("██\n", white, white);
    AnsiPrint("    ██████████████████████████████", white, black);
    AnsiPrint("    • Attack × 2                  \n", cyan, black);
    AnsiPrint("    ██", white, black);
    AnsiPrint("████████████", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("████████████", yellow, white);
    AnsiPrint("██\n", white, white);
    AnsiPrint("      ██", white, black);
    AnsiPrint("██████████", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("██████████", yellow, yellow);
    AnsiPrint("██  ", white, white);
    AnsiPrint("    • Maxhealth × 2               \n", cyan, black);
    AnsiPrint("        ██", white, black);
    AnsiPrint("████████", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("██████████", yellow, yellow);
    AnsiPrint("██\n", white, black);
    AnsiPrint("          ██", white, black);
    AnsiPrint("██████", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("████████", yellow, yellow);
    AnsiPrint("██    ", white, black);
    AnsiPrint("    • Healpower × 2               \n", cyan, black);
    AnsiPrint("            ██", white, black);
    AnsiPrint("████", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("████", yellow, yellow);
    AnsiPrint("████\n", white, black);
    AnsiPrint("              ██", white, black);
    AnsiPrint("██", green, green);
    AnsiPrint("██", white, white);
    AnsiPrint("██", yellow, yellow);
    AnsiPrint("██          ", white, black);
    AnsiPrint("    • Recover all health          \n", cyan, black);
    AnsiPrint("                ██████            \n", white, black);
    AnsiPrint("                  ██              ", white, black);
    AnsiPrint("    • Change your skin            \n", cyan, black);
    AnsiPrint("\n\n\n", black, black);
}
