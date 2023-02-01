# Alien vs. Zombie

Please introduce the game here.

Alien vs Zombie is a game that challege your IQ which is required the player to do calculating while playing the game. This game is inspired by Path Alien game however the ways its played is a bit different. The user is given a choice to customized their own gameboard and how many zombies they want to be fight with up to 9 zombies. This game would be one of your favourite games. Hope you will enjoy play Alien vs Zombie :)

Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=ZO7AEO-D1kA).

## Compilation Instructions

Provide instructions on how to compile your program, especially when it is non-trivial.

For example:

```
g++ main.cpp folder1\code.cpp folder2\code.cpp ......
```

## User Manual

Please provide the user manual on how to use your program.

1. User is provided 3 options which is:
    1. Play game!   --> to start the game
    2. How To Play? --> to know the overview of the game
    3. Help ...     --> to know the keywords
    4. Exit.        --> back to main menu

2. When the user click on 'Play game!', the user will be shown a default setting that contain the number of row and column and the user is given 2 choice which to remain the setting or change it. If he/she wants to change the setting, the user need to key in the value of the number of row, the number of column and also the number of zombies they want within the range stated.

3. The gameboard will pop up according to the setting. Alien and zombie(s)'s attribute will be shown under the gameboard. The attribute will change each time the attack is launched.

4. The user who is an Alien need to attack the zombie(s) until its lifes become zero to be declared as winner. The user need to use the keywords provided in 'Help...' to make a move which is UP, DOWN, LEFT, RIGHT and ARROW.

5. To change the direction of arrow, the user need to tell the coordinate of the arrow and the direction to change it by entering the the row, column and direction (UP, DOWN, RIGHT,LEFT). The arrow direction can be change many times as many as the user wants and the user can proceed to move the Alien. The move of the Alien can be enter once in each turn.

6. Remember, the Alien wil be stop once it hits Rock(r), border of the gameboard and zombie whose the lifes is greater than the Alien's attack.

7. How to kill the zombie(s)? The Alien can collect Pod objects(p) to inflict 10 damages to the nearest zombie and Arrow objects(<, >, ^, V) to increase the value of attack which is 20 values each Arrows. The Pods (p) and Arrows (<, >, ^, V) can also be hidden under a Rock but to get it, the Alien need to hit it and Alien will stop moving.

8. The game will take turn one after another which is start with the Alien first and followed by the zombie(s).

9. The zombie(s) can attack the Alien if the Alien is in the range of the zombie. The lifes of Alien will decrease according to the number of attack of the zombie.

10. To recharge the Alien's lifes, the user need to collect Health object (h) which is each Health object will add 20 lifes to the Alien if the lifes is not max.

11. The game will be continued until the zombie(s)'s lifes become zero and vice versa or the user choose to end the game by entering quit command, the game will end. The user will return to Main Menu.

12. The user also can save their games and load it to continue to play the saved game however once the user quit (quit command), the saved game will no longer exist. 

Please DO NOT change the Progress Log below. Leave it as it is.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

- Nurul Afiqah binti Ismail
- Amirah Hakimah binti Masri



