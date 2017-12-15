#define det(a,b,c) cross(vect(a,b),vect(a,c))
bool in_poly(vector<point>& l, point p){//be careful!!
int a=1,b=SZ(l)-1,c;//assumes no points on edges in CH
if (det(l[0],l[a],l[b])>0)swap(a,b);
if (det(l[0],l[a],p)>0 || det(l[0],l[b],p)<0)return 0;
while(abs(a-b)>1){
c=(a+b)/2;
if(det(l[0],l[c],p)>0)b=c;else a=c;
}return det(l[a], l[b], p) <= 0;
}// points compared lexicographically by (x, y).
//To include points on the edges of the hull,change ccw to <=.
vector<point> convex_hull(vector<point> pts){
sort(ALL(pts));vector<point> H;
REP(step,2){
auto start = H.size();
for(point P:pts){
while(SZ(H)>=start+2 && !ccw(H[SZ(H)-2],H[SZ(H)-1],P)){
H.pop_back();
}H.PB(P);
}H.pop_back();reverse(ALL(pts));
}return H;}
