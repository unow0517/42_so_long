# so_long
To write a program which takes a map as an input variable, verifying if the map is valid<br/>
(if 1 player, 1 house, more than 0 food exist, etc.) and making 2D game with the map.
<br/><br/>
![](https://github.com/unow0517/so_long/blob/master/playing.gif)<br/><br/>
Open Source Library [MLX 42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Textures.md) is used.
<br/>

## Must know
* Most of computer games refresh their frame so fast (60times per sec), so user input can be applied right away.
* Information such as player location, whether food is collected should be saved in struct.
<br/>

## Challenges
* Drawing background is feasible without struct, but moving Shiba is impossible without struct
* Validate the Map input if the map has connected path from player to collectable and exit. -> solved with **Flood Fill algorithm**
<br/>

## Key Point
* I thought using struct is following Object-Oriented-Programming paradigm, but not. [Why is C not considered an 'object-oriented' language?](https://softwareengineering.stackexchange.com/questions/113533/why-is-c-not-considered-an-object-oriented-language). C is procedural programming language.
* Using struct to store information about an Object. Shiba, Tile, House, Food in my case. why struct? to save information of an object. A struct can group related variables under one name, much like how an object in OOP(Object-Oriented-Programming) has properties.
<br/>

## How To Run
1. `git clone https://github.com/unow0517/so_long.git`
2. `cd so_long`
3. `make all`
4. `./so_long ./map.ber`

You can edit "map.ber" file to create your own map, following the rule that 1 is water, 0 is grass, P is shiba, C is food, E is house.
<br/>

## How To Play
* `w` `s` `a` `d` => move muscle shiba
* collect all the foods
* reach house and chill
