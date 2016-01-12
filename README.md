# Gray-Codes

The reflected binary code, also known as Gray code after Frank Gray, is a binary numeral system where two successive values differ in only one bit (binary digit). The reflected binary code was originally designed to prevent spurious output from electromechanical switches. Today, Gray codes are widely used to facilitate error correction in digital communications such as digital terrestrial television and some cable TV systems.

Many devices indicate position by closing and opening switches. If that device uses natural binary codes, positions 3 and 4 are next to each other but all three bits of the binary representation differ:

Decimal	Binary
...	...
3	011
4	100
...	...

The problem with natural binary codes is that, with physical, mechanical switches, it is very unlikely that switches will change states exactly in synchrony. In the transition between the two states shown above, all three switches change state. In the brief period while all are changing, the switches will read some spurious position. Even without keybounce, the transition might look like 011 — 001 — 101 — 100. When the switches appear to be in position 001, the observer cannot tell if that is the "real" position 001, or a transitional state between two other positions. If the output feeds into a sequential system, possibly via combinational logic, then the sequential system may store a false value.

The reflected binary code solves this problem by changing only one switch at a time, so there is never any ambiguity of position,

Decimal	 |  Binary  |  Gray  |  GrayAsDecimal	

   0     |   000    |   000  |      0
   1     |   001    |   001  |      1
   2     |   010    |   011  |      3
   3     |   011    |   010  |      2
   4     |   100    |   110  |      6
   5     |   101    |   111  |      7
   6     |   110    |   101  |      5
   7     |   111    |   100  |      4

Notice that state 7 can roll over to state 0 with only one switch change. This is called the "cyclic" property of a Gray code. In the standard Gray coding the least significant bit follows a repetitive pattern of 2 on, 2 off ( … 11001100 … ); the next digit a pattern of 4 on, 4 off; and so forth.

More formally, a Gray code is a code assigning to each of a contiguous set of integers, or to each member of a circular list, a word of symbols such that each two adjacent code words differ by one symbol. These codes are also known as single-distance codes, reflecting the Hamming distance of 1 between adjacent codes. There can be more than one Gray code for a given word length, but the term was first applied to a particular binary code for the non-negative integers, the binary-reflected Gray code, or BRGC, the three-bit version of which is shown above.
