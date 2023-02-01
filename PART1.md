# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=ZO7AEO-D1kA).

## Minimum Requirements

### Completed

List all the features completed.

1. Game Board
- The dimension must ne odd number and alien must be placed at the centre
2. Randomly generated Alien's attack.
3. Randomly generated Zombie's life, attack, and range.
4. Randomly puts zombie in the game board
5. Randomly generates game objects and puts them in the Game Board

### To Do

1. Alien's movement and attack.
2. Alien's trail.
3. Zombie's movement and attack.
4. Saving and loading file.

## Additional Features
### To do

1. A sound will be made when the alien hits the border, gain a health powerup, and successfully killed a zombie.
2. Super pod. Will attack 2 zombies that are nearby.

## Contributions

List down the contribution of each group members.


### Amirah Hakimah Binti Masri.

1. Zombie movement and attack behaviour.
2. Alien movement.
3. Alien making trail.
4. Making sound appear while playing games.

### Nurul Afiqah Binti Ismail.

1. Game interface (Menu).
3. Main Menu.
2. Generate game board.
3. Randomly generate pod, health, and arrow.
4. Saving and loading the files.


## Problems Encountered & Solutions

1. Problems encountered when using class, there are some errors that happened. Then when we tried not to use class and only by using functions but then we also encountered a lot more errors. 
We tried to solve the errors by going through the lecture slides, stackoverflow, chatGPT, and searching through google and able to solve some of them, but there's some error that we do not understand at all. 
For some of the problems, we have yet found its solution.

2. When we tried to set a default value to the board dimensions, the map did not display completely. Also, when the user input in their wanted dimensions, it did not update properly. 
Planned solutions : I think it might be some problems with our referencing I think which is at pass by referencing. When we updated the value of some variables in somewhere else, it did not update the variable propperly as such it cannot be used in another function.

3. When we insert the move function for the alien, we encountered some errors, and ended up we cannot make the alien move in our board. Eventhough, when we tried elsewhere, we successfully make the alien move throughout the boards. But when we put the codes in our game program in does not work.
Solutions: We tried and errors a lot of times, like really a lot but still unsuccessful. There are yet no solutions for this problem.

4. Some errors that we find and have successfully solves which is
- C++ function was not declared
- C++ error two or more data types in declaration of functions
- expected initializer before ''
- a declaration shadows a parameter
- ' ' was not declared in this scope
- expected primary expression before token C++

5. Zombie would be on top alien despite the location is being randomized.
Planned Solutions : Need to add index or add another functions or conditions.

6. Alien 1 would also be on top of Alien 2.
Planned solution : Same as above.