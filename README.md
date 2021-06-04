# Hyper Darts Simulator
_A ridiculously over-engineered simulator for estimating the answer to the Hyper Darts (Shrkinking Bullseye) problem_

## The Problem
This simulator was inspired by [this awesome video](https://youtu.be/6_yU9eJ0NxA) by [Numberphile](https://www.youtube.com/channel/UCoxcjq-8xIDTYp3uz647V5A), featuring [3Blue1Brown](https://www.youtube.com/channel/UCYO_jab_esuFRV4b17AJtAw). The problem was devised by [Greg Egan](https://twitter.com/gregeganSF) in [this tweet](https://twitter.com/i/status/1160461092973211648).
In essence though the problem is as follows:
- The perculiar game of 'Hyper Darts' starts of with a big bullseye
- Every time the player shoots within the bullseye, it gets smaller
- The new radius of the bullseye is the length of the perpendicular chord that contains the dart in the old bullseye
- So the closer you hit to the center of the bullseye the less the bullseye will shrink
- If you hit outside the bullseye it is game over and your score is the number of darts you've thrown (or 1 + the number of times you hit the bullseye)
- Now suppose that a player throws a darts that has an equal chance to hit anywhere within a square circumscribed around the original bullseye
- What is the expected score of that player? Or in other words if that player were to play an infinite amount of Hyper Darts games what will the average score be?

## The Simulator
Once I heard the problem in the video I knew it was a relatively simple and straightforward simulation to do and so I wanted to do it. I didn't even watch the rest of the video, because I didn't want to spoil the answer for myself.

**⚠ Spoiler Alert:** If you don't want to spoil the answer for yourself, here is probably the place to stop reading for the moment.

I thought I'd use C++ for better performance and I got the simulation working in C++ very quickly actually. Here's the thing though... I could've just let it run for half a day or something, but I thought I'd use multithreading so that the simulation ran faster. The thing is, I hadn't really ever used multithreading in C++, so I knew this was gonna be a learning experience. I didn't anticipate though just how much stuff you have to consider and keep in mind when multithreading. The actual threading part was pretty easy actually using `std::thread`. That is not enough unfortunately, because almost everything in your program has to be made with multithreading in mind. From storing the results of the simulations to even the random number generation, it all had to be done seperately on each thread just to work. Random number generation especially gave me a lot of trouble as I just hadn't thought of the fact that you need different random devices for each thread, or else the results were quite a long way off.
