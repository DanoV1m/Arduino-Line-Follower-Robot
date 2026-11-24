#include "../src/line_pid.h"
#include <cassert>
int main() {
  LinePid pid(35,4,0.6f);
  auto center=pid.update(0,0,1,0,0,.02f); assert(center.left==100 && center.right==100);
  for(int mask=0; mask<32; ++mask) {
    auto cmd=pid.update(mask&16,mask&8,mask&4,mask&2,mask&1,.02f);
    assert(cmd.left>=0 && cmd.left<=200 && cmd.right>=0 && cmd.right<=200);
  }
  auto lost=pid.update(0,0,0,0,0,.02f); assert(lost.left==0 && lost.right==0);
  auto right=pid.update(0,0,0,0,1,.02f); assert(right.left>right.right);
  auto invalid=pid.update(0,0,1,0,0,0); assert(invalid.left==0 && invalid.right==0);
  auto cross=pid.update(1,1,1,1,1,.02f); assert(cross.left==100 && cross.right==100);
}
