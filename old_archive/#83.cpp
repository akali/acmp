# include <iostream>

bool can(int p1, int p2)
{
 int i;
 int b[4];

 for (int i = 0; i <= n - 1; i++)
 {
  b[1] = bit(p1, i);
  b[2] = bit(p1, i + 1);
  b[3] = bit(p2, i);
  b[4] = bit(p2, i + 1);

  if (((b[1]) && (b[2]) && (b[3]) && (b[4])) || ((!b[1]) && (!b[2]) && (!b[3]) && (!b[4])))
   return false;
 }
 return true;
}

procedure determine_D;
var p1, p2 : integer;
begin
    for p1 := 0 to (1 shl n) - 1 do
        for p2 := 0 to (1 shl n) - 1 do
            if can(p1, p2) then d[p1, p2] :=1
            else d[p1, p2] := 0;
end;
