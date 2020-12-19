#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
  const size_t szA = a.size(), szB = b.size(), 
               diff = szA > szB ? szA - szB : szB - szA;

  string res;
  bool carry = false;
  char c;
  const auto& sLong = szA > szB ? a : b;
  const auto& sShrt = szA > szB ? b : a;
  printf("szA, szB: %zu, %zu\n", szA, szB);
  for (size_t i = sLong.size(); i-- > diff;) {
    printf("%zu\n", i);
    if (sLong[i] == '1' && sShrt[i - diff] == '1') {
      c = carry ? '1' : '0';
      carry = true;
    }
    else if ((sLong[i] == '1' && sShrt[i - diff] == '0') || 
             (sLong[i] == '0' && sShrt[i - diff] == '1')) {
      c = carry ? '0' : '1';
    }
    else { // both 0
      c = carry ? '1' : '0';
      carry = false;
    }
    res.push_back(c);
    printf("%s\n", res.c_str());
  }

/*c:01110
    10101
      111
    -----
    11100*/
  
  printf("diff: %zu\n", diff);
  for (size_t i = diff; i-- > 0;) {
    if (sLong[i] == '0') {
      c = carry ? '1' : '0';
      carry = false;
    }
    else {
      c = carry ? '0' : '1';
    }
    res.push_back(c);
  }

  if (carry)
    res.push_back('1');

  std::reverse(res.begin(), res.end());
  return res;
};

int main() {
	string r = addBinary("10101", "111");
	printf("Result: %s\n", r.c_str());
	return 0;
}