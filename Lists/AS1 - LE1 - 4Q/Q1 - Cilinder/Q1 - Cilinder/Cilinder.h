#include "Cilinder.c"

Cilinder* CreateCilinder ();
void SetDataToCilinder (Cilinder* c, int x, int y, float alt, float r);

//float ReturnCilinderHeight (Cilinder* c);

//float ReturnCilinderRadius (Cilinder* c);

float ReturnCilinderVolume (Cilinder* c);
//Should ReturnCilinderVolume and ReturnCilinderArea be put here in .h or just inside Cilinder.c?
//I guess the idea is to let the user only use certain functions, and these returns should be just internal commands,
//so they should be removed... but I'm not sure.
float ReturnCilinderArea (Cilinder* c);

void ShowCilinderData(Cilinder* c, int n);

void FreeCilinder (Cilinder* c);
