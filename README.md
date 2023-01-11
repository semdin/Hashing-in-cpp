# Hashing-in-C-

What is hashing?
Hashing is the process of converting a given key into another value. It is used for a fast-access data storage in implementations called “Hash Tables”.
Let’s assume that you have values 5, 9, 23, 4, 78, 8, 42, 7, 1, 271, 251, 420 in a linked list and you want to find 251. Traditionally, you iterate from the beginning and only access 251 in your 11th iteration. However, a hash table with key value of 10 stores data like this:

0: 420
1: 1, 271, 251
2: 42
3: 23
4: 4
5: 5
6:
7: 7
8: 78, 8
9: 9

Simply, takes modulus of these variables and puts them accordingly. Therefore, if you look up for 251, you simply 251 % 10 and get 1 and only check 1’s to find 251 for a much higher search speed. This is a simple hash table application.
