#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char z[256];

void init() {
  z['a']='o'; z['b']='p'; z['c']='q'; z['d']='r'; z['e']='s'; z['f']='t'; z['g']='u'; z['h']='v'; z['i']='w'; z['j']='x'; z['k']='y'; z['l']='z'; z['m']='a'; z['n']='b'; z['o']='c'; z['p']='d'; z['q']='e'; z['r']='f'; z['s']='g'; z['t']='h'; z['u']='i'; z['v']='j'; z['w']='k'; z['x']='l'; z['y']='m'; z['z']='n'; 
  z['A']='O'; z['B']='P'; z['C']='Q'; z['D']='R'; z['E']='S'; z['F']='T'; z['G']='U'; z['H']='V'; z['I']='W'; z['J']='X'; z['K']='Y'; z['L']='Z'; z['M']='A'; z['N']='B'; z['O']='C'; z['P']='D'; z['Q']='E'; z['R']='F'; z['S']='G'; z['T']='H'; z['U']='I'; z['V']='J'; z['W']='K'; z['X']='L'; z['Y']='M'; z['Z']='N'; 
}

bool check(char x) {
  if ('a' <= x && x <= 'z') return true;
  if ('A' <= x && x <= 'Z') return true;
  return false;
}

// q
signed main(void) {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  #ifdef ziwok
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
  init();

  string s, s1;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); i++) {
      if (check(s[i])) {
        putchar(z[s[i]]);
      } else putchar(s[i]);
    }
    putchar(endl);
  }
  return 0;
}