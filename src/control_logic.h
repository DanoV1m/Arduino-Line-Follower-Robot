#pragma once
struct DriveCommand { int left; int right; };
inline DriveCommand decideDrive(bool fl, bool l, bool m, bool r, bool fr) {
  if (!fl && !l && !m && !r && !fr) return {0, 0};
  if (fl && l && m && r && fr) return {100, 100};
  if (fl == fr && l == r) return m ? DriveCommand{100,100} : DriveCommand{0,0};
  if (fl && !fr) return {-120,140};
  if (fr && !fl) return {140,-120};
  if (l && !r) return {80,140};
  if (r && !l) return {140,80};
  return m ? DriveCommand{100,100} : DriveCommand{0,0};
}
