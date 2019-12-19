# Mario (more) Instructions


## tl;dr
Implement a program that prints out a double half-pyramid of a specified height, per the below.

```
$ python mario.py
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```


## Specification
- Write, in a file called `mario.py` in `~/workspace/pset6/mario/more/`, a program that recreates these half-pyramids using hashes (`#`) for blocks, exactly as you did in [Problem Set 1](../pSet1/mario/more/), except that your program this time should be written (a) in Python and (b) in CS50 IDE.
- To make things more interesting, first prompt the user for the half-pyramids' heights, a positive integer between `1` and `8`, inclusive. (The height of the half-pyramids pictured above happens to be `4`, the width of each half-pyramid `4`, with a gap of size `2` separating them.)
- If the user fails to provide a positive integer no greater than `8`, you should re-prompt for the same again.
- Then, generate (with the help of `print` and one or more loops) the desired half-pyramids.
- Take care to left-align the bottom-left corner of the left-hand half-pyramid with the left-hand edge of your terminal window.


## Usage
Your program should behave per the examples below. Assume that the underlined text is what some user has typed.

```
$ python mario.py
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

```
$ python mario.py
Height: 0
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

```
$ python mario.py
Height: -5
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

```
$ python mario.py
Height: -5
Height: five
Height: 40
Height: 24
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```


Full instructions available (here)[https://docs.cs50.net/2019/x/psets/6/sentimental/mario/more/mario.html]