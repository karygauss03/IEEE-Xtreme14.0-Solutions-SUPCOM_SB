import sys

def main():
  if len(sys.argv) < 2:
    sys.exit(1)
  filename = sys.argv[1]
  dic = {
    '+': '(*ptr)++;',
    '-': '(*ptr)--;',
    '>': 'ptr++;',
    '<': 'ptr--;',
    '[': 'while(*ptr){',
    ']': '}',
    ',': '*ptr=getchar();',
    '.': 'putchar(*ptr);',
  }

  start = '\
#include <bits/stdc++.h>\n\
using namespace std;\n\
int main(){\n\
const int len = 1024 * 1024;\n\
unsigned char *mem = (unsigned char*)malloc(len);\n\
for(int i = 0;i < len;i++){ mem[i] = 0; }\n\
unsigned char *ptr = mem;'

  end = '\n\
free(mem);\n\
return 0;\n\
}'

  print(start)
  with open(filename) as f:
    for line in f:
      for char in line:
        if char in dic:
          print(dic[char])
  print(end)


if __name__ == '__main__':
  main()