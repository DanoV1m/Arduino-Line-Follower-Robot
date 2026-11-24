#include "../src/control_logic.h"
#include <cassert>
int main() {
  for (int mask=0; mask<32; ++mask) {
    bool a=mask&16,b=mask&8,c=mask&4,d=mask&2,e=mask&1;
    auto x=decideDrive(a,b,c,d,e), y=decideDrive(e,d,c,b,a);
    assert(x.left==y.right && x.right==y.left);
    assert(x.left>=-255 && x.left<=255 && x.right>=-255 && x.right<=255);
  }
  auto lost=decideDrive(0,0,0,0,0); assert(lost.left==0 && lost.right==0);
  auto cross=decideDrive(1,1,1,1,1); assert(cross.left==100 && cross.right==100);
  auto sharp=decideDrive(1,0,1,0,0); assert(sharp.left<0 && sharp.right>0);
}
