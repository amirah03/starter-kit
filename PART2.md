# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Game Board - The dimension must ne odd number and alien must be placed at the centre.
2. Randomly generated Alien's health, and Zombie's life, attack, and range.
3. Randomly put Zombie inside the map and it's coordinate cannot be the same as alien.
4. Randomly generates game objects and puts them in the Game Board.
5. Alien and Zombie's movement.
6. Health and attack increased when meeting the attributes in the map.
7. Alien's trail.
8. When Alien hits the rock, the rock disappears and was replaced by random attributes (h/p/^/v/</>).
9. When Alien tried to get out of the border, it will stopped.
10. Change the wanted arrow at what coordinates.

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Delete the trail after alien's move.
2. Board setting for the map an the default value.
3. Saving and Loading the file.
4. Pod - When Alien meet the pod in the board, the alien is yet to be able to attack the nearest zombie(s) available.
5. Zombie is yet to be able to attack the alien if it is inside it's range.
6. Additional feature is also yet to be done - Adding sound effect.

## Contributions

List down the contribution of each group members.

For example:

### Amirah Hakimah Binti Masri

1. Alien's movement.
2. Change the wanted arrow at what coordinates.
3. Make the loop to play the game.
4. Accept the instructions from the user whether to change the arrow, move the alien, help or quit.
5. Change the arrow at user's input coordinate.
6. Increasing and decreasing of life and attack of alien.

### Nurul Afqah Binti Ismail

1. Create a board with randomly generated attributes inside the map.
2. Create Zombies vector and Zombie's movement.
3. Randomly insert Zombie(s) inside the gameboard.
4. Put the Aien in the middle of the gameboard.
5. Create and array for alien's health and attack.

## Problems Encountered & Solutions

We faced too many kind of problems that I cannot write all of them here. Below are several errors that we encountered :

1. We have created the default menu at the earlier stage of doing this assignment, thus we assume we would be able to put them inside our proggramme later since we would like to avoid a lenghty file. Surprisingly, we cannot use the same method of default value and we do not know what's exactly the solution. When we change the row and column acording to user's input, the default value did not follow the new value. 

2. We have created a function with it's parameter accepting two vectors which is zombie and alien. But then it says error. The error says that the function was expectig an int& value and i also says that cannot convert vector into integer. We do not understand the problem at all. We tried solving it by changing the alien's vector into array. Since the problem only arise with Alien's vector but not Zombie's vector.

3. There are some instances where when we run our proggrame it says terminated. We did not know what's the solution for this error and what exactly caused the error.

4. When I run my programe, runtime error occurred and then it opens up stl_vector.h files. Until now I did not understand what caused the error, and what exactly the solution.
