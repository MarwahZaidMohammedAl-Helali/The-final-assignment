# Part 2


## Video Demo


Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=M_0GizvEyBE).


## Minimum Requirements


### Completed


List all the features completed.


1. Developed the capability for the player to manipulate the direction of the arrows before moving the alien, enabling the player to exercise greater control and strategic planning in gameplay..


2.Rectified a previous stack overflow error that would occur when the alien encountered an arrow, resulting in a more stable and dependable game.


3.Successfully randomized placement and proper execution of all game objects, including Arrow, Health, Pod, Rock, Empty, and Trail.


4.Ensured proper functionality of the pods when encountered by the alien, allowing for successful collection and utilization during gameplay.


5.Implemented zombie movement functionality, enabling them to navigate the game board and inflict damage on the alien when within range, elevating the game's level of challenge and excitement.


6.Added movement functionality for both the alien and the zombie.




7.All the Game Objects (Arrow, Health, Pod, Rock, Empty and Trail ) are based in the board randomly and runs properly .
 
8. Established the ability for the player to manipulate the direction of the arrows, providing expanded control and strategic options during gameplay.


9.Implemented fully functional game controls, including arrow direction manipulation, help, save, and quit options.




### To Do


List all the features not yet done. Remove this section if there is no incomplete requirements.


1.We were successfully able  to save the game data. However, we encountered challenges in loading the saved data back into the game. The issue we faced was that we were unable to establish a connection between the saved file and the upload process, rendering it impossible to upload the saved file and retrieve the stored data. We have thoroughly investigated this problem and have concluded that further work is necessary to resolve the loading issue.


## Additional Features


Describe the additional features that has been implemented.


## Contributions


List down the contribution of each group members.




Marwah:


Played a great role in the development of the game, contributing to multiple aspects of the project. Specifically,  was involved in the implementation of the Alien and Zombie movement mechanics, as well as the overall gameplay flow. She was also responsible for ensuring that all of the Game Objects in the game, including the Arrow, Health, Pod, Rock, Empty, and Trail, functioned properly.  also played a crucial role in identifying and addressing various errors that were encountered during the development process, contributed to the addition of new features in the game and conducted research to ensure that the game was developed to the best of its potential.




Thabit:


Made significant contributions to the development of the game, with a focus on the game flow and controls. He was responsible for designing the turn-based mechanics that govern how the Alien and Zombie characters interact with each other and the game environment and managed their behaviors  ensuring that they functioned properly and interacted with each other and the game environment as intended.  was also responsible for implementing the additional feature and he did most of it, and he fix the ability for the player to control the Arrow direction, and the game controls for help,  and quit, worked diligently to fix errors encountered during the development process .


khalid:


Played a vital role in the development of the game, he  played a great role in identifying and addressing various errors in the code, ensuring that the game ran smoothly and without interruption. In addition to this, Khalid also contributed to the overall functionality of the game by describing both the Alien and Zombie movement and their interaction with the game objectives. He add the save option to the game,Throughout the development process, Khalid spent a significant amount of time working with the rest of the team to fix any issues that arose and ensure that the game was functioning as intended.






## Problems Encountered & Solutions


one of the problems that we encounterd was giving the player the ability to change the direction of the arrows, which we fixed by creating a function  arrow() that takes input from the user for the position of the row, as well as the column, and also the new direction that you want the arrow to face. It then checks the given cordinates for an arrow, if it finds an arrow (represented by the characters '<', '>', 'v', or '^'), it updates its direction to the given arrow direction.

We also had trouble with giving the zombies the ability to move around the board. we have fixed it by creating a loop that  loops over all the zombies and checks if the zombie is alive by checking its life attribute. If the zombie is alive, the function print_Alien_active() is called to indicate that the alien is now active. The function printA() is then called to print the current state of the alien. The variable Z_active is set to true for the current zombie, and a loop is executed to print the current state of all the zombies on the board. Then the variable Z_active is reset to false after printing the state of each zombie.

Fixing usability issues like, we fixed that by simply adding else statments to th if block as well as adding a default to the switches.

Adding additional features, we struggled to come up with a good idea but after we setteled on enabling the alien to wuekd weapons such as a sord and an axe. We created a function that declares a variable called selectWeapon, which Prompts the user to select a weapon by entering either 1 for Sword or 2 for either a sowrd or an Axe. then the function calls the select_weapon() function of the object A or the alien which in turn it updates the alien's damage according to the chossen weapn as well as the range which enables the alien to strike from a distance much like the zombie.

we also had a problem in figuring out a way to save the game, we did that by creating a function callled  saveToFile which openes a file in write mode using ofstream. Then it exports all of the essintial information of the game such as the dimensions of the game board, the number of zombies in the game, and the positions of different game objects on the board. It also writes information about the aliens and the zombies in the game, such as their health, attack power, and range.
