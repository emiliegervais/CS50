# Mario (less) Instructions


## tl;dr
Implement a program that prints out a half-pyramid of a specified height, per the below.

```
$ python mario.py
Height: 5
    #
   ##
  ###
 ####
#####
```

```
$ python mario.py
Height: 3
  #
 ##
###
```


## Specification
- Write, in a file called `mario.py` in `~/workspace/pset6/mario/less/`, a program that recreates this half-pyramid using hashes (`#`) for blocks, exactly as you did in [Problem Set 1](../pSet1/mario/less/), except that your program this time should be written (a) in Python and (b) in CS50 IDE.
- To make things more interesting, first prompt the user for the half-pyramid’s height, a positive integer between `1` and `8`, inclusive.
- If the user fails to provide a positive integer no greater than `8`, you should re-prompt for the same again.
- Then, generate (with the help of `print` and one or more loops) the desired half-pyramid.
- Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.


## Usage
Your program should behave per the examples below. Assume that the underlined text is what some user has typed.

```
$ python mario.py
Height: 4
   #
  ##
 ###
####
```

```
$ python mario.py
Height: 0
Height: 4
   #
  ##
 ###
####
```

```
$ python mario.py
Height: -5
Height: 4
   #
  ##
 ###
####
```

```
$ python mario.py
Height: -5
Height: five
Height: 40
Height: 24
Height: 4
   #
  ##
 ###
####
```


Full instructions available (here)[https://docs.cs50.net/2019/x/psets/6/sentimental/mario/less/mario.html]