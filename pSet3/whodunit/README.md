# Whodunit Instructions


## tl;dr
1. Answer the questions in `question.md`.
2. Help Mr. Boddy figure out who has done it by discovering the hidden message contained in the only evidence we have, the 24-bit BMP file `clue.bmp`.


## Specification
1. Open up `questions.md` and replace every TODO therein with your answer to the question above it.
2. Try and change the pixels at some point between reading from the source and writing to the destination?

"What if, perhaps. we wanted to turn all of the white pixels black, reasoning that the higher contrast might make for better readability? Or what if we just wanted to turn white all of that red “noise” in the image? Or if we wanted to better-simulate the idea of that red piece of plastic, and give everything a reddish shade? We can use some conditional logic, perhaps, to check the different properties of triple first, and then decide what to do with it based on evaluating that boolean expression."


## Usage
To reveal the answer to this mystery:

```
./whodunit clue.bmp verdict.bmp
```


Full instructions available [here](https://lab.cs50.io/cs50/labs/2019/x/whodunit/)