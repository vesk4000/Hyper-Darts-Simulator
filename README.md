# Hyper Darts Simulator
_A ridiculously over-engineered simulator for estimating the answer to the Hyper Darts (Shrkinking Bullseye) problem_

## The Problem
This simulator was inspired by [this awesome video](https://youtu.be/6_yU9eJ0NxA) by [Numberphile](https://www.youtube.com/channel/UCoxcjq-8xIDTYp3uz647V5A), featuring [3Blue1Brown](https://www.youtube.com/channel/UCYO_jab_esuFRV4b17AJtAw). The problem was devised by [Greg Egan](https://twitter.com/gregeganSF) in [this tweet](https://twitter.com/i/status/1160461092973211648).
<table>
  <tr>
    <th>In essence the problem is as follows:</th>
	  <th>Here's a gif from Greg's tweet, which illustrates the problem well:</th>
  </tr>
  <tr>
	  <td>

- The perculiar game of 'Hyper Darts' starts of with a giant bullseye
- Every time the player shoots within the bullseye, it becomes smaller
- The new radius of the bullseye is the length of the perpendicular chord (in the old bullseye) that contains the dart 
- So the closer you hit to the center of the bullseye the less it will shrink
- If you hit outside the bullseye it is game over and your score is the number of darts you've thrown (in other words - 1 plus the number of times you hit the bullseye)
- Now suppose that a player always throws a dart that has an equal chance to hit anywhere within a square circumscribed around the original bullseye
- What is the expected score of that player? Or in other words if that player were to play an infinite amount of Hyper Darts games what will their average score be?
    </td>
	  <td>
      <img src="https://user-images.githubusercontent.com/30286047/120922163-4058f100-c6d0-11eb-810b-2aaf58322768.gif" alt="A gif which illustrates the problem by showing how a game of Hyper Darts might happen">
    </td>
  </tr>
</table>
  
## The Simulator
Once I heard the problem in the video I knew it was a relatively simple and straightforward simulation to do and so I wanted to do it. I didn't even watch the rest of the video, because I didn't want to spoil the answer for myself.

**⚠ Spoiler Alert:** If you don't want to spoil the answer for yourself, here is probably the place to stop reading for the moment, maybe go watch the video or something.

![The final program running in a cmd window](https://user-images.githubusercontent.com/30286047/120921866-9b89e400-c6ce-11eb-92f1-4a4d73abd096.gif)

_Note: If you don't care about me rambling about the development of this thing you can [click here](#the-simulations) to skip over to the results._

I thought I'd use C++ for better performance and I got the simulation working in C++ very quickly actually. Here's the thing though... I could've just let it run for half a day or something, but I thought I'd use multithreading so that the simulation ran faster. The thing is, I hadn't really ever used multithreading in C++, like ever... I knew this was gonna be a learning experience, but I didn't anticipate though just how much stuff you have to consider and keep in mind when multithreading.

The actual threading part was pretty easy actually using `std::thread`. That was not enough unfortunately, because almost everything in your program has to be made with multithreading in mind. From storing the results of the simulations to even the random number generation, it all had to be done seperately on each thread in order to work. Random number generation especially gave me a lot of trouble as I just hadn't thought of the fact that you need different random devices for each thread, or else the results were quite a long way off. So I made a `RandomGenerator` class that uses `std::mt19937` to generate my random numbers.

Since I planned on running the simulator for at least a few hours I wanted to print continuosly updating stats on the console. And that took longer than I expected too, mostly because I didn't anticipate that I have to synchronise the updates to the text, or otherwise it gets all garbled up.

As bizzare as it might sound, another thing I had to do for the first time in C++ was use multiple source files. After years of competitive programming I still hadn't done that (by myself anyway). But the project grew to the point where I really felt that it was the sensible thing to do. So creating the (rather annoying) headers and splitting my project was a bit of a challange to get working for the first time. But it did end up being another learning experience and as it turns out, it really isn't that difficult of a thing to do, albeit a little tedious, especially if you have to refactor something.

In the end though I did get the simulator working and I definitelly think it was worth it, I learnt a lot from ths experience.

## The Simulations
So in the end what estimate did I get? Well I finally let the simulator do its thing on my laptop's Ryzen 5 3550H. I only used 3 threads, not to push my (4 core) CPU too much, since it is on a laptop and it ran at about 60-70%  CPU utilization at ~3GHz as far as I saw. I ran it for just over 5 and a half hours and here are the results:
```
Simulations terminated successfully
Total time taken: 5h 31m 56s
Total number of simulations ran: 356343513077
Total score of all simulations: 781561104166
Maximum score achieved: 14
Average score across all simulations: 2.1932800106764323011532269447343423962593078613281
```
As you can see the simulator ran over 356 Billion simulations of the game. Alright not quite infinity, but I reckon that's pretty good. And the actual estimate that the simulator came up with wasn't bad either. After watching Numberphile's video you'll see that the answer to the problem is e<sup>π/4</sup>. So let's compare my result to an [actual decimal approximation of the answer, according to Wolfram Alpha](https://www.wolframalpha.com/input/?i=e%5E%28pi%2F4%29):

<table>
  <tr>
    <td>
      My estimate
    </td>
    <td>
      <b>2.1932800</b>106764323011532269447343423962593078613281
    </td>
  </tr>
    <td>
        e<sup>π/4</sup>
    </td>
    <td>
      <b>2.1932800</b>507380154565597696592787382234616376419942723348580
    </td>
  </tr>
</table>

So all in all, I've got 8 decimal digits estimated correctly, or in other words a precision of about 0.00000004. Maybe that doesn't sound all that impressive, especially considering that I did run the simulation for 5 and a half hours, but at least it did seem to work correctly. You might be able to get better results if you run it for longer and/or on better hardware, but after running it for so long I definitely felt like I was reaching the limits of just how good of an estimate I could get with the pseudo-random number generation and also with current hardware in general.

## Conclusion
In the end, I'm very happy with how this project turned out. While I started off, thinking it would only take a couple of hours and in reality it took a couple of days to finish it, it was a massive learning experience. And also I did ultimately achieve my goal I got a correct estimate and although not particularly impressive, it had a fair amount of precision.

_Note: If you are interested here's some further reading material that I found in the course of making this - [a simpler simulation of the problem](https://github.com/PinwheelGalaxy101/Shrinking-Bullseye); [an article explaining a different and more technical solution to the problem and another simpler simulation](http://blog.itdxer.com/2019/11/24/expected-value-of-the-unusual-game-of-darts.html)._
