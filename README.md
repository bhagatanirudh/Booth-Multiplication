# Booth's Multiplication Algorithm : 
The booth algorithm is a multiplication algorithm that allows us to multiply the two signed binary integers in 2's complement, respectively. It is also used to speed up the performance of the multiplication process.

# Flow Chart : 
![booths-multiplication-algorithm-in-coa](https://user-images.githubusercontent.com/87819222/197015866-176c4653-af4f-4e0f-96cd-e7e0a8f404cf.png)

# Working on the Booth Algorithm : 
1. Set the Multiplicand and Multiplier binary bits as M and Q, respectively.
2. Initially, we set the AC and Qn + 1 registers value to 0.
3. SC represents the number of Multiplier bits (Q), and it is a sequence counter that is continuously decremented till equal to the number of bits (n) or reached to 0.
4. A Qn represents the last bit of the Q, and the Qn+1 shows the incremented bit of Qn by 1.On each cycle of the booth algorithm, Qn and Qn + 1 bits will be checked on the following parameters as follows : 
	 (i) When two bits Qn and Qn + 1 are 00 or 11, we simply perform the arithmetic shift right operation (ashr) to the partial product AC. And the bits of Qn and Qn+1 is incremented by 1 bit.
	(ii) If the bits of Qn and Qn + 1 is shows to 01, the multiplicand bits (M) will be added to the AC (Accumulator register). After that, we perform the right shift operation to the AC and QR bits by 1.
   (iii) If the bits of Qn and Qn + 1 is shows to 10, the multiplicand bits (M) will be subtracted from the AC (Accumulator register). After that, we perform the right shift operation to the AC and QR bits by 1.
6. The operation continuously works till we reached n - 1 bit in the booth algorithm.
7. Results of the Multiplication binary bits will be stored in the AC and QR registers.
