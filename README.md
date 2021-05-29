# CPP Videogame

<p align="center">
    <img src="https://i.imgur.com/lgi4uSY.jpg" width="250" alt="Università degli Studi Firenze"/>
</p>

## Overview

At game launch, after an introductory splashscreen, you will be able to select one of the proposed characters. Each of them has different abilities and weapons, which affect the fighting style. Next you'll be able to give your character a name and select a buddy: a dog, a chicken or a sheep. These will be NPCs that will help the protagonist during his adventures. Once this setup phase is finished, the real game will start. 

<p align="center">
    <img src="https://i.imgur.com/NQsmD3R.png" width="1000" alt="select player and name screen"/>
</p>

To move the character the classic WASD configuration was chosen, while the directional arrows were assigned the task of **casting spells** and the space bar the use of the selected **weapon**. Defeating enemies, they will drop their weapon that will become collectable and usable from that moment on. Other collectable items are **coins**, obtained by defeating enemies. Once they are collected, they will increase the relative counter. If the character is wounded, his life will decrease depending on the amount of the sustained damage. One way to recover life quickly is to use, if available, the various **potions**. Finally, as the game progresses, the character will get **experience points** according to the achievements he has reached.

<p align="center">
    <img src="https://i.imgur.com/KsWFDHD.png" width="1000" alt="gameplay"/>
</p>

In order to keep the status bar updated, the **Observer design patter** was used in pull mode. Moreover, to make the enemies' behavior more realistic, they will engage in duels with the protagonist, following him on the map until one of them dies. If the protagonist takes damage, his buddy will come to his rescue.

Please note that, since we used copyrighted sprites to make the game look more appealing, those were not included in the repo.

## Team

- Gianluca Botteri [[Github](https://github.com/GianlucaBotteri)] [[Email](mailto:gianluca.botteri@gmail.com)]
- Samuele Meta [[Github](https://github.com/SamueleMeta)] [[Email](mailto:samuele.meta@mail.polimi.it)]
