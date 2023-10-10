# HighestValuePalindrome

## Description

Palindromes are strings that read the same from the left or right, for example, madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make. Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes. The length of the string may not be altered, so you must consider _0_'s left of all higher digits in your tests. For example, _0110_ is valid, _0011_is not.

Given a string representing the starting number, and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string '-1' if it is not possible to create a palindrome under the constraints. 

## Returns

- string: a string representation of the highest value achievable or -1

## Input

- The first line contains two space-separated integers, _n_ and _k_, the number of digits in the number and the maximum number of changes allowed.
- The second line contains an _n_-digit string of numbers. 
