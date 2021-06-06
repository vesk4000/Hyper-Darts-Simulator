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

_Note: If you don't care about me ranting about the development of this thing you can [click here](#the-simulations) to skip over the results._

I thought I'd use C++ for better performance and I got the simulation working in C++ very quickly actually. Here's the thing though... I could've just let it run for half a day or something, but I thought I'd use multithreading so that the simulation ran faster. The thing is, I hadn't really ever used multithreading in C++, so I knew this was gonna be a learning experience. I didn't anticipate though just how much stuff you have to consider and keep in mind when multithreading.

The actual threading part was pretty easy actually using `std::thread`. That is not enough unfortunately, because almost everything in your program has to be made with multithreading in mind. From storing the results of the simulations to even the random number generation, it all had to be done seperately on each thread just to work. Random number generation especially gave me a lot of trouble as I just hadn't thought of the fact that you need different random devices for each thread, or else the results were quite a long way off. So I made a `RandomGenerator` class that uses `std::mt19937` to generate my random numbers.

I also planned on running the simulator for at least a few hours so I wanted to be able to see how the simulations were going. I didn't want to just print it in the console indefinitelly. Again I just had to make my life harder, just so that the simulator was a little bit fancier with continuosly updating text on the console. And that took longer than I expected too, mostly because I had to synchronise the updates to text, or otherwise it got all garbled up.

Another thing I had to do for the first time was use multiple files. It may sound strange, but after years of competitive programming I still hadn't done that (by myself atleast). So creating the (rather annoying) headers and splitting my project was a bit of a challange to get working for the first time. I didn't even plan on doing that, but the project grew quite a lot from the original idea, so I thought that was a sensible thing to do. Plus it did end up as another learning experience and as it turns out, it really isn't that difficult of a thing to do in C++, albeit a little tedious, especially if you have to refactor something.

In the end though I did get the simulator working and I definitelly think it was worth it.

## The Simulations
