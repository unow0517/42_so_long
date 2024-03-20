# so_long
2D game with Open Source Library [MLX 42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Textures.md)

## Must know
* 32 bits per pixel in PNG (8bits for R,G,B,A)
* Most of computer games refresh their frame so fast, so user input can be applied right away.

## Challenges
* Drawing background is feasible without struct, but moving Shiba is impossible without struct
<br/><br/>


## Key Point
* I thought using struct is following Object-Oriented-Programming paradigm, but not. [Why is C not considered an 'object-oriented' language?](https://softwareengineering.stackexchange.com/questions/113533/why-is-c-not-considered-an-object-oriented-language). C is procedural programming language.
* Using struct to store information about an Object. Shiba, Tile, House, Food in my case. why struct? to save information of an object. A struct can group related variables under one name, much like how an object in OOP(Object-Oriented-Programming) has properties