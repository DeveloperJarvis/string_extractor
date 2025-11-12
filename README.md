# String Extractor
A microproject to create a simple string extractor

### Install GCC
For Ubuntu:
```bash
sudo apt install gcc -y
```

## Compile using gcc
```bash
gcc -g -Wall -Wextra -o strex strex.c
```

## Execute the object file
1. Simple execute
```bash
./strex
```
2. Execute by passing echo
```bash
echo "Hello World" | ./strex
```


**Note:** 
1. This is a utility that shows binary data of string passed in echo
```bash
echo "Hello" | xxd
## expected output:
00000000: 4865 6c6c 6f0a                           Hello.
```
2. If we append -n in the above statement 
```bash
echo -n "Hello" | xxd
## expected output:
00000000: 4865 6c6c 6f                           Hello
```

**Note:** For manual pages (in Ubuntu)
```bash
# man <package_name>
man getchar
man ascii
# press q to quit man pages
# man <section_number> <package_name>
man 2 open
```

**Note:** In xxd, 
-r          reverse operation: convert (or patch) hexdump into binary.
-ps         output in postscript plain hexdump style
```bash
echo "48656c6c6f0a" | xxd -r -p
echo "CAACCAEFFE48656c6c6fEFFEACCAAC0A" | xxd -r -ps > sample
less sample
# press q to quit
# to execute with file use
cat sample | ./strex
```

```bash
xxd sample
00000000: caac caef fe48 656c 6c6f effe acca ac0a  .....Hello......
```

```bash
echo "CAACCAEFFE48656c6c6fEFFEACCAAC0A" | xxd -r -ps | ./strex
Hello
```

## ASCII Tables

For convenience, below are more compact ASCII tables in **hex** and **decimal** form.

### Hex Table

```text
      2 3 4 5 6 7
    -------------
   0:   0 @ P ` p
   1: ! 1 A Q a q
   2: " 2 B R b r
   3: # 3 C S c s
   4: $ 4 D T d t
   5: % 5 E U e u
   6: & 6 F V f v
   7: ' 7 G W g w
   8: ( 8 H X h x
   9: ) 9 I Y i y
   A: * : J Z j z
   B: + ; K [ k {
   C: , < L \ l |
   D: - = M ] m }
   E: . > N ^ n ~
   F: / ? O _ o DEL
```

### Decimal Table

```text
      30 40 50 60 70 80 90 100 110 120
    ---------------------------------
   0:    (  2  <  F  P  Z  d   n   x
   1:    )  3  =  G  Q  [  e   o   y
   2:    *  4  >  H  R  \  f   p   z
   3: !  +  5  ?  I  S  ]  g   q   {
   4: "  ,  6  @  J  T  ^  h   r   |
   5: #  -  7  A  K  U  _  i   s   }
   6: $  .  8  B  L  V  `  j   t   ~
   7: %  /  9  C  M  W  a  k   u  DEL
   8: &  0  :  D  N  X  b  l   v
   9: '  1  ;  E  O  Y  c  m   w

```

**NOTE:** Can use openssl rand to generate random data
```bash
openssl rand -hex 16
394026046acb00debb6960ff5960733b

openssl rand -hex 64 | xxd -r -p | ./strex
vk``U
```

**NOTE:** You can use hexedit to edit a hexadecimal file
```bash
# for installing hexedit on ubuntu
sudo apt install hexedit
# usage
hexedit
hexedit <filename>
```
