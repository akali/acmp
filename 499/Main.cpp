#include <fstream>

#define P [1] 
#define O [2]
#define L [3]

int a L, b L, k, w;
 
main() {
  std :: fstream ("input.txt") >> k >> w >> a P >> b P >> a O >> b O >> a L >> b L;
  std :: ofstream ("output.txt") << ( (a P <= w & b P >= k) | (a O <= w & b O >= k) | (a L <= w & b L >= k) | 
  	                (a P + a O <= w & b P + b O >= k) | (a P + a L <= w & b P + b L >= k) | (a O + a L <= w & b O + b L >= k) | 
  	                (a P + a O + a L <= w & b P + b O + b L >= k) ? ("YES") : ("NO"));
}
